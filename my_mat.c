#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH 10
#define INF 999999999

void initilizeMatrix(int* dist) {
    int *graph = malloc((ARRAY_LENGTH * ARRAY_LENGTH) * sizeof(int));
    int i, j;
    for (i = 0; i < ARRAY_LENGTH; i++) {
        for (j = 0; j < ARRAY_LENGTH; j++) {
            scanf("%d", &graph[(i * ARRAY_LENGTH) + j]);
        }
    }

    for (i = 0; i < ARRAY_LENGTH; i++)//checking purpose
    {
        for (j = 0; j < ARRAY_LENGTH; j++) {
            if (graph[i * ARRAY_LENGTH + j] == 0) dist[(i * ARRAY_LENGTH) + j] = INF;
            else dist[(i * ARRAY_LENGTH) + j] = graph[(i * ARRAY_LENGTH) + j];
        }
    }
    free(graph);
    for (int k = 0; k < ARRAY_LENGTH; k++) {
        for (int i = 0; i < ARRAY_LENGTH; i++) {
            for (int j = 0; j < ARRAY_LENGTH; j++) {
                if (dist[(i * ARRAY_LENGTH) + k] + dist[(k * ARRAY_LENGTH) + j] < dist[(i * ARRAY_LENGTH) + j])
                    dist[(i * ARRAY_LENGTH) + j] = dist[(i * ARRAY_LENGTH) + k] + dist[(k * ARRAY_LENGTH) + j];
            }
        }
    }

}

void isRoad(int *matrix) {
    int i, j;
    scanf("%d", &i);
    scanf("%d", &j);
    if (i != j && matrix[(i * ARRAY_LENGTH) + j] != INF) printf("True\n");
    else printf("False\n");

}

void shortestRoad(int *matrix) {
    int i, j;
    scanf("%d", &i);
    scanf("%d", &j);
    if (i == j || matrix[(i * ARRAY_LENGTH) + j] == INF) printf("-1\n");
    else printf("%d\n", matrix[(i * ARRAY_LENGTH) + j]);

}

