#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../include/ArvoreB.h"

int main() {
    Node *raiz = NULL;
    Node *vend = NULL;
    int escolha, valorItem;
    int count = 0, infernal = 0, angelical = 0, infernalMax = 0, angelicalMax = 0, benca = 0;
    float aposta, Carteira = 1000, CarteiraAux = 1000;

    int valoresVend[] = {5000, 2500, 1500, 1250, 1000, 975, 800, 625, 550, 375, 200, 105, 50};
    int n = 13;

    srand(time(NULL));

    do {
        printf("\n--- Gerenciador de acoes ---\n");
        printf("1. Reiniciar Jogo\n");
        printf("2. Roletar\n");
        printf("3. Inventarios\n");
        printf("4. Comprar um item\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        fflush(stdin);

        switch (escolha) {
            case 1:
                Carteira = 1000;
                CarteiraAux = 1000;
                benca = 0;
                vend = NULL;
                for (int i = 0; i < n; i++) {
                    vend = inserirNo(vend, valoresVend[i]);
                }
                raiz = NULL;
                printf("\n --- Jogo reiniciado! Saldo do jogador eh de: R$ %.2f e inventario do vendedor e jogador restaurados! ---\n", Carteira);
                break;
            case 2:
                if (Carteira <= 0) {
                    printf("\n ---== JOGADOR FALIU! A mafia cuidara de voce em alguns dias, fique no aguardo! ==--- \n\n :) veja suas estatisticas ate la!\n\n");
                        printf("\n --- Inventario final do Vendedor: \n\n");
                        imprime_inventario(vend, 0, benca);
                        printf("\n --- Inventario final do Jogador: \n\n");
                        imprime_inventario(raiz, 0, benca);
                        printf("\nSaldo final: %.2f\n", Carteira);
                        printf("Nao eh muita coisa :/\n");
                        printf("\nDivida de R$ %.2f\n", 1000 - Carteira);
                        printf("Mas tem juros ne\n");
                        printf("\nDivida final de R$ %.2f :)\n", (1000 - Carteira) * 50);
                        printf("Espero REALMENTE que voce nao fume nem beba muito.\n");
                    escolha = 5;
                    break;
                }
                printf("\nQuanto quer apostar nessa rodada? ;/\n");
                scanf("%f", &aposta);
                fflush(stdin);
                while(aposta > Carteira) {
                    printf("\nNao tem graca nao, o maximo que tu pode aposta eh %.2f", Carteira);
                    printf("\nQuanto quer apostar?\n");
                    scanf("%f", &aposta);
                    fflush(stdin);
                }
                count += 1;
                printf("\nRodada %d", count);
                printf("\nCom R$ %.2f na carteira, apostando R$ %.2f: \n", Carteira, aposta);
                Carteira = roda_roleta(Carteira, aposta);
                printf("\nSaldo: R$ %.2f\n", Carteira);
                if (count == 5) {
                    printf("\nVoce nota o vendedor ficando impaciente...\n");
                }
                if (count == 10) {
                    printf("\n--- Ta demorando DEMAIS!! Vou apimentar esse JOGO! vamos b-r-i-n-c-a-r...\n");
                    printf("\n--- Terminei de adicionar a mecanica 'Infernal' ao jogo\n--- Aposte a vontade agora eu insisto!\n");
                    printf("\n--- System: MODO INFERNAL habilitado, toda rodada par tera aumento de precos permanentes! ...a nao ser que...\n");
                }
                if (count > 9) {
                    if(fabs((Carteira - CarteiraAux) - (aposta * 7)) < TOLERANCIA) {
                        printf("\nTaxadd enlouqueceu e voce venceu, o jackpot ne, SONEGACAO DE IMPOSTO a caminho!\n");
                        angelical = geraValorNegativo();
                        angelicalMax += angelical;
                        benca = infernalMax + angelicalMax;
                        printf("\nVoce notou que TODOS os itens da loja estao custando MENOS: R$ %d\n", angelical * (-1));
                        if (angelical == 0) {
                            printf("\n--- Nem uma bencao abaixou meus precos HAHA\n    Que azar Womp Womp\n");
                        }
                        if (angelical == -25) {
                            printf("\n Se diminuisse umas 5 vezes isso ai pelo menos...\n");
                        }
                        vend = atualizaArvore(vend, angelical);
                    } else {
                        if (count % 2 == 0) {
                            printf("\nLula se elegeu e voce perdeu, TAXACAO a caminho!\n");
                            infernal = geraValor();
                            infernalMax += infernal;
                            benca = infernalMax + angelicalMax;
                            if(infernal == 0) {
                                printf("\nDroga.. pelo menos nao diminuiu\n");
                            }
                            if(infernal == 2000) {
                                printf("\nIt's Over! HAHAHA ;/\n");
                            }
                            printf("\nVoce notou que TODOS os itens da loja estao custando MAIS: R$ %d\n", infernal);
                            vend = atualizaArvore(vend, infernal);
                        }
                    }
                }
                CarteiraAux = Carteira;
                if (Carteira <= 0) {
                    printf("\n ---== JOGADOR FALIU! A mafia cuidara de voce em alguns dias, fique no aguardo! ==--- \n\n :) veja suas estatisticas ate la!\n\n");
                    printf("\n --- Inventario final do Vendedor: \n\n");
                    imprime_inventario(vend, 0, benca);
                    printf("\n --- Inventario final do Jogador: \n\n");
                    imprime_inventario(raiz, 0, benca);
                    printf("\nSaldo final: %.2f\n", Carteira);
                    printf("Nao eh muita coisa :/\n");
                    printf("\nDivida de R$ %.2f\n", 1000 - Carteira);
                    printf("Mas tem juros ne\n");
                    printf("\nDivida final de R$ %.2f :)\n", (1000 - Carteira) * 50);
                    printf("Espero REALMENTE que voce nao fume nem beba muito.\n");
                    escolha = 5;
                    break;
                }
                break;
            case 3:
                printf("\n --- Inventario do Vendedor: \n\n");
                imprime_inventario(vend, 0, benca);
                printf("\n --- Inventario do Jogador: \n\n");
                imprime_inventario(raiz, 0, benca);
                break;
            case 4:
                printf("\n --- Inventario do Vendedor: \n\n");
                imprime_inventario(vend, 0, benca);
                printf("\nDigite o valor do item que quer comprar e o vendedor sabera o que lhe entregar, se voce puder pagar, claro!\n");
                scanf("%d", &valorItem);
                if (buscaValor(vend, valorItem) == 0) {
                    printf("\nFicarei devendo um item desse valor, volte outra hora e eu talvez o tenha!\n");
                    break;
                }
                fflush(stdin);
                if(Carteira >= valorItem) {
                    vend = excluirNo(vend, valorItem);
                    raiz = inserirNo(raiz, valorItem);
                    Carteira = Carteira - valorItem;
                    printf("\nItem '%s' de valor: R$ %d foi comprado pelo jogador e retirado da loja do vendedor, parabens!\n", getName(valorItem - benca), valorItem);
                    if(vend == NULL) {
                        printf("\n\n---== JOGADOR GANHOU! :() ==---\n\n");
                        printf(" --- Inventario do Jogador: ---\n\n");
                        imprime_inventario(raiz, 0, benca);
                        printf("\nSaldo restante ainda: R$ %.2f\n", Carteira);
                        printf("\nPARABENS!\n\n");
                        escolha = 5;
                        break;
                    }
                    printf("\nSaldo: R$ %.2f\n", Carteira);
                } else {
                    printf("\nVoce esta pobre demais para um item assim, se quiser meu %s, consiga mais dinheiro antes de voltar aqui!\n", getName(valorItem - benca));
                }
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (escolha != 5);

    return 0;
}
