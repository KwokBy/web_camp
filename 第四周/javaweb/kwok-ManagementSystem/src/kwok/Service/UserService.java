package kwok.Service;

import kwok.pojo.User;

public interface UserService {
    /**
     * У���û���¼
     * @param uname �û���
     * @param pwd   ����
     * @return      ���ز�ѯ������Ϣ
     */
	User checkUserLoginService(String uname,String pwd);
    /**
     * �޸��û�����
     * @param newPwd ������
     * @param uid    �û�id
     * @return       
     */
	int userChangePwdService(String newPwd, int uid);
	/**
	 * ע��
	 * @param u �û�������Ϣ
	 * @return   
	 */
	int userRegisterService(User u);
   
}
