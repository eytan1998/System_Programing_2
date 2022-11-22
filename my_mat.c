#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH 10
#define V 10
#define INF 999999


int **makeMatrixOfDis(int **graph) {
    //let dist be a |V| × |V| array of minimum distances initialized to ∞ (infinity)
    int **dist = (int **) malloc(sizeof(int *) * ARRAY_LENGTH);
    int i, j;
    for (i = 0; i < ARRAY_LENGTH; i++)//checking purpose
    {
        dist[i] = (int *) malloc(sizeof(int) * ARRAY_LENGTH);
        for (j = 0; j < ARRAY_LENGTH; j++) {
            if (graph[i][j] == 0) dist[i][j] = INF;
            else dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }


    return dist;
}

int **initilizeMatrix() {
    int **arr = (int **) malloc(sizeof(int *) * ARRAY_LENGTH);
    int i, j;
    for (i = 0; i < ARRAY_LENGTH; i++)//checking purpose
    {
        arr[i] = (int *) malloc(sizeof(int) * ARRAY_LENGTH);
        for (j = 0; j < ARRAY_LENGTH; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    return makeMatrixOfDis(arr);

}

void isRoad(int **matrix) {
    int i, j;
    scanf("%d", &i);
    scanf("%d", &j);
    if (i != j && matrix[i][j] != INF) printf("True\n");
    else printf("False\n");

}

void shortestRoad(int **matrix) {
    int i, j;
    scanf("%d", &i);
    scanf("%d", &j);
    if (i == j || matrix[i][j] == INF) printf("-1\n");
    else printf("%d\n", matrix[i][j]);

}

