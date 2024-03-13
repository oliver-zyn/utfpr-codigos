package br.edu.utfpr;

import br.edu.utfpr.enums.Status;
import br.edu.utfpr.enums.TipoTerreno;

public class Terreno implements Comissao {
    private TipoTerreno tipo;
    private double area;
    private double precoArea;
    private Status status;

    public Terreno() {
    }

    public Terreno(TipoTerreno tipo, double area, double precoArea, Status status) {
        this.tipo = tipo;
        this.area = area;
        this.precoArea = precoArea;
        this.status = status;
    }

    public TipoTerreno getTipo() {
        return this.tipo;
    }

    public void setTipo(TipoTerreno tipo) {
        this.tipo = tipo;
    }

    public double getArea() {
        return this.area;
    }

    public void setArea(double area) {
        this.area = area;
    }

    public double getPrecoArea() {
        return this.precoArea;
    }

    public void setPrecoArea(double precoArea) {
        this.precoArea = precoArea;
    }

    public Status getStatus() {
        return this.status;
    }

    public void setStatus(Status status) {
        this.status = status;
    }

    @Override
    public String toString() {
        return "{" +
            " tipo='" + getTipo() + "'" +
            ", area='" + getArea() + "'" +
            ", precoArea='" + getPrecoArea() + "'" +
            ", status='" + getStatus() + "'" +
            "}";
    }

    public double getPrecoTotal() {
        if(getTipo() == TipoTerreno.Com_Muro) {
            return (this.getArea() * this.getPrecoArea()) * 1.3;
        } else {
            return (this.getArea() * this.getPrecoArea());
        }
    }

    @Override
    public double calcularComissao() {
        return getPrecoTotal() * TAXA;
    }

}
