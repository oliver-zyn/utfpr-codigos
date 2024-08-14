#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ArvoreB.h"

int main() {
        char nome[100];
        int opcao;
        char delimitador[] = "-";
        char *ptr;
        char valor[100];
        char l[1000];

        Node *raiz = NULL;

        printf("Criacao de Arvore-B de ordem %d, ou seja, nos com %d filhos, e no maximo %d nomes:\n", M, M, M - 1);
        while (1) {
                printf("\n1.Inserir\n");
                printf("2.Remover\n");
                printf("3.Buscar\n");
                printf("4.Imprimir arvore\n");
                printf("5.Sair do programa\n");
                printf("\nEscolha uma das opcoes do menu: ");
                scanf("%d", &opcao); //eatline();

                switch (opcao) {
                case 1:
                        printf("\nDigite os nomes a serem inseridos, separados por hifen (sem espaco).\n");
                        printf("Exemplo: pedro-oliver-ana\n");
                        scanf("%s", l);
                        //quebra a string de entrada
                        ptr = strtok(l, delimitador);
                        while(ptr != NULL) {
							strcpy(valor, ptr);
                            raiz = inserirNo(raiz, valor);
                            ptr = strtok(NULL, delimitador); //breaks string str into a series of tokens using the delimiter delim.
                        }
                        break;
                case 2:
                        printf("Informe a chave a ser removida: ");
                        scanf("%s", nome);
                        excluirNo(raiz, nome);
                        break;
                case 3:
                        printf("Informe a chave a ser procurada: ");
                        scanf("%s", nome);
                        busca(raiz, nome);
                        break;
                case 4:
                        printf("Impressao da Arvore-B de ordem %d:\n", M);
                        imprime_arvore(raiz, 0);
                        break;
                case 5:
                        exit(1);
                default:
                        printf("Opcao invalida.\n");
                        break;
                }/*Fim switch*/
        }/*Fim while*/
        return 0;
}/*Fim main()*/
