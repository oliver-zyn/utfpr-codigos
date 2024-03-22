import java.io.File;
import java.util.Scanner;

import br.utfpr.aula2.Dao2103;

public class UsaDao {
    public static void main(String[] args) throws Exception {
        Dao2103 dao = new Dao2103();
        File arq = new File("./src/teste/teste2103.dat");
        String nome;
        int idade;
        double salario;

        Scanner ler = new Scanner(System.in);
        System.out.println("Nome: ");
        nome = ler.nextLine();
        
        System.out.println("Idade: ");
        idade = ler.nextInt();

        System.out.println("Salario: ");
        salario = ler.nextDouble();

        dao.gravarArquivo(arq, nome, idade, salario);
        System.out.println("Ler dados do arquivo");
         
        String aux = dao.lerArquivo(arq);

        System.out.println(aux);

        ler.close();
    }
}
