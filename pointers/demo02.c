#include <stdio.h>

int a = 20;
void myfun(int p) {
    p = a;
}
int main() {
    int x = 10;
    myfun(x);
    printf("x = %d\n", x);
    return 0;
}
