#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

typedef struct aluno{
    int codigo;
    char nome[20];
    float media;
    Aluno *ant;
    Aluno *prox;
} Aluno;

typedef struct arvore{
    No *raiz;
} Arvore;

typedef struct no{
    No *direita;
    No *esquerda;
    Aluno *aluno;
} No;

void criaLista(Aluno **aluno){
    *aluno = NULL;
}

void criaAluno(int cod, char *nome, float media, Aluno **alunoInicio, Arvore *arvoreCodigo, Arvore *arvoreMedia, Arvore *arvoreNome){
    Aluno *newAluno = (Aluno*)malloc(sizeof(Aluno));
    newAluno->ant = NULL;
    newAluno->codigo = cod;
    newAluno->media = media;
    strcpy(newAluno->nome, nome);
    newAluno->prox = *alunoInicio;

    if(*alunoInicio != NULL) (*alunoInicio)->ant = newAluno;
    *alunoInicio = newAluno;

    insereArvoreCodigo(arvoreCodigo, *alunoInicio, cod);
    insereArvoreMedia(arvoreMedia, *alunoInicio, cod);
    insereArvoreNome(arvoreNome, *alunoInicio, cod);

}

void imprime(Aluno *aluno){
    while(aluno != NULL){
        printf("Nome: %s\tCod: %i\t\tMedia: %.2f\n", aluno->nome, aluno->codigo, aluno->media);
        aluno = aluno->prox;
    }
}

Aluno *buscaAluno(Aluno *aluno, int cod){
    while(aluno != NULL){
        if(aluno->codigo == cod) return aluno;
        aluno = aluno->prox;
    }
    return NULL;
}

int removerArvoreRecursiva(No *noAtual, Aluno *alunoRemover){
    if(alunoRemover == NULL) return 0;
    if(noAtual == NULL) return 0;

    if(noAtual->aluno == alunoRemover && (noAtual->esquerda == NULL || noAtual->direita == NULL)){ // REMOVER ESTE
        return 1;
    }

    int aux = removerArvoreRecursiva(noAtual->esquerda, alunoRemover);
    if(aux == 1){
        No *noRemover = noAtual->esquerda;
        if(noRemover->aluno != alunoRemover) return 1;

        if(noRemover->esquerda == NULL && noRemover->direita == NULL){
            free(noRemover);
            noAtual->esquerda = NULL;
        }else if(noRemover->esquerda != NULL){
            noAtual->esquerda = noRemover->esquerda;
            free(noRemover);
        }else if(noRemover->direita != NULL){
            noAtual->esquerda = noRemover->direita;
            free(noRemover);
        }
        return 1;
    }

    aux = removerArvoreRecursiva(noAtual->direita, alunoRemover);
    if(aux == 1){
        No *noRemover = noAtual->direita;

        if(noRemover->aluno != alunoRemover) return 1;

        if(noRemover->esquerda == NULL && noRemover->direita == NULL){
            free(noRemover);
            noAtual->direita = NULL;
        }else if(noRemover->esquerda != NULL){
            noAtual->direita = noRemover->esquerda;
            free(noRemover);
        }else if(noRemover->direita != NULL){
            noAtual->direita = noRemover->direita;
            free(noRemover);
        }
        return 1;
    }
    return 0;

}

void removerRaiz(Arvore *arvore){
    No *raiz = arvore->raiz;
    if(raiz == NULL) return;

    if(raiz->esquerda == NULL){ // SE A ESQUERDA ESTA VAZIA, BASTA PASSAR A DIREITA COMO RAIZ
        arvore->raiz = arvore->raiz->direita;
        free(raiz);
        return;
    }
    if(raiz->direita == NULL){ // SE A DIREITA ESTA VAZIA, BASTA PASSAR A ESQUERDA COMO RAI
        arvore->raiz = arvore->raiz->esquerda;
        free(raiz);
        return;
    }

    No *novaRaiz = raiz->esquerda; // INICIA A BUSCA PELA NOVA RAIZ
    No *ant = NULL;
    while(novaRaiz->direita != NULL){ // BUSCA O VALOR MAIS PROXIMO A RAIZ, PELA ESQUERDA-DIREITA
        ant = novaRaiz; // ANTERIOR A NOVA RAIZ
        novaRaiz = novaRaiz->direita;
    }
    if(novaRaiz->esquerda != NULL && ant != NULL){ // VERIFICA SE A NOVA RAIZ TEM FILHOS A ESQUERDA
        ant->direita = novaRaiz->esquerda; // SE EXISTE ANTERIOR, PASSA A ESQUERDA PARA DIREITA DO ANTERIOR
    } // SENAO MANTEM A MESMA ORDEM DOS FILHOS

    arvore->raiz = novaRaiz;
    free(raiz);
}


void remover(Aluno **alunoInicio, int cod, Arvore *arvoreCodigo, Arvore *arvoreMedia, Arvore *arvoreNome){
    Aluno *alunoRemover = buscaAluno(*alunoInicio, cod);
    if(alunoRemover == NULL){
        printf("\nAluno nao encontrado.\n");
        return;
    }

    if(arvoreCodigo->raiz->aluno != alunoRemover) removerArvoreRecursiva(arvoreCodigo->raiz, alunoRemover);
    else{
        removerRaiz(arvoreCodigo);
    }

    if(arvoreMedia->raiz->aluno != alunoRemover) removerArvoreRecursiva(arvoreMedia->raiz, alunoRemover);
    else{
        removerRaiz(arvoreMedia);
    }


    if(arvoreNome->raiz->aluno != alunoRemover) removerArvoreRecursiva(arvoreNome->raiz, alunoRemover);
    else{
        removerRaiz(arvoreNome);
    }


    if(alunoRemover == *alunoInicio) *alunoInicio = alunoRemover->prox;
    else alunoRemover->ant->prox = alunoRemover->prox;

    if(alunoRemover->prox != NULL) alunoRemover->prox->ant = alunoRemover->ant;
    free(alunoRemover);

}

Arvore *criaArvore(){
    Arvore *newArvore = (Arvore*)malloc(sizeof(Arvore));
    newArvore->raiz = NULL;
    return newArvore;
}

No *criaNo(Aluno *aluno, int cod){
    Aluno *alunoInserir = buscaAluno(aluno, cod);
    if(alunoInserir == NULL){
        printf("Nao foi possivel encontrar o aluno\n");
        return NULL;
    }

    No *newNo = (No*)malloc(sizeof(No));

    newNo->direita = NULL;
    newNo->esquerda = NULL;
    newNo->aluno = alunoInserir;

    return newNo;
}

        // ARVORE DE CODIGOS
void insereArvoreCodigoRecursiva(No *noPai, No *no){
    if(no->aluno->codigo == noPai->aluno->codigo){
        printf("\nCodigo duplicado. Aluno nao inserido na arvore de codigos.\n");
        return;
    }

    if(no->aluno->codigo < noPai->aluno->codigo){
        if(noPai->esquerda == NULL) noPai->esquerda = no;
        else insereArvoreCodigoRecursiva(noPai->esquerda, no);
    }else{
        if(noPai->direita == NULL) noPai->direita = no;
        else insereArvoreCodigoRecursiva(noPai->direita, no);
    }
}
void insereArvoreCodigo(Arvore *arvoreCodigo, Aluno *aluno, int codAluno){

    No *no = criaNo(aluno, codAluno);
    if(no == NULL){
        printf("No nulo\n");
        return;
    }
    if(arvoreCodigo->raiz == NULL) arvoreCodigo->raiz = no;
    else{
        insereArvoreCodigoRecursiva(arvoreCodigo->raiz, no);
    }
}

        // ARVORE DE MEDIAS
void insereArvoreMediaRecursiva(No *noPai, No *no){
    if(no->aluno->media == noPai->aluno->media){
        printf("\nMedia duplicada. Aluno nao inserido na arvore de medias.\n");
        return;
    }

    if(no->aluno->media < noPai->aluno->media){
        if(noPai->esquerda == NULL) noPai->esquerda = no;
        else insereArvoreMediaRecursiva(noPai->esquerda, no);
    }else{
        if(noPai->direita == NULL) noPai->direita = no;
        else insereArvoreMediaRecursiva(noPai->direita, no);
    }
}
void insereArvoreMedia(Arvore *arvoreMedia, Aluno *aluno, int codAluno){
    No *no = criaNo(aluno, codAluno);
    if(no == NULL){
        printf("No nulo\n");
        return;
    }
    if(arvoreMedia->raiz == NULL) arvoreMedia->raiz = no;
    else{
        insereArvoreMediaRecursiva(arvoreMedia->raiz, no);
    }
}

       // ARVORE DE NOMES
void insereArvoreNomeRecursiva(No *noPai, No *no){

    if(strcmp(no->aluno->nome, noPai->aluno->nome)== 0){
        printf("\nNome duplicado. Aluno nao inserido na arvore de nomes.\n");
        return;
    }
    int n1 = no->aluno->nome[0];
    int n2 = noPai->aluno->nome[0];

    if(n1 < n2){
        if(noPai->esquerda == NULL) noPai->esquerda = no;
        else insereArvoreNomeRecursiva(noPai->esquerda, no);
    }else{
        if(noPai->direita == NULL) noPai->direita = no;
        else insereArvoreNomeRecursiva(noPai->direita, no);
    }
}
void insereArvoreNome(Arvore *arvoreNome, Aluno *aluno, int codAluno){
    No *no = criaNo(aluno, codAluno);
    if(no == NULL){
        printf("No nulo\n");
        return;
    }
    if(arvoreNome->raiz == NULL){
        arvoreNome->raiz = no;
    }else{
        insereArvoreNomeRecursiva(arvoreNome->raiz, no);
    }
}

void imprimeArvore(Arvore *arvoreGeral){
    No *raiz = arvoreGeral->raiz;
    imprimeArvoreRecursiva(raiz);
}

void imprimeArvoreRecursiva(No *atual){
    if(atual == NULL) return;

    imprimeArvoreRecursiva(atual->esquerda);
    printf("Nome: %s\tCod: %i\t\tMedia: %.2f\n",atual->aluno->nome,atual->aluno->codigo,atual->aluno->media);
    imprimeArvoreRecursiva(atual->direita);
}

void menuPrincipal(Aluno **aluno, Arvore *arvoreCodigo, Arvore *arvoreMedia, Arvore *arvoreNome){
    int opt;
    do{
        system("CLS");
        printf("\t------  MENU -------\n");
        printf("1 - Adicionar alunos\n");
        printf("2 - Excluir alunos\n");
        printf("3 - Exibir dados dos alunos (lista)\n");
        printf("4 - Exibir dados ordenados pelo codigo\n");
        printf("5 - Exibir dados ordenados pela media\n");
        printf("6 - Exibir dados ordenados pelo nome\n");
        printf("7 - Sair do programa\n");
        printf("\n\nOpcao: ");
        scanf("%i", &opt);
    }while(opt<1 || opt>7);

    switch (opt){
        case 1:
            system("CLS");
            printf("\t--- ADICIONAR ALUNO ---");
            char nome[20];
            int cod;
            float media;
            printf("\nNome do aluno: ");
            scanf("%s", nome);
            printf("Codigo: ");
            scanf("%i", &cod);
            printf("Media: ");
            scanf("%f", &media);

            criaAluno(cod, nome, media, aluno, arvoreCodigo, arvoreMedia, arvoreNome);
            system("pause");
            break;
        case 2:
            system("CLS");
            printf("\t--- REMOVER ALUNO ---");
            int codR;
            printf("\nCodigo do aluno: ");
            scanf("%i", &codR);

            remover(aluno, codR, arvoreCodigo, arvoreMedia, arvoreNome);
            system("pause");
            break;
        case 3:
            system("CLS");
            printf("\t--- ALUNOS ---\n");
            imprime(*aluno);
            printf("\n");
            system("pause");
            break;
        case 4:
            system("CLS");
            printf("\t--- ALUNOS ORDENADOS POR CODIGO ---\n");
            imprimeArvore(arvoreCodigo);
            printf("\n");
            system("pause");
            break;
        case 5:
            system("CLS");
            printf("\t--- ALUNOS ORDENADOS POR MEDIA ---\n");
            imprimeArvore(arvoreMedia);
            printf("\n");
            system("pause");
            break;
        case 6:
            system("CLS");
            printf("\t--- ALUNOS ORDENADOS POR NOME ---\n");
            imprimeArvore(arvoreNome);
            printf("\n");
            system("pause");
            break;
        case 7:
            exit(0);
    }

    menuPrincipal(aluno, arvoreCodigo, arvoreMedia, arvoreNome);

}
