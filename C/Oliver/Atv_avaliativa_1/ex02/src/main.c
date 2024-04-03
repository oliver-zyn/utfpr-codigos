#include <stdio.h>
#include <stdlib.h>
#include "../include/itemListaEnc.h"

int main() {
    Lista *lst = criaListaVazia();

    insere(lst, 1, "Super Mario", "descricao mario", 12, "supermario.com");
    insere(lst, 2, "GTA V", "descricao gta v", 18, "gta-v.com");
    insere(lst, 3, "Bloons TD 6", "descricao bloons td 6", 8, "bloonstd.com");
    insere(lst, 4, "Counter Strike", "descricao counter strike", 16, "counterstrike.com");
    insere(lst, 5, "Far Cry", "descricao far cry", 18, "farcry.com");
    insere(lst, 6, "Outlast 2", "descricao outlast 2", 16, "outlast2.com");

    printf("\nLista completa: \n");
    imprimeLista(lst);

    removePorNome(lst, "Super Mario");

    printf("\nLista depois de remover Super Mario:\n");
    imprimeLista(lst);

    printf("\nBuscando jogos por nome: \n");

    imprime_jogo(lst, "Counter Strike");
    imprime_jogo(lst, "Outlast");
    imprime_jogo(lst, "God Of War");

    return 0;
}
