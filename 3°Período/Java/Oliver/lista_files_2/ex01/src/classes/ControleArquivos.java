package classes;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class ControleArquivos {
  public void gravarArquivoClientes(File f, Cliente cliente) {
    try {
      OutputStream o = new FileOutputStream(f, true);

      DataOutputStream d = new DataOutputStream(o);
      d.writeInt(cliente.getCodigoCliente());
      d.writeUTF(cliente.getNome());
      
      d.close();
      o.close();
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }    
  }

  public boolean clienteExisteArquivo(File f, int codigoCliente) {
    boolean encontrouCliente = false;
    
    try {
      InputStream i = new FileInputStream(f);
      DataInputStream d = new DataInputStream(i);
      int codigoClienteArq;
      
      while (d.available() > 0) {
        codigoClienteArq = d.readInt();

        if (codigoClienteArq == codigoCliente) {
          encontrouCliente = true;
          break;
        }

        d.readUTF();
      }

      d.close();
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }
    
    return encontrouCliente;
  }

  public List<Integer> retCodigosClientes(File f) {
    List<Integer> codigosClientes = new ArrayList<>();
    
    try {
      InputStream i = new FileInputStream(f);
      DataInputStream d = new DataInputStream(i);
      int codigoClienteArq;
      
      while (d.available() > 0) {
        codigoClienteArq = d.readInt();

        codigosClientes.add(codigoClienteArq);

        d.readUTF();
      }

      d.close();
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }
    
    return codigosClientes;
  }

  public void gravarArquivoOperacoes(File f, int codigoCliente, String nomeVeiculo, String tipoOperacao, double valorOperacao) {
    try {
      OutputStream o = new FileOutputStream(f, true);

      DataOutputStream d = new DataOutputStream(o);
      d.writeInt(codigoCliente);
      d.writeUTF(nomeVeiculo);
      d.writeUTF(tipoOperacao);
      d.writeDouble(valorOperacao);
      
      d.close();
      o.close();
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }    
  }

  public String lerArquivoOperacoes(File f) {
    StringBuilder sb = new StringBuilder();
    
    try {
      InputStream i = new FileInputStream(f);
      DataInputStream d = new DataInputStream(i);
      String nomeVeiculo, tipoOperacao;
      int codigoCliente;
      double valorOperacao;
      
      while (d.available() > 0) {
        codigoCliente = d.readInt();
        nomeVeiculo = d.readUTF();
        tipoOperacao = d.readUTF();
        valorOperacao = d.readDouble();

        sb.append("\nCliente: " + codigoCliente)
          .append(tipoOperacao.equals("C") ? " | Compra" : " | Venda")
          .append(" | " + nomeVeiculo)
          .append(" | " + valorOperacao)
          .append("\n");
      }

      d.close();
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }
    
    return sb.toString();
  }

  public String lerArquivoOperacoesCliente(File f, int codigoCliente) {
    StringBuilder sb = new StringBuilder();
    
    try {
      InputStream i = new FileInputStream(f);
      DataInputStream d = new DataInputStream(i);
      String nomeVeiculo, tipoOperacao;
      int codigoClienteArq;
      double valorOperacao;
      boolean encontrouOperacao = false;

      sb.append("\nOperacoes do cliente: " + codigoCliente);
      
      while (d.available() > 0) {
        codigoClienteArq = d.readInt();

        if (codigoClienteArq != codigoCliente) {
          continue;
        }

        nomeVeiculo = d.readUTF();
        tipoOperacao = d.readUTF();
        valorOperacao = d.readDouble();

        sb.append(tipoOperacao.equals("C") ? "\nCompra" : "\nVenda")
          .append(" | " + nomeVeiculo)
          .append(" | " + valorOperacao)
          .append("\n");

        encontrouOperacao = true;
      }

      if (!encontrouOperacao) {
        sb.append("\nNenhuma operacao encontrada...");
      }

      d.close();
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }
    
    return sb.toString();
  }

  public int totalOperacoesCliente(File f, int codigoCliente, String tipoOperacao) {    
    int totalOperacao = 0;
    
    try {
      InputStream i = new FileInputStream(f);
      DataInputStream d = new DataInputStream(i);
      String tipoOperacaoArq;
      int codigoClienteArq;
      
      while (d.available() > 0) {
        codigoClienteArq = d.readInt();

        if (codigoClienteArq != codigoCliente) {
          continue;
        }

        tipoOperacaoArq = d.readUTF();

        if (tipoOperacaoArq.equals(tipoOperacao)) {
          totalOperacao++;
        }
      }

      d.close();
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }

    return totalOperacao;
  }

  public void gravaArqTexto(File arq, String conteudo) {
    try {
      FileWriter fw = new FileWriter(arq);
      PrintWriter pt = new PrintWriter(fw);

      pt.println(conteudo);

      fw.close();
      pt.close();
    } catch (Exception e) {
      System.out.println("Ocorreu um erro: " + e.getMessage());
    }
  }
}