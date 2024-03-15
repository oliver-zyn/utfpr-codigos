import java.util.ArrayList;

import br.edu.utfpr.javaretomada.Academico;
import br.edu.utfpr.javaretomada.Curso;
import br.edu.utfpr.javaretomada.Turma;

public class GerenciaUtfpr {
    public static void main(String[] args) throws Exception {
        Curso ads = new Curso("Tec em ADS", 1);

        Academico acad1 = new Academico();
        acad1.setCurso(ads);
        acad1.setNome("Oliver");
        acad1.setIdade(18);
        acad1.setRa("123");
        acad1.setSalario(1000);

        Turma t3p = new Turma();
        t3p.setAno(2024);
        t3p.setCodigo("321");
        t3p.setCursoOferta(ads);
        t3p.setSemestre(1);
        
        ArrayList<Academico> listaA = new ArrayList<>();
        listaA.add(acad1);

        t3p.setListaAcademicos(listaA);

        System.out.println("Turma: " + t3p.toString());
        System.out.println("Curso: " + ads.toString());
        System.out.println("Academico: " + acad1.toString());

    }
}
