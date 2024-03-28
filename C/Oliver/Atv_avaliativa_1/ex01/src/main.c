#include <stdio.h>
#include <stdlib.h>
#include "../include/itemDequeEnc.h"

int main() {
    Deque *dq = criarJornal();
    int opcao = 0;

    do {
        opcao = exibeMenuUsuario();
        
        switch (opcao) {
            case 1: {
                int cod;
                char titulo[100], conteudo[500], classificacao[50];
                printf("Digite o codigo da noticia: ");
                scanf("%d", &cod);
                printf("Digite o título da notícia: ");
                scanf(" %[^\n]", titulo);
                printf("Digite o conteúdo da notícia: ");
                scanf(" %[^\n]", conteudo);
                printf("Digite a classificação da notícia: ");
                scanf(" %[^\n]", classificacao);
                insereFinal_Deque(dq, criarNoticia(cod, titulo, conteudo, classificacao));
                printf("Notícia inserida com sucesso!\n");
                break;
            }
            case 2:
                removerPrimeiraNoticia(dq);
                printf("Primeira notícia removida!\n");
                break;
            case 3:
                removerUltimaNoticia(dq);
                printf("Última notícia removida!\n");
                break;
            case 4:
                imprimirJornal(dq);
                break;
            case 5:
                calcularQuantidadePorClassificacao(dq);
                break;
            case 6: {
                char nomeClassificacao[50];
                printf("Digite o nome da nova classificação: ");
                scanf(" %[^\n]", nomeClassificacao);
                adicionarClassificacao(jornal, nomeClassificacao);
                printf("Classificação adicionada com sucesso!\n");
                break;
            }
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 7);

    libera_Deque(dq);

    return 0;
}

int exibeMenuUsuario() {
    int opcao = 0;

    printf("Menu:\n");
    printf("1. Inserir notícia no inicio\n");
    printf("1. Inserir notícia no final\n");
    printf("2. Remover primeira notícia\n");
    printf("3. Remover ultima notícia\n");
    printf("4. Imprimir jornal\n");
    printf("5. Calcular quantidade por classificação\n");
    printf("6. Adicionar classificação\n");
    printf("7. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    return opcao;
}