#include <stdio.h>
#include <limits.h>

#define MAX 10

int cost[MAX][MAX], n, t[MAX][2], sum;
int parent[MAX], rank[MAX];

void kruskal();
int find(int i);
void union_sets(int u, int v);

int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (Use a high value like 999 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    kruskal();

    printf("Edges of the Minimal Spanning Tree:\n");
    for (i = 0; i < n - 1; i++) {
        printf("(%d, %d)\n", t[i][0], t[i][1]);
    }
    printf("Sum of Minimal Spanning Tree: %d\n", sum);

    return 0;
}

void kruskal() {
    int min, u, v, count = 0, k = 0;


    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    sum = 0;

    while (count < n - 1) {
        min = INT_MAX;
        u = -1;
        v = -1;


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] && find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (u == -1 || v == -1) break;


        union_sets(u, v);
        t[k][0] = u;
        t[k][1] = v;
        sum += min;
        k++;
        count++;
    }
}


int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}

void union_sets(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u != root_v) {
        if (rank[root_u] > rank[root_v])
            parent[root_v] = root_u;
        else if (rank[root_u] < rank[root_v])
            parent[root_u] = root_v;
        else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }
}
