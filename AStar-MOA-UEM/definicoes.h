/* 
 * File:   definicoes.h
 * Author: max
 *
 * Created on 23 de Setembro de 2014, 10:14
 */


/*
 * Definicoes de constantes utilizadas
 */
#define LENMATRIX 4

/*
 * Definição das estruturas utilizadas
 */
typedef struct tNodeBoard{
    int matrix[LENMATRIX][LENMATRIX];
    int g;
    int h;
    int f;
    struct tNodeBoard *p;
} tNodeBoard;

typedef struct tNodeQueue{
    struct tNodeQueue *next;
    struct tNodeQueue *ant;
    tNodeBoard *elem;
} tNodeQueue;

typedef struct tQueue{
    tNodeQueue *begin;
    tNodeQueue *end;
    int length;
} tQueue;

/*
 * Definicoes do arquivo util.c
 */
void printMatrix(int m[4][4]);
 

/*
 * Definicoes do arquivo heuristicas.c
 */
int h1(int m[4][4]);

