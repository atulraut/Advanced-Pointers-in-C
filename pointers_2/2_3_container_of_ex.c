#include <stdio.h>
#pragma pack(1)
#define debug(str,args...) printf("[%s] L=%d :"str"\n", __func__, __LINE__, ##args)

struct test {
  short a;
  char b;
  double c;
  int d;
};

static struct test v = { 12, 'S', 4.94, 432 };
static struct test *ptr = &v;

void test1() {
  debug("%d, %d", v.a, ptr->a);
  debug("%c, %c", v.b, ptr->b);
  debug("%lf, %lf", v.c, ptr->c);
  debug("%d, %d", v.d, ptr->d);
}

int test2() {
  debug("%d, %d", v.d, ptr->d);
  debug("%d", *(int*)((char*)&v + 11));
  debug("%d", *(int*)((char*)ptr + 11));
  return 0;
}

void test3() {
  ptr = NULL;
  /* Get offset of structure member variable using address of(In short I can access address) */
  debug("%d, %u, %u, %u", (short)&ptr->a, (char)&ptr->b, (unsigned int)&ptr->c, (int)&ptr->d);
  /* Crash if we access using pointers i.e. value at */
  debug("%d, %u, %u, %u", ptr->a, ptr->b, ptr->c, ptr->d);
}

int main() {
  test1();
  test2();
  test3();
  return 0;
}

/**
   [test1] L=16 :12, 12
   [test1] L=17 :S, S
   [test1] L=18 :4.940000, 4.940000
   [test1] L=19 :432, 432
   [test2] L=23 :432, 432
   [test2] L=24 :432
   [test2] L=25 :432
   [test3] L=32 :0, 2, 3, 11
**/


