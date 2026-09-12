/**
   offset_of - why & when to used

   If we have address of member, then we can get address of begining of the structure.
   e.g.
   Per below we struct member address int d, then we can get struct test base address.

   int* d = &v.d  // Here I have pointer to the member & use am getting base address to the structure test.
   struct test* qPtr = (struct test *)((char *)d - offset_of(struct test, d))

   container_of --> It lets you get the address of the containing structure when you
                    only have a pointer to one of its members.
**/
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

/**
   &v = 1827959096
   &v.d = 1827959099
   offset_of(struct test, a) = 0
   offset_of(struct test, b) = 2
   offset_of(struct test, c) = 3
   offset_of(struct test, d) = 11
   container_of(&v.a, struct test, a) = 1827959096
   container_of(&v.b, struct test, b) = 1827959096
   container_of(&v.c, struct test, c) = 1827959096
   container_of(&v.d, struct test, d) = 1827959096
**/

