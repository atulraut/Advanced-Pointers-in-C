#include <stdio.h>

int main() {
    int arr[3][4] = { {11, 22}, {33, 44, 55}, {66} };
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }
    printf("\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++)
            printf("%d\t", *(*(arr+i)+j));
        printf("\n");
    }
    printf("\n");

    printf("arr = %u\n", arr);
    printf("*arr = %u\n", *arr);
    printf("&arr = %u\n", &arr);

    printf("arr+1 = %u\n", arr+1);
    printf("*arr+1 = %u\n", *arr+1);
    printf("&arr+1 = %u\n", &arr+1);

    printf("%d\n", arr[1][2]);
    printf("%d\n", arr[2][-3]);

    int(*ptr)[4] = arr;
    printf("%d\n", ptr[-1][6]);
    return 0;
}
