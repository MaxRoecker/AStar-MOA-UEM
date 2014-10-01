/* 
 * File:   heuristicas.c
 * Author: max
 *
 * Created on 29 de Setembro de 2014, 10:33
 */

#include <string.h>
#include <stdio.h>

#include "definicoes.h"

/*
 * findZeroPosition
 * Parametros: Matriz de entrada
 * retorna em I e J a posição do 0 da Matriz de entrada
 *
 */
void findZeroPosition(int m[LENMATRIX][LENMATRIX], int* i, int* j) {
    *i = 0;
    *j = 0;
    while ((m[*i][*j] != 0)&&(*i < LENMATRIX)) {
        *j = 0;
        while ((m[*i][*j] != 0)&&(*j < LENMATRIX)) {
            (*j)++;
        }
        if (m[*i][*j] != 0) {
            (*i)++;
        }
    }
}

int moveTop(int m[LENMATRIX][LENMATRIX], int top[LENMATRIX][LENMATRIX], int i, int j) {
    if (i - 1 >= 0) {
        memcpy(top, m, LENMATRIX * LENMATRIX * sizeof (int));
        int aux = top[i][j];
        top[i][j] = top[i - 1][j];
        top[i - 1][j] = aux;
        return 1;
    }
    return 0;
}

int moveRight(int m[LENMATRIX][LENMATRIX], int right[LENMATRIX][LENMATRIX], int i, int j) {
    if (j + 1 < LENMATRIX) {
        memcpy(right, m, LENMATRIX * LENMATRIX * sizeof (int));
        int aux = right[i][j];
        right[i][j] = right[i][j + 1];
        right[i][j + 1] = aux;
        return 1;
    }
    return 0;
}

int moveBottom(int m[LENMATRIX][LENMATRIX], int bottom[LENMATRIX][LENMATRIX], int i, int j) {
    if (i + 1 < LENMATRIX) {
        memcpy(bottom, m, LENMATRIX * LENMATRIX * sizeof (int));
        int aux = bottom[i][j];
        bottom[i][j] = bottom[i + 1][j];
        bottom[i + 1][j] = aux;
        return 1;
    }
    return 0;
}

int moveLeft(int m[LENMATRIX][LENMATRIX], int left[LENMATRIX][LENMATRIX], int i, int j) {
    if (j - 1 >= 0) {
        memcpy(left, m, LENMATRIX * LENMATRIX * sizeof (int));
        int aux = left[i][j];
        left[i][j] = left[i][j - 1];
        left[i][j - 1] = aux;
        return 1;
    }
    return 0;
}