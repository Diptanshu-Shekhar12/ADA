#include <stdio.h>
#include <time.h>

void m_sort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);

void m_sort(int a[], int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    m_sort(a, low, mid);
    m_sort(a, mid + 1, high);
    merge(a, low, mid, high);
}

void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[high - low + 1];
    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }

    while (j <= high) {
        temp[k++] = a[j++];
    }

    for (int i = 0; i < k; i++) {
        a[low + i] = temp[i];
    }
}

int main() {
    int n, i;
    clock_t start, end;
    double time_taken;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements of array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Original array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    start = clock();
    m_sort(a, 0, n - 1);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Time taken to sort = %f seconds\n", time_taken);

    return 0;
}
