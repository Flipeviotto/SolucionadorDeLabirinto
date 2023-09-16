#include <stdio.h>
#include <stdlib.h>
#include "biblioteca/Marcacao.h"
#include "biblioteca/Busca.h"



int main(){
    int lin = 20;
    int col = 21;
    
    char * mat = CriaMatriz(lin,col);
    mat = BuscaCaminho(mat, lin, col);
    LimpaMat(mat,lin,col);
    PrintaMatriz(mat,lin,col);
    return 0;
}