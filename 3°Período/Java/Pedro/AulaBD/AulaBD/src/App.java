/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

import classes.ConexaoDAO;
import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class App {

    public static void main(String[] args) {
        ConexaoDAO con = ConexaoDAO.getInstance();        
        Statement st;
        ResultSet rs;
        String sql = "Select * from aluno";

        try {

            st = con.getCon().createStatement();
            rs = st.executeQuery(sql);
            while (rs.next()) {
                System.out.println("Codigo: "
                        + rs.getInt(1));
                System.out.println("Cpf: "
                        + rs.getString(2));
                System.out.println("Nome: "
                        + rs.getString(3));

            }
        } catch (SQLException ex) {
            Logger.getLogger(App.class.
                    getName()).log(Level.SEVERE,
                            null, ex);
        }
        con.fecharCon();
    }
}

