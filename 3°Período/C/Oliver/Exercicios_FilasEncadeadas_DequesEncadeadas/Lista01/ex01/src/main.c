#include <stdio.h>
#include "../include/itemFilaEnc.h"

int main() {
    Fila *f = criaFilaVazia();

    enfileira(f, -5);
    enfileira(f, 1);
    enfileira(f, 2);
    enfileira(f, 3);
    enfileira(f, 4);
    enfileira(f, 5);
    enfileira(f, 6);
    enfileira(f, 6);

    imprimeFila(f);

    printf("Ordenada: %d", verificaFilaOrdenada(f));

    return 0;
}
