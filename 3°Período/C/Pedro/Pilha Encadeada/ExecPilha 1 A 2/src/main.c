#include <stdio.h>
#include <stdlib.h>
#include "../include/PilhaEnc.h"

int main()
{
    Pilha *p1 = criaPilhaVazia();
    Pilha *pP = criaPilhaVazia();
    Pilha *pI = criaPilhaVazia();
    Pilha *p2 = criaPilhaVazia();

    printf("Adicionando chaves!\n\n");
    empilha(p1, 2);
    empilha(p1, 1);
    empilha(p1, 3);
    empilha(p1, 4);
    empilha(p1, 5);
    empilha(p1, 4);
    empilha(p1, 6);
    empilha(p1, 3);

    printf("Pilha 1: \n");
    imprimePilha(p1);

    // -- Exec 1

    parImpar(p1, pP, pI);

    printf("Pilha par: \n");
    imprimePilha(pP);

    printf("Pilha impar: \n");
    imprimePilha(pI);

    // -- Exec 2

    semDuplicadas(p1, p2);

    printf("Pilha sem duplicatas: \n");
    imprimePilha(p2);

    // -- Exec 3

    

    return 0;
}
