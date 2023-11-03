/*
* autor 1: Filipe Viotto Rodrigues
* autor 2: Isadora Vanço
* Solucionador de Labirinto usando pilha
*/
#include <stdio.h>
#include <stdlib.h>
#include "Marcacao.h"
#include "Busca.h"



int main(int argc, char* argv[]){
    
    int lin;
    int col;
    
    char * mat = CriaMatriz(&lin,&col);
    BuscaCaminho(mat, lin, col);
    //PrintaMatriz(mat,lin,col);
    //printf("\n\n");
    LimpaMat(mat,lin,col);
    PrintaMatriz(mat,lin,col);

    free(mat);
    
    return 0;
}