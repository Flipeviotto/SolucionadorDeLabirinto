#include "Busca.h"
#include "Marcacao.h"
#include <stdio.h>
#include <stdlib.h>

PILHA * IniciaPilha(){
    PILHA * topo = malloc(sizeof(PILHA*));
    topo->next = NULL;
    return topo;
}

char * BuscaInicio(char *mat,int linha, int coluna, int* x, int* y){
    int primeiro=0;
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            if(*(mat+i*coluna+j)=='p'){
                *x=i;
                *y=j;
                return(mat+i*coluna+j);
            }
            else if(primeiro==0 && *(mat+i*coluna+j)==' '){
                *x=i;
                *y=j;
                primeiro=1;
            }
        }
    }
    if(primeiro==0){
        printf("Nao foi possivel definir ponto de partida.\n");
        exit(1);
    }
    *(mat+ *x*coluna+ *y) = 'p';
    return(mat+ *x*coluna+ *y);
}

int ContPossibilidades(char * p, int coluna){
    int possibilidade = 0 ;
    if(*(p+coluna)==' ' || *(p+coluna)== 'o')
        possibilidade++;
    if(*(p-coluna)==' ' || *(p-coluna)=='o')
        possibilidade++;
    if(*(p+1)==' ' || *(p+1)=='o')
        possibilidade++;
    if(*(p-1)==' ' || *(p-1)=='o')
        possibilidade++;
    
    return possibilidade;
}

char * desempilhar(char * ponto, PILHA * topo, char* mat, int lin, int col){
    struct cel * aux;
    
    while(topo->next!=NULL && topo->next->possibilidades==1){
        PrintaBusca(mat, lin, col);
        *ponto = 'f';
        ponto += topo->next->deslocamento * (-1);

        aux = topo->next;
        topo->next = aux->next;
        free(aux);
        
    }
    if(topo->next!=NULL){
        PrintaBusca(mat, lin, col);
        *ponto = 'f';
        ponto += topo->next->deslocamento * (-1);
        aux = topo->next;
        topo->next = aux->next;
        free(aux);
    }
    return ponto;
}

void Empilhar(PILHA * topo, int possibilidade){
    struct cel * aux = malloc(sizeof(struct cel*));
    aux->possibilidades=possibilidade;
    aux->next = topo->next;
    topo->next = aux;
}

char * MovePonto(struct cel * aux, char * ponto, int coluna, int* x, int* y){
    if(*(ponto-coluna)==32 || *(ponto-coluna)=='o'){
        aux->deslocamento = coluna*(-1);
        *x = *x -1;
        aux->x = *x;
        aux->y = (*y);
        return (ponto-coluna);
    }
    else if(*(ponto+1)==32 || *(ponto+1)=='o'){
        aux->deslocamento = 1;
        *y = *y+1;
        aux->x = *x;
        aux->y = *y;
        return ponto+1;
    }
    else if(*(ponto+coluna)==32 || *(ponto+coluna)== 'o'){
        aux->deslocamento = coluna;
        *x = *x +1;
        aux->x = *x;
        aux->y = *y;
        return(ponto+coluna);
    }
    else if(*(ponto-1)==32 || *(ponto-1)=='o'){
        aux->deslocamento = -1;
        *y = *y -1;
        aux->x = *x;
        aux->y = *y;
        return ponto-1;
    }
    else{
        printf("Nao esta deslocando\n");
        exit(1);
    }
}

void FreePilha(PILHA * topo){
    struct cel * aux;
    while(topo->next!=NULL){
        aux = topo->next;
        topo->next = aux->next;
        free(aux);
    }
}

void PrintaCoordenada(PILHA * topo,int x2,int y2){
    PILHA * Reordenado = IniciaPilha();
    Reordenado->next = NULL;

    struct cel * aux = topo->next;
    struct cel* aux2;
    do{
        aux2 = malloc(sizeof(struct cel*));
        aux2->x = aux->x;
        aux2->y = aux->y;
        
        aux2->next = Reordenado->next;
        Reordenado->next = aux2;
        aux = aux->next; 
    
    }while(aux!=NULL);
    printf("Caminho correto apartir do ponto p:\n(%d, %d)",x2,y2);


    while(aux2!=NULL){
        printf(" (%d, %d)", aux2->x,aux2->y);
        aux2 = aux2->next;
    }
    printf("\n");

    FreePilha(Reordenado);
}

void BuscaCaminho(char * mat, int linha, int coluna){
    PILHA * topo = IniciaPilha();
    int x,y;
    char * ponto = BuscaInicio(mat, linha, coluna, &x,&y);
    int x2=x,y2=y;

    while(*ponto != 'o'){
        PrintaBusca(mat, linha, coluna);
        int possibilidade = ContPossibilidades(ponto, coluna);
        
        if(possibilidade == 0){
            if(*ponto=='p'){
                printf("nao tem solucao\n");
                exit(1);
            }
            *ponto = '.';
            ponto = desempilhar(ponto, topo, mat, linha, coluna);
            
            if(topo->next!=NULL){
                x = topo->next->x;
                y = topo->next->y;
            }
            else{
                x=x2;
                y=y2;
            }
        }
        else{
            if(*ponto!='p'){
                *ponto='c';
            }
            Empilhar(topo,possibilidade);
            ponto = MovePonto(topo->next, ponto, coluna, &x,&y);
        }
    }

    //printar as coordenadas invertida;
    if(topo->next!=NULL){
        PrintaCoordenada(topo,x2,y2);
    }
    FreePilha(topo);
}

