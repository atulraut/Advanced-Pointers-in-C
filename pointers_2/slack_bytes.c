#include <stdio.h>
#define debug(str,args...) printf("[%s] L=%d :"str"\n", __func__, __LINE__, ##args)
#define at_offset_off(type, member) ((long)&((type *)0)->member)
/* Empty struct */
struct test1 {

};

void testEmptyStructSize() {
  struct test1 t;
  debug("Hello World = %ld ", sizeof(t));
}

struct test2{
  char c;
  int  i;
};

/***
 * Slack byte/Struct Padding/Byte Alignment
 * Compiler add slack bytes to make address of
 * each member multiple of its size
 **/
void testSlackBytes() {
  struct test2 t;
  debug ("t   = %pK", &t);
  debug ("t.c = %pK", &t.c);
  debug ("t.i = %pK", &t.i);
  debug ("t.c = %d ", at_offset_off(struct test2, c));
  debug ("t.c = %d ", at_offset_off(struct test2, i));
}

int main() {
  debug ("Enter");
  testEmptyStructSize();
  testSlackBytes();
  debug("End");
  return 0;
}

/**
 *  > ./a.out
 [main] L=34 :Enter
 [testEmptyStructSize] L=11 :Hello World = 0
 [testSlackBytes] L=26 :t   = 0x7ffc218fdd00K
 [testSlackBytes] L=27 :t.c = 0x7ffc218fdd00K
 [testSlackBytes] L=28 :t.i = 0x7ffc218fdd04K
 [testSlackBytes] L=29 :t.c = 0
 [testSlackBytes] L=30 :t.c = 4
 [main] L=37 :End
 * */
