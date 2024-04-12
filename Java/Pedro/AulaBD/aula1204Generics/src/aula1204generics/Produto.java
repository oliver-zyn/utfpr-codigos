/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package aula1204generics;

/**
 *
 * @author geri_
 * @param <T>
 * @param <U>
 */
public class Produto<T, U> {
    private T codigo;
    private String nome;
    private U valor;

    public Produto() {
    }

    public Produto(T codigo, String nome, U valor) {
        this.codigo = codigo;
        this.nome = nome;
        this.valor = valor;
    }

    public T getCodigo() {
        return codigo;
    }

    public void setCodigo(T codigo) {
        this.codigo = codigo;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public U getValor() {
        return valor;
    }

    public void setValor(U valor) {
        this.valor = valor;
    }

    @Override
    public String toString() {
        return "Produto{" + "codigo=" + codigo + ", nome=" + nome + ", valor=" + valor + '}';
    }
    
    
    
}
