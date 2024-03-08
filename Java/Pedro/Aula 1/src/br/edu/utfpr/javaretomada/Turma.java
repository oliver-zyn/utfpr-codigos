package br.edu.utfpr.javaretomada;

import java.util.ArrayList;

public class Turma {
    private String codigo;
    private int ano;
    private int semestre;
    private ArrayList<Academico> listaAcademico;
    private Curso cursoOferta;

    public Turma() {
    }

    public Turma(String codigo, int ano, int semestre, ArrayList<Academico> listaAcademico, Curso cursoOferta) {
        this.codigo = codigo;
        this.ano = ano;
        this.semestre = semestre;
        this.listaAcademico = listaAcademico;
        this.cursoOferta = cursoOferta;
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

    public ArrayList<Academico> getListaAcademico() {
        return this.listaAcademico;
    }

    public void setListaAcademico(ArrayList<Academico> listaAcademico) {
        this.listaAcademico = listaAcademico;
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
            ", listaAcademico='" + getListaAcademico() + "'" +
            ", cursoOferta='" + getCursoOferta() + "'" +
            "}";
    }

}
