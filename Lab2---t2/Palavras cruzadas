#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int vetToMat(int m, int n, int altura){
    return n+m*altura;
}

void printMat(char* mat, int m, int n){
    int i, j;

    for(j=0;j<n+2;j++)
        printf("* ");
    printf("\n");

    for(i=0;i<m;i++){
        printf("* ");
        for(j=0;j<n;j++)
            printf("%c ",mat[vetToMat(i,j,m)]);
        printf("*");
        printf("\n");
    }

    for(j=0;j<n+2;j++)
        printf("* ");
    printf("\n");


}

void inicializarMat(char* mat, int m, int n, char ch){
    int i,j;

    if(ch == '*')
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                mat[vetToMat(i,j,m)] = 'a' + rand()%26;
    else
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                mat[vetToMat(i,j,m)] = ch;

}

void inserirPalavras(char* mat, int m, int n, char palavras[][10]){
    char* ocupadas = malloc(sizeof(char)*m*n);
    int estado, ocupado = 0; /* estado: 0 e 1 para vertical, 2 e 3, horizontal e 4 e 5 diagonal */
    int i,j;
    int x,y;
    int numPal;

    inicializarMat(ocupadas, m, n, ' ');

    numPal = (int) ((m+n)/4);
    if (numPal > 9)
        numPal = 9;
    for(i=0; i<numPal; i++){
        estado = rand()%6;
        ocupado = 1;


        switch(estado){
            case 0:
                while(ocupado){
                    ocupado = 0;
                    x = rand()%n;
                    y = rand()%(m - strlen(palavras[i]));

                    for(j=0;j<strlen(palavras[i]);j++)
                        if(ocupadas[vetToMat(y+j,x,m)] == '-')
                            ocupado = 1;
                }

                for(j=0;j<strlen(palavras[i]);j++){
                    mat[vetToMat(y+j,x,m)] = palavras[i][j];
                    ocupadas[vetToMat(y+j,x,m)] = '-';
                }

            break;


            case 1:
                while(ocupado){
                    ocupado = 0;
                    x = rand()%n;
                    y = m - 1 - rand()%(m - strlen(palavras[i]));

                    for(j=0;j<strlen(palavras[i]);j++)
                        if(ocupadas[vetToMat(y-j,x,m)] == '-')
                            ocupado = 1;
                }

                for(j=0;j<strlen(palavras[i]);j++){
                    mat[vetToMat(y-j,x,m)] = palavras[i][j];
                    ocupadas[vetToMat(y-j,x,m)] = '-';
                }

                break;


            case 2:
                while(ocupado){
                    ocupado = 0;
                    x = rand()%(n - strlen(palavras[i]));
                    y = rand()%m;

                    for(j=0;j<strlen(palavras[i]);j++)
                        if(ocupadas[vetToMat(y,x+j,m)] == '-')
                            ocupado = 1;
                }
                for(j=0;j<strlen(palavras[i]);j++){
                    mat[vetToMat(y,x+j,m)] = palavras[i][j];
                    ocupadas[vetToMat(y,x+j,m)] = '-';
                }
            break;


            case 3:

                while(ocupado){
                    ocupado = 0;
                    x = n - 1 - rand()%(n - strlen(palavras[i]));
                    y = rand()%m;

                    for(j=0;j<strlen(palavras[i]);j++)
                        if(ocupadas[vetToMat(y,x-j,m)] == '-')
                            ocupado = 1;
                }
                for(j=0;j<strlen(palavras[i]);j++){            /* Horizontal invertida*/
                    mat[vetToMat(y,x-j,m)] = palavras[i][j];
                    ocupadas[vetToMat(y,x-j,m)] = '-';
                }
            break;

            case 4:
                while(ocupado){
                    ocupado = 0;
                    x = rand()%(n - strlen(palavras[i]));
                    y = rand()%(m - strlen(palavras[i]));

                    for(j=0;j<strlen(palavras[i]);j++)
                        if(ocupadas[vetToMat(y+j,x+j,m)] == '-')
                            ocupado = 1;
                }

                for(j=0;j<strlen(palavras[i]);j++){
                    mat[vetToMat(y+j,x+j,m)] = palavras[i][j];
                    ocupadas[vetToMat(y+j,x+j,m)] = '-';
                }
            break;

            case 5:
                while(ocupado){
                    ocupado = 0;
                    x = n - 1 - rand()%(n - strlen(palavras[i]));
                    y = m - 1 - rand()%(m - strlen(palavras[i]));

                    for(j=0;j<strlen(palavras[i]);j++)
                        if(ocupadas[vetToMat(y-j,x-j,m)] == '-')
                            ocupado = 1;
                }
                for(j=0;j<strlen(palavras[i]);j++){
                    mat[vetToMat(y-j,x-j,m)] = palavras[i][j];
                    ocupadas[vetToMat(y-j,x-j,m)] = '-';
                }
            break;
        }

    }

}



int busca(char* mat, int m, int n, char* palavra, char palavras[][10], char encontradas[][10]){
    int i,j,k;
    int tam = strlen(palavra), numPal;
    int encontrouVN = 0, encontrouVI = 0;
    int encontrouHN = 0, encontrouHI = 0;
    int encontrouDN = 0, encontrouDI = 0;
    int existe = 0;

    for(i=0;i<9;i++){
        if(strcmp (palavra, palavras[i]) == 0) /*verifica se a palavra esta na lista */
            existe = 1;
    }
    if(!existe){
        printf("Palavra nao encontrada :(\n\n");
        return 0;
    }

    numPal = (int)((m+n)/4);
    if(numPal > 9)
        numPal = 9;
    for(i=0;i<numPal;i++){
        if(strcmp(palavra, encontradas[i]) == 0){   /* se ja foi encontrada */
            printf("Palavra ja encontrada\n\n");
            return 0;
        }
    }

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if((mat[vetToMat(i,j,n)] == palavra[0]) && (!encontrouVN || !encontrouVI ||
                                                        !encontrouHN || !encontrouHI ||
                                                        !encontrouDN || !encontrouDI))
            {
                encontrouVN = 1;
                encontrouVI = 1;
                encontrouHN = 1;
                encontrouHI = 1;
                encontrouDN = 1;
                encontrouDI = 1;
                for(k=0;k<tam;k++){
                    if(mat[vetToMat(i+k,j,n)] != palavra[k])
                        encontrouVN = 0;
                    if(mat[vetToMat(i-k,j,n)] != palavra[k])
                        encontrouVI = 0;
                    if(mat[vetToMat(i,j+k,n)] != palavra[k])
                        encontrouHN = 0;
                    if(mat[vetToMat(i,j-k,n)] != palavra[k])
                        encontrouHI = 0;
                    if(mat[vetToMat(i+k,j+k,n)] != palavra[k])
                        encontrouDN = 0;
                    if(mat[vetToMat(i-k,j-k,n)] != palavra[k])
                        encontrouDI = 0;
                }  /* verifica se encontrou em algum sentido */
                if(encontrouVN){
                    printf("Encontrou %s em (%d,%d) ate (%d,%d)\n\n",palavra,i,j,i+tam-1,j);
                    return 1;
                }
                else if(encontrouVI){
                    printf("Encontrou %s em (%d,%d) ate (%d,%d)\n\n",palavra,i,j,i-tam+1,j);
                    return 1;
                }
                else if(encontrouHN){
                    printf("Encontrou %s em (%d,%d) ate (%d,%d)\n\n",palavra,i,j,i,j+tam-1);
                    return 1;
                }
                else if(encontrouHI){
                    printf("Encontrou %s em (%d,%d) ate (%d,%d)\n\n",palavra,i,j,i,j-tam+1);
                    return 1;
                }
                else if(encontrouDN){
                    printf("Encontrou %s em (%d,%d) ate (%d,%d)\n\n",palavra,i,j,i+tam-1,j+tam-1);
                    return 1;
                }
                else if(encontrouDI){
                    printf("Encontrou %s em (%d,%d) ate (%d,%d)\n\n",palavra,i,j,i-tam+1,j-tam+1);
                    return 1;
                }
            }

    printf("Palavra nao encontrada :(\n\n");
    return 0;

}




int main(){
    int m, n, numPalEnc = 0, numPal;
    char* mat;
    int v[6];
    int encontrou = 0;
    char palavra[10], encontradas[9][10];
    char palavras[][10] = {"abacaxi", "banana", "pera", "limao", "laranja", "mamao","melancia","uva","bergamota"};

    srand(time(NULL));

    printf("Tamanho da matriz: (de preferencia maior que 8x8) \n");
    scanf("%d %d", &m, &n);
    mat = malloc(sizeof(char)*m*n);
    numPal = (int) ((m+n)/4);         /* Número de palavras baseado no número de linhas e col. */
    if(numPal>9)
        numPal = 9;

    inicializarMat(mat,m,n,'*');      /* Preenche a matriz com o char dado e '*' para usar letras aleatórias */
    inserirPalavras(mat,m,n,palavras);/* Insere as palavras que estão dentro do main */

    while(numPal > numPalEnc){
        printMat(mat,m,n);
        printf("\n\n%d/%d encontradas\n",numPalEnc, numPal);
        printf("Digite uma palavra: ");
        scanf("%s", palavra);
        system("cls");
        encontrou = busca(mat, m, n, palavra, palavras, encontradas);

        if(encontrou){
            strcpy(encontradas[numPalEnc], palavra);
            numPalEnc ++;
        }
    }

    printMat(mat, m, n);
    printf("Todas as palavras foram encontradas!");
    getch();

}
