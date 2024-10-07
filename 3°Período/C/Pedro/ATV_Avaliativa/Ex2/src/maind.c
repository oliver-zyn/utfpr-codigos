



void insereOrdenado(Lista *lst, int chave, int idadeMinima, char nome[], char descricao[], char linkAcesso[]) {
    Celula *aux = malloc(sizeof(Celula));
    
    if (verificaListaVazia(lst) || idadeMinima < lst->primeira->jogo.idadeMinima) {
        insereInicioLista(lst, chave, idadeMinima, nome, descricao, linkAcesso);
        return;
    }
    
    Celula *atual = lst->primeira;
    Celula *anterior = NULL;
    
    while (atual != NULL && atual->jogo.idadeMinima < idadeMinima) {
        anterior = atual;
        atual = atual->prox;
    }
    
    aux->prox = atual;
    
    if (anterior != NULL) {
        anterior->prox = aux;
    } else {
        lst->primeira = aux; // Atualiza o início da lista se o novo item for o primeiro
    }
    
    if (atual == NULL) {
        insereFimLista(lst, chave, idadeMinima, nome, descricao, linkAcesso);
    }
}

void insereOrdenado(Lista *lst, int chave, int idadeMinima, char nome[], char descricao[], char linkAcesso[]) {
    if (verificaListaVazia(lst) || lst->primeira->jogo.idadeMinima > idadeMinima) {
        insereInicioLista(lst, chave, idadeMinima, nome, descricao, linkAcesso);
        return;
    }
    
    Celula *atual = lst->primeira;
    Celula *anterior = NULL;
    
    while (atual != NULL && atual->jogo.idadeMinima < idadeMinima) {
        anterior = atual;
        atual = atual->prox;
    }
    
    Celula *nova = malloc(sizeof(Celula));
    nova->jogo.chave = chave;
    nova->jogo.idadeMinima = idadeMinima;
    strcpy(nova->jogo.nome, nome);
    strcpy(nova->jogo.descricao, descricao);
    strcpy(nova->jogo.linkAcesso, linkAcesso);
    
    nova->prox = atual;
    
    if (anterior != NULL) {
        anterior->prox = nova;
    } else {
        lst->primeira = nova; // Atualiza o início da lista se o novo item for o primeiro
    }
    
    if (atual == NULL) {
        insereFimLista(lst, chave, idadeMinima, nome, descricao, linkAcesso);
    }
}
