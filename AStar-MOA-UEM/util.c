/* 
 * File:   util.c
 * Author: max
 *
 * Created on 23 de Setembro de 2014, 10:12
 */

#include "definicoes.h"

void printMatrix(int m[LENMATRIX][LENMATRIX]) {
    int i;
    int j;
    for (i = 0; i < LENMATRIX; i++) {
        for (j = 0; j < LENMATRIX; j++) {
            int x = m[i][j];
            printf("%d ", x);
        }
        printf("\n");
    }
}

int equalsMatrix(int m1[LENMATRIX][LENMATRIX], int m2[LENMATRIX][LENMATRIX]) {
    int i,j;
    for (i = 0; i < LENMATRIX; i++) {
        for (j = 0; j < LENMATRIX; j++) {
            if (m1[i][j] != m2[i][j]){
                return 0;
            }
        }
    }
    return 1;
}