#include <stdio.h>
#include <stdlib.h>
#include "biblioteca/Marcacao.h"
#include "biblioteca/Busca.h"



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