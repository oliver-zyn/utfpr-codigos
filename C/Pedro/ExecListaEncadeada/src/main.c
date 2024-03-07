#include <stdio.h>
#include "../include/itemListaEnc.h"

int main()
{
    Lista *lst1 = criaListaVazia();
    Lista *lst2 = criaListaVazia();
    Lista *lstConcatenada = criaListaVazia();

    insereFimLista(lst1, 1);
    insereFimLista(lst1, 2);

    insereFimLista(lst2, 3);
    insereFimLista(lst2, 4);

    lstConcatenada = concatenacaoDeLista(lst1, lst2);

    return 0;
}
