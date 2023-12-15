/***
    Reverse Endiness
 **/
#include <stdio.h>

int rev(int a) {
    int x = a;
    char* p = (char*)&x;
    char* q = p + sizeof(a) - 1;
    while (p < q) {
        char t = *p;
        *p = *q;
        *q = t;
        p++;
        q--;
    }
    return x;
}

int main() {
    int num = 0x12345678;
    int res;
    res = rev(num);
    printf("num = %x\nres = %x\n", num, res);
    return 0;
}
