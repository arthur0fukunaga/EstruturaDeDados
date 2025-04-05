#include <stdio.h>
#include <stdlib.h>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// MERGE SORT
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    if (!L || !R) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// QUICK SORT
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;
}

void quick(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick(arr, low, pi - 1);
        quick(arr, pi + 1, high);
    }
}

// FUNÇÃO PRINCIPAL
int main() {
    int original[] = {5, 1, 3, 6, 8, 7, 2, 10};
    int n = sizeof(original) / sizeof(original[0]);

    void (*sorts3[])(int[], int, int) = {mergeSort, quick};

    char *nomes[] = {"Merge", "Quick"};

    for (int i = 0; i < 2; i++) {
        int arr[n];
        for (int j = 0; j < n; j++)
            arr[j] = original[j];

        if (i == 0) {
            sorts3[i](arr, 0, n - 1);
        } else if (i == 1) {
            sorts3[i](arr, 0, n - 1);
        }

        printf("%s Sort: ", nomes[i]);
        print(arr, n);
    }

    return 0;
}
