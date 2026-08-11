#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int rows, int cols) {
    int** mat = (int**) calloc(rows, sizeof(int*));
    if (mat == NULL) exit(1);
    
    for (int i = 0; i < rows; i++) {
        *(mat + i) = (int*) calloc(cols, sizeof(int)); 
        if (*(mat + i) == NULL) exit(1);
    }
    return mat;
}

void readMatrix(int** mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", (*(mat + i) + j));
        }
    }
}

void displayMatrix(int** mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}

void multiplyMatrices(int** mat1, int** mat2, int** prod, int x, int y, int z) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < z; j++) {
            int sum = 0;
            for (int k = 0; k < y; k++) {
                sum += (*(*(mat1 + i) + k)) * (*(*(mat2 + k) + j));
            }
            *(*(prod + i) + j) = sum;
        }
    }
}

int main() {
    int x, y, z;
    printf("Enter x, y, and z for size of mat1(x * y) and mat2(y * z): ");
    scanf("%d %d %d", &x, &y, &z);

    int** mat1 = createMatrix(x, y);
    int** mat2 = createMatrix(y, z);
    int** prod = createMatrix(x, z);

    printf("Enter elements of mat1:\n");
    readMatrix(mat1, x, y);

    printf("Enter elements of mat2:\n");
    readMatrix(mat2, y, z);

    multiplyMatrices(mat1, mat2, prod, x, y, z);

    printf("Product Matrix:\n");
    displayMatrix(prod, x, z);

    return 0;
}
