#include <stdio.h>
#include <stdlib.h>
#include "../include/itemDequeEnc.h"

int main()
{

    Deque* dq;

    printf("Pau");

    // implementaQtdArvore(dq, 1);
    // implementaQtdArvore(dq, 3);
    // implementaQtdArvore(dq, 5);
    // implementaQtdArvore(dq, 7);
    // implementaQtdArvore(dq, 1);
    // implementaQtdArvore(dq, 1);
    // implementaQtdArvore(dq, 3);

    insereInicio_Deque(dq, 1, 1);
    insereInicio_Deque(dq, 2, 5);
    insereInicio_Deque(dq, 3, 3);

    imprime_Deque(dq);

    // imprimePorcentagemPorEspecie(dq);

    // printf("Chave mais frequente: %d\n", codMaisFrequente(dq));

    return 0;
}
