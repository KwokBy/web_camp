package kwok.Dao;

import kwok.pojo.User;

public interface UserDao {
   /**
    * 根据用户名，密码查询登录信息
    * @param uname         用户名
    * @param pwd             密码
    * @return 返回查询到的用户信息
    */
	User checkUserLoginDao(String uname,String pwd);
/**
 * 根据用户id修改密码
 * @param newPwd  新密码
 * @param uid     
 * @return
 */
int userChangePwdDao(String newPwd, int uid);
/**
 * 注册
 * @param u
 * @return
 */
int userRegisterDao(User u); 
}
