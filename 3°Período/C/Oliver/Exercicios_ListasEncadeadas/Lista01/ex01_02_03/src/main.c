#include <stdio.h>
#include "../include/itemListaEnc.h"

int main(int argc, char const *argv[]) {

    //EX 01

    Lista *lst1 = criaListaVazia();
    Lista *lst2 = criaListaVazia();
    Lista *lstConcat = criaListaVazia();

    insereFimLista(lst1, 1);
    insereFimLista(lst1, 3);

    insereFimLista(lst2, 7);
    insereFimLista(lst2, 6);
    insereFimLista(lst2, 9);
    
    lstConcat = concatenarListas(lst1, lst2);

    printf("\nLISTA 1:\n");
    imprimeLista(lst1);

    printf("\nLISTA 2:\n");
    imprimeLista(lst2);

    printf("\nLISTA CONCATENADA:\n");
    imprimeLista(lstConcat);

    //EX 02

    Lista *lst3 = criaListaVazia();
    Lista *lst4 = criaListaVazia();

    insereFimLista(lst3, 9);
    insereFimLista(lst3, 1);
    insereFimLista(lst3, 3);
    insereFimLista(lst3, 4);
    insereFimLista(lst3, 8);
    insereFimLista(lst3, 2);
    insereFimLista(lst3, 3);

    insereOrdenadosOutraLista(lst3, lst4);

    return 0;
}
