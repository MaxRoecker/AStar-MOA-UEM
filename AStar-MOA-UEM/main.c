/* 
 * File:   main.c
 * Author: joao
 *
 * Created on 22 de Setembro de 2014, 11:00
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

typedef struct {
    int matrix[4][4];
    int g;
    int h;
    tNo p;
}tNo;

int main(int argc, char** argv) {
    FILE *fileInput = fopen(argv[1],"r");
    return (EXIT_SUCCESS);
}

