package kwok.Service.impl;

import kwok.Dao.UserDao;
import kwok.Dao.impl.UserDaoImpl;
import kwok.Service.UserService;
import kwok.pojo.User;

public class UserServiceImpl implements UserService{
    //����Dao�����
	UserDao ud = new UserDaoImpl(); 
	//�û���¼ 
	@Override
    public User checkUserLoginService(String uname, String pwd) {
    	return ud.checkUserLoginDao(uname, pwd);
    }
	//�޸�����
	@Override
	public int userChangePwdService(String newPwd, int uid) {
		// TODO Auto-generated method stub
		return ud.userChangePwdDao(newPwd,uid);
	}
	//ע��
	@Override
	public int userRegisterService(User u) {
		// TODO Auto-generated method stub
		return ud.userRegisterDao(u);
	}
}
