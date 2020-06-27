#include <stdio.h>

int main() {
    short a = 0x1234;
    char* p = (char*)&a;
    if (*p == 0x34)
        printf("Little Endian.\n");
    else
        printf("Big Endian.\n");
    return 0;
}
