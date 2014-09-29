/* 
 * File:   main.c
 * Author: joao
 *
 * Created on 22 de Setembro de 2014, 11:00
 */

#include <stdio.h>
#include <stdlib.h>
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
//    printf("\n\n%d",min.elem->f);
    
    return (EXIT_SUCCESS);
}

