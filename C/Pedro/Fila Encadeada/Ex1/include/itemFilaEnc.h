typedef struct item Item;
typedef struct celula Celula;
typedef struct fila Fila;

Fila *criaFilaVazia();
int verificaFilaVazia(Fila *f);
void enfileira(Fila *f, int chave);
void imprimeFila(Fila *f);
void desenfleira(Fila *f);
void liberaFila(Fila *f);
int verificaFilaOrdenada(Fila *f);