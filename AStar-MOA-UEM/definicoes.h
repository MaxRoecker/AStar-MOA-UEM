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

//Variaveis globais de peso
double p1;
double p2;
double p3;

/*
 * Definicoes do arquivo util.c
 */
void printMatrix(int m[LENMATRIX][LENMATRIX]);
 

/*
 * Definicoes do arquivo heuristicas.c
 */
int h1(int m[LENMATRIX][LENMATRIX]);
int h2(int m[LENMATRIX][LENMATRIX]);
int h3(int m[LENMATRIX][LENMATRIX]);

int h5(int m[LENMATRIX][LENMATRIX]);
