import java.io.File;
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner ler = new Scanner(System.in);
        String nome;

        System.out.print("Informe o nome (arquivo ou diretorio): ");
        nome = ler.nextLine();
        ler.close();
        
        File objFile = new File(nome);

        if (objFile.exists()) {
            if (objFile.isFile()) {
                System.out.println("- Arquivo: " + objFile.getName() + " \n- Tamanho: " + objFile.length());
            } else {
                System.out.println("Conteudo diretorio: ");
                String[] diret = objFile.list();
                for (String d: diret) {
                    System.out.println("- " + d);
                }
            }
        } else {
            System.out.println("O arquivo/diretorio nao foi encontrado");
        }
        
        try {

            File cdir = new File("./src/arquivos");

            if (!cdir.mkdir()) {
                throw new Exception("Diretorio nao criado");
            }

            System.out.println("Diretorio criado");
    
            File carq = new File(cdir, "teste2.txt");

            if (!carq.createNewFile()) {
                throw new Exception("Arquivo nao criado");
            } 

            System.out.println("Arquivo criado");
            
        } catch (Exception e) {
            System.out.println(e.getMessage());    
        }

        
    }
}
