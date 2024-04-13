typedef struct oliver Oliver;
typedef struct celula Celula;
typedef struct fila Fila;
typedef struct data Data;

Fila * criaFilaVazia();

int verificaFilaVazia(Fila *f);

void enfileira(Fila *f, int idAtleta, int dia, int mes, int ano, float kmPercorridos, char rota[]);

void imprimeFila(Fila *f);

void desenfileira(Fila *f);

void liberaFila(Fila *f);

float calculaTotalKmPercorridosMes(Fila * f, int mes);