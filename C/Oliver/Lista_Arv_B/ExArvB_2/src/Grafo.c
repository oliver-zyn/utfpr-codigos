#include <stdio.h>
#include <stdlib.h>
#include "../include/Grafo.h"

#define MAX_VERTICES 10

const char *nomes_paises[MAX_VERTICES] = {
    "Brasil", "Argentina", "Chile", "Uruguai", "Paraguai", 
    "Peru", "Bolivia", "Colombia", "Venezuela", "Equador"
};

struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};

Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado){
    Grafo *gr;
    gr = (Grafo*) malloc(sizeof(struct grafo));
    if(gr != NULL){
        int i;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0)?1:0;
        gr->grau = (int*) calloc(nro_vertices,sizeof(int));

        gr->arestas = (int**) malloc(nro_vertices * sizeof(int*));
        for(i=0; i<nro_vertices; i++)
            gr->arestas[i] = (int*) malloc(grau_max * sizeof(int));

        if(gr->eh_ponderado){
            gr->pesos = (float**) malloc(nro_vertices * sizeof(float*));
            for(i=0; i<nro_vertices; i++)
                gr->pesos[i] = (float*) malloc(grau_max * sizeof(float));
        }

    }
    return gr;
}

void libera_Grafo(Grafo* gr){
    if(gr != NULL){
        int i;
        for(i=0; i<gr->nro_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);

        if(gr->eh_ponderado){
            for(i=0; i<gr->nro_vertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    gr->arestas[orig][gr->grau[orig]] = dest;
    if(gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;
    gr->grau[orig]++;

    if(eh_digrafo == 0)
        insereAresta(gr,dest,orig,1,peso);
    return 1;
}

int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    int i = 0;
    while(i<gr->grau[orig] && gr->arestas[orig][i] != dest)
        i++;
    if(i == gr->grau[orig])
        return 0;
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
    if(gr->eh_ponderado)
        gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];
    if(eh_digrafo == 0)
        removeAresta(gr,dest,orig,1);
    return 1;
}

void imprime_Grafo(Grafo *gr){
    if(gr == NULL)
        return;

    int i, j;
    for(i=0; i < gr->nro_vertices; i++){
        printf("%d: ", i);
        for(j=0; j < gr->grau[i]; j++){
            if(gr->eh_ponderado)
                printf("%d(%.2f), ", gr->arestas[i][j], gr->pesos[i][j]);
            else
                printf("%d, ", gr->arestas[i][j]);
        }
        printf("\n");
    }
}

int procuraMenorDistancia(float *dist, int *visitado, int NV){
    int i, menor = -1, primeiro = 1;
    for(i=0; i < NV; i++){
        if(dist[i] >= 0 && visitado[i] == 0){
            if(primeiro){
                menor = i;
                primeiro = 0;
            }else{
                if(dist[menor] > dist[i])
                    menor = i;
            }
        }
    }
    return menor;
}

void menorCaminho_Grafo(Grafo *gr, int ini, int *ant, float *dist){
    int i, cont, NV, ind, *visitado, vert;
    cont = NV = gr->nro_vertices;
    visitado = (int*) malloc(NV * sizeof(int));
    for(i=0; i < NV; i++){
        ant[i] = -1;
        dist[i] = -1;
        visitado[i] = 0;
    }
    dist[ini] = 0;
    while(cont > 0){
        vert = procuraMenorDistancia(dist, visitado, NV);
        if(vert == -1)
            break;

        visitado[vert] = 1;
        cont--;
        for(i=0; i<gr->grau[vert]; i++){
            ind = gr->arestas[vert][i];
            if(dist[ind] < 0){
               dist[ind] = dist[vert] + 1;
               ant[ind] = vert;
            }else{
                if(dist[ind] > dist[vert] + 1){
                    dist[ind] = dist[vert] + 1;
                    ant[ind] = vert;
                }
            }
        }
    }

    free(visitado);
}

void buscaProfundidade(Grafo *gr, int ini, int *visitado, int cont){
    int i;
    visitado[ini] = cont;
    for(i=0; i<gr->grau[ini]; i++){
        if(!visitado[gr->arestas[ini][i]])
            buscaProfundidade(gr,gr->arestas[ini][i],visitado,cont+1);
    }
}
void buscaProfundidade_Grafo(Grafo *gr, int ini, int *visitado){
    int i, cont = 1;
    for(i=0; i<gr->nro_vertices; i++)
        visitado[i] = 0;
    buscaProfundidade(gr,ini,visitado,cont);

    for(i=0; i < gr->nro_vertices; i++)
        printf("%d -> %d\n",i,visitado[i]);
}

void buscaLargura_Grafo(Grafo *gr, int ini, int *visitado){
    int i, vert, NV, cont = 1;
    int *fila, IF = 0, FF = 0;
    for(i=0; i<gr->nro_vertices; i++)
        visitado[i] = 0;

    NV = gr->nro_vertices;
    fila = (int*) malloc(NV * sizeof(int));
    FF++;
    fila[FF] = ini;
    visitado[ini] = cont;
    while(IF != FF){
        IF = (IF + 1) % NV;
        vert = fila[IF];
        cont++;
        for(i=0; i<gr->grau[vert]; i++){
            if(!visitado[gr->arestas[vert][i]]){
                FF = (FF + 1) % NV;
                fila[FF] = gr->arestas[vert][i];
                visitado[gr->arestas[vert][i]] = cont;
            }
        }
    }
    free(fila);
    for(i=0; i < gr->nro_vertices; i++)
        printf("%d -> %d\n",i,visitado[i]);
}

// ALGORITMO PRIM

void algPRIM(Grafo *gr, int orig, int *pai) {
    int i, j, dest, NV = gr->nro_vertices;
    double menorPeso;
    double custo[NV];
    int incluido[NV];

    for (i = 0; i < NV; i++) {
        pai[i] = -1;
        custo[i] = __DBL_MAX__;
        incluido[i] = 0;
    }

    custo[orig] = 0.0; 

    for (int count = 0; count < NV - 1; count++) {
        menorPeso = __DBL_MAX__;
        dest = -1;

        for (i = 0; i < NV; i++) {
            if (incluido[i] == 0 && custo[i] < menorPeso) {
                menorPeso = custo[i];
                dest = i;
            }
        }

        if (dest == -1)
            break;

        incluido[dest] = 1;

        for (j = 0; j < gr->grau[dest]; j++) {
            int vizinho = gr->arestas[dest][j];
            double pesoAresta = gr->pesos[dest][j];

            if (incluido[vizinho] == 0 && pesoAresta < custo[vizinho]) {
                pai[vizinho] = dest;
                custo[vizinho] = pesoAresta;
            }
        }
    }
}

Grafo* constroi_MST(Grafo *gr, int *pai) {
    Grafo *mst = cria_Grafo(gr->nro_vertices, gr->grau_max, gr->eh_ponderado);

    for (int i = 1; i < gr->nro_vertices; i++) {
        if (pai[i] != -1) {
            for (int j = 0; j < gr->grau[pai[i]]; j++) {
                if (gr->arestas[pai[i]][j] == i) {
                    insereAresta(mst, pai[i], i, 0, gr->pesos[pai[i]][j]);
                    break;
                }
            }
        }
    }

    return mst;
}

void imprime_MST(Grafo *mst) {
    if (mst == NULL)
        return;

    int i, j;
    for(i = 0; i < mst->nro_vertices; i++) {
        printf("%d: ", i);
        for(j = 0; j < mst->grau[i]; j++) {
            if (i < mst->arestas[i][j]) {
                if(mst->eh_ponderado)
                    printf("%d(%.2f), ", mst->arestas[i][j], mst->pesos[i][j]);
                else
                    printf("%d, ", mst->arestas[i][j]);
            }
        }
        printf("\n");
    }
}

void imprime_MST_com_paises(Grafo *mst) {
    if (mst == NULL)
        return;

    int i, j;
    for(i = 0; i < mst->nro_vertices; i++) {
        printf("%s: ", nomes_paises[i]);
        for(j = 0; j < mst->grau[i]; j++) {
            if (i < mst->arestas[i][j]) {
                if(mst->eh_ponderado)
                    printf("%s(%.2f), ", nomes_paises[mst->arestas[i][j]], mst->pesos[i][j]);
                else
                    printf("%s, ", nomes_paises[mst->arestas[i][j]]);
            }
        }
        printf("\n");
    }
}

void imprime_MST_com_descricao(Grafo *mst) {
    if (mst == NULL)
        return;

    int i, j;
    for(i = 0; i < mst->nro_vertices; i++) {
        for(j = 0; j < mst->grau[i]; j++) {
            if (i < mst->arestas[i][j]) {
                printf("A distancia do pais %s para o pais %s eh de %.2f\n", 
                       nomes_paises[i], 
                       nomes_paises[mst->arestas[i][j]], 
                       mst->pesos[i][j]);
            }
        }
    }
}
