#include <stdio.h>
#include "../include/pilhaEnc.h"

int main(int argc, char const *argv[])
{
    Pilha *p1 = criaPilhaVazia();

    empilha(p1, 1, "Netflix", "Streaming", 0.10);
    empilha(p1, 2, "Spotify", "Musica", 0.20);
    empilha(p1, 3, "Rocketseat", "Educacao", 0.10);

    imprimePilha(p1);

    liberaPilha(p1);

    return 0;
}
