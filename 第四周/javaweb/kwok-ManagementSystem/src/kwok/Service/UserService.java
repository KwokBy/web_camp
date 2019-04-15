package kwok.Service;

import kwok.pojo.User;

public interface UserService {
    /**
     * 校验用户登录
     * @param uname 用户名
     * @param pwd   密码
     * @return      返回查询到的信息
     */
	User checkUserLoginService(String uname,String pwd);
    /**
     * 修改用户密码
     * @param newPwd 新密码
     * @param uid    用户id
     * @return       
     */
	int userChangePwdService(String newPwd, int uid);
	/**
	 * 注册
	 * @param u 用户各种信息
	 * @return   
	 */
	int userRegisterService(User u);
   
}
