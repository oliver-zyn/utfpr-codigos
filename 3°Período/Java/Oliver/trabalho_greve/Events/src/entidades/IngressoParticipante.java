/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entidades;

/**
 *
 * @author geri_
 */
public class IngressoParticipante {
    private int id;
    private Participante participante;
    private Ingresso ingresso;

    public IngressoParticipante() {
    }

    public IngressoParticipante(int id, Participante participante, Ingresso ingresso) {
        this.id = id;
        this.participante = participante;
        this.ingresso = ingresso;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Participante getParticipante() {
        return participante;
    }

    public void setParticipante(Participante participante) {
        this.participante = participante;
    }

    public Ingresso getIngresso() {
        return ingresso;
    }

    public void setIngresso(Ingresso ingresso) {
        this.ingresso = ingresso;
    }

    @Override
    public String toString() {
        return "IngressoParticipante{" + "id=" + id + ", participante=" + participante + ", ingresso=" + ingresso + '}';
    }
    
}
