/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entidades;

/**
 *
 * @author geri_
 */
public class Ingresso {
    private int id;
    private double preco;
    private int quantidade;
    private String tipo;
    private Evento evento;

    public Ingresso() {
    }

    public Ingresso(int id, double preco, int quantidade, String tipo, Evento evento) {
        this.id = id;
        this.preco = preco;
        this.quantidade = quantidade;
        this.tipo = tipo;
        this.evento = evento;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public Evento getEvento() {
        return evento;
    }

    public void setEvento(Evento evento) {
        this.evento = evento;
    }

    @Override
    public String toString() {
        return "Ingresso{" + "id=" + id + ", preco=" + preco + ", quantidade=" + quantidade + ", tipo=" + tipo + ", evento=" + evento + '}';
    }
    
}
