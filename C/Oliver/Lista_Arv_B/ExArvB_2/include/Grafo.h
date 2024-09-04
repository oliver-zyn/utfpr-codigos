typedef struct grafo Grafo;

Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado);
void libera_Grafo(Grafo* gr);
int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso);
int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo);

void imprime_Grafo(Grafo *gr);
void buscaProfundidade_Grafo(Grafo *gr, int ini, int *visitado);
void buscaLargura_Grafo(Grafo *gr, int ini, int *visitado);
void menorCaminho_Grafo(Grafo *gr, int ini, int *antecessor, float *distancia);

void algPRIM(Grafo *gr, int orig, int *pai);
Grafo* constroi_MST(Grafo *gr, int *pai);
void imprime_MST(Grafo *mst);
void imprime_MST_com_paises(Grafo *mst);
void imprime_MST_com_descricao(Grafo *mst);