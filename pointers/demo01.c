#include <stdio.h>

int main() {
    double a = 1.2;
    double* p = &a;
    double** pp = &p;
    printf("%lf\n", a);
    printf("%lf\n", *p);
    printf("%lf\n", **pp);
    printf("p = %p\n", p);
    printf("pp = %p\n", pp);
    printf("sizeof(p) = %u\n", sizeof(p));
    printf("sizeof(pp) = %u\n", sizeof(pp));
    return 0;
}
