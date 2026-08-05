#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    printf("Binary Search\n");
    printf("Enter n: \n");
    int n;
    scanf("%d", &n);
    printf("Enter elements: \n");
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key: ");
    int key;
    scanf("%d", &key);

    bool found = false;

    int start = 0, end = n-1;
    while (start < end) {
        int mid = (start + end) / 2;
        if (arr[mid] == key) {
            found = true;
            printf("Found %d at index %d", key, mid);
            break;
        } else if (arr[mid] > key) {
            end = mid - 1;
        } else if (arr[mid] < key) {
            start = mid + 1;
        }
    }

    if (!found) {
        printf("%d not found", key);
    }

    return 0;
}
