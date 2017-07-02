#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


Tree* criaArvore(){
    Tree*  raiz = (Tree*) malloc(sizeof(Tree));
    if(raiz!=NULL){
        struct no* novo;
        novo  = (struct no*) malloc(sizeof(struct no));
        novo->dir = NULL;
        novo->esq = NULL;
        novo->op = '0'; //sempre começa com zero e muda a partir do momento que raiz tiver filhos
        (*raiz) = novo;
    }
    return raiz;
}

void freeArvore(Tree *raiz){
    if(raiz==NULL){
        return;
    }
    freeNode(*raiz); //libera cada nó da arvore
    free(raiz);  //libera raiz da arvore
}

void freeNode(struct no* node){
    if(node == NULL)
        return;
    freeNode(node->esq);
    freeNode(node->dir);
    free(node);
    node = NULL;
}

//percorre esquerda-raiz-direita
void preOrder(Tree *raiz, char* entrada, Pilha* stack, int result){
    static int i=0;
    static char operators[51];

    if(raiz==NULL){
        return;
    }
    if(*raiz!=NULL){
        executeOp(stack, entrada, operators, result);
        operators[i] = (*raiz)->op;
        i++;
        preOrder(&((*raiz)->esq), entrada, stack, result);
        preOrder(&((*raiz)->dir), entrada, stack, result);
        executeOp(stack, entrada, operators, result);
        i--;
        operators[i] = '0';
    }

}

//percorre esquerda-raiz-direita e insere valor
void preOrderInsert(Tree *raiz){

    //caso o nó não tiver filhos(se não tem esquerda, nao tem direita ou caso só houver a raiz(primeira vez)
    if((*raiz)->esq==NULL || (*raiz)->op=='0'){

        struct no* novoD;
        novoD  = (struct no*) malloc(sizeof(struct no));
        if(novoD == NULL)
            return;
       // novoD->num = raiz->num*valor;
        novoD->op = '*';
        novoD->dir = NULL;
        novoD->esq = NULL;

        struct no* novoE;
        novoE  = (struct no*) malloc(sizeof(struct no));
        if(novoE == NULL)
            return;
        //novoE->num = raiz->num+valor;
        novoE->op = '+';
        novoE->dir = NULL;
        novoE->esq = NULL;

        (*raiz)->dir = novoD;
        (*raiz)->esq = novoE;

        if((*raiz)->op=='0'){
            (*raiz)->op='1';
        }
        return;
    }

    if(*raiz != NULL){
        preOrderInsert(&((*raiz)->esq));
        preOrderInsert(&((*raiz)->dir));
    }
}



