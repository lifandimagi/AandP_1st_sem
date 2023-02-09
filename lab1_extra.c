#include <stdio.h>
#include <math.h>

int main(void) {
    int n;
    int lmax = (int)pow(2, 8 * sizeof(int) - 1);
    printf("Задание 1:\nВведите длину массива M:\n");
    scanf("%d", &n);
    int M[n+1];
    if (n < 1 || n > lmax){
        return -1;
    }
    printf("Массив M из %d элементов:\n", n);
    for (int i = 1; i <= n; i++){
        M[i] = pow(-1, i) + pow(i, 2);
        printf("%d ", M[i]);
    }
    printf("\nЗадание 2. Найти первый min\n");
    int minvalue = M[n];
    int minindex = n;
    for (int i = n; i > 0; i--){
        if (M[i]<= minvalue){
            minvalue = M[i];
            minindex = i;
        }
    }
    printf("Первый минимальный элемент: %d\n", minvalue);
    if(minindex == 1) {
        printf("Минимальный элемент - первый в массиве. Задание 3 выполнить невозможно!\n");
    } else {
        int sum = 0;
        for(int i = 1; i < minindex; i++){
            sum+=M[i];
        }
        int srzn = sum/(minindex - 1);
        printf("Среднее арифметическое: %d: \n", srzn);
    }
    return 0;
}