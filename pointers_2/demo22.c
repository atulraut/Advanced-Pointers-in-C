#include <stdio.h>

int sum(int p, int q) {
    return p + q;
}

int subtract(int p, int q) {
    return p - q;
}

int main() {
    int (*p1)(int, int);
    int (*p2)(int, int);
    int res;
    p1 = sum;
    p2 = subtract;
    res = p1(12, 4);
    printf("%d\n", res);
    res = p2(12, 4);
    printf("%d\n", res);
    return 0;
}
