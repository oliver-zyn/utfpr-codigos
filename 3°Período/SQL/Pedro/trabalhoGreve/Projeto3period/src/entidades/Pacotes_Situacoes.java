/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entidades;

import java.util.Date;

public class Pacotes_Situacoes {
    private int pacote_situacoes_id;
    private int pacote_id;
    private int situacao_anterior_id;
    private int situacao_atual_id;
    private Date data_alteracao;

    public Pacotes_Situacoes() {
    }

    public Pacotes_Situacoes(int pacote_id, int situacao_anterior_id, int situacao_atual_id, Date data_alteracao) {
        this.pacote_id = pacote_id;
        this.situacao_anterior_id = situacao_anterior_id;
        this.situacao_atual_id = situacao_atual_id;
        this.data_alteracao = data_alteracao;
    }

    public int getPacote_situacoes_id() {
        return pacote_situacoes_id;
    }
    
    public int getPacote_id() {
        return pacote_id;
    }

    public int getSituacao_anterior_id() {
        return situacao_anterior_id;
    }

    public int getSituacao_atual_id() {
        return situacao_atual_id;
    }

    public Date getData_alteracao() {
        return data_alteracao;
    }

    public void setPacote_situacoes_id(int pacote_situacoes_id) {
        this.pacote_situacoes_id = pacote_situacoes_id;
    }

    public void setPacote_id(int pacote_id) {
        this.pacote_id = pacote_id;
    }

    public void setSituacao_anterior_id(int situacao_anterior_id) {
        this.situacao_anterior_id = situacao_anterior_id;
    }

    public void setSituacao_atual_id(int situacao_atual_id) {
        this.situacao_atual_id = situacao_atual_id;
    }

    public void setData_alteracao(Date data_alteracao) {
        this.data_alteracao = data_alteracao;
    }

    @Override
    public String toString() {
        return "Pacotes_Situacoes{" + "pacote_situacoes_id=" + pacote_situacoes_id + ", pacote_id=" + pacote_id + ", situacao_anterior_id=" + situacao_anterior_id + ", situacao_atual_id=" + situacao_atual_id + ", data_alteracao=" + data_alteracao + '}';
    }
    
}
