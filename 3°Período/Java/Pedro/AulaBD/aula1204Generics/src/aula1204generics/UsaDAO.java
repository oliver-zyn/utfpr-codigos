/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package aula1204generics;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author geri_
 */
public class UsaDAO {
    public static void main(String[] args) {
        AlunoDAO con = new AlunoDAO();        
        Aluno x = new Aluno(12,"22","teste22",'M',22);

        con.inserir(x);

        con.listar().forEach(System.out::println);

        System.out.println("Alterando o CPF");
        x.setCpf("22222");
        con.alterar(x);

        con.listar().forEach(System.out::println);

        System.out.println("Removendo registros");
        con.remover(12);
        
        con.listar().forEach(System.out::println);                
    }
    
}
