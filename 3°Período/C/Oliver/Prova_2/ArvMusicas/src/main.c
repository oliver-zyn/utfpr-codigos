#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ArvoreB.h"

int main() {
    int opcao;
    char musica[100];

    Node *raiz = NULL;

    printf("Criacao de Arvore-B de ordem %d, ou seja, nos com %d filhos, e no maximo %d chaves:\n", M, M, M - 1);
    while (opcao != 3) {
        printf("\nCriando uma arvore de musicas, como deseja prosseguir?\n");
        printf("\n1. Inserir uma nova musica\n");
        printf("2. Imprimir arvore de musicas\n");
        printf("3. Sair do programa\n");
        printf("\nEscolha uma das opcoes do menu: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("\nDigite o nome da musica a ser inserida: ");
            scanf("%s", musica);

            raiz = inserirNo(raiz, musica);
            
            break;
        case 2:
            printf("Impressao da Arvore-B de ordem %d:\n\n", M);
            imprime_arvore(raiz, 0);
            break;
        case 3:
            printf("\nEncerrando...\n");
            break;
        default:
            printf("\nOpcao invalida.\n");
            break;
        }
    }
    return 0;
}