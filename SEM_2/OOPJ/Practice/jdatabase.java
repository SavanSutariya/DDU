import java.sql.*;

class jdatabase{
    public static void main(String [] args) throws Exception{
        String url = "jdbc:mysql://localhost:3306/exam";
        String uname = "root";
        String pass = "savan";
        Class.forName("com.mysql.jdbc.jc.Driver");
        Connection con = DriverManager.getConnection(url,uname,pass);
    }
}