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
public class CheckIn {
    private int id;
    private Ingresso ingresso;
    private Date dataCheckIn;

    public CheckIn() {
    }

    public CheckIn(int id, Ingresso ingresso, Date dataCheckIn) {
        this.id = id;
        this.ingresso = ingresso;
        this.dataCheckIn = dataCheckIn;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Ingresso getIngresso() {
        return ingresso;
    }

    public void setIngresso(Ingresso ingresso) {
        this.ingresso = ingresso;
    }

    public Date getDataCheckIn() {
        return dataCheckIn;
    }

    public void setDataCheckIn(Date dataCheckIn) {
        this.dataCheckIn = dataCheckIn;
    }

    @Override
    public String toString() {
        return "CheckIn{" + "id=" + id + ", ingresso=" + ingresso + ", dataCheckIn=" + dataCheckIn + '}';
    }
    
}
