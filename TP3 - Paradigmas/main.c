#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "bandeira.h"
#include "dinamica.h"
#include "greedy.h"
#include "forcaBruta.h"


int comparaCrescente(const void *x, const void *y);

int main()
{

    char alg;
    int i, qntBares, aux, aux2;

    scanf("%c", &alg);
    scanf("%d", &qntBares);

    Bandeiras b[qntBares];

    for(i=0; i<qntBares; i++){
            scanf("%d %d", &aux, &aux2);
            if(aux%2 == 0){ //numBar = todos os pares, numCasa = todos os impares
                b[i].numBar = aux;
                b[i].numCasa = aux2;

            }
            else{
                b[i].numBar = aux2;
                b[i].numCasa = aux;
            }

    }

    qsort(b, qntBares, sizeof(Bandeiras), comparaCrescente); //ordena rua em ordem crescente

    if(alg == 'b'){
        printf("%d\n", forcaBruta(b, qntBares, INT_MIN, 0));
    }
    else if(alg == 'g'){
        greedy(qntBares, b);
    }
    else if(alg == 'd'){
        dinamica(qntBares, b);
    }
    else{
        printf("YOU SHALL NOT PASS! \nDigite um caractere valido: b, g ou d!\n");
        return 0;
    }

    return 0;
}

int comparaCrescente(const void *x, const void *y){
    Bandeiras *p1 = (Bandeiras *)x;
    Bandeiras *p2 = (Bandeiras *)y;
    if(p1->numBar == p2->numBar){
        return 0;
    }
    else{
        if(p1->numBar < p2->numBar){
            return -1; //p1 vem antes de p2
        }
        else{
            return 1; //p1 vem depois de p2
        }
    }
}

