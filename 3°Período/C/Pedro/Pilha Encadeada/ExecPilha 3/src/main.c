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
    empilha(p1, 1, "Pedro INC", "Venda de Drogas / Farmacia", 0.5);
    empilha(p1, 2, "Oliver INC", "Venda de Cosmeticos", 0.1);
    empilha(p1, 3, "Spotify", "Entretenimento", 0.2);

    printf("Pilha 1: \n");
    imprimePilha(p1);

    // -- Exec 3

    

    return 0;
}
