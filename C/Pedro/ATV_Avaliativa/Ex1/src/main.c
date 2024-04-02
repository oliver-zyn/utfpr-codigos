#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/itemDequeEnc.h"

int main() {
    
    Deque* dq = cria_Deque();

    int opcao = 0;
    int opcao2 = 0;
    do {
        printf("\nMenu:\n");
        printf("1. Incluir noticia no comeco\n");
        printf("2. Incluir noticia no final\n");
        printf("3. Remover primeira noticia\n");
        printf("4. Remover ultima noticia\n");
        printf("5. Imprimir noticias\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: {
                int id = 0, pagina = 0;
                char titulo[100];
                char descricao[200];
                char classificacao[50];
                char autor[50];

                printf("Informe o ID da noticia: ");
                scanf("%d", &id);
                fflush(stdin);

                printf("Informe a pagina da noticia: ");
                scanf("%d", &pagina);
                fflush(stdin);

                printf("Informe o titulo da noticia: ");
                gets(titulo);
                fflush(stdin);
                
                printf("Informe a descricao da noticia: ");
                gets(descricao);
                fflush(stdin);

                printf("Informe o autor da noticia: ");
                gets(autor);
                fflush(stdin);

                printf("A noticia eh de esportes: 1\n");
                printf("A noticia eh de cultura: 2\n");
                printf("A noticia eh de politica: 3\n");
                scanf("%d", &opcao2);
                fflush(stdin);
                switch (opcao2) {
                case 1:
                    strcpy(classificacao, "Esportes");
                    break;
                case 2:
                    strcpy(classificacao, "Cultura");
                    break;
                case 3:
                    strcpy(classificacao, "Politica");
                    break;
                default:
                    break;
                }

                insereInicio_Deque(dq, id, pagina, titulo, descricao, classificacao, autor);
                printf("Noticia incluida com sucesso!\n");
                break;
            }
            case 2: {
                int id = 0, pagina = 0;
                char titulo[100];
                char descricao[200];
                char classificacao[50];
                char autor[50];
                int opcao2;

                printf("Informe o ID da noticia: ");
                scanf("%d", &id);
                fflush(stdin);

                printf("Informe a pagina da noticia: ");
                scanf("%d", &pagina);
                fflush(stdin);

                printf("Informe o titulo da noticia: ");
                gets(titulo);
                fflush(stdin);
                
                printf("Informe a descricao da noticia: ");
                gets(descricao);
                fflush(stdin);

                printf("Informe o autor da noticia: ");
                gets(autor);
                fflush(stdin);

                printf("A noticia eh de esportes: 1\n");
                printf("A noticia eh de cultura: 2\n");
                printf("A noticia eh de poltica: 3\n");
                scanf("%d", &opcao2);
                fflush(stdin);
                switch (opcao2) {
                case 1:
                    strcpy(classificacao, "Esportes");
                    break;
                case 2:
                    strcpy(classificacao, "Cultura");
                    break;
                case 3:
                    strcpy(classificacao, "Politica");
                    break;
                default:
                    break;
                }

                insereFinal_Deque(dq, id, pagina, titulo, descricao, classificacao, autor);
                printf("Noticia incluida com sucesso!\n");
                break;
            }
            case 3: {
                removeInicio_Deque(dq);
                printf("Primeira noticia removida com sucesso!\n");
                break;
            }
            case 4: {
                removeFinal_Deque(dq);
                printf("Ultima noticia removida com sucesso!\n");
                break;
            }
            case 5: {
                printf("Noticias:\n");
                imprime_Deque(dq);
                porcentagemNot(dq);
                numNot(dq);
                break;
            }
            case 6: {
                printf("Encerrando o programa...\n");
                break;
            }
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 6);


    libera_Deque(dq);
    return 0;
}
