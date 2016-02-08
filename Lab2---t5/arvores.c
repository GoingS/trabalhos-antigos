#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvores.h"

Arvore* addA(Arvore* a, Arvore* sae, Arvore* sad, int codigoX, char nomeX[], float mediaX){
    Arvore* novo = (Arvore*) malloc(sizeof(Arvore));
    novo->codigo = codigoX;
    strcpy(novo->nome, nomeX);
    novo->media = mediaX;

    novo->esq = sae;
    novo->dir = sad;
    return novo;
}

Arvore* rmvA(Arvore* a){
    if(a != NULL){
        rmvA(a->esq);
        rmvA(a->dir);
        free(a);
    }
    return NULL;
}

void printArvore(Arvore* a){
    if(a != NULL){
        printf("Codigo: %d\nAluno: %sMedia final: %.1f\n\n", a->codigo,a->nome,a->media);
        printArvore(a->esq);
        printArvore(a->dir);
    }
}

Arvore* adicionarArvoreDeCodigo(Arvore* l, int codigoX, char nomeX[], float mediaX){
    if(l == NULL)
        l =  addA(l, NULL, NULL, codigoX, nomeX, mediaX);
    else if(codigoX < l->codigo){
        if(l->esq == NULL)
            l->esq = addA(l->esq, NULL, NULL, codigoX, nomeX, mediaX);
        else
            l->esq = adicionarArvoreDeCodigo(l->esq, codigoX, nomeX, mediaX);
    }
    else{
        if(l->dir == NULL)
            l->dir = addA(l->dir, NULL, NULL, codigoX, nomeX, mediaX);
        else
            l->dir = adicionarArvoreDeCodigo(l->dir, codigoX, nomeX, mediaX);
    }

    return l;
}

Arvore* adicionarArvoreDeNome(Arvore* l, int codigoX, char nomeX[], float mediaX){
    if(l == NULL)
        l =  addA(l, NULL, NULL, codigoX, nomeX, mediaX);
    else if(strcmp(nomeX, l->nome) == -1){
        if(l->esq == NULL)
            l->esq = addA(l->esq, NULL, NULL, codigoX, nomeX, mediaX);
        else
            l->esq = adicionarArvoreDeNome(l->esq, codigoX, nomeX, mediaX);
    }
    else{
        if(l->dir == NULL)
            l->dir = addA(l->dir, NULL, NULL, codigoX, nomeX, mediaX);
        else
            l->dir = adicionarArvoreDeNome(l->dir, codigoX, nomeX, mediaX);
    }

    return l;
}

Arvore* adicionarArvoreDeMedia(Arvore* l, int codigoX, char nomeX[], float mediaX){
    if(l == NULL)
        l =  addA(l, NULL, NULL, codigoX, nomeX, mediaX);
    else if(mediaX < l->media){
        if(l->esq == NULL)
            l->esq = addA(l->esq, NULL, NULL, codigoX, nomeX, mediaX);
        else
            l->esq = adicionarArvoreDeMedia(l->esq, codigoX, nomeX, mediaX);
    }
    else{
        if(l->dir == NULL)
            l->dir = addA(l->dir, NULL, NULL, codigoX, nomeX, mediaX);
        else
            l->dir = adicionarArvoreDeMedia(l->dir, codigoX, nomeX, mediaX);
    }

    return l;
}
