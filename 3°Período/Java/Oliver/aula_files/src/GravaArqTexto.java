import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public class GravaArqTexto {
  public static void main(String[] args) {
    File arq = new File("./src/arquivos/teste2.txt");
    
    try {
      FileWriter fw = new FileWriter(arq);
      PrintWriter pt = new PrintWriter(fw);

      for(int i = 0; i <= 10; i++) {
        pt.println("Linha: " + i);
      }

      System.out.println("Conteudo escrito");

      fw.close();
      pt.close();
    } catch (Exception e) {
      System.out.println("Ocorreu um erro: " + e.getMessage());
    }
    
    try {
      FileReader arqReader = new FileReader("./src/arquivos/teste2.txt");
      BufferedReader bufferedReader = new BufferedReader(arqReader);

      String linha = bufferedReader.readLine();
      String conteudo = "";

      while (linha != null) {
        conteudo += linha + "\n";
        linha = bufferedReader.readLine();
      }

      System.out.println(conteudo);

      arqReader.close();
      bufferedReader.close();
    } catch (Exception e) {
      System.out.println("Ocorreu um erro: " + e.getMessage());
    }

  }
}
