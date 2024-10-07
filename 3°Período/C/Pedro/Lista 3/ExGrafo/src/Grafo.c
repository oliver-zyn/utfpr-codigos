#include <stdio.h>
#include <stdlib.h>
#include "../include/Grafo.h"

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

void algPRIM(Grafo *gr, int orig, int *pai) {
    int i, j, dest = -1, primeiro, NV = gr->nro_vertices;
    double menorPeso;
    int* visitado = (int*) malloc(NV * sizeof(int));

    for (i = 0; i < NV; i++) {
        pai[i] = -1; // sem pai
        visitado[i] = 0; // todos os vértices não visitados
    }
    pai[orig] = orig;
    visitado[orig] = 1;

    while (1) {
        primeiro = 1;
        menorPeso = __DBL_MAX__;

        // percorre todos os vértices
        for (i = 0; i < NV; i++) {
            // achou vértice já visitado
            if (visitado[i]) {
                // percorre os vizinhos do vértice visitado
                for (j = 0; j < gr->grau[i]; j++) {
                    // procurar menor peso entre os vizinhos ainda não visitados
                    if (!visitado[gr->arestas[i][j]] && (primeiro || gr->pesos[i][j] < menorPeso)) {
                        menorPeso = gr->pesos[i][j];
                        orig = i;
                        dest = gr->arestas[i][j];
                        primeiro = 0;
                    }
                }
            }
        }

        if (primeiro == 1) // não encontrou mais nenhum vértice para visitar
            break;

        pai[dest] = orig;
        visitado[dest] = 1;
    }

    free(visitado);
}

const char* getName(int nome) {
    switch (nome) {
        case 0: return "Maria";
        case 1: return "Viagens";
        case 2: return "Beltrano";
        case 3: return "Tecnologia";
        case 4: return "Investimentos";
        case 5: return "Fulano";
        case 6: return "Futebol";
        case 7: return "Joao";
        case 8: return "Negocios";
        default: return "Vertice desconhecido";
    }
}

void imprimePaiName(int *pai, int n, Grafo *gr) {
    printf("De investimentos menor caminho para todos os vertices:\n\n");
    for (int i = 0; i < n; i++) {
        if (pai[i] != -1) {
            for (int j = 0; j < gr->grau[pai[i]]; j++) {
                if (gr->arestas[pai[i]][j] == i) {
                    printf("De %s para %s o custo eh %.2f\n", getName(pai[i]), getName(i), gr->pesos[pai[i]][j]);
                    break;
                }
            }
        }
    }
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
    if(i == gr->grau[orig])//elemento nao encontrado
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

void imprime_GrafoName(Grafo *gr) {
    if(gr == NULL)
        return;

    int i, j;
    for(i = 0; i < gr->nro_vertices; i++) {
        printf("%s: ", getName(i));  // Usando getName para imprimir o nome do vértice
        for(j = 0; j < gr->grau[i]; j++) {
            if(gr->eh_ponderado)
                printf("%s(%.2f), ", getName(gr->arestas[i][j]), gr->pesos[i][j]);
            else
                printf("%s, ", getName(gr->arestas[i][j]));
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
        //printf("u = %d\n",u);
        if(vert == -1)
            break;

        visitado[vert] = 1;
        cont--;
        for(i=0; i<gr->grau[vert]; i++){
            ind = gr->arestas[vert][i];
            if(dist[ind] < 0){
               dist[ind] = dist[vert] + 1;//ou peso da aresta
               ant[ind] = vert;
            }else{
                if(dist[ind] > dist[vert] + 1){
                    dist[ind] = dist[vert] + 1;//ou peso da aresta
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
// http://en.wikipedia.org/wiki/Breadth-first_search
// http://www.princeton.edu/~achaney/tmve/wiki100k/docs/Breadth-first_search.html

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

