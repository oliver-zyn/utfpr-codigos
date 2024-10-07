package br.utfpr.lista;

import java.io.File;
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        DaoList dl = new DaoList();
        File f = new File("./src/br/Alunos.dat");
        String nome;
        int cod, nota1, nota2;
        Scanner ler = new Scanner(System.in);

        try {
			for (int i = 1; i <= 3; i++) {
				System.out.println("\nALUNO " + i);
				System.out.println("=====================");

				System.out.print("Informe o código do aluno: ");
				cod = ler.nextInt();
				ler.nextLine();

				System.out.print("Informe o nome do aluno: ");
				nome = ler.nextLine();

				System.out.print("Informe a primeira nota do aluno: ");
				nota1 = ler.nextInt();
				ler.nextLine();

				System.out.print("Informe a segunda nota do aluno: ");
				nota2 = ler.nextInt();
				ler.nextLine();

				dl.gravarArquivo(f, cod, nome, nota1, nota2);
			}

			System.err.println("\nCONTEUDO DO ARQUIVO:");
			System.out.println(dl.lerArquivo(f));

		} catch (Exception e) {
			System.out.println("Ocorreu um erro: " + e.getMessage());
		} finally {
			ler.close();
    }
}
}
