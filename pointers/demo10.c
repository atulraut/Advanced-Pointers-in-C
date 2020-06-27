#include <stdio.h>

int main() {
    int arr[5] = { 11, 22, 33 };
    printf("arr = %u\n", arr);
    printf("arr+1 = %u\n", arr+1);
    printf("&arr = %u\n", &arr);
    printf("&arr+1 = %u\n", &arr + 1);
    return 0;
}
