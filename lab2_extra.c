#include <stdio.h>
#define lmax 20

int main(void) {
    int maxi, iindex,sum, i, j, m, n, A[lmax][lmax];
    printf("Введите размеры матрицы\n");
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++) {
            printf("Элемент %d %d:\n", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("Введенная матрица:\n");
    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++) {
            printf("%5d ", A[i][j]);
        }
        printf("\n");
    }
    i = 1;
    for (j = 1; j<= m; j++) {
        sum+=A[1][j];
    }
    maxi = sum;
    iindex = 1;
    if (n > 1) {
        for (i = 2; i <= n; i++){
            sum = 0;
            for (j = 1; j <= m; j++) {
                sum+=A[i][j];
            }
            if (sum >= maxi) {
                maxi = sum;
                iindex = i;
            }
        }
        for (i = iindex; i < n; i++) {
            for (j = 1; j <= m; j++) {
                A[i][j] = A[i+1][j];
            }
        }
        printf("Измененная матрица:\n");
        for (i = 1; i < n; i++){
            for (j = 1; j <= m; j++) {
                printf("%5d ", A[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Строка только одна\n");
    }
    return 0;
}