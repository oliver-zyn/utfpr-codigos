/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entidades;

public class Situacoes {
    private int situacoes_id;
    private String descricao;

    public Situacoes() {
    }

    public Situacoes(String descricao) {
        this.descricao = descricao;
    }

    public int getSituacoes_id() {
        return situacoes_id;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setSituacoes_id(int situacoes_id) {
        this.situacoes_id = situacoes_id;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    @Override
    public String toString() {
        return "Situacoes{" + "situacoes_id=" + situacoes_id + ", descricao=" + descricao + '}';
    }
    
}
