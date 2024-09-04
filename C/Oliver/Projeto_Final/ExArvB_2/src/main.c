#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/ArvoreB.h"

int main() {
    srand(time(NULL));
    Node *inventario = NULL;
    int saldo = 100;
    int opcao;

    while (opcao != 4) {
        printf("\nSaldo: %d\n", saldo);
        printf("1. Minerar\n");
        printf("2. Vender Minerio\n");
        printf("3. Ver Inventario\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                minerar(&inventario, &saldo);
                break;
            case 2: {
                char nome[50];
                int quantidade;
                printf("Digite o nome do minerio para vender: ");
                scanf("%s", nome);
                printf("Digite a quantidade a ser vendida: ");
                scanf("%d", &quantidade);
                venderItem(inventario, nome, quantidade, &saldo);
                break;
            }
            case 3:
                imprimeInventario(inventario, 0);
                break;
            case 4:
                printf("Obrigado por jogar!\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

        if (verificarFimJogo(saldo)) {
            break;
        }
    }

    return 0;
}

