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
    printf("sizeof(p) = %ld\n", sizeof(p));
    printf("sizeof(pp) = %ld\n", sizeof(pp));
    return 0;
}

/*
  => ./a.out
  1.200000
  1.200000
  1.200000
  p = 0x7ffc2e9f8cc0
  pp = 0x7ffc2e9f8cc8
  sizeof(p) = 8
  sizeof(pp) = 8
*/
