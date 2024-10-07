typedef struct item Item;
typedef struct celula Celula;
typedef struct deque Deque;

Deque* cria_Deque();
void libera_Deque(Deque* dq);
int verificaDequeVazia(Deque* dq);
void insereFinal_Deque(Deque* dq, int cod_especie, int qtd);
void insereInicio_Deque(Deque* dq, int cod_especie, int qtd);
void removeInicio_Deque(Deque* dq);
int removeFinal_Deque(Deque* dq);
void imprime_Deque(Deque* dq);

void atualizaDequeArvores(Deque *dq, int cod_especie);
void imprimePorcentagemEspecie(Deque *dq);
int qtdTotalArvores(Deque *dq);
int codEspecieMaisFrequente(Deque *dq);
