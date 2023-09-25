#include "Marcacao.h"
#include <stdio.h>
#include <stdlib.h>


#ifdef _WIN64
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

char * CriaMatriz(int * lin, int * col){ //baixar o conteudo da matriz
    FILE * arq = fopen("labirinto.txt", "r");
    if(arq==NULL){
        printf("erro em abrir arquivo\n");
        exit(1);
    }
    
    fscanf(arq,"%d", lin); 
    *col = *lin;
    *lin = *lin -1;

    char c;
    char * mat = malloc(sizeof(char*)* (*col) * (*lin));
    for(int i=0;i< *lin * *col;i++){
        fscanf(arq,"%c", &c);
        if(c=='\n' && i==0 || c==' '){
            i--;
        }
        else if(c=='0'){
            *(mat+i) = ' ';
        }
        else if(c=='2'){
            *(mat+i) = 'p';
        }
        else if(c=='3'){
            *(mat+i) = 'o';
        }
        else if(c=='1'){
            *(mat+i) = '#';
        }
        else
            *(mat+i) = c;
            
    }
    fclose(arq);
    *(mat+*lin * *col) ='\n';

    return mat;
    
}

void PrintaMatriz(char * mat, int lin, int col){
    printf(" ");
    for(int i=0;i<lin+1;i++){
        for(int j=0;j<col;j++){
            printf("%c ", *(mat+col*i+j));
        }
    }
    printf("\n");
}

void PrintaBusca(char * mat,int lin, int col){
    printf(" ");
    for(int i=0;i<lin+1;i++){
        for(int j=0;j<col;j++){
            if(*(mat+col*i+j)=='c')
                printf(". ");
            else if(*(mat+col*i+j)=='f')
                printf("%c ",' ');
            else{
                printf("%c ", *(mat+col*i+j));
                if(*(mat+col*i+j)=='.'){
                    *(mat+col*i+j) = 'f';
                }
            }
        }
    }
    printf("\n");
    sleep(1);
}

void LimpaMat(char * mat, int linha, int coluna){
    char caracter;
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            caracter = *(mat+i*coluna+j);
            if(caracter == 'f'){
                *(mat+i*coluna+j) = ' ';
            }
            else if(caracter == 'c'){
                *(mat+i*coluna+j) = '.';
            }
        }
    }
}

