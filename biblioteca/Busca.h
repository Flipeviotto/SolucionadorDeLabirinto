#ifndef BUSCA_H
#define BUSCA_H

struct cel{
    struct cel * next;
    int possibilidades;
    int deslocamento;
};

typedef struct{
    struct cel * next;
}PILHA;

void BuscaCaminho(char * mat, int, int); //retorna pilha com caminho
PILHA * IniciaPilha();
char * BuscaInicio(char *, int,int);
int ContPossibilidades(char *, int coluna);
char * desempilhar(char *, PILHA *);
char * MovePonto(struct cel *, char *, int );
void Empilhar(PILHA *, int);


#endif