package classes;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;;

public class ControleArquivosAlunos {
  public void gravarArquivo(File f, int cod, String nome, int nota1, int nota2) {
    try {
      OutputStream o = new FileOutputStream(f, true);

      DataOutputStream d = new DataOutputStream(o);
      d.writeInt(cod);
      d.writeUTF(nome);
      d.writeInt(nota1);
      d.writeInt(nota2);
      
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
      int cod, nota1, nota2;
      
      while (d.available() > 0) {
        cod = d.readInt();
        nome = d.readUTF();
        nota1 = d.readInt();
        nota2 = d.readInt();

        sb.append("\nCodigo do aluno: " + cod)
          .append("\nNome: " + nome)
          .append("\nNota 1: " + nota1)
          .append("\nNota 2: " + nota2)
          .append("\n");
      }

      d.close();
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }
    
    return sb.toString();
  }

  public String calcularResultadoFinal(File f) {
    StringBuilder sb = new StringBuilder();
    
    try {
      InputStream i = new FileInputStream(f);
      DataInputStream d = new DataInputStream(i);
      String nome;
      int cod, nota1, nota2;
      float media;
      
      while (d.available() > 0) {
        cod = d.readInt();
        nome = d.readUTF();
        nota1 = d.readInt();
        nota2 = d.readInt();

        media = (nota1 + nota2) / 2.0f;

        System.out.println(media);

        sb.append("\nCodigo do aluno: " + cod)
          .append("\nNome: " + nome)
          .append("\nNota 1: " + nota1)
          .append("\nNota 2: " + nota2)
          .append(String.format("\nMedia %.1f: ", media))
          .append("\nSituacao: " + situacaoAluno(media))
          .append("\n");
      }

      d.close();
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }

    return sb.toString();
  }

  private static String situacaoAluno(float media) {
		String situacao = "Reprovado";

		if (media >= 7) {
			situacao = "Aprovado";
		} else if (media >= 4) {
			situacao = "Em exame";
		}

		return situacao;
	}
}