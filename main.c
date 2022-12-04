#include <stdio.h>
#include "my_mat.h"


int main() {
    char choice;
    int matrix[MATRIX_SIZE][MATRIX_SIZE] = {0};

    do {
        scanf(" %c", &choice);
        switch (choice) {
            case 'A':
                initializeMatrix(matrix);
                break;
            case 'B':
                if (isRoad(matrix))printf("True\n");
                else printf("False\n");
                break;
            case 'C':
                printf("%d\n", shortestRoad(matrix));
                break;
        }
    } while (choice != 'D');

    return 0;
}