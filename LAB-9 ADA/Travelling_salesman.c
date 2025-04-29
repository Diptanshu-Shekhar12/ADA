#include <stdio.h>
#include <limits.h>

int dist[4][4] = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
int n = 4;
int visited[4];

int tsp(int pos, int count, int cost, int start) {
    if (count == n - 1) {
        return cost + dist[pos][start];
    }

    int minCost = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && i != pos) {
            visited[i] = 1;
            int newCost = tsp(i, count + 1, cost + dist[pos][i], start);
            if (newCost < minCost) {
                minCost = newCost;
            }
            visited[i] = 0;
        }
    }
    return minCost;
}

int main() {
    visited[0] = 1;
    printf("Minimum cost: %d\n", tsp(0, 1, 0, 0));
    return 0;
}
