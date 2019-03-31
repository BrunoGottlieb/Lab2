#include <stdio.h>
#include "arvore.h"

int main(){
    Aluno *aluno;
    criaLista(&aluno);

    // CRIACAO DAS ARVORES
    Arvore *arvoreCodigo = criaArvore();
    Arvore *arvoreNome = criaArvore();
    Arvore *arvoreMedia = criaArvore();

    // REDIRECIONAR AO MENU
    menuPrincipal(&aluno, arvoreCodigo, arvoreMedia, arvoreNome);

    return 0;
}

