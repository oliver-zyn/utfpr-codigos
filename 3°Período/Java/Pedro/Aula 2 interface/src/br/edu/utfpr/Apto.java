package br.edu.utfpr;

import br.edu.utfpr.enums.Status;

public class Apto extends Construcao {
    private int numQuartos;

    public Apto() {
    }

    public Apto(Status status, double area, double precoArea, int numQuartos) {
        super(status, area, precoArea);
        this.numQuartos = numQuartos;
    }

    public int getNumQuartos() {
        return this.numQuartos;
    }

    public void setNumQuartos(int numQuartos) {
        this.numQuartos = numQuartos;
    }

    @Override
    public double getPrecoTotal() {
        return (this.getArea() * this.getPrecoArea()) * this.getNumQuartos();
    }

    @Override
    public double calcularComissao() {
        return getPrecoTotal() * TAXA;
    }

    @Override
    public String toString() {
        return "{" +
            " numQuartos='" + getNumQuartos() + "'" +
            "}";
    }
}
