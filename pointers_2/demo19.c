#include <stdio.h>
#pragma pack(1)
int main() {
    struct test {
        short a;
        char b;
        double c;
        int d;
    }v = { 12, 'S', 4.94, 432 }, * p;
    p = &v;
    printf("%d, %d\n", v.d, p->d);
    printf("%d\n", *(int*)((char*)&v + 11));
    printf("%d\n", *(int*)((char*)p + 11));

    p = NULL;
    printf("%u, %u, %u, %u\n", &p->a, &p->b, &p->c, &p->d);
    return 0;
}




