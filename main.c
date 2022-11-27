
#define ARRAY_LENGTH 10

#include <stdlib.h>
#include <stdio.h>
#include "my_mat.h"

int main() {
    char choice;
    int *matrix;

    do {
        scanf(" %c", &choice);
        switch (choice) {
            case 'A':
                matrix = initilizeMatrix();
                break;
            case 'B':
                isRoad(matrix);
                break;
            case 'C':
                shortestRoad(matrix);
                break;
            default:
                break;
        }

    } while (choice != 'D');
    free(matrix);
    return 0;
}
/*
0 3 1 0 0 2 0 0 0 0
3 0 1 0 0 0 0 0 0 0
1 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 5 0 0
0 0 0 0 0 0 0 4 1 1
2 0 0 0 0 0 2 0 0 0
0 0 0 0 0 2 0 0 0 0
0 0 0 5 4 0 0 0 0 2
0 0 0 0 1 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0
___________________
0 1 2  3  4 5 6  7  8  9
2 2 1 -1 -1 2 4 -1 -1 -1
2 2 1 -1 -1 4 6 -1 -1 -1
1 1 2 -1 -1 3 5 -1 -1 -1
13 15 14 10 8 11 9 5 9 7
7  9  8  9  2  5 3 4 1 1
2 4 3 -1 -1 4 2 -1 -1 -1
4 6 5 -1 -1 2 4 -1 -1 -1
8 10 9 5  3 6 4  7  4  2
8 10 9 10 1 6 4  5  2  2
6 8  7 10 1 4 2  5  2  2

 */