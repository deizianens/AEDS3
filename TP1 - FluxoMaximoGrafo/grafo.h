#ifndef TP1_GRAFO_H
#define TP1_GRAFO_H

typedef struct grafo{
        int numVertices;
        int **arestas;
        float **pesos;
        int* grau;
        int  grauMax;
        char *tipo;
}Grafo;

Grafo *criaGrafo(int numVert, int grauMax);
void liberaGrafo(Grafo *gr);
void insereAresta(Grafo* gr, int origin, int dest, float peso);
void atualizaAresta(Grafo* gr, int origin, int pos, float peso);
void marcaFranquia(Grafo* gr, int numVertex);
void marcaCliente(Grafo* gr, int numVertex);
int* depthSearch(Grafo *gr, int ini, int* visitado, int cont, int end, int flag, int menor, int *caminho, int k);
int depthFirstSearch(Grafo *gr, int ini, int end, int *visitado);

#endif //TP1_GRAFO_H
