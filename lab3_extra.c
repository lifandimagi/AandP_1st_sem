#include <stdio.h>
#define lmax 50

void vv_matrix(int A[][lmax], int *n);
void print_matrix(int A[][lmax], int n);
int glav(int A[][lmax], int n);
void zam(int A[][lmax], int n, int s);

int main(void) {
    int n, A[lmax][lmax];
    vv_matrix(A, &n);
    print_matrix(A, n);
    printf("Сумма элементов на главной диагонали: %d\n", glav(A, n));
    zam(A, n, glav(A, n));
    printf("Матрица с заменой:\n");
    print_matrix(A, n);
}

void vv_matrix(int A[][lmax], int *n) {    
    printf("Введите размерность вашей КВАДРАТНОЙ матрицы:\n");
    scanf("%d", n);
    printf("Введите элементы вашей матрицы %d*%d\n", *n, *n);
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++){
            printf("Элемент матрицы %d %d\n", (i+1), (j+1));
            scanf("%d", &A[i][j]);
        }
    }
}

void print_matrix(int A[][lmax], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d", A[i][j]);
        }
        printf("\n");
    }
}

int glav(int A[][lmax], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j<n; j++) {
            if (i == j) {
                sum += A[i][j];
            }
        }
    }
    return sum;
}

void zam(int A[][lmax], int n, int s) {
    int k;
    printf("Введите число, на которое хотите заменить элементы матрицы, равные %d:\n", s);
    scanf("%d", &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == s) {
                A[i][j] = k;
            }
        }
    }
}