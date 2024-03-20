#include <stdio.h>
#include <stdlib.h>
#include "../include/itemDequeEnc.h"

int main()
{

    Deque* dq = cria_Deque();

    implementaQtdArvore(dq, 1);
    implementaQtdArvore(dq, 3);
    implementaQtdArvore(dq, 5);
    implementaQtdArvore(dq, 7);
    implementaQtdArvore(dq, 1);
    implementaQtdArvore(dq, 1);
    implementaQtdArvore(dq, 3);

    imprime_Deque(dq);

    imprimePorcentagemPorEspecie(dq);

    printf("Chave mais frequente: %d\n", codMaisFrequente(dq));

    return 0;
}
