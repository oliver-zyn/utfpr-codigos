typedef struct item Item;
typedef struct celula Celula;
typedef struct lista Lista;

Lista *criaListaVazia();
int verificaListaVazia(Lista *lst);
Celula* buscaPorChave(Lista *lst, int chave);
void imprimeLista(Lista *lst);
void insereInicioLista(Lista *lst, int chave);
void insereFimLista(Lista *lst, int chave);
void insereMeioLista(Lista *lst, int chave, int x);
void removeItem(Lista *lst, int x);
void liberaLista(Lista *lst);

Lista *concatenacaoDeLista(Lista *lst1, Lista *lst2);