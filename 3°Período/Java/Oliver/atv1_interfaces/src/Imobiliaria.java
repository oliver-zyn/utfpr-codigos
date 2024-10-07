import br.edu.utfpr.classes.Apto;
import br.edu.utfpr.classes.GerenciaComissao;
import br.edu.utfpr.classes.Loja;
import br.edu.utfpr.classes.Terreno;
import br.edu.utfpr.enums.Status;
import br.edu.utfpr.enums.TipoTerreno;

public class Imobiliaria {
    public static void main(String[] args) throws Exception {
        GerenciaComissao gerenciaComissao = new GerenciaComissao();
        Apto apto1 = new Apto(4, Status.DISPONIVEL, 40, 100);
        Loja loja1 = new Loja(0.10, Status.DISPONIVEL, 90, 50);
        Terreno terreno1 = new Terreno(TipoTerreno.COM_MURO, 120, 30, Status.DISPONIVEL);

        apto1.setStatus(Status.VENDIDO);
        gerenciaComissao.adicionaComissao(apto1);

        loja1.setStatus(Status.VENDIDO);
        gerenciaComissao.adicionaComissao(loja1);

        terreno1.setStatus(Status.VENDIDO);
        gerenciaComissao.adicionaComissao(terreno1);

        System.out.println("\nVenda realizada! APTO1: \n- Status atual: " + apto1.getStatus() + "\n- Preco: " + apto1.getPrecoTotal() + "\n- Comissao: " + apto1.calcularComissao());
        System.out.println("\nVenda realizada! LOJA1: \n- Status atual: " + loja1.getStatus() + "\n- Preco: " + loja1.getPrecoTotal() + "\n- Comissao: " + loja1.calcularComissao());
        System.out.println("\nVenda realizada! TERRENO1: \n- Status atual: " + terreno1.getStatus() + "\n- Preco: " + terreno1.getPrecoTotal() + "\n- Comissao: " + terreno1.calcularComissao());
        System.out.println("\nTotal de vendas: " + (apto1.getPrecoTotal() + loja1.getPrecoTotal() + terreno1.getPrecoTotal()) + "\nTotal de comissoes: " + gerenciaComissao.getTotalComissao());
    }
}
