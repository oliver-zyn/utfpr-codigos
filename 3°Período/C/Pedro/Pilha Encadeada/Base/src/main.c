#include <stdio.h>
#include <stdlib.h>
#include "../include/PilhaEnc.h"

int main()
{
    printf("Criando pilha vazia! \n");
    Pilha *p1 = criaPilhaVazia();
    int vazia, chave;

    vazia = verificaPilhaVazia(p1);
    printf("Pilha esta vazia: %d (1 - sim / 0 - nao)\n\n", vazia);

    printf("Adicionando chaves!\n\n");
    empilha(p1, 2);
    empilha(p1, 1);
    empilha(p1, 3);
    empilha(p1, 4);

    vazia = verificaPilhaVazia(p1);
    printf("Pilha esta vazia: %d (1 - sim / 0 - nao)\n\n", vazia);

    imprimePilha(p1);

    printf("\nDesempilhando um item\n\n");
    desempilha(p1);

    imprimePilha(p1);

    printf("\nDesempilhando um item\n\n");
    desempilha(p1);

    imprimePilha(p1);

    return 0;
}
