#include <stdio.h>
#include <limits.h>

void prims(int n, int cost[n][n]);

int main() {
    int n, i, j;


    printf("Enter the number of vertices: ");
    scanf("%d", &n);


    int cost[n][n];
    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }


    prims(n, cost);

    return 0;
}

void prims(int n, int cost[n][n]) {
    int i, j, u, v, min;
    int sum = 0;
    int parent[n];
    int key[n];
    int mstSet[n];


    for (i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }


    key[0] = 0;
    parent[0] = -1;

    for (i = 0; i < n - 1; i++) {
        min = INT_MAX;
        u = -1;


        for (j = 0; j < n; j++) {
            if (!mstSet[j] && key[j] < min) {
                min = key[j];
                u = j;
            }
        }


        mstSet[u] = 1;
        sum += min;
        for (v = 0; v < n; v++) {
            if (cost[u][v] != 0 && !mstSet[v] && cost[u][v] < key[v]) {
                key[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }


    printf("Edges of the minimal spanning tree:\n");
    for (i = 1; i < n; i++) {
        printf("(%d, %d) with weight %d\n", parent[i], i, cost[i][parent[i]]);
    }


    printf("Sum of minimal spanning tree: %d\n", sum);
}
