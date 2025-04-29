#include <stdio.h>
#include <limits.h>

#define N 3

int minCost = INT_MAX;
int costMatrix[N][N] = {
    {9, 2, 7},
    {6, 4, 3},
    {5, 8, 1}
};

int assigned[N];

void solve(int worker, int currCost) {
    if (worker == N) {
        if (currCost < minCost)
            minCost = currCost;
        return;
    }
    for (int job = 0; job < N; job++) {
        if (!assigned[job]) {
            assigned[job] = 1;
            solve(worker + 1, currCost + costMatrix[worker][job]);
            assigned[job] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < N; i++)
        assigned[i] = 0;
    solve(0, 0);
    printf("Minimum cost is %d\n", minCost);
    return 0;
}
