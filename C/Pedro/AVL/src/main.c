#include <stdio.h>
#include <stdlib.h>
#include "../include/ArvoreAVL.h"

int main(){
    NoArvAVL* avl = cria_ArvAVL();
    char nome[100];
    int idade;
    char continuar;

    do {
        printf("Digite o nome do participante: ");
        gets(nome);
        fflush(stdin);
        printf("Digite a idade do participante: ");
        scanf("%d", &idade);
        fflush(stdin);
        fflush(stdin);

        if (insere_ArvAVL(avl, nome, idade)) {
            printf("Participante adicionado com sucesso!\n");
        } else {
            printf("Erro ao adicionar participante.\n");
        }

        printf("\nDeseja adicionar outro participante? (S/N): ");
        scanf(" %c", &continuar);
        fflush(stdin);
    } while (continuar == 'S' || continuar == 's');

    printf("\nImpressao da arvore AVL - em ordem:\n");
    emOrdem_ArvAVL(avl, "Raiz");
    printf("\n");

    char nome1[100], nome2[100];
    int resultado1, resultado2, i = 1;
    char continuar1;

    printf("\nInsercoes de resultados!\n");

    do {
        printf("\nResultado da partida %d:\n", i);
        i += 1;
        printf("\nDigite o nome do primeiro participante: ");
        gets(nome1);
        fflush(stdin);
        printf("Digite o resultado do primeiro participante (Rodadas Vencidas do Adversario): ");
        scanf("%d", &resultado1);
        fflush(stdin);

        printf("\nDigite o nome do segundo participante: ");
        gets(nome2);
        fflush(stdin);
        printf("Digite o resultado do segundo participante (Rodadas Vencidas do Adversario): ");
        scanf("%d", &resultado2);
        fflush(stdin);

        resultadoPontuacao(avl, nome1, resultado1, nome2, resultado2);

        printf("\nDeseja adicionar outro resultado? (S/N): ");
        scanf(" %c", &continuar1);
        fflush(stdin);
    } while (continuar1 == 'S' || continuar1 == 's');

    printf("\nImpressao da arvore AVL - em ordem:\n");
    emOrdem_ArvAVL(avl, "Raiz");
    printf("\n\n");

    libera_ArvAVL(avl);
    return 0;
}
