#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/itemListaEnc.h"

int main()
{
    Lista *lst1 = criaListaVazia();

    insereOrdenado(lst1, 1, 18, "Jogo 1", "1", "1");
    insereOrdenado(lst1, 2, 12, "2", " 2", "2");
    insereOrdenado(lst1, 3, 16, "3", "3", "3");
    insereOrdenado(lst1, 4, 17, "4", "4", "4");

    printf("Primeiro Print de tudo!!\n\n");
    imprimeLista(lst1);

    printf("\nBusca pelo nome!!\n");
    buscaPorNome(lst1, "Jogo 1");

    char nome[10] = "2";
    printf("\nRemovendo o jogo de nome '%s'!!\n", nome);
    removeItemPorNome(lst1, nome);
    printf("\nSucesso!\n");

    printf("\nSegundo Print de tudo!!\n\n");
    imprimeLista(lst1);

    return 0;
}
