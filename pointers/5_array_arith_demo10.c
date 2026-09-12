#include <stdio.h>

int main() {

    int arr[5] = { 11, 22, 33 };

    printf("arr = %p\n", arr);
    printf("arr+1 = %p\n", arr+1);
    printf("&arr = %p\n", &arr);
    printf("&arr+1 = %p\n", &arr + 1);

    return 0;
}

/**
   arr = 0x16ef3f130
   arr+1 = 0x16ef3f134
   &arr = 0x16ef3f130
   &arr+1 = 0x16ef3f144
*/
