/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entidades;

public class Entregadores {
    private int entregador_id;
    private int usuario_id;
    private String CPF;
    private String nome;
    private String telefone;

    public Entregadores() {
    }

    public Entregadores(int usuario_id, String CPF, String nome, String telefone) {
        this.usuario_id = usuario_id;
        this.CPF = CPF;
        this.nome = nome;
        this.telefone = telefone;
    }

    public int getEntregador_id() {
        return entregador_id;
    }

    public int getUsuario_id() {
        return usuario_id;
    }

    public String getCPF() {
        return CPF;
    }

    public String getNome() {
        return nome;
    }

    public String getTelefone() {
        return telefone;
    }

    public void setEntregador_id(int entregador_id) {
        this.entregador_id = entregador_id;
    }

    public void setUsuario_id(int usuario_id) {
        this.usuario_id = usuario_id;
    }

    public void setCPF(String CPF) {
        this.CPF = CPF;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    @Override
    public String toString() {
        return "Entregadores{" + "entregador_id=" + entregador_id + ", usuario_id=" + usuario_id + ", CPF=" + CPF + ", nome=" + nome + ", telefone=" + telefone + '}';
    }
    
}
