/* 
 * File:   main.c
 * Author: joao
 *
 * Created on 22 de Setembro de 2014, 11:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definicoes.h"

int readNumberFromFile(FILE *fileInput) {
    char c;
    fread(&c, 1, sizeof (char), fileInput);
    char buffer[3];
    buffer[0] = '\0';
    buffer[1] = '\0';
    buffer[2] = '\0';
    int i = 0;
    while (c != 32 && c != 10) {
        buffer[i] = c;
        i++;
        fread(&c, 1, sizeof (char), fileInput);
    }
    return atoi(buffer);
}

void readMatrix(FILE *fileInput, tNodeBoard *root) {
    int i;
    int j;
    for (i = 0; i < LENMATRIX; i++) {
        for (j = 0; j < LENMATRIX; j++) {
            root->matrix[i][j] = readNumberFromFile(fileInput);
        }
    }
    root->p = NULL;
    root->g = 0;
    root->h = 0;
}

int main(int argc, char** argv) {
    //FILE *fileInput = fopen(argv[1],"r");


    //char fileName[50];
//    char buffer;
//    printf("Informe o nome do arquivo: ");
//    gets(fileName);
//    scanf("%c",buffer);
    char fileName[50] = "caso1.txt";
    FILE *fileInput = fopen(fileName, "r");
    
    printf("\n\n[1] Heuristica 1 \n");
    printf("[2] Heuristica 2 \n");
    printf("[3] Heuristica 3 \n");
    printf("[4] Heuristica 4 \n");
    printf("[5] Heuristica 5 \n");
    printf("Informe a heuristica: ");

    int heuristica = 1;
    //scanf("%d",&heuristica);
    
    if (heuristica == 4){
        printf("\nInforme o peso para a heuristica 1: ");
        scanf("%lf",&p1);
        printf("\nInforme o peso para a heuristica 2: ");
        scanf("%lf",&p2);
        printf("\nInforme o peso para a heuristica 3: ");
        scanf("%lf",&p3);
    }

    tNodeBoard *initBoard = malloc(sizeof(tNodeBoard));
    readMatrix(fileInput, initBoard);
    initBoard->p = NULL;
    initBoard->g = 0;
    switch (heuristica) {
        case 1:
            initBoard->h = h1(initBoard->matrix);
            break;
        case 2:
            initBoard->h = h2(initBoard->matrix);
            break;
        case 3:
            initBoard->h = h3(initBoard->matrix);
            break;
        case 4:
            initBoard->h = h4(initBoard->matrix, p1, p2, p3);
            break;
        case 5:
            initBoard->h = h5(initBoard->matrix);
            break;

    }
    initBoard->f = initBoard->g + initBoard->h;   
    
    tNodeQueue *root = malloc(sizeof(tNodeQueue));
    root->elem = initBoard;
    root->ant = NULL;
    root->next = NULL;
    
    int answer;
    if (aStar(root,heuristica,&answer)){
        printf("\nPara a entrada temos o resultado de %d\n\n",answer);
    } else {
        printf("\nNao ha resultado para esta entrada\n\n");
    }

    return (EXIT_SUCCESS);
}

