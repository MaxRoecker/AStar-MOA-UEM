/* 
 * File:   heuristicas.c
 * Author: max
 *
 * Created on 29 de Setembro de 2014, 10:33
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "definicoes.h"

/*
 * findZeroPosition
 * Parametros: Matriz de entrada
 * retorna em I e J a posição do 0 da Matriz de entrada
 *
 */
void findZeroPosition(int m[LENMATRIX][LENMATRIX], int *i, int *j) {
    for (*i = 0; *i < LENMATRIX; (*i)++) {
        for (*j = 0; *j < LENMATRIX; (*j)++) {
            if (m[*i][*j] == 0){
                return;
            }
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

int isFinalState(int m[LENMATRIX][LENMATRIX]) {
    int i = 0;
    int j = 0;
    for (i = 0; i < LENMATRIX; i++) {
        for (j = 0; j < LENMATRIX; j++) {
            if (m[i][j] != (i + LENMATRIX * j + 1)) {
                if (!((i == 3) && (j == 3) && (m[i][j] == 0))) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

void calcH(tNodeQueue *p, tNodeQueue *m, int heuristica) {
    m->elem->p = p->elem;
    switch (heuristica) {
        case 1:
            m->elem->h = h1(m->elem->matrix);
            break;
        case 2:
            m->elem->h = h2(m->elem->matrix);
            break;
        case 3:
            m->elem->h = h3(m->elem->matrix);
            break;
        case 4:
            m->elem->h = h4(m->elem->matrix, p1, p2, p3);
            break;
        case 5:
            m->elem->h = h5(m->elem->matrix);
            break;

    }
    m->elem->f = m->elem->h + m->elem->g;
}

int validSuccessor(tQueue *a, tQueue *f, tNodeQueue *p, tNodeQueue *m, int heuristica) {
    m->elem->g = p->elem->g + 1;

    printf("%d\n",a);
    if ((!(memberOf(m, a)) || (!(memberOf(m, f))))) {
        insertAtEnd(m, a);
        calcH(p, m, heuristica);
    } else {
        if (memberOfWithGMin(m, a)) {
            insertAtEnd(m, a);
            calcH(p, m, heuristica);
        } else {
            if (memberOfWithGMin(m, f)) {
                removeElem(m, f);
                insertAtEnd(m, a);
                calcH(p, m, heuristica);
            }
        }

    }
}

int aStar(tNodeQueue *root, int heuristica, int *answer) {
    tQueue *a = malloc(sizeof(tQueue));
    tQueue *f = malloc(sizeof(tQueue));
    *answer = -1;
    printf("%d\n",a);
    initialize(a);
    initialize(f);


    insertAtEnd(a, root);

    while (!isEmpty(a)) {
        tNodeQueue *v = removeMin(a);
        insertAtEnd(f, v);

        if (isFinalState(v->elem->matrix)) {
            *answer = v->elem->f;
            return 1;
        } else {
            tNodeQueue *top = malloc(sizeof (tNodeQueue));
            tNodeBoard *topBoard = malloc(sizeof (tNodeBoard));
            top->elem = topBoard;
            tNodeQueue *right = malloc(sizeof (tNodeQueue));
            tNodeBoard *rightBoard = malloc(sizeof (tNodeBoard));
            right->elem = rightBoard;
            tNodeQueue *bottom = malloc(sizeof (tNodeQueue));
            tNodeBoard *bottomBoard = malloc(sizeof (tNodeBoard));
            bottom->elem = bottomBoard;
            tNodeQueue *left = malloc(sizeof (tNodeQueue));
            tNodeBoard *leftBoard = malloc(sizeof (tNodeBoard));
            left->elem = leftBoard;

            int i;
            int j;
            findZeroPosition(v->elem->matrix, &i, &j);
            if (moveTop(v->elem->matrix, top->elem->matrix, i, j)) {
                validSuccessor(a, f, v, top, heuristica);
            } else {
                free(topBoard);
                free(top);
            }
            if (moveRight(v->elem->matrix, right->elem->matrix, i, j)) {
                validSuccessor(a, f, v, right, heuristica);
            } else {
                free(rightBoard);
                free(right);
            }
            if (moveBottom(v->elem->matrix, bottom->elem->matrix, i, j)) {
                validSuccessor(a, f, v, bottom, heuristica);
            } else {
                free(bottomBoard);
                free(bottom);
            }
            if (moveLeft(v->elem->matrix, left->elem->matrix, i, j)) {
                validSuccessor(a, f, v, left, heuristica);
            } else {
                free(leftBoard);
                free(left);
            }

        }
    }
    if (isEmpty(a)) {
        return 0;
    }

}