#ifndef TP1_FORDFULKERSON_H
#define TP1_FORDFULKERSON_H

//cabeçalho de funções

void enqueue(int x, int *tail, int* color, int *q); //ENFILEIRA
int dequeue(int *head, int* color, int *q); //TIRA DA FILA
int min(int x, int y); //RETORNA MINIMO
int bfs(int ini, int fim, int vertex, int *pred, int **capacity); //BUSCA EM LARGURA
int max_flow (int ini, int fim, int vertex, int**capacity); //CALCULA FLUXO MAXIMO

#endif //TP1_FORDFULKERSON_H
