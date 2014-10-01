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

    /*
        char fileName[50];
        printf("Informe o nome do arquivo: ");
        gets(fileName);
        FILE *fileInput = fopen(fileName,"r");
    
        tNodeBoard root;
        int i;
        int j;
        readMatrix(fileInput, &root);
        for (i = 0; i < 4; i++){
            for (j=0; j < 4; j++){
                printf("%d ",root.matrix[i][j]);
            }
            printf("\n");
        }
    
        tQueue queue;
        initialize(&queue);
        tNodeQueue node1;
        tNodeBoard e1;
        node1.elem = &e1;
        node1.elem->f = 5;
        insertAtEnd(&queue, node1);
        printf("tamanho: %d\n",queue.length);
        printf("%d\n",queue.begin->elem->f);
        tNodeQueue node2;
        tNodeBoard e2;
        node2.elem = &e2;
        node2.elem->f = 6;
        insertAtEnd(&queue, node2);
        printf("tamanho: %d\n",queue.length);
        printf("%d\n",queue.begin->elem->f);
        tNodeQueue node3;
        tNodeBoard e3;
        node3.elem = &e3;
        node3.elem->f = 7;
        insertAtEnd(&queue, node3);
        printf("tamanho: %d\n",queue.length);
        printf("%d\n",queue.begin->elem->f);
    
    //    tNodeQueue min;
    //    removeMin(&queue,&min);
    //    printf("\n\n%d",min.elem->f);*/

    int m0[LENMATRIX][LENMATRIX] = {
        {1, 5, 9, 13},
        {2, 6, 10, 14},
        {3, 0, 11, 15},
        {4, 8, 12, 7}};

    /*
        printf("H1: %d \n",h1(m0));
        printf("H2: %d \n",h2(m0));
        printf("H3: %d \n",h3(m0));
        printf("H4: %d \n",h4(m0,0.3,0.3,0.4));
        printf("H5: %d \n\n",h5(m0));
     */
    
    int *top = malloc(sizeof(m0));
    int *right = malloc(sizeof(m0));
    int *bottom = malloc(sizeof(m0));
    int *left = malloc(sizeof(m0));
    int i,j;
    
    findZeroPosition(m0,&i,&j);
    
    if(moveTop(m0,top,i,j)){
        printMatrix(top);
    }else{
        printf("Não deu.");
    }
    printf("\n\n");
    if(moveRight(m0,right,i,j)){
        printMatrix(right);
    }else{
        printf("Não deu.");
    }
    printf("\n\n");
    if(moveBottom(m0,bottom,i,j)){
        printMatrix(bottom);
    }else{
        printf("Não deu.");
    }
    printf("\n\n");
    
    if(moveLeft(m0,left,i,j)){
        printMatrix(left);
    }else{
        printf("Não deu.");
    }
    
    
    
/*
    int j = 1;
    memccpy(p,m0,-1,4*4*sizeof(int));
    
    printMatrix(m0);
    printMatrix(p);
    
    int (*m)[4] = p;
    
    printf("\nElemento: %d\n\n",m[1][1]);
    
*/
    

    return (EXIT_SUCCESS);
}

