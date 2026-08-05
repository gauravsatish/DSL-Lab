#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Sorting\n");
    printf("Enter n: ");
    int n;
    scanf("%d", &n);
    printf("Enter elements: \n");
    int arr[n], arr1[n], arr2[n], arr3[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i] = arr[i];
    }

    // Bubble Sort
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr1[j] > arr1[j+1]) {
                int temp = arr1[j];
                arr1[j] = arr1[j+1];
                arr1[j+1] = temp;
            }
        }
    }

    printf("\nBubble Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr1[i]);
    }

    // Selection Sort
    for (int i = 0; i < n; i++) {
        int smallest = i;
        for (int j = i + 1; j < n; j++) {
            if (arr2[j] < arr2[smallest]) {
                smallest = j;
            }
        }
        int temp = arr2[i];
        arr2[i] = arr2[smallest];
        arr2[smallest] = temp;
    }

    printf("\nSelection Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr2[i]);
    }


    // Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = arr3[i];
        int j = i - 1;

        while (j>= 0 && arr3[j] > key) {
            arr3[j+1] = arr3[j];
            j--;
        }

        arr3[j+1] = key;
    }

    printf("\nInsertion Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr3[i]);
    }

    return 0;
}
