#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int matrix[n][n];
    int flag = 1;

    // Input matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check identity matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(i == j && matrix[i][j] != 1)
                flag = 0;

            if(i != j && matrix[i][j] != 0)
                flag = 0;
        }
    }

    if(flag)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}