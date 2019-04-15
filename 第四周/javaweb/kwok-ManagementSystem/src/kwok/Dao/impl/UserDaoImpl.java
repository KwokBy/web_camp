package kwok.Dao.impl;

import java.sql.Connection;

import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import kwok.Dao.UserDao;
import kwok.pojo.User;

public class UserDaoImpl implements UserDao{

	@Override
	public User checkUserLoginDao(String uname, String pwd) {
		//声明jdbc对象
		Connection conn = null;
		PreparedStatement ps = null;
		ResultSet rs = null;
		//声明变量
		User u = null;
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			conn=DriverManager.getConnection("jdbc:mysql://localhost:3306/qglogin?useSSL=false&serverTimezone=UTC","root","Gl987963951");
			String sql = "select * from t_user where uname=? and pwd=?";
			ps = conn.prepareStatement(sql);
			ps.setString(1, uname);
			ps.setString(2, pwd);
			rs = ps.executeQuery();
			while(rs.next()) {
				u=new User();
				u.setUid(rs.getInt("uid"));
				u.setUname(rs.getString("uname"));
				u.setPwd(rs.getString("pwd"));
				u.setAge(rs.getInt("age"));
				u.setSex(rs.getString("sex"));
				u.setBirth(rs.getString("birth"));
			}
		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
		}finally {
			try {
				rs.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			try {
				ps.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			try {
				conn.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return u;
	}
    //根据uid修改密码
	@Override
	public int userChangePwdDao(String newPwd, int uid) {
		Connection conn = null;
		PreparedStatement ps = null;
		int index=-1;
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			conn=DriverManager.getConnection("jdbc:mysql://localhost:3306/qglogin?useSSL=false&serverTimezone=UTC","root","Gl987963951");
			String sql = "update t_user set pwd=? where uid=?";
			ps = conn.prepareStatement(sql);
			ps.setString(1, newPwd);
			ps.setInt(2, uid);
			index=ps.executeUpdate();
		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
		}finally {
			try {
				ps.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			try {
				conn.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return index;
	}
	//注册
	@Override
	public int userRegisterDao(User u) {
		//声明jdbc对象
				Connection conn = null;
				PreparedStatement ps = null;
				int index=-1;
				try {
					Class.forName("com.mysql.cj.jdbc.Driver");
					conn=DriverManager.getConnection("jdbc:mysql://localhost:3306/qglogin?useSSL=false&serverTimezone=UTC","root","Gl987963951");
					String sql = "insert into t_user(uname,pwd,sex) values(?,?,?)";
					ps = conn.prepareStatement(sql);
					ps.setString(1, u.getUname());
					ps.setString(2, u.getPwd());
					ps.setString(3, u.getSex());
	
					index=ps.executeUpdate();
				} catch (Exception e) {
					// TODO: handle exception
					e.printStackTrace();
				}finally {
					try {
						ps.close();
					} catch (SQLException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					try {
						conn.close();
					} catch (SQLException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
				return index;
	}

}
