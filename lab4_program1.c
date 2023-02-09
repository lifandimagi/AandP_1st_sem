#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define lmax 50

void search(char str[][lmax], int k, int *knew, char str1[][lmax], int index[]);
int min_str(char str1[][lmax], int knew);
int twice_lat(char *string);

int main(void) {
    char str[lmax][lmax], str1[lmax*(int)(lmax/3)][lmax];
    int res, k, knew = 0, i, index[lmax], min_res;
    puts("Лабораторная работа №4");
    puts("Автор: Лифановский Дмитрий БИВ225");
    puts("");
    puts("Задание 1");
    printf("Укажите число строк k < %d, которые вы хотите ввести:\n", lmax);
    do {
        res = 0;
        res = scanf("%d", &k);
    } while (getchar()!='\n' || res != 1 || k < 1 || k > lmax);
    printf("Введите последовательно указанное число строк, по длине не превышающих %d символов:\n", lmax-1);
    for (i = 0; i < k; i++) {
        do {
            printf("Введите строку №%d\n", i+1);
        } while (fgets(str[i], lmax, stdin)==NULL);
    }
    search(str, k, &knew, str1, index);
    if (knew==0) {
        puts("В введенных строках не существует подстрок либо они нулевые");
        puts("Выполнение дальнейших заданий не возможно");
    } else {
        puts("Выделенные подстроки");
        for (i = 0; i < knew; i++) {
            puts(str1[i]);
        }
        puts("");
        puts("Задание №2");
        min_res = min_str(str1, knew);
        if (min_res == -1) {
            puts("Произошла непредвиденная ошибка! Попробойте перезапустить программу.");
        } else {
            puts("Самая минимальная по длине подстрока:");
            puts(str1[min_res]);
            printf("Это подстрока рассполагается в %d строке\n", index[min_res]+1);
        }
        puts("");
        puts("Задание №3");
        if (twice_lat(str[index[min_res]])) {
            printf("Новая %d строка, в которой все латинские буквы удвоены\n", index[min_res]+1);
            puts(str[index[min_res]]);
        } else {
            printf("В строке %d изменений не было\n", index[min_res]+1);
        }
    }
    return 0;
}

void search(char str[][lmax], int k, int *knew, char str1[][lmax], int index[]) {
    int i;
    char *ukaz, *ukaz_first;
    *knew = 0;
    for (i = 0; i < k; i++) {
        ukaz = str[i];
        while (*ukaz) {
            if ((*ukaz)=='+' || (*ukaz)=='-' || (*ukaz)=='*' || (*ukaz)=='/') {
                ukaz++;
                ukaz_first = ukaz;
                while (*ukaz && (*ukaz)!='+' && (*ukaz)!='-' && (*ukaz)!='*' && (*ukaz)!='/') {
                    ukaz++;
                }
                if (((*ukaz)=='+' || (*ukaz)=='-' || (*ukaz)=='*' || (*ukaz)=='/') && ukaz!=ukaz_first) {
                    index[*knew] = i;
                    strncpy(str1[*knew], ukaz_first, ukaz-ukaz_first);
                    str1[*knew][ukaz-ukaz_first] = '\0';
                    (*knew)++;
                }
            } else {
                ukaz++;
            }
        }
    }
}

int min_str(char str1[][lmax], int knew) {
    int min_len = lmax, min_ind = -1, i;
    for (i = 0; i < knew; i++) {
        if (strlen(str1[i]) < min_len) {
            min_len = strlen(str1[i]);
            min_ind = i;
        }
    }
    return min_ind;
}

int twice_lat(char *string) {
    int flag = 0;
    char *ukaz;
    while (*string) {
        if (isalpha(*string)) {
            flag = 1;
            ukaz = string + strlen(string);
            while (ukaz >= string) {
                *(ukaz+1) = *ukaz;
                ukaz--;
            }
            string = string + 2;
        } else {
            string++;
        }
    }
    return flag;
}