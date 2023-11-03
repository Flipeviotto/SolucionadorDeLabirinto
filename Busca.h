#ifndef BUSCA_H
#define BUSCA_H

struct cel{
    struct cel * next;
    int possibilidades;
    int deslocamento;
    int x;
    int y;
};

typedef struct{
    struct cel * next;
}PILHA;

void BuscaCaminho(char * , int, int); //retorna pilha com caminho
PILHA * IniciaPilha();
char * BuscaInicio(char *, int,int, int*,int*);
int ContPossibilidades(char *, int );
char * desempilhar(char *, PILHA *, char * , int, int);
char * MovePonto(struct cel *, char *, int,int *,int *);
void Empilhar(PILHA *, int);
void FreePilha(PILHA *);
void PrintaCoordenada(PILHA *, int, int);


#endif