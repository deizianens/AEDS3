#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

Grafo *criaGrafo(int numVert, int grauMax){
    Grafo *gr = (Grafo*) malloc(sizeof(struct grafo));
    if(gr != NULL){
        int i;
        gr->numVertices = numVert;
        gr->grauMax = grauMax;
        gr->grau = (int*)calloc(numVert,sizeof(int));
        gr->tipo = (char*)malloc(numVert*sizeof(char));
        gr->arestas = (int**)malloc(numVert*sizeof(int*));
        for(i=0; i<numVert; i++)
            gr->arestas[i] = (int*)malloc(sizeof(int));
            gr->pesos =(float**)malloc(numVert*sizeof(float*));
            for(i=0; i<numVert; i++){
                gr->pesos[i] = (float*)malloc(sizeof(float));
            }

    }
    return gr;
};

void liberaGrafo(Grafo *gr){
    if(gr!=NULL){
        int i;
        for(i=0; i<gr->numVertices; i++){
            free(gr->arestas[i]);
            free(gr->pesos[i]);
        }
        free(gr->arestas);
        free(gr->pesos);
        free(gr->grau);
        free(gr);
    }
}

void insereAresta(Grafo* gr, int origin, int dest, float peso){
    if(gr==NULL){
        return 0;
    }
    if(origin < 0 || origin >= gr->numVertices) //verifica se vertice existe
        return 0;
    if(dest <0 || dest >= gr->numVertices) //verifica se vertice existe
        return 0;

    gr->arestas[origin] = (int*)realloc(gr->arestas[origin], (gr->grau[origin]+1)*sizeof(int));
    gr->pesos[origin] = (float*)realloc(gr->pesos[origin], (gr->grau[origin]+1)*sizeof(float));
    gr->arestas[origin][gr->grau[origin]] = dest;
    gr->pesos[origin][gr->grau[origin]] = peso;
    gr->grau[origin]++;
}

void atualizaAresta(Grafo* gr, int origin, int pos, float peso){
    gr->pesos[origin][pos] = peso;
}

//marca vertice como franquia
void marcaFranquia(Grafo* gr, int numVertex){
    if(gr==NULL){
        return 0;
    }
    if(numVertex < gr->numVertices){
        gr->tipo[numVertex] = 'f';
    }
}

//marca vertice como cliente
void marcaCliente(Grafo* gr, int numVertex){
    if(gr==NULL){
        return 0;
    }
    if(numVertex < gr->numVertices){
        gr->tipo[numVertex] = 'c';
    }
}

int* depthSearch(Grafo *gr, int ini, int* visitado, int cont, int end, int flag, int menor, int *caminho, int k){ //flag=1, chegou num cliente
    int i, j;
    static int f;
    f = 0;
    visitado[ini] = cont;
    for(i=0; i<gr->grau[ini]; i++){
        if(f!=1){
            if(!visitado[gr->arestas[ini][i]]){ //se vertice nao foi visitado
                for(j=k; j<gr->numVertices; j++){
                    caminho[j] = -1;
                }
                if(gr->arestas[ini][i]!= end){ //nao seja um cliente
                    if(gr->pesos[ini][i] != 0){ //caso ainda haja ciclistas permitidos naquela via
                        if(gr->pesos[ini][i] < menor){
                                menor = gr->pesos[ini][i];
                        }
                        if(caminho[k-1] != ini){
                            caminho[k++] = ini;
                        }
                        depthSearch(gr, gr->arestas[ini][i], visitado, cont+1,  end, f, menor, caminho, k);
                    }
                }
                else{
                    if(gr->pesos[ini][i] != 0){ //verifica se aresta é viavel
                        f=1;
                        caminho[k++] = ini;
                        caminho[k++] = end;
                        if(gr->pesos[ini][i] < menor){
                            menor = gr->pesos[ini][i];
                        }
                        caminho[0] = menor;
                    }
                    else{ //caso aresta nao seja viavel
                        menor = 99999;

                    }
                }
            }
        }
    }
    k--;
    menor = 99999;
    return caminho;
}

int depthFirstSearch(Grafo *gr, int ini, int end, int *visitado){
    int i, cont =1, m, aux2, j, c;
    static int menor=99999;
    static int aux, k=1;
    int *caminho;

    caminho = (int*) malloc((gr->numVertices+1)*sizeof(int));

    for(i=0; i<gr->numVertices; i++){
        visitado[i] = 0;
        caminho[i] = -1;
    }
    caminho[gr->numVertices] = -1; //garante que ele sempre ache a flag -1
    caminho = depthSearch(gr, ini, visitado, cont, end, 0, menor, caminho, k);

    if(caminho[0] != -1){
        for(j=1; caminho[j+1]!= -1; j++){
            for(c=0; c<gr->grau[caminho[j]]; c++){
                if(gr->arestas[caminho[j]][c] == caminho[j+1]){ //procura até acha a aresta que liga os dois vertices
                    aux2 = gr->pesos[caminho[j]][c] - caminho[0];
                    atualizaAresta(gr, caminho[j], c, aux2); //faz subtração de peso da aresta menor
                    break;
                }
            }
        }
    }

    return caminho[0];
}

void breadthFirstSearch(Grafo *gr, int ini, int *visitado){
    int i, vert, NV, cont=1, *fila, IF=0, FF=0;
    for(i=0; i<gr->numVertices; i++){
        visitado[i] = 0; //marca cmo nao visitado
    }
    NV = gr->numVertices;
    fila = (int*) malloc(NV*sizeof(int));
    FF++;
    fila[FF] = ini; //adiciona vertice inicial a fila
    visitado[ini] = cont; //marca como visitado
    //enquanto nao estiver no fim da fila
    while(IF!=FF){
        IF = (IF+1)%NV;
        vert = fila[IF];
        cont++;
        for(i=0; i<gr->grau[vert]; i++){ //visita vizinhos nao visitados
            if(!visitado[gr->arestas[vert][i]]){
                FF = (FF+1) % NV; //adiciona vertice a fila
                fila[FF] = gr->arestas[vert][i];
                visitado[gr->arestas[vert][i]] = cont;
            }
        }
    }
    free(fila);
}
