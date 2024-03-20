#include <stdio.h>
#include <stdlib.h>
#include "../include/itemFilaEnc.h"

int main() {
    Fila *f = criaFilaVazia();

    for(int i = 0; i < 10; i++) {
        enfileira(f, i);
    }
    printf("Antes\n");
    imprimeFila(f);

    desenfleira(f);
    printf("Depois\n");
    imprimeFila(f);

    liberaFila(f);
}