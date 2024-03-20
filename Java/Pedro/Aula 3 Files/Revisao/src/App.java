
import java.io.File;
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner ler = new Scanner(System.in);

        System.err.println("Informe o nome (Arq ou diretorio): ");
        String nome = ler.nextLine();
        ler.close();

        File objt = new File(nome);

        if(objt.exists()) {
            if(objt.isFile()) {
                System.err.println("Arquivo: " + objt.getName() + " Tamanho: " + objt.length());
            } else {
                System.err.println("Conteúdo do diretório: ");
                String[] diret = objt.list();
                for (String string : diret) {
                    System.err.println(string);
                }
            }
        } else {
            System.err.println("Arquivo não existe!");
        }

        File cdir = new File("./src/teste");

        if(cdir.mkdir()) {
            System.out.println("Diretorio criado");
        } else {
            System.out.println("Nao funcionou");
        }
        File carq = new File(cdir, "teste3.txt");
        try {

            if(carq.createNewFile()) {
                System.out.println("Arquivo criado");
            } else {
                System.out.println("Nao funcionou");
            }
        } catch (Exception ex) {
            System.out.println("Deu problema no arquivo!");
        }

        
    }
}
