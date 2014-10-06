/* 
 * File:   heuristicas.c
 * Author: max
 *
 * Created on 23 de Setembro de 2014, 10:00
 */

#include "definicoes.h"

/*
 * Heuristica 1:
 * Conta a quantidade de nos fora do local na resposta.
 *
 */
int h1(int m[LENMATRIX][LENMATRIX]) {
    int i;
    int counter = 0;
    int j;
    for (i = 0; i < LENMATRIX; i++) {
        for (j = 0; j < LENMATRIX; j++) {
            if (m[i][j] != (i + LENMATRIX * j + 1)) {
                if (!((m[i][j] == 0))) {
                    counter++;
                }
            }
        }
    }
    return counter;
}

/*
 * Heuristica 2
 * Conta quantos numeros estao fora da sequencia a partir do primeiro elemento.
 */
int h2(int m[LENMATRIX][LENMATRIX]) {
    int i;
    int counter = 0;
    int previous = m[0][0];
    for (i = 0; i < LENMATRIX; i++) {
        int j;
        for (j = 0; j < LENMATRIX; j++) {
            if (!((i == 0)&&(j == 0))) {
                if (!((previous == 15)&&(m[j][i] == 0))) {
                    if (m[j][i] != previous + 1) {
                        counter++;
                    }
                }
                if (m[j][i] != 0) {
                    previous = m[j][i];
                }
            }
        }
    }
    return counter;
}

/*
 * Heuristica 3
 * Conta a quantidade de movimentos necessarios para que cada elemento
 * esteja em seu lugar correto.
 */
int h3(int m[LENMATRIX][LENMATRIX]) {
    int i;
    int counter = 0;
    for (i = 0; i < LENMATRIX; i++) {
        int j;
        for (j = 0; j < LENMATRIX; j++) {
            if (m[i][j] != 0) {
                int value = m[i][j] - 1;
                int posj = value / LENMATRIX;
                int posi = value % LENMATRIX;
                counter += abs(posi - i) + abs(posj - j);
            }
        }
    }
    return counter;
}

/*
 * Heuristica 4
 * Faz uma média ponderadas das Heurísticas 1, 2 e 3.
 */
int h4(int m[LENMATRIX][LENMATRIX], double p1, double p2, double p3) {
    int answer;
    if (p1 + p2 + p3 != 1) {
        answer = -1;
    } else {
        int r1 = p1 * h1(m);
        int r2 = p2 * h2(m);
        int r3 = p3 * h3(m);
        answer = r1 + r2 + r3;
    }
    return answer;
}

/*
 * Heuristica 5
 * Retorna o maior valor das heurísticas 1, 2 e 3.
 */

int h5(int m[LENMATRIX][LENMATRIX]) {
    int answer;
    int r1 = h1(m);
    int r2 = h2(m);
    int r3 = h3(m);
    if (r1 > r2) {
        if (r1 > r3) {
            answer = r1;
        } else {
            answer = r3;
        }
    } else {
        if (r2 > r3) {
            answer = r2;
        } else {
            answer = r3;
        }
    }
    return answer;
}