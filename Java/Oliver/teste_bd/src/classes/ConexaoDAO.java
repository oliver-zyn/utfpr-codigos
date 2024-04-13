/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package classes;
import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;
public class ConexaoDAO {
    Connection con;
    private static ConexaoDAO instancia = null;
    
    public ConexaoDAO(){
        String url = 
        "jdbc:postgresql://localhost:5432/testebd";
        String usuario = "postgres";
        String senha = "242322";
        try {
            con = DriverManager.getConnection(
                    url,usuario,senha);
            System.out.println("Conexao ok");
        } catch (SQLException ex) {
            Logger.getLogger(ConexaoDAO.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public Connection getCon(){
        return this.con;
    }
    
    public static ConexaoDAO getInstance(){
        if(instancia == null){
            instancia = new ConexaoDAO();
        }
        return instancia;
    }
    
    public void fecharCon(){
        if (con != null){
            try {
                con.close();
            } catch (SQLException ex) {
                Logger.getLogger(ConexaoDAO.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }    
}
