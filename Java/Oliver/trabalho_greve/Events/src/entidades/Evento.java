/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entidades;

import java.util.Date;

/**
 *
 * @author geri_
 */
public class Evento {
    private int id;
    private String titulo;
    private String descricao;
    private int maxParticipantes;
    private Date dataEvento;
    private Palestrante palestrante;
    private Local local;

    public Evento() {
    }

    public Evento(String titulo, String descricao, int maxParticipantes, Date dataEvento, Palestrante palestrante, Local local) {
        this.titulo = titulo;
        this.descricao = descricao;
        this.maxParticipantes = maxParticipantes;
        this.dataEvento = dataEvento;
        this.palestrante = palestrante;
        this.local = local;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public int getMaxParticipantes() {
        return maxParticipantes;
    }

    public void setMaxParticipantes(int maxParticipantes) {
        this.maxParticipantes = maxParticipantes;
    }

    public Date getDataEvento() {
        return dataEvento;
    }

    public void setDataEvento(Date dataEvento) {
        this.dataEvento = dataEvento;
    }

    public Palestrante getPalestrante() {
        return palestrante;
    }

    public void setPalestrante(Palestrante palestrante) {
        this.palestrante = palestrante;
    }

    public Local getLocal() {
        return local;
    }

    public void setLocal(Local local) {
        this.local = local;
    }

    @Override
    public String toString() {
        return "Evento{" + "id=" + id + ", titulo=" + titulo + ", descricao=" + descricao + ", maxParticipantes=" + maxParticipantes + ", dataEvento=" + dataEvento + ", palestrante=" + palestrante + ", local=" + local + '}';
    }

}
