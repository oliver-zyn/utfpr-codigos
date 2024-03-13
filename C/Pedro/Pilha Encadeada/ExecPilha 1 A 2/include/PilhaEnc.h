
typedef struct pilha Pilha;
typedef struct celula Celula;
typedef struct item Item;

Pilha *criaPilhaVazia();
void empilha(Pilha *p, int chave);
void imprimePilha(Pilha *p);
int verificaPilhaVazia(Pilha *p);
void desempilha(Pilha *p);
void liberaPilha(Pilha *p);
void parImpar(Pilha *p1, Pilha *pP, Pilha *pI);
void semDuplicadas(Pilha *p1, Pilha *p2);