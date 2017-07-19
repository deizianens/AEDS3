#include <stdio.h>
#include <stdlib.h>
#include "bandeira.h"
#include "greedy.h"

void greedy(int qntBares, Bandeiras* b){

    int tail[qntBares], i;
    memset(tail, 0, qntBares); //inicializa todas as posições com 0,
    //tail guarda os valores de todas os elementos finais de cada subsequencia encontrada

    int length = 1; // always points empty slot in tail

    tail[0] = b[0].numCasa; //sempre pega o primeiro elemento do array

    for (i = 1; i < qntBares; i++) {
        /*
        *   A cada iteração temos tres alternativas
        *   caso o valor de b[i].numCasa seja menor que o valor encontrado em tail, iniciamos uma nova subsequencia (if)
        *   caso o valor de b[i].numCasa seja maior que o valor encontrado em tail, estendemos a subsequencia ja existente (else if)
        *   caso não seja nem o maior nem o menor, procuramos uma subsequencia onde o valor de tail seja menor que b[i].numCasa
        *   sendo assim, b[i].numCasa estende a subsequencia e descartamos todas as outras subsequencias do mesmo comprimento que a da subsequencia modificada. (else)
        */
        if (b[i].numCasa < tail[0])
            // achamos um novo valor minimo
            tail[0] = b[i].numCasa;
        else if (b[i].numCasa > tail[length-1])
            //b[i].numCasa faz parte da lis encontrada até o momento
            tail[length++] = b[i].numCasa;
        else
            tail[CeilIndex(tail, -1, length-1, b[i].numCasa)] = b[i].numCasa;
    }

    printf("%d\n", length);
}

// busca binaria
int CeilIndex(int* v, int l, int r, int key) {
    while (r-l > 1) {
    int m = l + (r-l)/2;
    if (v[m] >= key)
        r = m;
    else
        l = m;
    }

    return r;
}
