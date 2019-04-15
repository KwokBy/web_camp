package kwok.Service.impl;

import kwok.Dao.UserDao;
import kwok.Dao.impl.UserDaoImpl;
import kwok.Service.UserService;
import kwok.pojo.User;

public class UserServiceImpl implements UserService{
    //声明Dao层对象
	UserDao ud = new UserDaoImpl(); 
	//用户登录 
	@Override
    public User checkUserLoginService(String uname, String pwd) {
    	return ud.checkUserLoginDao(uname, pwd);
    }
	//修改密码
	@Override
	public int userChangePwdService(String newPwd, int uid) {
		// TODO Auto-generated method stub
		return ud.userChangePwdDao(newPwd,uid);
	}
	//注册
	@Override
	public int userRegisterService(User u) {
		// TODO Auto-generated method stub
		return ud.userRegisterDao(u);
	}
}
