package br.edu.utfpr.classes;

import br.edu.utfpr.interfaces.Comissao;

public class GerenciaComissao {
  private double totalComissao;
  
  public GerenciaComissao() {
  }

  public GerenciaComissao(double totalComissao) {
    this.totalComissao = totalComissao;
  }

  public double getTotalComissao() {
    return this.totalComissao;
  }

  public void setTotalComissao(double totalComissao) {
    this.totalComissao = totalComissao;
  }

  public void adicionaComissao(Comissao c) {
    setTotalComissao(this.getTotalComissao() + c.calcularComissao());
  }

  @Override
  public String toString() {
    return "{" +
      " totalComissao='" + getTotalComissao() + "'" +
      "}";
  }
  
}
