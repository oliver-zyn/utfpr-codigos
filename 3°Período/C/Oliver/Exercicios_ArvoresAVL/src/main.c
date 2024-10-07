#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ArvoreAVL.h"

 int main() {
    NoArvAVL* arvore = cria_ArvAVL();
    char opcao;
    char nome[100], nome2[100], nome_vencedor[100];
    int idade;
    char resultado;
    int continuar_incluindo = 1;

    do {
        printf("\n=== Incluir participante ===\n\n");
        printf("Nome do participante: ");
        scanf("%s", nome);
        printf("Idade do participante: ");
        scanf("%d", &idade);
        
        insere_ArvAVL(arvore, nome, idade, 0);
        
        printf("Deseja incluir outro participante? (S/N): ");
        scanf(" %c", &opcao);
        if (opcao == 'N' || opcao == 'n') {
            continuar_incluindo = 0;
        }
    } while (continuar_incluindo);

    printf("\nArvore gerada (em ordem):\n");
    emOrdem_ArvAVL(arvore);

    do {
        printf("\n=== Incluir resultado de partida ===\n\n");
        printf("Nome do primeiro competidor: ");
        scanf("%s", nome);
        printf("Nome do segundo competidor: ");
        scanf("%s", nome2);
        printf("Nome do participante vencedor (0 para empate): ");
        scanf("%s", nome_vencedor);
        
        if (strcmp(nome_vencedor, nome) == 0) {
            alteraPontuacaoParticipante(arvore, nome, 'v');
            alteraPontuacaoParticipante(arvore, nome2, 'p');
        } else if (strcmp(nome_vencedor, nome2) == 0) {
            alteraPontuacaoParticipante(arvore, nome, 'p');
            alteraPontuacaoParticipante(arvore, nome2, 'v');
        } else if (strcmp(nome_vencedor, "0") == 0) {
            alteraPontuacaoParticipante(arvore, nome, 'e');
            alteraPontuacaoParticipante(arvore, nome2, 'e');
        } else {
            printf("Nome do vencedor invalido!\n");
            continue;
        }

        printf("Deseja incluir outro resultado de partida? (S/N): ");
        scanf(" %c", &opcao);
    } while (opcao == 'S' || opcao == 's'); 

    printf("\nArvore apos inclusao dos resultados de partidas (em ordem):\n");
    emOrdem_ArvAVL(arvore);

    libera_ArvAVL(arvore);

    return 0;
}