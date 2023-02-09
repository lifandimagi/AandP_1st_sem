/*ЗАМЕЧАНИЕ 1: получилась 1 основная функция fun_fukt, которая возвращает значение ln(k!) и она вызывается несколько раз
ТРЕБОВАНИЕ 1: стандартная проверка с циклом с постусловием и очисткой потока
ТРЕБОВАНИЕ 2: выполнено (проконсультировался с ЕА, уточнил, что необходимо все вводы/выводы выполнить в виде функций)
ТРЕБОВАНИЕ 3: массивов нет*/

#include <stdio.h>                                                                                       //библиотека ввода/вывода
#include <math.h>                                                                                        //библиотека для работы функций ln и exp
#define lmax 50                                                                                          //максимально возможное вводимое число, так как факториалы больших чисел считать намного медленне и сложнее и незачем
#define _CRT_SECURE_NO_WARNINGS                                                                          //для понимания, что scanf может быть небезопасен

void vv_numbers(int *n, int*m);                                                                          //прототипы
float fun_fakt(int k);
void res_fun(int n, int m);                                                                              

int main(void) {
    int n, m;                                                                                            //инициализируем основные переменные
    printf("Лабораторная работа №3\n");
    printf("Автор: Лифановский Дмитрий БИВ225\n");
    printf("Задание 1\n");
    printf("Введите два целых неотрицательных числа n и m таких, что m >= n, и не превышающих максимальное значение: %d\n", lmax);
    vv_numbers(&n, &m);
    res_fun(n, m);
    return 0;                                                                                            //основная функция всегда заканчивается без "наших" ошибок
}

void vv_numbers(int *n, int*m) {
    int res;
    do {                                                                                                 //вводим два числа до тех пор, пока не будет верно
        res = 0;                                                                                             
        printf("Ввод будет доступен до тех пор, пока данные не будут введены правильно.\n");
        res = scanf("%d%d", n, m);
    } while(getchar()!='\n' || *n < 0 || *m < 0 || *n > lmax || *m > lmax || *m < *n || res != 2);
}

float fun_fakt(int k) {                                                                                  //основная функция
    float sum = .0;                                                                                      //для подсчета и его возврата
    if (k == 0) {                                                                                        //факториал нуля определяется отдельно, не как другие ЦЕЛЫЕ ПОЛОЖИТЕЛЬНЫЕ ЧИСЛА, для которых n! = 1*2*...*n
        return 0;                                                                                        //так как 0! = 1 => ln(1) = 0
    } else {                                                                                             //для других целых положительных чисел
        for (int i = 1; i <= k; i++) {                                                                   //по определению из условия задачи, что ln(k!) = СУММ(ln(i)), где i = 1,k
            sum += log(i);                                                                               //по формуле
        }
        return sum;                                                                                      //возвращаем полученное значение
    }
}

void res_fun(int n, int m) {
    float a = exp(fun_fakt(m) - fun_fakt(n) - fun_fakt(m-n));
    printf("\nРезультат выполнения программы: a = %.0f\n", a);                                             //можно перевести в целое значение, так как по свойствам 
}