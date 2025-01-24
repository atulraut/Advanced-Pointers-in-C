/***
    Check - /home/atul/dev/atclib/bitwise/crack-d-ivi/litle-big-endian.c
 */

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

/**
 * => ./a.out
   Little Endian.
 */
