#include <stdio.h>

int main() {
    int arr[5] = { 11, 22, 33 };
    int* ptr = arr;
    printf("%d, %d, %d, %d, %d, %d\n",
        *ptr, ++*ptr++, (*ptr)++, *ptr++, *++ptr, ++ * ptr);
    return 0;
}

