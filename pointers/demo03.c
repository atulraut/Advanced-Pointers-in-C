#include <stdio.h>

int a = 20;
void myfun(int* p) {
    *p = a;
}
int main() {
    int x = 10;
    int* p = &x;
    myfun(p);
    printf("x = %d\n", x);
    return 0;
}
