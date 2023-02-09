#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define lmax 100

int lenlong(char str[][lmax], int k);
void understr(char str[], char unstr[][lmax], int k, int *knew);
void replace(char str[]);

int main(void) {
    char str[lmax][lmax], unstr[(int)(lmax/3)][lmax];
    int k, res, i, res_max;
    int knew;
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
    res_max = lenlong(str, k);
    if (res_max <= 0) {
        puts("Ошибка! Не удалось найти максимальную по длине строку");
    } else {
        puts("");
        printf("Максимальная по длине строка под номером %d\n", res_max+1);
        puts(str[res_max]);
        understr(str[res_max], unstr, k, &knew);
        puts("");
        puts("Найденный подстроки");
        for (int i = 0; i < knew; i++){
            puts(unstr[i]);
        }
        replace(unstr[0]);
        puts("Замененная подстрока");
        puts(unstr[0]);
    }
    return 0;
}

int lenlong(char str[][lmax], int k) {
    int max_len = -1;
    int max_ind = -1;
    int l;
    for (int i = 0; i < k; i++) {
        l = strlen(str[i]);
        if (l > max_len){
            max_len = strlen(str[i]);
            max_ind = i;
        }
    }
    return max_ind;
}

void understr(char str[], char unstr[][lmax], int k, int *knew) {
    int i;
    char *ukaz, *ukaz_first;
    *knew = 0;
    ukaz = str;
    while (*ukaz) {
        if ((*ukaz)=='{') {
            ukaz++;
            ukaz_first = ukaz;
            while (*ukaz && (*ukaz)!='}') {
                ukaz++;
            }
            if ((*ukaz)=='}' && ukaz!=ukaz_first) {
                strncpy(unstr[*knew], ukaz_first, ukaz-ukaz_first);
                unstr[*knew][ukaz-ukaz_first] = '\0';
                (*knew)++;
            }
        } else {
            ukaz++;
        }
    }
}

void replace(char str[]) {
    int l = strlen(str);
    for (int i = 0; i < l; i++){
        if(str[i] == '+') {
            str[i] = '-';
        }
    }
}