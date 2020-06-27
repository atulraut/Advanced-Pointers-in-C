// demo06.c
#include <stdio.h>

int main() {
    int arr[5] = { 11, 22, 33 };
    int i, *ptr = arr;

    for (i = 0; i < 5; i++)
        printf("arr[%d] = %d\n", i, arr[i]);
    printf("\n");

    for (i = 0; i < 5; i++)
        printf("*(arr+%d) = %d\n", i, *(arr+i));
    printf("\n");

    for (i = 0; i < 5; i++)
        printf("*(%d+arr) = %d\n", i, *(i + arr));
    printf("\n");

    for (i = 0; i < 5; i++)
        printf("%d[arr] = %d\n", i, i[arr]);
    printf("\n");


    for (i = 0; i < 5; i++)
        printf("ptr[%d] = %d\n", i, ptr[i]);
    printf("\n");

    for (i = 0; i < 5; i++)
        printf("*(ptr+%d) = %d\n", i, *(ptr + i));
    printf("\n");

    for (i = 0; i < 5; i++)
        printf("*(%d+ptr) = %d\n", i, *(i + ptr));
    printf("\n");

    for (i = 0; i < 5; i++)
        printf("%d[ptr] = %d\n", i, i[ptr]);
    printf("\n");

    short* p1 = &arr[3];
    int* p2 = &arr[0];
    printf("diff = %d\n", p1 - p2);

    printf("arr = %p\n", arr);
    printf("arr + 1 = %p\n", arr + 1);
    printf("&arr = %p\n", &arr);
    printf("&arr + 1 = %p\n", &arr + 1);

    return 0;
}
