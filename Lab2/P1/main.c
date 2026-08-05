#include <stdio.h>
#include <stdlib.h>

int* small(int* arr, int n) {
    int* smallest = arr;
    for (int i = 1; i < n; i++) {
        if (*(arr+i) < *smallest) {
            smallest = (arr+i);
        }
    }

    return smallest;
}

int main() {
    int n;
    printf("Enter no of elements: ");
    scanf("%d", &n);

    int* arr = (int *) malloc(n * sizeof(int));

    if (arr==NULL) {
        printf("Memory not allocated");
        return 1;
    }

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Smallest: %d", *small(arr, n));

    free(arr);

    return 0;
}
