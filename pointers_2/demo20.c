#include <stdio.h>
#pragma pack(1)

#define offset_of(type,member) ((unsigned int)&((type*)NULL)->member)
#define container_of(ptr,type,member) ((type*)(((char*)ptr)-offset_of(type,member)))

struct test {
    short a;
    char b;
    double c;
    int d;
};
int main() {
    struct test v = { 12, 'S', 4.94, 432 };
    double* pd = &v.c;
    
    printf("&v = %u\n", &v);
    printf("&v.d = %u\n", pd);
    
    printf("offset_of(struct test, a) = %u\n", offset_of(struct test, a));
    printf("offset_of(struct test, b) = %u\n", offset_of(struct test, b));
    printf("offset_of(struct test, c) = %u\n", offset_of(struct test, c));
    printf("offset_of(struct test, d) = %u\n", offset_of(struct test, d));

    printf("container_of(&v.a, struct test, a) = %u\n", container_of(&v.a, struct test, a));
    printf("container_of(&v.b, struct test, b) = %u\n", container_of(&v.b, struct test, b));
    printf("container_of(&v.c, struct test, c) = %u\n", container_of(&v.c, struct test, c));
    printf("container_of(&v.d, struct test, d) = %u\n", container_of(&v.d, struct test, d));
    return 0;
}

