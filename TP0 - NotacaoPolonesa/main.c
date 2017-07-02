//DEIZIANE NATANI DA SILVA
//AEDS 3 - TP0
//2015121980

#include <stdio.h>
#include <string.h>
#include "pilha.h"
#include "tree.h"

int main(int argc, char *argv[]){

    char entrada[201];
    int result, i=0;

    Pilha* stack = criaPilha();
    Operando op;

    scanf("%[^\n]s", &entrada);
    scanf("%d", &result);

    Tree* arv  = criaArvore();

    for(i=0; entrada[i]!='\0'; i++){
        if(entrada[i]=='?'){ //se for operando, insere na arvore
                preOrderInsert(arv);
        }
    }

    preOrder(arv, entrada, stack, result);
    system("PAUSE");
}//fim main
