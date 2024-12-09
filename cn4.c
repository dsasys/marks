#include <stdio.h>

#define MAX 5
#define INF 9999

void update(int dist[MAX][MAX]) {
    for (int k = 0; k < MAX; k++) {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void print(int dist[MAX][MAX]) {
    printf("Router | Destination | Distance\n");
    printf("--------------------------------\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (dist[i][j] == INF) {
                printf("  %d    |      %d     |   INF\n", i, j);
            } else {
                printf("  %d    |      %d     |    %d\n", i, j, dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int cost[MAX][MAX], dist[MAX][MAX];

    printf("Enter the cost matrix (-1 for INF):\n");

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (i == j) {
                cost[i][j] = 0;
            } else {
                printf("Enter the cost from router %d to router %d: ", i, j);
                scanf("%d", &cost[i][j]);

                if (cost[i][j] == -1) {
                    cost[i][j] = INF;
                }
            }
            dist[i][j] = cost[i][j];
        }
    }

    for (int iteration = 1; iteration <= MAX; iteration++) {
        printf("\nIteration %d:\n", iteration);
        update(dist);
        print(dist);
    }

    return 0;
}

