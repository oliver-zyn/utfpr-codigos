#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/itemDequeEnc.h"

int exibeMenuUsuario() {
    int opcao = 0;

    printf("\nMenu:\n");
    printf("1. Inserir noticia no inicio\n");
    printf("2. Inserir noticia no final\n");
    printf("3. Remover noticia do final\n");
    printf("4. Remover noticia do inicio\n");
    printf("5. Imprimir noticias\n");
    printf("6. Imprimir a quantidade de noticias cadastradas por classificacao \n");
    printf("7. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

char* retNomeClassificacao(int classificacao) {
    switch (classificacao) {
        case 1:
            return "Cinema";
        case 2:
            return "Ciencia";
        case 3:
            return "Politica";
        default:
            return "";
    }
}

void cadastraNoticia(Deque *dq, int inserirInicio) {
    int cod, anoPublicacao, opcaoClassificacao;
    char manchete[100], corpo[500], autor[100];
    char * classificacao;

    printf("Digite o codigo da noticia: ");
    scanf("%d", &cod);
    fflush(stdin);

    printf("Digite a manchete da noticia: ");
    gets(manchete);
    fflush(stdin);

    printf("Digite o corpo da noticia: ");
    gets(corpo);
    fflush(stdin);

    printf("Digite o autor da noticia: ");
    gets(autor);
    fflush(stdin);

    printf("Digite o ano de publicacao da noticia: ");
    scanf("%d", &anoPublicacao);
    fflush(stdin);

    printf("Selecione a classificacao da noticia: ");
    printf("\n1 - Cinema");
    printf("\n2 - Ciencia");
    printf("\n3 - Politica");
    printf("\nOpcao: ");
    scanf("%d", &opcaoClassificacao);

    classificacao = retNomeClassificacao(opcaoClassificacao);

    if (strcmp(classificacao, "") == 0) {
        printf("\nClassificacao invalida!\n");
        return;
    }

    if (inserirInicio == 1) {
        insereInicio_Deque(dq, cod, anoPublicacao, manchete, corpo, autor, classificacao);
    } else {
        insereFinal_Deque(dq, cod, anoPublicacao, manchete, corpo, autor, classificacao);
    }

    printf("\nNoticia inserida com sucesso!\n");
}

int main() {
    Deque *dq = cria_Deque();
    int opcao = 0;

    do {
        opcao = exibeMenuUsuario();
        
        switch (opcao) {
            case 1:
                cadastraNoticia(dq, 0);
                break;
            case 2:
                cadastraNoticia(dq, 1);
                break;
            case 3:
                removeFinal_Deque(dq);
                printf("\nNoticia removida do final com sucesso!\n");
                break;
            case 4:
                removeInicio_Deque(dq);
                printf("\nNoticia removida do inicio com sucesso!\n");
                break;
            case 5:
                printf("\nNoticias cadastradas: \n");
                imprime_Deque(dq);
                break;
            case 6: {
                imprimePorcentagemClassificacaoMaior(dq);
                imprimeNumeroNoticiasClassificacao(dq);
                break;
            }
            case 7:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 7);

    libera_Deque(dq);

    return 0;
}


