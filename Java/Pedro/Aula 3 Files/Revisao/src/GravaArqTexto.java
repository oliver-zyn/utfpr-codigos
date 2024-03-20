import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public class GravaArqTexto {

    // GRAVACAO
    public static void main(String[] args) {
        File arq = new File("./src/teste/teste4.txt");
        try {
            FileWriter fw = new FileWriter(arq);
            PrintWriter pt = new PrintWriter(fw);
            for (int i = 0; i < 10; i++) {
                pt.println("Linha: " + (i + 1));
            }
            pt.close();
            fw.close();
            System.out.println("Deu certo a gravacao!");
        } catch (Exception e) {
            System.out.println("Deu erro!");
        }

        // LEITURA

        try {
            FileReader fr = new FileReader(arq);
            BufferedReader br = new BufferedReader(fr);

            String linha = br.readLine();
            String conteudo = "";
            while (linha != null) {
                conteudo = conteudo + linha + "\n";
                linha = br.readLine();
            }
            
            fr.close();
            br.close();
            System.out.println("Conteudo lido: ");
            System.out.println("" + conteudo);
        } catch (Exception e) {
            System.out.println("Deu merda!");
        }
        
    }
}
