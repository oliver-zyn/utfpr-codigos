typedef struct oliver Oliver;
typedef struct celula Celula;
typedef struct pilha Pilha;

Pilha * criaPilhaVazia();
int verificaPilhaVazia(Pilha *p);
void empilha(Pilha *p, int chave, char nomeEmpresa[], char areaAtuacao[], float descontoAssociados);
void imprimePilha(Pilha *p);
void desempilha(Pilha *p);
void liberaPilha(Pilha *p);