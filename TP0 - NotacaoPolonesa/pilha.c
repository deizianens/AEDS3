#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

//cria pilha vazia
Pilha* criaPilha(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = NULL;
	p->size = 0;

	return p;
}

//verifica se pilha esta vazia
bool pilhaVazia(Pilha* p){
	return (p->size==0);
}

//posta operando no topo da pilha :)
void pushOp(Pilha* p, Operando opr){
	Celula* cel = (Celula *) malloc(sizeof(Celula));

	cel->op = opr;
	cel->prox_c = p->topo;
	p->topo = cel;
	p->size++;
}

int popOp(Pilha* p){
    int op;

    if(!pilhaVazia(p)){
        Celula* ponteiro = p->topo; //cria ponteiro auxiliar pro topo da pilha
        op = p->topo->op.op; //pega operador do topo
        p->topo = ponteiro->prox_c; //liga o topo ao proximo elemento da pilha
        p->size--;
    }
    else{
        printf("Pilha Vazia!\n");
    }
    return op;
}

void executeOp(Pilha* stack, char* entrada, char* op, int result){
    Operando opr;
    int op1, op2, j=1, i;
    char aux2[3];
    static char* aux[51];

    for(i=0; entrada[i]!='\0'; i++){
        if(entrada[i]!='?' && entrada[i]!=' '){ //se for operando, empilha
            if(entrada[i]!='?' && entrada[i+1]!=' '){
                aux2[0] = entrada[i];
                aux2[1] = entrada[i+1];
                opr.op = atoi(aux2);
                i++;
                pushOp(stack, opr);
            }
            else{
                opr.op = entrada[i]-'0'; //ninja
                pushOp(stack, opr);
            }
        }
        else if(entrada[i]=='?'){ //se for operação, pega operando no vetor de operandos e faz a conta
            if(!pilhaVazia(stack) && stack->size>1){
                op1 = popOp(stack);
                op2 = popOp(stack);
                if(op[j]=='+'){
                    opr.op = op1+op2;
                    pushOp(stack, opr);
                }
                else if(op[j]=='*'){
                    opr.op = op1*op2;
                    pushOp(stack, opr);
                }
                else if(op[j]=='0'){
                    return;
                }
                j++;
            }
        }
    }

    if(!pilhaVazia(stack)){
        if(popOp(stack)==result){
            if(strcmp(aux, op)!=0){
                for(i=1; op[i]!='\0'; i++){
                    printf("%c", op[i]);
                }
                printf("\n");
                strcpy(aux, op);
            }
        }
    }
}
