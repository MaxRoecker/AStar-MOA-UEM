/* 
 * File:   util.c
 * Author: max
 *
 * Created on 23 de Setembro de 2014, 10:12
 */


void printMatrix(int m[4][4]){
    int i;
    for (i = 0; i < 4; i++) {
        int j;
        for (j = 0; j < 4; j++) {
            int x = m[i][j];
            printf("%d ",x);
        }
        printf("\n");
    }
}