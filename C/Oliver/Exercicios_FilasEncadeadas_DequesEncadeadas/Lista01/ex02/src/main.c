#include <stdio.h>
#include <stdlib.h>
#include "../include/itemDequeEnc.h"

int main() {
    Deque* dq = cria_Deque();

    atualizaDequeArvores(dq, 1);
    atualizaDequeArvores(dq, 5);
    atualizaDequeArvores(dq, 5);
    atualizaDequeArvores(dq, 9);
    atualizaDequeArvores(dq, 9);
    atualizaDequeArvores(dq, 9);
    atualizaDequeArvores(dq, 9);
    atualizaDequeArvores(dq, 2);
    atualizaDequeArvores(dq, 3);
    atualizaDequeArvores(dq, 4);
    atualizaDequeArvores(dq, 4);

    imprime_Deque(dq);

    imprimePorcentagemEspecie(dq);

    printf("\nCodigo especie mais frequente: %d", codEspecieMaisFrequente(dq));

    libera_Deque(dq);

    return 0;
}
