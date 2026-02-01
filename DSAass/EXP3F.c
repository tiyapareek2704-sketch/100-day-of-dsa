#include <stdio.h>

int main() {
    int matrix[10][10], sparse[20][3];
    int rows, cols, i, j, count = 0;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");
    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(matrix[i][j] != 0) {
                sparse[count][0] = i;
                sparse[count][1] = j;
                sparse[count][2] = matrix[i][j];
                count++;
            }
        }
    }

    printf("\nSparse Matrix Representation:\n");
    printf("Row Col Value\n");
    for(i = 0; i < count; i++) {
        printf("%d   %d   %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    return 0;
}