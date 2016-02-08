#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"
#include "arvores.h"
#include "atualizarArvores.h"

Arvore* atualizarArvoreDeCodigo(Arvore* a, Lista* alunos){
    Lista* p = alunos;

    a = rmvA(a);
    while(p != NULL){
        a = adicionarArvoreDeCodigo(a, p->codigo, p->nome, p-> media);
        p = p->prox;
    }

    return a;
}

Arvore* atualizarArvoreDeNome(Arvore* a, Lista* alunos){
    Lista* p = alunos;

    a = rmvA(a);
    while(p != NULL){
        a = adicionarArvoreDeNome(a, p->codigo, p->nome, p-> media);
        p = p->prox;
    }

    return a;
}

Arvore* atualizarArvoreDeMedia(Arvore* a, Lista* alunos){
    Lista* p = alunos;

    a = rmvA(a);
    while(p != NULL){
        a = adicionarArvoreDeMedia(a, p->codigo, p->nome, p-> media);
        p = p->prox;
    }

    return a;
}
