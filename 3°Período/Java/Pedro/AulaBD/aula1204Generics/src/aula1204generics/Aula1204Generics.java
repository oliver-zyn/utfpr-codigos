/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package aula1204generics;

/**
 *
 * @author geri_
 */
public class Aula1204Generics {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Produto p = new Produto(1, "produto 1",200);
        Produto p1 = new Produto("2","produto 2","200");
        System.out.println("Produto 1: "+p.toString());
        System.out.println("Produto 2: "+p1.toString());
    }
    
}
