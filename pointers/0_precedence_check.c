#include <stdio.h>

int main() {
  int arr[5] = { 11, 22, 33 }; // 11 22 33 0 0 <-- How Compiler Sees it
    int* ptr = arr;
    printf("*ptr=%d, ++*ptr++=%d, (*ptr)++=%d, *ptr++=%d, *++ptr=%d, ++*ptr=%d\n",
        *ptr, ++*ptr++, (*ptr)++, *ptr++, *++ptr, ++*ptr);
    return 0;
}

