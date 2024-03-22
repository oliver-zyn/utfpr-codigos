package br.utfpr.aula2;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;;

public class Dao2103 {
  public void gravarArquivo(File f, String nome, int idade, double salario) {
    try {
      OutputStream o = new FileOutputStream(f, true);

      DataOutputStream d = new DataOutputStream(o);
      d.writeUTF(nome);
      d.writeInt(idade);
      d.writeDouble(salario);
      
      d.close();
      o.close();
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }    
  }

  public String lerArquivo(File f) {
    StringBuilder sb = new StringBuilder();
    
    try {
      InputStream i = new FileInputStream(f);
      DataInputStream d = new DataInputStream(i);
      String nome;
      int idade;
      double salario;
      
      while (d.available() > 0) {
        nome = d.readUTF();
        idade = d.readInt();
        salario = d.readDouble();

        sb.append("Nome: " + nome)
          .append("\nIdade: " + idade)
          .append("\nSalario: " + salario);
      }

      d.close();
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }
    
    return sb.toString();
  }
}