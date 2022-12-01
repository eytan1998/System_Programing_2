#include <stdio.h>

#define MATRIX_SIZE 10
#define INF -1

void initializeMatrix(int matrix[][MATRIX_SIZE]) {

    //initialize the matrix by the graph that user input
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            int input;
            scanf("%d", &input);

            if (input == 0) matrix[i][j] = INF;
            else matrix[i][j] = input;
        }
    }

    for (int k = 0; k < MATRIX_SIZE; k++) {
        for (int i = 0; i < MATRIX_SIZE; i++) {
            for (int j = 0; j < MATRIX_SIZE; j++) {
                //to adapt -1(=infinity) for comparison
                int isCurrentInf = (matrix[i][j] == INF);
                int isMaybeInf = (matrix[i][k] == INF || matrix[k][j] == INF);

                //if is inf so surly is not less than current
                if (isMaybeInf) continue;
                //if there is shorter road take it
                else if (isCurrentInf || matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }

            }
        }
    }

}

int shortestRoad(int matrix[][MATRIX_SIZE]) {
    int i, j;
    scanf("%d%d", &i, &j);
    //to eliminate the possibility to get road to myself from other nodes
    if (i == j) return INF;
    else return matrix[i][j];
}

int isRoad(int matrix[][MATRIX_SIZE]) {
    return (shortestRoad(matrix) != INF);
}

