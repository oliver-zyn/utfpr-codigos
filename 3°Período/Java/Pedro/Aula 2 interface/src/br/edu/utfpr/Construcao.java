package br.edu.utfpr;

import br.edu.utfpr.enums.Status;

public abstract class Construcao implements Comissao {
    private Status status;
    private double area;
    private double precoArea;

    public Construcao() {
    }

    public Construcao(Status status, double area, double precoArea) {
        this.status = status;
        this.area = area;
        this.precoArea = precoArea;
    }

    public Status getStatus() {
        return this.status;
    }

    public void setStatus(Status status) {
        this.status = status;
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

    abstract public double getPrecoTotal();
}
