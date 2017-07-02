#include <stdio.h>
#include <stdlib.h>
#include "fordfulkerson.h"

int main()
{
    int vertex, edges, numFranq, numClientes, numBikes, aux, aux2, *vetorFr, *vetorCl, i, j, fluxo=0;
    int **capacity;

    scanf("%d %d %d %d", &vertex, &edges, &numFranq, &numClientes);

    vetorFr = (int*)malloc(numFranq*sizeof(int)); //armazena vertices com franquias
    vetorCl = (int*)malloc(numClientes*sizeof(int)); //armazena vertices com clientes
    capacity = (int**)malloc(vertex*sizeof(int*));
    for(j=0; j<vertex; j++){
        capacity[j] = (int*)calloc(vertex,sizeof(int));
    }

    for(i=0; i<edges; i++){
        scanf("%d %d %d", &aux, &aux2, &numBikes);
        capacity[aux][aux2] = numBikes;
    }

    for(i=0; i<numFranq; i++){ //numero de franquias
        scanf("%d", &aux);
        vetorFr[i] = aux;
    }

    for(i=0; i<numClientes; i++){
        scanf("%d", &aux2);
        vetorCl[i] = aux2;
    }

    for(i=0; i<numFranq; i++){
        for(j=0; j<numClientes; j++){
            fluxo += max_flow(vetorFr[i], vetorCl[j], vertex, capacity);
        }
    }

    printf("%d", fluxo);
    free(vetorCl);
    free(vetorFr);
    for(i=0; i<vertex; i++){
        free(capacity[i]);
    }
    free(capacity);
    return 0;
}
