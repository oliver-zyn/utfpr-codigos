import br.edu.utfpr.Apto;
import br.edu.utfpr.GerenciaComissao;
import br.edu.utfpr.Loja;
import br.edu.utfpr.Terreno;
import br.edu.utfpr.enums.Status;
import br.edu.utfpr.enums.TipoTerreno;

public class Imobiliaria {
    public static void main(String[] args) throws Exception {
        Apto apt1 = new Apto(Status.Disponivel, 1200, 30, 3);
        Loja loja1 = new Loja(Status.Disponivel, 300, 40, 0.2);
        Terreno terreno1 = new Terreno(TipoTerreno.Com_Muro, 3000, 15, Status.Disponivel);
        
        GerenciaComissao gerencia = new GerenciaComissao();

        terreno1.setStatus(Status.Vendido);
        gerencia.adicionaComissao(terreno1);

        System.err.println("Terreno: \n" + "\nTotal de vendas: " + terreno1.getPrecoTotal() + "\nTotal de comissao: " + terreno1.calcularComissao() + "\n");

        loja1.setStatus(Status.Vendido);
        gerencia.adicionaComissao(loja1);

        System.err.println("Loja: \n" + "\nTotal de vendas: " + loja1.getPrecoTotal() + "\nTotal de comissao: " + loja1.calcularComissao() + "\n");

        apt1.setStatus(Status.Vendido);
        gerencia.adicionaComissao(apt1);

        System.err.println("Apt: \n" + "\nTotal de vendas: " + apt1.getPrecoTotal() + "\nTotal de comissao: " + apt1.calcularComissao() + "\n");

        System.err.println("Gerencia total de comissoes: " + gerencia.getTotalComissao() + "\nTotal de vendas: " + (loja1.getPrecoTotal() + terreno1.getPrecoTotal() + apt1.getPrecoTotal()) );
    }
}
