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
	//��ȡservice�����
	UserService us = new UserServiceImpl();   
	@Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        resp.setContentType("text/html;charset=utf-8");
        //��ȡ������
        String oper=req.getParameter("oper");
        if("login".equals(oper)) {
        	 //���õ�¼������
            checkUserLogin(req,resp); 	
        }else if("regiter".equals(oper)){
        	//����ע�ᴦ����
        	UserRegister(req,resp);
        }else if("pwd".equals(oper)) {
        	//���������޸�
        	userChangPwd(req,resp);
        }else {
        	System.out.println("û���ҵ���Ӧ�Ĳ�����"+oper);
        }
    }
       //�����޸�����
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
	//����ע��
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
	//�����¼
	private void checkUserLogin(HttpServletRequest req, HttpServletResponse resp) throws IOException {
		// TODO Auto-generated method stub
		String uname = req.getParameter("uname");
		String pwd = req.getParameter("pwd");
		System.out.println(uname+":"+pwd);//У���û��������봫���Ƿ�ɹ�
		User u = us.checkUserLoginService(uname, pwd);
		System.out.println(u);//u�Ƿ��ȡ�ɹ�
		if(u!=null){
			HttpSession hs=req.getSession();
			hs.setAttribute("user", u);
			//�ض���
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
