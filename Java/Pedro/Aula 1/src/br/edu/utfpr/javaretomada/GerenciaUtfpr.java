package br.edu.utfpr.javaretomada;

import java.util.ArrayList;

public class GerenciaUtfpr {
    public static void main(String[] args) {
        Curso ads = new Curso("Tec em ADS", 1);
        Academico acad1 = new Academico();

        acad1.setCurso(ads);
        acad1.setIdade(19);
        acad1.setNome("Alerandro");
        acad1.setRa("1");
        acad1.setSalario(-4300);

        Turma t3p = new Turma();

        t3p.setAno(2024);
        t3p.setCodigo("123");
        t3p.setCursoOferta(ads);
        t3p.setSemestre(5);

        ArrayList<Academico> listaA = new ArrayList();

        listaA.add(acad1);
        t3p.setListaAcademico(listaA);

        System.out.println("Turma: " + t3p.toString());
        System.out.println("Curso: " + ads.toString());
        System.out.println("Academico: " + acad1.toString());
    }
}
