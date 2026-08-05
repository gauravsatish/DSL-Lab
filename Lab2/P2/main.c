#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, z;
    printf("Enter x, y, and z for size of mat1(x * y) and mat2(y * z): ");
    if (scanf("%d %d %d", &x, &y, &z) != 3) return 1;

    int** mat1 = (int**) malloc(x * sizeof(int*));
    int** mat2 = (int**) malloc(y * sizeof(int*));
    int** prod = (int**) malloc(x * sizeof(int*));

    for (int i = 0; i < x; i++) *(mat1 + i) = (int*) malloc(y * sizeof(int));
    for (int i = 0; i < y; i++) *(mat2 + i) = (int*) malloc(z * sizeof(int));
    for (int i = 0; i < x; i++) *(prod + i) = (int*) malloc(z * sizeof(int));

    printf("Enter elements of mat1:\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", (*(mat1 + i) + j));
        }
    }

    printf("Enter elements of mat2:\n");
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < z; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", (*(mat2 + i) + j));
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < z; j++) {
            int sum = 0;
            for (int k = 0; k < y; k++) {
                sum += (*(*(mat1 + i) + k)) * (*(*(mat2 + k) + j));
            }
            *(*(prod + i) + j) = sum;
        }
    }

    printf("Product: \n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < z; j++) {
            printf("%d ", *(*(prod + i) + j));
        }
        printf("\n");
    }

    for (int i = 0; i < x; i++) free(*(mat1 + i));
    for (int i = 0; i < y; i++) free(*(mat2 + i));
    for (int i = 0; i < x; i++) free(*(prod + i));
    free(mat1);
    free(mat2);
    free(prod);

    return 0;
}
