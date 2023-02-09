#include <stdio.h>
#define lmax 50

int main(void) {
    int k, res = 0, q, X[lmax], newnamber;
    printf("Лабораторная работа №2\nАвтор: Лифановский Дмитрий БИВ225\nЗадание 2\nВведите длину массива (k) X от 1 до %d:\n", lmax);
    do {
        printf("Ввод будет достпуен до тех пор, пока данные не будут введены правильно.\n");                                           //ввод длины массива с проверкой на корректность данных и дополнительный ввод
        res = scanf("%d", &k);
    } while(getchar()!='\n' || k < 1 || k > lmax || res!= 1);
    printf("Введите по очереди элементы массива\n");
    for(q = 1; q <= k; q++){
        res = 0;
        do {
            printf("Элемент %d:\n", q);
            res = scanf("%d", &X[q]);
        } while(getchar()!='\n' || res!= 1 || X[q] < 1);
    }
    printf("Введенный массив:\n");
    for(q = 1; q <= k; q++){
        printf("%5d ", X[q]);
    }
    printf("\n");
    printf("Новый массив:\n");
    for (q = 1; q <= k; q++){
        newnamber = X[q];
        X[q] = 0;
        while (newnamber > 0) {
            X[q] = X[q] * 10 + (newnamber % 10);
            newnamber = (int)newnamber/10;
        }
        printf("%5d ", X[q]);
    }
    printf("\n");
    return 0;
}