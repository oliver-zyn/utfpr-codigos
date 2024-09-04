#include <stdio.h>
#include <stdlib.h>
#include "../include/Grafo.h"

int main(){
    int eh_digrafo = 0;
    Grafo* gr = cria_Grafo(6, 6, 1);

    insereAresta(gr, 0, 1, eh_digrafo, 6);
    insereAresta(gr, 0, 2, eh_digrafo, 1);
    insereAresta(gr, 0, 3, eh_digrafo, 5);
    insereAresta(gr, 1, 2, eh_digrafo, 2);
    insereAresta(gr, 1, 4, eh_digrafo, 5);
    insereAresta(gr, 2, 3, eh_digrafo, 2);
    insereAresta(gr, 2, 4, eh_digrafo, 6);
    insereAresta(gr, 2, 5, eh_digrafo, 4);
    insereAresta(gr, 3, 5, eh_digrafo, 4);
    insereAresta(gr, 4, 5, eh_digrafo, 3);

    int i, pai[6];

    imprime_Grafo(gr);

    printf("\nAPOS O ALGORITMO\n\n");

    algPRIM(gr, 0, pai);

    Grafo *mst = constroi_MST(gr, pai);

    imprime_MST(mst);

    printf("\nPAISES\n\n");

    imprime_MST_com_paises(mst);

    printf("\nPAISES DESCRICAO\n\n");

    imprime_MST_com_descricao(mst);

    libera_Grafo(gr);
    libera_Grafo(mst);

    return 0;
}
