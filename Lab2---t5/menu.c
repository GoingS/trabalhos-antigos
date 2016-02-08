#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

Lista* adicionar_aluno(Lista* l){
    char nome[20];
    int codigo;
    int jaExiste = 0;
    float media;
    Lista* p = l;

    system("cls");
    printf("Adicionando aluno\n\n\nDigite o codigo: ");
    fflush(stdin);
    scanf("%d", &codigo);

    while(p != NULL){
        if(codigo == p->codigo)
            jaExiste = 1;
        p = p->prox;
    }
    if(jaExiste)
        printf("Codigo ja existente\n\n\n");
    else{
        printf("\nDigite o nome: ");
        fflush(stdin);
        fgets(nome, 20, stdin);
        fflush(stdin);
        printf("\nDigite a media: ");
        scanf("%f", &media);

        printf("\n\n\nAluno adicionado.\n\n\n");
        l = addL(l, codigo, nome, media);
    }

    system("pause");
    return l;
}

Lista* remover_aluno(Lista* l){
    int codigo;
    int encontrou = 0;
    Lista* p = l;

    system("cls");
    printf("Removendo aluno:\n\n\nDigite o codigo do aluno: ");
    fflush(stdin);
    scanf("%d", &codigo);

    while(p != NULL && !encontrou){
        if(p->codigo == codigo)
            encontrou = 1;
        else
            p = p->prox;
    }
    if(encontrou){
        printf("\nAluno removido %s\n\n\n", p->nome);
        l = rmvL(l, codigo);
    }
    else
        printf("\nAluno nao encontrado\n\n\n");

    system("pause");
    return l;
}
