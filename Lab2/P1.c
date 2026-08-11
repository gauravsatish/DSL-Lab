#include <stdio.h>
#include <stdlib.h>


int* smallest(int *arr, int n) {
    int* small = arr;
    for (int i = 1; i < n; i++) {
        if (*(arr+i) < *small) {
            small = (arr+i);
        }
    }

    return small;
}

int main() {
    printf("Enter size of array: ");
    int n;
    scanf("%d", &n);

    int *arr = (int*) calloc(n, sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", arr+i);
    }

    printf("Smallest element in array: %d\n", *smallest(arr, n));

    free(arr);

}
