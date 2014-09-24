/* 
 * File:   heuristicas.c
 * Author: max
 *
 * Created on 23 de Setembro de 2014, 10:00
 */

int h1(int m[4][4]) {
    int i;
    int counter = 0;
    for (i = 0; i < 4; i++) {
        int j;
        for (j = 0; j < 4; j++) {
            if (m[i][j] != (i + 4 * j + 1)) {
                if (!((i == 3) && (j == 3) && (m[i][j] == 0))) {
                    counter++;
                }
            }
        }
    }
    return counter;
}

int h2(int[4][4]){
    
}