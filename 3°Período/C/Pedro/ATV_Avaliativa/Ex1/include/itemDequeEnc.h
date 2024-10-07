typedef struct item Item;
typedef struct celula Celula;
typedef struct deque Deque;

Deque* cria_Deque();
void libera_Deque(Deque* dq);
int verificaDequeVazia(Deque* dq);
void insereFinal_Deque(Deque* dq, int chave, int pagina, char titulo[], char descricao[], char classificacao[], char autor[]);
void insereInicio_Deque(Deque* dq, int chave, int pagina, char titulo[], char descricao[], char classificacao[], char autor[]);
void removeInicio_Deque(Deque* dq);
int removeFinal_Deque(Deque* dq);
void imprime_Deque(Deque* dq);
float totalQtdNot(Deque *dq);
void numNot(Deque *dq);
void porcentagemNot(Deque *dq);
float numDeNotPorClass(Deque *dq, char class[]);



