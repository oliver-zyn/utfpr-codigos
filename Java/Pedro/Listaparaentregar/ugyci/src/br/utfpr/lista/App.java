package br.utfpr.lista;

import java.io.File;
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        DaoList dl = new DaoList();
        File f = new File("./src/teste/testeList.dat");
        String nome;
        int cod, nota1, nota2;

        Scanner ler = new Scanner(System.in);
        System.out.println("Código: ");
        cod = ler.nextInt();
        
        System.out.println("Nome: ");
        ler.nextLine();
        nome = ler.nextLine();

        System.out.println("Nota 1: ");
        nota1 = ler.nextInt();

        System.out.println("Nota 2: ");
        nota2 = ler.nextInt();
        ler.close();

        dl.gravarArquivo(f, cod, nome, nota1, nota2);

        String aux = dl.lerArquivo(f);

        System.out.println(aux);
    }
}
