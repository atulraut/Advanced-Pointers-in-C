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



