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
        printf("\nIncluir resultado de partida:\n");
        printf("Nome do primeiro competidor: ");
        scanf("%s", nome1);
        printf("Nome do segundo competidor: ");
        scanf("%s", nome2);
        printf("Nome do participante vencedor: ");
        scanf("%s", nome_vencedor);
        
        // Atualiza a pontuação conforme o nome do vencedor
        if (strcmp(nome_vencedor, nome1) == 0) {
            alteraPontuacao_Participante(arvore, nome1, 'v');
            alteraPontuacao_Participante(arvore, nome2, 'p');
        } else if (strcmp(nome_vencedor, nome2) == 0) {
            alteraPontuacao_Participante(arvore, nome1, 'p');
            alteraPontuacao_Participante(arvore, nome2, 'v');
        } else {
            printf("Nome do vencedor inválido!\n");
            continue;
        }

        printf("Deseja incluir outro resultado de partida? (S/N): ");
        scanf(" %c", &opcao);
    } while (opcao == 'S' || opcao == 's'); 

    printf("\nImpressao da arvore AVL - em ordem:\n");
    emOrdem_ArvAVL(avl, "Raiz");
    printf("\n\n");

    libera_ArvAVL(avl);
    return 0;
}
