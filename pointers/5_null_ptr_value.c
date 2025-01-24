#include <stdio.h>

int main() {
    char* p1 = NULL; // 1
    short* p2 = NULL; // 2
    float* p3 = NULL; // 4
    double* p4 = NULL; // 8
    printf("%p, %p, %p, %p\n", ++p1, ++p2, ++p3, ++p4);
    return 0;
}
