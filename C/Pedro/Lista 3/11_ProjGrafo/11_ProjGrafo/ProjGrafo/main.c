#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main(){
    int eh_digrafo = 1;
    printf("Criado grafo digrafo com 5 vertices, grau maximo 5, nao ponderado.\n");
    Grafo* gr = cria_Grafo(5, 5, 0);

    printf("Inclusao de arestas entre vertices 0, 1, 2, 3 e 4:\n");
    printf("A={{%d,%d},", 0, 1);
    insereAresta(gr, 0, 1, eh_digrafo, 0);
    printf("{%d,%d},", 1, 3);
    insereAresta(gr, 1, 3, eh_digrafo, 0);
    printf("{%d,%d},", 1, 2);
    insereAresta(gr, 1, 2, eh_digrafo, 0);
    printf("{%d,%d},", 2, 4);
    insereAresta(gr, 2, 4, eh_digrafo, 0);
    printf("{%d,%d},", 3, 0);
    insereAresta(gr, 3, 0, eh_digrafo, 0);
    printf("{%d,%d},", 3, 4);
    insereAresta(gr, 3, 4, eh_digrafo, 0);
    printf("{%d,%d}}\n", 4, 1);
    insereAresta(gr, 4, 1, eh_digrafo, 0);

    imprime_Grafo(gr);
//
//    printf("\nRemocao de aresta que une vertices 1 e 3: \n");
//    removeAresta(gr, 1, 3, 0);
//    imprime_Grafo(gr);

    int vis[5];
    int chave = 2; //chave para busca
    printf("\n\n.......\nSimulacao de busca em largura a partir do Vertice 0:\n");
    buscaLargura_Grafo(gr, 0, vis, chave);

    printf("\n\n.......\nSimulacao de busca em profundidade a partir do Vertice 0:\n");
    buscaProfundidade_Grafo(gr, 0, vis, chave);

    printf("\n\n.......\nSimulacao de busca pelo menor caminho a partir do Vertice 0:\n");
    int i,ant[5];
    float dist[5];
    menorCaminho_Grafo(gr, 0, ant, dist, chave);
    for(i=0; i<5; i++)
    {
        printf(".Ate o Vertice %d: Anterior %d -> distancia : %f\n",i,ant[i],dist[i]);
    }

    printf("\n\n.......\nSimulacao de busca pelo menor caminho a partir do Vertice 2:\n");
    menorCaminho_Grafo(gr, 2, ant, dist, chave);
    for(i=0; i<5; i++)
    {
        printf(".Ate o Vertice %d: Anterior %d -> distancia : %f\n",i,ant[i],dist[i]);
    }

    libera_Grafo(gr);
    return 0;
}
