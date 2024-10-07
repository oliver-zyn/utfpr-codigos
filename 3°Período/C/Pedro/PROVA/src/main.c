#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/itemListaEnc.h"

int main()
{
    Lista *lst1 = criaListaVazia();

    int opcao = 0;
    int opcao2 = 0;
    do {
        printf("\nMenu:\n");
        printf("1. Incluir registro no comeco\n");
        printf("2. Incluir registro no final\n");
        printf("3. Incluir registro no meio\n");
        printf("4. Remover registro\n");
        printf("5. Imprimir registros\n");
        printf("6. Imprimir quilometragem de rota\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: {
                int chave = 0, id_atleta = 0, rota = 0;
                char data_reg[20] = " ";
                float quilom;

                printf("Informe a chave do registro: ");
                scanf("%d", &chave);
                fflush(stdin);

                printf("Informe o id do atleta: ");
                scanf("%d", &id_atleta);
                fflush(stdin);

                printf("Informe a data de registro: ");
                gets(data_reg);
                fflush(stdin);
                
                printf("Informe a qtd de quilometros percorridos pelo atleta: ");
                scanf("%f", &quilom);
                fflush(stdin);

                printf("Informe a rota percorrida: ");
                scanf("%d", &rota);
                fflush(stdin);

                insereInicioLista(lst1, chave, data_reg, id_atleta, quilom, rota);
                printf("Noticia incluida com sucesso!\n");
                break;
            }
            case 2: {
                int chave = 0, id_atleta = 0, rota = 0;
                char data_reg[20] = " ";
                float quilom;

                printf("Informe a chave do registro: ");
                scanf("%d", &chave);
                fflush(stdin);

                printf("Informe o id do atleta: ");
                scanf("%d", &id_atleta);
                fflush(stdin);

                printf("Informe a data de registro: ");
                gets(data_reg);
                fflush(stdin);
                
                printf("Informe a qtd de quilometros percorridos pelo atleta: ");
                scanf("%f", &quilom);
                fflush(stdin);

                printf("Informe a rota percorrida: ");
                scanf("%d", &rota);
                fflush(stdin);

                insereFimLista(lst1, chave, data_reg, id_atleta, quilom, rota);
                printf("Noticia incluida com sucesso!\n");
                break;
            }
            case 3: {
                int chave = 0, id_atleta = 0, rota = 0, chave2 = 0;
                char data_reg[20] = " ";
                float quilom;

                printf("Informe a chave do registro: ");
                scanf("%d", &chave);
                fflush(stdin);

                printf("Informe o id do atleta: ");
                scanf("%d", &id_atleta);
                fflush(stdin);

                printf("Informe a data de registro: ");
                gets(data_reg);
                fflush(stdin);
                
                printf("Informe a qtd de quilometros percorridos pelo atleta: ");
                scanf("%f", &quilom);
                fflush(stdin);

                printf("Informe a rota percorrida: ");
                scanf("%d", &rota);
                fflush(stdin);

                printf("Inserir novo registro depois do registro de chave: ");
                scanf("%d", &chave2);
                fflush(stdin);

                imprimeLista(lst1);
                insereMeioLista(lst1, chave, data_reg, id_atleta, quilom, rota, chave2);
                break;
            }
            case 4: {
                int chave4;
                imprimeLista(lst1);
                printf("\nQual a chave do registro que deseja excluir?\n");
                scanf("%d", &chave4);
                removeRegistro(lst1, chave4);
                break;
            }
            case 5: {
                imprimeLista(lst1);
                break;
            }
            case 6: {
                int rota6 = 0;
                printf("Qual a rota a ser analisada?\n");
                scanf("%d", &rota6);
                totalQtdQuikporRota(lst1, rota6);
                break;
            }
            case 7: {
                printf("Encerrando o programa...\n");
                break;
            }
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 7);

    liberaLista(lst1);
    return 0;
}
