#include <stdio.h>
#include <stdlib.h>
#include "../include/Grafo.h"

int main(){
    int eh_digrafo = 0;
    printf("Criado grafo digrafo com 9 vertices, grau maximo 3, nao ponderado.\n");
    Grafo* gr = cria_Grafo(9, 3, 1);

    printf("Inclusao de arestas entre vertices 0, 1, 2, 3, 4, 5, 6, 7 e 8:\n");

    printf("A={{%d,%d},", 0, 1);
    insereAresta(gr, 0, 1, eh_digrafo, 5); //viagens -> maria

    printf("A={%d,%d},", 0, 2);
    insereAresta(gr, 0, 2, eh_digrafo, 5); //viagens -> beltrano

    printf("A={%d,%d},", 1, 3);
    insereAresta(gr, 1, 3, eh_digrafo, 3); //maria -> tecnologia

    printf("A={%d,%d},", 3, 2);
    insereAresta(gr, 3, 2, eh_digrafo, 7); //tecnologia -> beltrano

    printf("A={%d,%d},", 1, 4);
    insereAresta(gr, 1, 4, eh_digrafo, 1); //maria -> investimentos

    printf("A={%d,%d},", 4, 5);
    insereAresta(gr, 4, 5, eh_digrafo, 1); //investimentos -> fulano

    printf("A={%d,%d},", 4, 6);
    insereAresta(gr, 4, 6, eh_digrafo, 5); //investimentos -> joão

    printf("A={%d,%d},", 6, 7);
    insereAresta(gr, 6, 7, eh_digrafo, 3); //joão -> negócios

    printf("A={%d,%d},", 5, 8);
    insereAresta(gr, 5, 8, eh_digrafo, 7); //fulano -> futebol

    printf("A={%d,%d}},", 6, 8);
    insereAresta(gr, 6, 8, eh_digrafo, 5); //joão -> futebol

    // imprime_Grafo(gr);

    printf("\n\nIMPRESSAO DO GRAFO EM FORMATO TEXTUAL: \n\n");
    imprime_Grafo_Textual(gr);

    imprime_busca_menor_caminho(gr, 5);

    libera_Grafo(gr);
    return 0;
}
