#include "Busca.h"
#include "Marcacao.h"
#include <stdio.h>
#include <stdlib.h>

PILHA * IniciaPilha(){
    PILHA * topo = malloc(sizeof(PILHA*));
    topo->next = NULL;
    return topo;
}

char * BuscaInicio(char *mat,int linha, int coluna){
    for(int i=0;i<linha*coluna;i++){
        if(*(mat)=='p')
            return(mat);
        else
            mat++;
    }
    printf("ponto de inicio nao encontrado\n");
    exit(1);
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

char * desempilhar(char * ponto, PILHA * topo){
    struct cel * aux;
    
    while(topo->next!=NULL && topo->next->possibilidades==1){
        *ponto = 'f';
        ponto += topo->next->deslocamento * (-1);

        aux = topo->next;
        topo->next = aux->next;
        free(aux);
    }
    if(topo->next!=NULL){
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

char * MovePonto(struct cel * aux, char * ponto, int coluna){
    if(*(ponto-coluna)==32 || *(ponto-coluna)=='o'){
        aux->deslocamento = coluna*(-1);
        return (ponto-coluna);
    }
    else if(*(ponto+1)==32 || *(ponto+1)=='o'){
        aux->deslocamento = 1;
        return ponto+1;
    }
    else if(*(ponto+coluna)==32 || *(ponto+coluna)== 'o'){
        aux->deslocamento = coluna;
        return(ponto+coluna);
    }
    else if(*(ponto-1)==32 || *(ponto-1)=='o'){
        aux->deslocamento = -1;
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

void BuscaCaminho(char * mat, int linha, int coluna){
    PILHA * topo = IniciaPilha();
    char * ponto = BuscaInicio(mat, linha, coluna);

    while(*ponto != 'o'){
        int possibilidade = ContPossibilidades(ponto, coluna);
        
        if(possibilidade == 0){
            if(*ponto=='p'){
                printf("nao tem solucao\n");
                exit(1);
            }
            ponto = desempilhar(ponto, topo);
        }
        else{
            if(*ponto!='p'){
                *ponto='c';
            }
            Empilhar(topo,possibilidade);
            ponto = MovePonto(topo->next, ponto, coluna);
        }
    }

    FreePilha(topo);

}

