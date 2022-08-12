#include <stdio.h>

struct op {
    int x, y;
    int (*fn)(int, int);
};
int sum(int p, int q) {
    return p + q;
}
int subtract(int p, int q) {
    return p - q;
}
int calculate(struct op* ptr) {
    return ptr->fn(ptr->x, ptr->y);
}

int main() {
    int x = 12, y = 3;
    struct op a = { x, y, sum };
    struct op b = { x, y, subtract };
    printf("%d\n", calculate(&a));
    printf("%d\n", calculate(&b));
    return 0;
}

