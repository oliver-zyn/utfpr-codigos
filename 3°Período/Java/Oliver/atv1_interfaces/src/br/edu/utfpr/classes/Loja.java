package br.edu.utfpr.classes;

import br.edu.utfpr.enums.Status;

public class Loja extends Construcao {
  private double percAjustePonto;

  public Loja() {
  }

  public Loja(double percAjustePonto, Status status, double area, double precoArea) {
    super(status, area, precoArea);
    this.percAjustePonto = percAjustePonto;
  }

  public double getPercAjustePonto() {
    return this.percAjustePonto;
  }

  public void setPercAjustePonto(double percAjustePonto) {
    this.percAjustePonto = percAjustePonto;
  }

  public double getPrecoTotal() {
    double precoTotal = (this.getPrecoArea() * this.getArea()) * this.getPercAjustePonto();

    return precoTotal;
  }

  public double calcularComissao() {
    return (this.getPrecoTotal() * TAXA);
  }

  @Override
  public String toString() {
    return "{" +
      " percAjustePonto='" + getPercAjustePonto() + "'" +
      ", status='" + getStatus() + "'" +
      ", area='" + getArea() + "'" +
      ", precoArea='" + getPrecoArea() + "'" +
      ", precoTotal='" + getPrecoTotal() + "'" +
      ", comissao='" + calcularComissao() + "'" +
      "}";
  }
  
}
