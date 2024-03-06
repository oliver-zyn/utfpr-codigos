#include <stdio.h>
#include <stdlib.h>
#include "../include/itemListaEnc.h"

int main() {
    Lista *lst;
    int vazia;

    printf("Criando lista asd.\n");
    lst = criaListaVazia();
    
    vazia = verificaListaVazia(lst);
    printf("Lista vazia? %d\n", vazia);

    printf("Adicionando o 1o item.\n");

    return 0;
}
