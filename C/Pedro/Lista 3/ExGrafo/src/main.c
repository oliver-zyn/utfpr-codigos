#include <stdio.h>
#include <stdlib.h>
#include "../include/Grafo.h"

int main(){
    int eh_digrafo = 0;
    Grafo* gr = cria_Grafo(9, 9, 1);

    insereAresta(gr, 0, 1, eh_digrafo, 5);
    insereAresta(gr, 0, 3, eh_digrafo, 3);
    insereAresta(gr, 0, 4, eh_digrafo, 1);

    insereAresta(gr, 1, 2, eh_digrafo, 5);

    insereAresta(gr, 2, 3, eh_digrafo, 7);

    insereAresta(gr, 4, 5, eh_digrafo, 1);
    insereAresta(gr, 4, 7, eh_digrafo, 5);

    insereAresta(gr, 5, 6, eh_digrafo, 7);

    insereAresta(gr, 6, 7, eh_digrafo, 5);

    insereAresta(gr, 7, 8, eh_digrafo, 3);

    int i, ant[9];
    float dist[9];

    imprime_GrafoName(gr);

    printf("\n");

    menorCaminho_Grafo(gr, 4, ant, dist);

    imprimePaiName(ant, 9, gr);

    libera_Grafo(gr);

    return 0;
}