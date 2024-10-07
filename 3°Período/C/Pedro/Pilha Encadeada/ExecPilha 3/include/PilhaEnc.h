
typedef struct pilha Pilha;
typedef struct celula Celula;
typedef struct pedro Pedro;

Pilha *criaPilhaVazia();
void empilha(Pilha *p, int chave, char nome_emp[], char atuacao[], float desconto);
void imprimePilha(Pilha *p);
int verificaPilhaVazia(Pilha *p);
void desempilha(Pilha *p);
void liberaPilha(Pilha *p);