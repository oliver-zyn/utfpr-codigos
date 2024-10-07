package br.edu.utfpr.classes;

import br.edu.utfpr.enums.Status;
import br.edu.utfpr.enums.TipoTerreno;
import br.edu.utfpr.interfaces.Comissao;

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

  public double getPrecoTotal() {
    double taxaExtra, precoTotal;
    
    precoTotal = this.getPrecoArea() * this.getArea();

    if (this.tipo == TipoTerreno.COM_MURO) {
      taxaExtra = (this.getPrecoArea() * this.getArea()) * 0.05;
      precoTotal += taxaExtra;
    }

    return precoTotal;
  }

  public double calcularComissao() {
    return (this.getPrecoTotal() * TAXA);
  }

  @Override
  public String toString() {
    return "{" +
      " tipo='" + getTipo() + "'" +
      ", area='" + getArea() + "'" +
      ", precoArea='" + getPrecoArea() + "'" +
      ", status='" + getStatus() + "'" +
      ", precoTotal='" + getPrecoTotal() + "'" +
      ", comissao='" + calcularComissao() + "'" +
      "}";
  }
  
}
