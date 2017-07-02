#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define oo 100000000

void enqueue(int x, int *tail, int* color, int *q){
    q[(*tail)] = x;
    (*tail)++;
    color[x] = GRAY; //visitado
}

int dequeue(int *head, int* color, int *q){
    int x = q[(*head)];
    (*head)++;
    color[x] = BLACK; //visitou todos os vertices adjacentes
    return x;
}

int min(int x, int y){
    return x<y ? x : y; //retorna o minimo entre x e y
}

//busca em largura
int bfs(int ini, int fim, int vertex, int *pred, int **capacity){
    static int head, tail;
    static int *q;
    static int *color;

    color = (int*)malloc(vertex*sizeof(int));
    q = (int*)malloc((vertex+2)*sizeof(int));
    int u, v;

    for(u=0; u<vertex; u++){
        color[u] = WHITE; //todos os vertices inicializam brancos
    }
    head = tail = 0;
    enqueue(ini, &tail, color, q);
    pred[ini] = -1;

    //enquanto fila nao está "vazia"
    while (head!=tail){
        u=dequeue(&head, color, q);
        //procura por todos os vertices brancos adjacentes
        for(v=0; v<vertex; v++){
            if(color[v]==WHITE && capacity[u][v]>0){
                enqueue(v, &tail, color, q);
                pred[v]= u; //armazena caminho
            }
        }
    }
    //se a cor do vertice alvo for preta significa que encontramos o caminho
    return color[fim] == BLACK;
}


int max_flow (int ini, int fim, int vertex, int**capacity){
    int i,j,u, v;
    static int **flow; //matriz de fluxo
    static int *pred;  // store augmenting path
    pred = (int*)malloc(vertex*sizeof(int)); //armazena o caminho (usado pelo bfs)

    flow = (int**)malloc(vertex*sizeof(int*));
    for(j=0; j<vertex; j++){
        flow[j] = (int*)calloc(vertex,sizeof(int));
    }

    for(i=0; i<vertex; i++){
        for(j=0; j<vertex; j++){
            flow[i][j] = capacity[i][j];
        }
    }

    //inicializa com flow =0;
    int max_flow =0;

    //incrementa o fluxo sobre o caminho
    while(bfs(ini, fim, vertex, pred, flow)){ //determina quantidade que deve ser incrementada no fluxo
      //encontra fluxo maximo no caminho encontrado por bfs
      int increment = oo;
      for(v=fim; v!=ini; v=pred[v]){
        u = pred[v];
        increment = min(increment, flow[u][v]);
      }

      //incrementa flow
      for(v=fim;v!=ini; v=pred[v]){
        u = pred[v];
        flow[u][v] -= increment;
        flow[v][u] += increment;
      }
      max_flow += increment;
    }

    for(i=0; i<vertex; i++){
        for(j=0; j<vertex; j++){
            capacity[i][j] = flow[i][j];
        }
    }

    free(pred);
    for(i=0; i<vertex; i++){
        free(flow[i]);
    }
    free(flow);
    return max_flow;
}
