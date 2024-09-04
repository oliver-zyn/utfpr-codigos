#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/ArvoreB.h"

int main() {
    Node *raiz = NULL;
    Node *vend = NULL;
    int escolha, valorItem, aposta;

    int valoresVend[] = {1250, 1000, 975, 800, 625, 550, 375, 200, 105, 50};
    int n = sizeof(valoresVend) / sizeof(valoresVend[0]);
    int Carteira = 0;

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
                Carteira = 1250;
                for (int i = 0; i < n; i++) {
                    vend = inserirNo(vend, valoresVend[i]);
                }
                raiz = NULL;
                printf("\n --- Jogo reiniciado! Saldo do jogador eh de: R$ %d e inventario do vendedor e jogador restaurados! ---\n", Carteira);
                break;
            case 2:
                if (Carteira <= 0) {
                    printf("\n ---== JOGADOR FALIU! A mafia cuidara de voce em alguns dias, fique no aguardo! ==--- \n\n :) veja suas estatisticas ate la!\n\n");
                        printf("\n --- Inventario final do Vendedor: \n\n");
                        imprime_inventario(vend, 0);
                        printf("\n --- Inventario final do Jogador: \n\n");
                        imprime_inventario(raiz, 0);
                        printf("\nSaldo final: %d\n", Carteira);
                        printf("Nao eh muita coisa :/\n");
                        printf("\nDivida de R$ %d\n", 1250 - Carteira);
                        printf("Mas tem juros ne\n");
                        printf("\nDivida final de R$ %d :)\n", (1250 - Carteira) * 13);
                        printf("Espero REALMENTE que voce nao fume nem beba muito.\n");
                    escolha = 5;
                    break;
                }
                printf("\nQuanto quer apostar nessa rodada? ;/\n");
                scanf("%d", &aposta);
                fflush(stdin);
                while(aposta > Carteira) {
                    printf("\nNao tem graca nao, o maximo que tu pode aposta eh %d", Carteira);
                    printf("\nQuanto quer apostar?\n");
                    scanf("%d", &aposta);
                    fflush(stdin);
                }
                printf("\nRodando com %d ao preco de %d: \n", Carteira, aposta);
                Carteira = roda_roleta(Carteira, aposta);
                printf("\nSaldo: R$ %d\n", Carteira);
                if (Carteira <= 0) {
                    printf("\n ---== JOGADOR FALIU! A mafia cuidara de voce em alguns dias, fique no aguardo! ==--- \n\n :) veja suas estatisticas ate la!\n\n");
                    printf("\n --- Inventario final do Vendedor: \n\n");
                    imprime_inventario(vend, 0);
                    printf("\n --- Inventario final do Jogador: \n\n");
                    imprime_inventario(raiz, 0);
                    printf("\nSaldo final: %d\n", Carteira);
                    printf("Nao eh muita coisa :/\n");
                    printf("\nDivida de R$ %d\n", 1250 - Carteira);
                    printf("Mas tem juros ne\n");
                    printf("\nDivida final de R$ %d :)\n", (1250 - Carteira) * 13);
                    printf("Espero REALMENTE que voce nao fume nem beba muito.\n");
                    escolha = 5;
                    break;
                }
                break;
            case 3:
                printf("\n --- Inventario do Vendedor: \n\n");
                imprime_inventario(vend, 0);
                printf("\n --- Inventario do Jogador: \n\n");
                imprime_inventario(raiz, 0);
                break;
            case 4:
                printf("\n --- Inventario do Vendedor: \n\n");
                imprime_inventario(vend, 0);
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
                    printf("\nItem '%s' de valor: R$ %d foi comprado pelo jogador e retirado da loja do vendedor, parabens!\n", getName(valorItem), valorItem);
                    if(vend == NULL) {
                        printf("\n\n---== JOGADOR GANHOU! :() ==---\n\n");
                        printf(" --- Inventario do Jogador: ---\n\n");
                        imprime_inventario(raiz, 0);
                        printf("\nSaldo restante ainda: R$ %d\n", Carteira);
                        printf("\nPARABENS!\n\n");
                        escolha = 5;
                        break;
                    }
                    printf("\nSaldo: R$ %d\n", Carteira);
                } else {
                    printf("\nVoce esta pobre demais para um item assim, se quiser meu %s, consiga %d reais antes de voltar aqui!\n", getName(valorItem), valorItem - Carteira);
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
