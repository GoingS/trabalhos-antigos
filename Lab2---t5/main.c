#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <string.h>
#include "listas.h"
#include "arvores.h"
#include "menu.h"

int main(){
    char op;
    Lista* listaAlunos = NULL;
    Arvore* ArvoreCodigo = NULL;
    Arvore* ArvoreNome = NULL;
    Arvore* ArvoreMedia = NULL;

    ///*
    listaAlunos = addL(listaAlunos, 5, "ADeise\n", 8.2);
    listaAlunos = addL(listaAlunos, 1, "BMaria\n", 6.1);
    listaAlunos = addL(listaAlunos, 10, "DJoao\n", 4.9);
    listaAlunos = addL(listaAlunos, 12, "CPaulo\n", 5.8);


    do{
        system("cls");
        printf("Digite: \n");
        printf("1 - Adicionar alunos;\n");
        printf("2 - Remover alunos;\n");
        printf("3 - Mostrar lista de alunos;\n");
        printf("4 - Mostrar arvore ordenada por codigo;\n");
        printf("5 - Mostrar arvore ordenada por nome;\n");
        printf("6 - Mostrar arvore ordenada por media\n");
        printf("0 - Sair\n\n");
        op = getch();

        switch(op){
            case '1':
                listaAlunos = adicionar_aluno(listaAlunos);
            break;

            case '2':
                listaAlunos = remover_aluno(listaAlunos);
            break;

            case '3':
                printLista(listaAlunos);
            break;

            case '4':
                ArvoreCodigo = atualizarArvoreDeCodigo(ArvoreCodigo, listaAlunos);
                system("cls");
                printf("Arvore ordenada por codigo:\n\n\n");
                printArvore(ArvoreCodigo);
                system("pause");
            break;

            case '5':
                ArvoreNome = atualizarArvoreDeNome(ArvoreNome, listaAlunos);
                system("cls");
                printf("Arvore ordenada por nome:\n\n\n");
                printArvore(ArvoreNome);
                system("pause");
            break;

            case '6':
                ArvoreMedia = atualizarArvoreDeMedia(ArvoreMedia, listaAlunos);
                system("cls");
                printf("Arvore ordenada por media:\n\n\n");
                printArvore(ArvoreMedia);
                system("pause");
            break;

        }
    } while(op != '0');
    //*/
    return 0;
}
