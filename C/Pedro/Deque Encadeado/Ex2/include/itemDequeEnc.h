typedef struct item Item;
typedef struct celula Celula;
typedef struct deque Deque;

Deque* cria_Deque();
void libera_Deque(Deque* dq);
int verificaDequeVazia(Deque* dq);
void insereFinal_Deque(Deque* dq, int chave, int qtd);
void insereInicio_Deque(Deque* dq, int chave, int qtd);
void removeInicio_Deque(Deque* dq);
int removeFinal_Deque(Deque* dq);
void imprime_Deque(Deque* dq);
void implementaQtdArvore(Deque *dq, int chaveArvore);
int totalQtdArvore(Deque *dq);
void imprimePorcentagemPorEspecie(Deque *dq);
int codMaisFrequente(Deque *dq);



