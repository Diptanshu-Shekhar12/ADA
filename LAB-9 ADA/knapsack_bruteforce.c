#include <stdio.h>
#include <stdlib.h>

int n = 5;
int weights[] = {2, 3, 4, 5, 6};
int values[] = {3, 4, 5, 6, 7};
int capacity = 10;

void knapsack_bruteforce() {
    int max_value = 0;
    int total_combinations = (1 << n);

    for (int i = 0; i < total_combinations; i++) {
        int total_weight = 0;
        int total_value = 0;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                total_weight += weights[j];
                total_value += values[j];
            }
        }

        if (total_weight <= capacity && total_value > max_value) {
            max_value = total_value;
        }
    }

    printf("Maximum value that can be carried in the knapsack: %d\n", max_value);
}

int main() {
    knapsack_bruteforce();
    return 0;
}

