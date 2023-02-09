#include <stdio.h>

int main(void) {
    int res = 0, i, count=0, num=0;
    float chislo, sum = 0;
    FILE *fl = fopen("file1.txt", "w");
    if (fl == NULL) {
        fprintf(stderr, "Невозможно открыть файл\n");
    }
    puts("Лабораторная работа №5");
    puts("Автор: Лифановский Дмитрий БИВ225");
    puts("Задача 1");
    puts("Введите последовательно действительные числа, которые будут записаны в файл");
    while (res != EOF) {
        do {
            res = 0;
            res = scanf("%f", &chislo);   
        } while ((getchar()!='\n' || res != 1) && res != EOF);
        if (res!=EOF) {
            fprintf(fl, "%f\n", chislo); 
            num++;
        }
    }
    fclose(fl);
    if (num > 0) {
        fl = fopen("file1.txt", "r");
        for (i = 0; i < num; i++) {
            res = 0;
            res = fscanf(fl, "%f", &chislo);
            if (res==1) {
                if (chislo > 0) {
                    sum+=chislo;
                    count++;
                }
            }
        }
        fclose(fl);
        if(count!=0) {
            printf("\nСреднее арифметическое положительных чисел в файле: %f\n", sum/count);
        } else {
            puts("Положительных чисел не нашлось.");
        }
    } else {
        puts("Вы не ввели числа, соответственно выполнить 2 часть невозможно");
    }
    return 0;
}