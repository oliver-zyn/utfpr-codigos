package br.edu.utfpr;

import br.edu.utfpr.enums.Status;

public class Loja extends Construcao {
    private double precoAjustePonto;

    public Loja() {
    }

    public Loja(Status status, double area, double precoArea, double precoAjustePonto) {
        super(status, area, precoArea);
        this.precoAjustePonto = precoAjustePonto;
    }

    public double getPrecoAjustePonto() {
        return this.precoAjustePonto;
    }

    public void setPrecoAjustePonto(double precoAjustePonto) {
        this.precoAjustePonto = precoAjustePonto;
    }
    
    @Override
    public double getPrecoTotal() {
        return this.getArea() * this.getPrecoArea() * this.getPrecoAjustePonto();
    }

    @Override
    public double calcularComissao() {
        return getPrecoTotal() * TAXA;
    }

    @Override
    public String toString() {
        return "{" +
            " precoAjustePonto='" + getPrecoAjustePonto() + "'" +
            "}";
    }

}
