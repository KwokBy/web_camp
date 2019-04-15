package kwok.Servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import kwok.Service.UserService;
import kwok.Service.impl.UserServiceImpl;
import kwok.pojo.User;

/**
 * Servlet implementation class UserServlet
 */
@WebServlet("/UserServlet")
public class UserServlet extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
	//获取service层对象
	UserService us = new UserServiceImpl();   
	@Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        resp.setContentType("text/html;charset=utf-8");
        //获取操作符
        String oper=req.getParameter("oper");
        if("login".equals(oper)) {
        	 //调用登录处理方法
            checkUserLogin(req,resp); 	
        }else if("regiter".equals(oper)){
        	//调用注册处理方法
        	UserRegister(req,resp);
        }else if("pwd".equals(oper)) {
        	//调用密码修改
        	userChangPwd(req,resp);
        }else {
        	System.out.println("没有找到对应的操作符"+oper);
        }
    }
       //处理修改密码
    private void userChangPwd(HttpServletRequest req, HttpServletResponse resp) throws IOException {
		// TODO Auto-generated method stub
    	String newPwd=req.getParameter("newPwd");
        User u=(User)req.getSession().getAttribute("user");
        int uid=u.getUid();
        int index=us.userChangePwdService(newPwd,uid);
        if(index!=-1) {
        	req.setAttribute("flag1", "true");
        	try {
				req.getRequestDispatcher("/Login.jsp").forward(req, resp);
			} catch (ServletException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return;
        }else {
        	req.setAttribute("flag1", "false");
        	try {
				req.getRequestDispatcher("/Pwd.jsp").forward(req, resp);
			} catch (ServletException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
        	return;
        }
	}
	//处理注册
    private void UserRegister(HttpServletRequest req, HttpServletResponse resp) throws IOException {
	    String uname=req.getParameter("uname");
	    String pwd=req.getParameter("pwd");
	    String pwd2=req.getParameter("pwd2");
	    String sex=req.getParameter("sex");
	    String birth=req.getParameter("birth"); 
	    System.out.println(uname+":"+pwd+":"+pwd2+":"+sex+":"+birth);
	    User u=new User(0, uname, pwd, sex, birth);
	    if("pwd".equals("pwd2")) {
	    int index=us.userRegisterService(u);
	    if(index!=-1) {
        	req.setAttribute("flag2", "true");
        	try {
				req.getRequestDispatcher("/Login.jsp").forward(req, resp);
			} catch (ServletException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	     }
	   }else {
		   req.setAttribute("flag2", "false");
		   try {
				req.getRequestDispatcher("/Login.jsp").forward(req, resp);
			} catch (ServletException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	     }
	}
	//处理登录
	private void checkUserLogin(HttpServletRequest req, HttpServletResponse resp) throws IOException {
		// TODO Auto-generated method stub
		String uname = req.getParameter("uname");
		String pwd = req.getParameter("pwd");
		System.out.println(uname+":"+pwd);//校验用户名和密码传入是否成功
		User u = us.checkUserLoginService(uname, pwd);
		System.out.println(u);//u是否获取成功
		if(u!=null){
			HttpSession hs=req.getSession();
			hs.setAttribute("user", u);
			//重定向
			resp.sendRedirect("/kwok-ManagementSystem/main/main.jsp");
			return;
		}else {
			req.setAttribute("flag", "false");
			try {
				req.getRequestDispatcher("/Login.jsp").forward(req, resp);
			} catch (ServletException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return;
		}
	}
}
