#include <stdio.h>

#define MATRIX_SIZE 10
#define INF -1

void initializeMatrix(int *matrix) {

    //initialize the matrix by the graph that user input
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            int input;
            scanf("%d", &input);

            if (input == 0) matrix[(i * MATRIX_SIZE) + j] = INF;
            else matrix[(i * MATRIX_SIZE) + j] = input;
        }
    }

    for (int k = 0; k < MATRIX_SIZE; k++) {
        for (int i = 0; i < MATRIX_SIZE; i++) {
            for (int j = 0; j < MATRIX_SIZE; j++) {
                //to adapt -1(=infinity) for comparison
                int isCurrentInf = (matrix[(i * MATRIX_SIZE) + j] == INF);
                int isMaybeInf = (matrix[(i * MATRIX_SIZE) + k] == INF || matrix[(k * MATRIX_SIZE) + j] == INF);

                //if is inf so surly is not less than current
                if (isMaybeInf) continue;
                //if there is shorter road take it
                else if (isCurrentInf || matrix[(i * MATRIX_SIZE) + j] >
                                                matrix[(i * MATRIX_SIZE) + k] + matrix[(k * MATRIX_SIZE) + j]) {
                    matrix[(i * MATRIX_SIZE) + j] = matrix[(i * MATRIX_SIZE) + k] + matrix[(k * MATRIX_SIZE) + j];
                }

            }
        }
    }

}

int shortestRoad(int *matrix) {
    int i, j;
    scanf("%d%d", &i, &j);
    //to eliminate the possibility to get road to myself from other
    if (i == j) return INF;
    else return matrix[(i * MATRIX_SIZE) + j];
}

int isRoad(int *matrix) {
    return (shortestRoad(matrix) != INF);
}

