#include <stdio.h>
#include <stdlib.h>
#include "itemListaEnc.h"

int main() {
    Lista *l;
    l = criaListaVazia();
    insereInicioLista(l, 1);
    imprimeLista(l);
    return 0;
}
