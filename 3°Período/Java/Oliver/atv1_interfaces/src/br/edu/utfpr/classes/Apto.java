package br.edu.utfpr.classes;

import br.edu.utfpr.enums.Status;

public class Apto extends Construcao {
  private int numQuartos;

  public Apto() {
  }

  public Apto(int numQuartos, Status status, double area, double precoArea) {
    super(status, area, precoArea);
    this.numQuartos = numQuartos;
  }

  public int getNumQuartos() {
    return this.numQuartos;
  }

  public double getPrecoTotal() {
    double precoTotal = (this.getPrecoArea() * this.getArea()) * this.getNumQuartos();

    return precoTotal;
  }

  public double calcularComissao() {
    return (this.getPrecoTotal() * TAXA);
  }
 
  @Override
  public String toString() {
    return "{" +
      " numQuartos='" + getNumQuartos() + "'" +
      ", status='" + getStatus() + "'" +
      ", area='" + getArea() + "'" +
      ", precoArea='" + getPrecoArea() + "'" +
      ", precoTotal='" + getPrecoTotal() + "'" +
      ", comissao='" + calcularComissao() + "'" +
      "}";
  }

}
