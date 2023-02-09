#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define lmax 50

int main(void) {
    char str1[lmax], str2[(int)lmax/3][lmax], *ukaz, *ukazn, *ukazfix;
    int k = 0;
    FILE *IN = fopen("in2.txt", "r");
    fgets(str1, lmax, IN);
    fclose(IN);
    ukaz = str1;
    while(*ukaz) {
        if (*ukaz == '[') {
            ukaz++;
            ukazn = ukaz;
            while (*ukaz != ']'){
                ukaz++;
            }
            if (*ukaz == ']') {
                strncpy(str2[k], ukazn, ukaz-ukazn);
                str2[k][ukaz-ukazn] = '\0';
                k++;
            }
        } else {
            ukaz++;
        }
    }
    for (int i = 0; i < k; i++) {
        puts(str2[i]);
        ukaz = str2[i];
        while (*ukaz) {
            if (*ukaz == '1') {
                ukazfix = ukaz;
                while(*(ukaz+1)) {
                    *ukaz = *(ukaz + 1);
                    ukaz++;
                }
                *ukaz = '\0';
                *(ukaz+1) = '\n';
                ukaz = ukazfix;
            } else {
                ukaz++;
            }
        }
    }
    FILE *OUT = fopen("out2.txt", "w");
    for (int i = 0; i < k; i++){
        fputs(str2[i], OUT);
    }
    fclose(OUT);
    return 0;
}