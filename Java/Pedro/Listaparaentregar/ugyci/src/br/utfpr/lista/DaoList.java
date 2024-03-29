package br.utfpr.lista;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;

public class DaoList {

    public static float notaMedia(int nota1, int nota2) {
        return (nota1 + nota2) / 2.0f;
    }

    public void gravarArquivo(File f, int cod, String nome, int nota1, int nota2) {
        try {
                OutputStream o = new FileOutputStream(f, true);
                DataOutputStream d = new DataOutputStream(o);

                d.writeInt(cod);
                d.writeUTF(nome);
                d.writeInt(nota1);
                d.writeInt(nota2);
                d.writeFloat(notaMedia(nota1, nota2));

                if(notaMedia(nota1, nota2) > 7) {
                    d.writeUTF("Aprovado");
                } else {
                    d.writeUTF("Reprovado");
                }
                
                d.close();
                o.close();
            } catch (Exception e) {
                System.out.println("Erro");
            }
        }
    
    public String lerArquivo(File f) {
        StringBuilder sb = new StringBuilder();
        
        try {
            InputStream i = new FileInputStream(f);
            DataInputStream d = new DataInputStream(i);
            String nome, aprovacao;
            int cod, nota1, nota2;
            float notaMedia;
            
            while (d.available() > 0) {
            cod = d.readInt();
            nome = d.readUTF();
            nota1 = d.readInt();
            nota2 = d.readInt();
            notaMedia = d.readFloat();
            aprovacao = d.readUTF();
    
            sb.append("\nCódigo: " + cod)
                .append("\nNome: " + nome)
                .append("\nNota 1: " + nota1)
                .append("\nNota 2: " + nota2)
                .append(String.format("\nNota Média: %.1f", notaMedia))
                .append("\nAprovação: " + aprovacao)
                .append("\n");
            }
    
            d.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        
        return sb.toString();
        }
    }