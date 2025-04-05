#include <stdio.h>
#include <stdlib.h>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
        printf("\n");
}

// ==================== BUBBLE SORT ====================
void bubble(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
            for (int j = 0; j < n - i - 1; j++)
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;
                        swapped = 1;
                    }
            if (!swapped) break;
        }
}

// ==================== INSERTION SORT ====================
void insertion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

// ==================== SELECTION SORT ====================
void selection(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min]) min = j;
        int temp = arr[i]; arr[i] = arr[min]; arr[min] = temp;
    }
}

// ==================== FUNÇÃO PRINCIPAL ====================
int main() {
    int original[] = {25, 5, 75, 65, 35, 95, 15, 85};
    int n = sizeof(original) / sizeof(original[0]);

    void (*sorts[])(int[], int) = {bubble, insertion, selection};

    char *nomes[] = {"Bubble", "Insertion", "Selection"};

    for (int i = 0; i < 5; i++) {
        int arr[n];
        for (int j = 0; j < n; j++) arr[j] = original[j];

        if (i < 3) sorts[i](arr, n);

        printf("%s Sort: ", nomes[i]);
        print(arr, n);
    }

    return 0;
}
