package kwok.Dao;

import kwok.pojo.User;

public interface UserDao {
   /**
    * �����û����������ѯ��¼��Ϣ
    * @param uname         �û���
    * @param pwd             ����
    * @return ���ز�ѯ�����û���Ϣ
    */
	User checkUserLoginDao(String uname,String pwd);
/**
 * �����û�id�޸�����
 * @param newPwd  ������
 * @param uid     
 * @return
 */
int userChangePwdDao(String newPwd, int uid);
/**
 * ע��
 * @param u
 * @return
 */
int userRegisterDao(User u); 
}
