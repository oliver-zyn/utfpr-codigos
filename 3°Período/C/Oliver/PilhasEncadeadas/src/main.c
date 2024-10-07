#include <stdio.h>
#include "../include/pilhaEnc.h"

int main(int argc, char const *argv[])
{
    Pilha *p;
    int vazia, chave;

    printf("Criando pilha encadeada vazia.\n");
    p = criaPilhaVazia();

    vazia = verificaPilhaVazia(p);
    printf("Pilha vazia? %d\n", vazia);

    printf("\nAdicionando o 1o item.\n");
    chave = 1;
    empilha(p, chave);

    vazia = verificaPilhaVazia(p);
    printf("Pilha vazia? %d\n", vazia);

    printf("\nAdicionando o 2o item.\n");
    chave = 2;
    empilha(p, chave);

    printf("\nAdicionando o 3o item.\n");
    chave = 3;
    empilha(p, chave);

    printf("\nAdicionando o 4o item.\n");
    chave = 4;
    empilha(p, chave);

    printf("\nAdicionando o 5o item.\n");
    chave = 5;
    empilha(p, chave);

    printf("\nAdicionando o 6o item.\n");
    chave = 6;
    empilha(p, chave);

    printf("\nItens da pilha:\n");
    imprimePilha(p);

    printf("\nRemovendo ultimo item da pilha.\n");
    desempilha(p);

    imprimePilha(p);

    liberaPilha(p);

    return 0;
}
