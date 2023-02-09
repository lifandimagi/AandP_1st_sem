#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define lmax 255

void deln(char *s);

int main(void) {
    char name[2][lmax], str[lmax][lmax], *ukaz, vv[lmax];
    int num=0;
    puts("Лабораторная работа №5");
    puts("Автор: Лифановский Дмитрий БИВ225");
    puts("Задача 2");
    puts("Введите имена входного и выходного файла");
    for (int i = 0; i < 2; i++) {
        do {
        } while ();
    }
    FILE *IN = fopen(name[0], "r");
    FILE *OUT = fopen(name[1], "w");
    if (IN == NULL || OUT == NULL) {
        fprintf(stderr, "Невозможно прочитать и открыть файлы\n");
    }
    while(fgets(str[num], lmax, IN)!=NULL) {
        deln(str[num]);
        num++;
    }
    fclose(IN);
    if (num < 1){
        puts("Входной файл пуст");
    } else {
        puts("Строки из входного файла");
        for (int i = 0; i < num; i++){
            puts(str[i]);
            ukaz = str[i];
            while (*ukaz){
                if (isdigit(*ukaz)){
                    *ukaz=*ukaz+17;
                }
                ukaz++;
            }
            fprintf(OUT, "%s",str[i]);
        }
        fclose(OUT);
        FILE *IN2 = fopen(name[1], "r");
        puts("Полученные строки из выходного файла");
        while(fgets(vv, lmax, IN2)!=NULL) {
            deln(vv);
            puts(vv);
        }
        fclose(IN2);
    }
    return 0;
}

void deln(char *s) {
    for(; *s && *s=='\n'; s++){
        *s='\0';
    }
}