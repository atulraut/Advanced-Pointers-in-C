// demo09.c
#include <stdio.h>

void print_arr(int a[][4]);

int main() {
    int arr[3][4] = { {11, 22}, {33, 44, 55}, {66} };
    int i, j;
    int(*ptr)[4] = arr;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++)
            printf("%d\t", ptr[i][j]);
        printf("\n");
    }
    printf("\n");

    print_arr(arr);
}

void print_arr(int a[][4]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
    printf("\n");
}
