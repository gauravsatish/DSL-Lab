#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("Linear search\n\n");
    printf("Enter n: !\n");
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

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = true;
            printf("Found %d at index %d\n", key, i);
            break;
        }
    }

    if (!found) {
        printf("Element not found");
    }
    return 0;
}
