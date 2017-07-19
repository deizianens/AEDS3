#include <stdio.h>
#include <stdlib.h>
#include "bandeira.h"
#include "forcaBruta.h"

int forcaBruta(Bandeiras* b, int qntBares, int ant, int posAtual) {
        if (posAtual == qntBares) {
            return 0;
        }
        int inclui = 0;
        if (b[posAtual].numCasa > ant) {
            inclui = 1 + forcaBruta(b, qntBares, b[posAtual].numCasa, posAtual + 1);
        }
        int naoInclui = forcaBruta(b, qntBares, ant, posAtual + 1);
        return max(inclui, naoInclui);
}

// Calcula o max entre dois valores
int max(int a, int b) { return (a > b)? a : b; }
