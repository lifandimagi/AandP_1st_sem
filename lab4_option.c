#include <stdio.h>

int main(void) {
    int n;
    printf("Введите номер вашего варианта:\n");
    scanf("%d", &n);
    printf("Номер вашего варината для задания 1:%d\n", (n%12) + 1);
    printf("Номер вашего варината для задания 2:%d\n", (n%10) + 1);
    printf("Номер вашего варината для задания 3:%d\n", (n%11) + 1);
}