#include <stdio.h>
#include "../include/itemFilaEnc.h"

int main() {
    Fila *f = criaFilaVazia();

    for(int i = 1; i <= 10; i++) {
        enfileira(f, i);
    }

    imprimeFila(f);

    desenfileira(f);

    printf("\nDESENFILEIROU\n");

    imprimeFila(f);

    liberaFila(f);

    return 0;
}
