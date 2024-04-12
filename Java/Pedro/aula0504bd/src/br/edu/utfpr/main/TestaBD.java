/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.edu.utfpr.main;

import br.edu.utfpr.DAO.ConexaoDAO;
import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class TestaBD {

    public static void main(String[] args) {
        ConexaoDAO con = ConexaoDAO.getInstance();        
        Statement st;
        PreparedStatement pst;
        ResultSet rs;
        String sql = "Select * from aluno";
        String sql1 = "insert into aluno (matricula, cpf, nome, "
                + "sexo, profissao) values (?,?,?,?,?)";
        String sql2 = "update aluno set cpf = ?, nome = ?, sexo = ?,"
                + "profissao = ? where matricula = ?";
        String sql3 = "delete from aluno where matricula = ?";
        try {
            // Inserção de registros no BD
            pst = con.getCon().prepareStatement(sql1);
            pst.setInt(1, 10);
            pst.setString(2,"999");
            pst.setString(3, "teste");
            pst.setString(4, "F");
            pst.setInt(5, 1);
            pst.executeUpdate();
            // Seleção de registros do BD
            st = con.getCon().createStatement();
            rs = st.executeQuery(sql);
            // Alteração de registros do BD
            pst = con.getCon().prepareStatement(sql2);            
            pst.setString(1,"999999");
            pst.setString(2, "testeteste");
            pst.setString(3, "M");
            pst.setInt(4, 3);
            pst.setInt(5, 10);
            pst.executeUpdate();   
            // deleção de registros do BD
            pst = con.getCon().prepareStatement(sql3);            
            pst.setInt(1, 10);
            pst.executeUpdate();
            while (rs.next()) {
                System.out.println("Codigo: "
                        + rs.getInt(1));
                System.out.println("Cpf: "
                        + rs.getString(2));
                System.out.println("Nome: "
                        + rs.getString(3));
            }
        } catch (SQLException ex) {
            Logger.getLogger(TestaBD.class.
                    getName()).log(Level.SEVERE,
                            null, ex);
        }
        con.fecharCon();
    }
}
