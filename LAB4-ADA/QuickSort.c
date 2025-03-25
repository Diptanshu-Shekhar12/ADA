#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

void quicksort(int[], int, int);
int partition(int[], int, int);

int main() {
    int n, a[MAX], b = 1;
    clock_t start, end;

    while (b) {
        printf("Enter number of elements: ");
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            a[i] = rand() % 200;
        }

        printf("Array is: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");

        start = clock();
        quicksort(a, 0, n - 1);
        end = clock();

        printf("Sorted array elements are: \n");
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");

        printf("Time taken = %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

        printf("Do you wish to continue (0/1): ");
        scanf("%d", &b);
    }

    return 0;
}

int partition(int a[], int low, int high) {
    int key = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    while (i <= j) {
        while (i <= high && a[i] <= key) {
            i++;
        }
        while (a[j] > key) {
            j--;
        }
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    a[low] = a[j];
    a[j] = key;

    return j;
}

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int mid = partition(a, low, high);
        quicksort(a, low, mid - 1);
        quicksort(a, mid + 1, high);
    }
}
