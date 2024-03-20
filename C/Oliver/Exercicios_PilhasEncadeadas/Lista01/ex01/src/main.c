#include <stdio.h>
#include "../include/pilhaEnc.h"

int main(int argc, char const *argv[])
{
    Pilha *p1, *p2, *p3;
    p1 = criaPilhaVazia();
    p2 = criaPilhaVazia();
    p3 = criaPilhaVazia();

    for (int i = 1; i <= 11; i++) {
        empilha(p1, i);
    }

    preenchePilhasParesImpares(p1, p2, p3);

    printf("\nLista 01 (original): \n");
    imprimePilha(p1);
    printf("\nLista 02 (pares): \n");
    imprimePilha(p2);
    printf("\nLista 03 (impares): \n");
    imprimePilha(p3);

    liberaPilha(p1);
    liberaPilha(p2);
    liberaPilha(p3);

    return 0;
}
