#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH 10
#define V 10
#define INF 999999999


int* makeMatrixOfDis(int *graph) {


}

int* initilizeMatrix() {
    int* graph = malloc((ARRAY_LENGTH * ARRAY_LENGTH) * sizeof(int));
    int i, j;
    for (i = 0; i < ARRAY_LENGTH; i++)
    {
        for (j = 0; j < ARRAY_LENGTH; j++) {
            scanf("%d", &graph[(i*ARRAY_LENGTH)+j]);
        }
    }
    int* dist = malloc((ARRAY_LENGTH * ARRAY_LENGTH) * sizeof(int));

    for (i = 0; i < ARRAY_LENGTH; i++)//checking purpose
    {
        for (j = 0; j < ARRAY_LENGTH; j++) {
            if (graph[i*ARRAY_LENGTH+j] == 0) dist[(i*ARRAY_LENGTH)+j] = INF;
            else dist[(i*ARRAY_LENGTH)+j] = graph[(i*ARRAY_LENGTH)+j];
        }
    }
    free(graph);
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[(i*ARRAY_LENGTH)+k] + dist[(k*ARRAY_LENGTH)+j] < dist[(i*ARRAY_LENGTH)+j])
                    dist[(i*ARRAY_LENGTH)+j] = dist[(i*ARRAY_LENGTH)+k] + dist[(k*ARRAY_LENGTH)+j];
            }
        }
    }
    for (i = 0; i < ARRAY_LENGTH; i++)
    {
        for (j = 0; j < ARRAY_LENGTH; j++) {
            if (dist[(i*ARRAY_LENGTH)+j] == INF || i ==j ) dist[(i*ARRAY_LENGTH)+j] =-1;
        }
    }
    return dist;
}

void isRoad(int *matrix) {
    int i, j;
    scanf("%d", &i);
    scanf("%d", &j);
    if (i != j && matrix[(i*ARRAY_LENGTH)+j] != INF) printf("True\n");
    else printf("False\n");

}

void shortestRoad(int *matrix) {
    int i, j;
    scanf("%d", &i);
    scanf("%d", &j);
    if (i == j || matrix[(i*ARRAY_LENGTH)+j] == INF) printf("-1\n");
    else printf("%d\n", matrix[(i*ARRAY_LENGTH)+j]);

}

