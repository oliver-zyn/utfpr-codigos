package br.edu.utfpr.javaretomada;

import java.util.ArrayList;

public class Turma {
  private String codigo;
  private int ano;
  private int semestre;
  private ArrayList<Academico> listaAcademicos;
  private Curso cursoOferta;

  public Turma(String codigo, int ano, int semestre, ArrayList<Academico> listaAcademicos, Curso cursoOferta) {
    this.codigo = codigo;
    this.ano = ano;
    this.semestre = semestre;
    this.listaAcademicos = listaAcademicos;
    this.cursoOferta = cursoOferta;
  }

  public Turma() {
  }

  public String getCodigo() {
    return this.codigo;
  }

  public void setCodigo(String codigo) {
    this.codigo = codigo;
  }

  public int getAno() {
    return this.ano;
  }

  public void setAno(int ano) {
    this.ano = ano;
  }

  public int getSemestre() {
    return this.semestre;
  }

  public void setSemestre(int semestre) {
    this.semestre = semestre;
  }

  public ArrayList<Academico> getListaAcademicos() {
    return this.listaAcademicos;
  }

  public void setListaAcademicos(ArrayList<Academico> listaAcademicos) {
    this.listaAcademicos = listaAcademicos;
  }

  public Curso getCursoOferta() {
    return this.cursoOferta;
  }

  public void setCursoOferta(Curso cursoOferta) {
    this.cursoOferta = cursoOferta;
  }

  @Override
  public String toString() {
    return "{" +
      " codigo='" + getCodigo() + "'" +
      ", ano='" + getAno() + "'" +
      ", semestre='" + getSemestre() + "'" +
      ", listaAcademicos='" + getListaAcademicos() + "'" +
      ", cursoOferta='" + getCursoOferta() + "'" +
      "}";
  }
}
