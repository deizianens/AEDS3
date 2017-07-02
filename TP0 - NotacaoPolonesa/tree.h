#ifndef NOTACAOPOLONESA_TREE_H
#define NOTACAOPOLONESA_TREE_H

#include<stdio.h>
#include<stdlib.h>
#include "pilha.h"

struct no{
    int num;
    char op; //guarda a operação do nó
    struct No *esq;
    struct No *dir;
};

typedef struct no* Tree;

//metodos
Tree* criaArvore();
void freeArvore(Tree *raiz);
void freeNode(struct no* node);
void preOrder(Tree *raiz, char* entrada, Pilha* stack, int result);
void preOrderInsert(Tree *raiz);

#endif //NOTACAOPOLONESA_TREE_H
