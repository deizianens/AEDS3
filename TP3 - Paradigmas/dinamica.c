#include <stdio.h>
#include <stdlib.h>
#include "bandeira.h"
#include "dinamica.h"

void dinamica(int qntBares, Bandeiras* b){
    int lis[qntBares], i, j;
    for (i=0; i<qntBares; i++){
        lis[i] = 1;
    }

    // Subsequência Crescente Mais Longa
    // aplicada na rua oposta
    for (i=1; i<qntBares; i++){
        for (j=0; j<i; j++){
            if (b[i].numCasa >= b[j].numCasa && lis[i] < 1 + lis[j]){
                lis[i] = 1 + lis[j];
            }
        }
    }

    int max = lis[0];
    for (i=1; i<qntBares; i++)
        if (max < lis[i])
            max = lis[i];

    printf("%d\n", max);
}
