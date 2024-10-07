#include <stdio.h>
#include "../include/pilhaEnc.h"

int main(int argc, char const *argv[])
{
    Pilha *p1, *p2;
    p1 = criaPilhaVazia();
    p2 = criaPilhaVazia();

    empilha(p1, 1);
    empilha(p1, 2);
    empilha(p1, 3);
    empilha(p1, 5);
    empilha(p1, 2);
    empilha(p1, 1);

    insereItensNaoDuplicados(p1, p2);

    printf("\nLista 01 (original): \n");
    imprimePilha(p1);
    printf("\nLista 02 (sem duplicados): \n");
    imprimePilha(p2);

    liberaPilha(p1);
    liberaPilha(p2);

    return 0;
}
