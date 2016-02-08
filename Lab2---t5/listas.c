#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"

Lista* addL(Lista* l, int codigoX, char nomeX[], float mediaX){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    Lista* p = l;

    novo->codigo = codigoX;
    strcpy(novo->nome, nomeX);
    novo->media = mediaX;
    novo->prox = NULL;

    if(l == NULL)
        return novo;
    else{
        while(p->prox != NULL)
            p = p->prox;
        p->prox = novo;

        return l;
    }
}

Lista* rmvL(Lista* l, int codigoX){
    Lista* p = l;
    Lista* ant = NULL;
    int encontrou = 0;

    while(p != NULL && !encontrou){
        if(codigoX == p->codigo)
            encontrou = 1;
        else{
            ant = p;
            p = p->prox;
        }
    }

    if(p == NULL) // Se a lista é vazia ou não encontrou o elemento
        return l;
    else if(ant == NULL){ // Se o elemento a ser retirado é o primeiro
        ant = l;
        l = l->prox;
        free(ant);
        return l;
    }
    else{
        ant->prox = p->prox;
        free(p);
        return l;
    }
}

void printLista(Lista* l){
    Lista* p;

    system("cls");
    for(p=l; p != NULL; p = p->prox)
        printf("Codigo: %d\nAluno: %sMedia final: %.1f\n\n", p->codigo,p->nome,p->media);

    system("pause");
}
