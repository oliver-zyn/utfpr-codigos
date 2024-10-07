typedef struct jogo Jogo;
typedef struct celula Celula;
typedef struct lista Lista;

Lista *criaListaVazia();
int verificaListaVazia(Lista *lst);
void buscaPorNome(Lista *lst, char nome[]);
Celula* buscaPorChave(Lista * lst, int chave);
void imprimeLista(Lista *lst);
void insereInicioLista(Lista *lst, int chave, int idadeMinima, char nome[], char descricao[], char linkAcesso[]);
void insereFimLista(Lista *lst, int chave, int idadeMinima, char nome[], char descricao[], char linkAcesso[]);
void insereMeioLista(Lista *lst, int chave, int idadeMinima, char nome[], char descricao[], char linkAcesso[], int x);
void removeItemPorNome(Lista *lst, char nome[]);
void removeItem(Lista *lst, int x);
void liberaLista(Lista *lst);

void insereOrdenado(Lista *lst, int chave, int idadeMinima, char nome[], char descricao[], char linkAcesso[]);