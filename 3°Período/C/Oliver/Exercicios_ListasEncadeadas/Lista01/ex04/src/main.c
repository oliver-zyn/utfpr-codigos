#include <stdio.h>
#include "../include/itemListaEnc.h"

int main()
{
    Lista *lst = criaListaVazia();

    insereInicioLista(lst, 1, "oliver", "contatoOliver", "2313213213", "oliver@gmail.com");
    insereFimLista(lst, 2, "joao", "contatoJoao", "0859374832", "joao@gmail.com");
    insereMeioLista(lst, 3, "pedro", "contatoPedro", "0398493284", "pedro@gmail.com", 2);
    insereInicioLista(lst, 4, "carlos", "contatoCarlos", "97387584823", "carlos@gmail.com");

    printf("\nMinha lista v1: \n");
    imprimeLista(lst);

    removeItem(lst, 2);

    printf("\nMinha lista v2: \n");
    imprimeLista(lst);

    return 0;
}
