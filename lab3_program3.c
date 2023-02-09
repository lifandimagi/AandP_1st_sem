#include <stdio.h>
#define lmax 50
#define _CRT_SECURE_NO_WARNINGS

void vv_mas(int A[lmax], int *n);
void count_rep(int A[lmax], int n, int B[lmax], int kol[lmax], int *k);
void print_mas(int A[lmax], int n);
void remove_el(int A[lmax], int *n, int B[lmax], int kol[lmax], int k);

int main(void) {
    int A[lmax], B[lmax], kol[lmax], n, *k, m;
    printf("Лабораторная работа №3\n");
    printf("Автор: Лифановский Дмитрий БИВ225\n");
    printf("Задание 3\nВведите длину массива (n), не превышающую %d\n", lmax);
    vv_mas(A, &n);
    m = n;
    count_rep(A, n, B, kol, k);
    printf("Количество повторений каждого элемента:\n");
    print_mas(B, *k);
    print_mas(kol, *k);
    remove_el(A, &n, B, kol, *k);
    if (n == 0) {
        printf("Массив удален полностью\n");
    } else {
        if (n ==m) {
            printf("Удалений не было\n");
        } else {
            printf("Массив без одиночных элементов:\n");
            print_mas(A, n);
        }
    }
    return 0;
}

void vv_mas(int A[lmax], int *n) {
    int res;
    do {
        res = 0;
        printf("Ввод будет доступен до тех пор, пока данные не будут введены правильно\n");                                           //ввод длины массива с проверкой на корректность данных и дополнительный ввод
        res = scanf("%d", n);
    } while(getchar()!='\n' || *n < 1 || *n > lmax || res!= 1);
    printf("Введите поочередно каждый элемент массива\n");
    for(int i = 0; i < *n; i++){
        do {
            res = 0;
            printf("Элемент %d:\n", (i+1));
            res = scanf("%d", A+i);
        } while(getchar()!='\n' || res!= 1);
    }
    printf("\nВведенный массив:\n");
    for(int i = 0; i < *n; i++){
        printf("%5d ", *(A+i));
    }
    printf("\n");
}

void count_rep(int A[lmax], int n, int B[lmax], int kol[lmax], int *k) {
    *k = 0;
    for (int i = 0; i < n; i++) {
        int j = 0;
        while ( A[i] != B[j] && j < *k) {
            j++;
        }
        if (j >= *k) {
            B[*k] = A[i];
            kol[*k] = 1;
            (*k)++;
        } else {
            kol[j]++;
        }
    }
}

void print_mas(int A[lmax], int n) {
    for (int i = 0; i < n; i++) {
        printf("%5d ", *(A+i));
    }
    printf("\n");
}

void remove_el(int A[lmax], int *n, int B[lmax], int kol[lmax], int k) {
    //int m = *n;
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < k; j++) {
            if (A[i] == B[j] && kol[j] == 1) {
                for (int l = i; l < (*n-1); l++) {
                    A[l] = A[l+1];
                }
                *n -= 1;
                i-=1;
            }
        }
    }
}