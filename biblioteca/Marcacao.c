#include "Marcacao.h"
#include <stdio.h>
#include <stdlib.h>

char * CriaMatriz(int lin, int col){ //baixar o conteudo da matriz
    FILE * arq = fopen("labirinto.txt", "r");
    if(arq==NULL){
        printf("erro em abrir arquivo\n");
        exit(1);
    }
    char * mat = malloc(sizeof(char*)*col*lin);

    for(int i=0;i<lin*col;i++){
        fscanf(arq,"%c", (mat+i));
    }
    fclose(arq);

    return mat;
    
}

void PrintaMatriz(char * mat, int lin, int col){
    for(int i=0;i<lin+1;i++){
        for(int j=0;j<col;j++){
            printf("%c", *(mat+col*i+j));
        }
    }
    printf("\n");
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

