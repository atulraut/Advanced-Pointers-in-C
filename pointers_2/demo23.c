#include <stdio.h>

int sum(int p, int q) {
    return p + q;
}

int subtract(int p, int q) {
    return p - q;
}

int main() {
    int (*arr[2])(int, int);
    int i, res;
    arr[0] = sum;
    arr[1] = subtract;
    for (i = 0; i < 2; i++) {
        res = arr[i](12, 4);
        printf("%d\n", res);
    }
    return 0;
}
