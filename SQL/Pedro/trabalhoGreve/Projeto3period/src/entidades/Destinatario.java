/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entidades;

public class Destinatario {
    private int destinatario_id;
    private String nome;
    private String CPF;
    private String telefone;
    private String rua;
    private String bairro;
    private int numero;
    private String cep;

    public Destinatario() {
    }

    public Destinatario(String nome, String CPF, String telefone, String rua, String bairro, int numero, String cep) {
        this.nome = nome;
        this.CPF = CPF;
        this.telefone = telefone;
        this.rua = rua;
        this.bairro = bairro;
        this.numero = numero;
        this.cep = cep;
    }

    public int getDestinatario_id() {
        return destinatario_id;
    }

    public String getNome() {
        return nome;
    }

    public String getCPF() {
        return CPF;
    }

    public String getTelefone() {
        return telefone;
    }

    public String getRua() {
        return rua;
    }

    public String getBairro() {
        return bairro;
    }

    public int getNumero() {
        return numero;
    }

    public String getCep() {
        return cep;
    }

    public void setDestinatario_id(int destinatario_id) {
        this.destinatario_id = destinatario_id;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setCPF(String CPF) {
        this.CPF = CPF;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    public void setRua(String rua) {
        this.rua = rua;
    }

    public void setBairro(String bairro) {
        this.bairro = bairro;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public void setCep(String cep) {
        this.cep = cep;
    }

    @Override
    public String toString() {
        return "Destinatario{" + "destinatario_id=" + destinatario_id + ", nome=" + nome + ", CPF=" + CPF + ", telefone=" + telefone + ", rua=" + rua + ", bairro=" + bairro + ", numero=" + numero + ", cep=" + cep + '}';
    }
    
}
