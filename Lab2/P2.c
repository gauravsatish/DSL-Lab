#include <stdio.h>
#include <stdlib.h>


void selectionSort(int* arr, int n) {
    if (n == 1) return;
    int* smallest = arr;
    for (int i = 1; i < n; i++) 
        if (*(arr+i) < *smallest) smallest = (arr+i);
    
    int temp = *smallest;
    *smallest = *arr;
    *arr = temp;

    selectionSort(arr+1, n-1);
}


int main() {
    printf("Enter no of elements: ");
    int n;
    scanf("%d", &n);

    int* arr = (int*) calloc(n, sizeof(int));
    
    printf("Enter elements: \n");
    for (int i = 0; i < n; i++) 
        scanf("%d", (arr+i));

    selectionSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr+i));
    }

    free(arr);

    return 0;
}
