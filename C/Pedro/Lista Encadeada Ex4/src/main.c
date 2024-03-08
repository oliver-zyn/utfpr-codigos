#include <stdio.h>
#include <string.h>
#include "../include/itemListaEnc.h"

int main(int argc, char const *argv[]) {

    Lista *agenda = criaListaVazia();

    for(int i = 1; i <= 4; i++) {
        int chave = 0;
        char nome[100] = "", email[100] = "", telefone[100] = "";

        printf("Informe a chave que deseja atribuir a %d pessoa da agenda:\n", i);
        scanf("%d", &chave);
        fflush(stdin);

        printf("Informe o nome que deseja atribuir a %d pessoa da agenda:\n", i);
        gets(nome);
        fflush(stdin);

        printf("Informe o email que deseja atribuir a %d pessoa da agenda:\n", i);
        gets(email);
        fflush(stdin);

        printf("Informe o telefone que deseja atribuir a %d pessoa da agenda:\n", i);
        gets(telefone);
        fflush(stdin);

        insereFimLista(agenda, chave, nome, telefone, email);
    }

    imprimeLista(agenda);
    printf("\n-------------------\n");

    removePessoa(agenda, 2);

    imprimeLista(agenda);

    return 0;
}
