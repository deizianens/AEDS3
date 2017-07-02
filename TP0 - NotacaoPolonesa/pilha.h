#ifndef NOTACAOPOLONESA_PILHA_H
#define NOTACAOPOLONESA_PILHA_H

#include<stdbool.h>

typedef struct operando{
	int op;
}Operando;

typedef struct celula {
	Operando op;
	struct celula *prox_c;
}Celula;

typedef struct pilha {
	int size;
	Celula *topo;
}Pilha;

//cabeçalho das funções

Pilha* criaPilha();
bool pilhaVazia(Pilha* p); //verifica se a pilha está vazia
void pushOp(Pilha* p, Operando opr); //coloca operando na pilha
int popOp(Pilha* p); //remove celula do topo
void executeOp(Pilha* stack, char* entrada, char* op, int result); //executa operações

#endif //NOTACAOPOLONESA_PILHA_H
