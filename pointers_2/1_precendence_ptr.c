/***

    Pointers : Understanding Precedence & Associativity!

    gcc -g -o main -Wall -Wextra -pedantic -Wwrite-strings -fsanitize=address *.c -lm

    Date: Sat Sep 12 10:08:25 PDT 2026
    Folsom, CA.
 */

/*----------------------------------- Header --------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>  /* malloc */
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <stdint.h> /* uint32_t */
#include <unistd.h> /* sleep */

#define debug(str,args...) printf("L=[%d] [%s] :| "str"\n", __LINE__, __func__, ##args)

void sun_test() {

  int arr[5] = {11, 22, 33}; // rest element become 0
  int* ptr = arr;
  // output printed is left to right executed reason unknow.
  debug("*ptr=[%d] ++*ptr++=[%d] (*ptr)++=[%d] *++ptr=[%d], ++*ptr=[%d]", *ptr, ++*ptr++, (*ptr)++,  *++ptr, ++*ptr);
}

void test() {

  int i = 10;
  int j = 20;
  int* ptr1 = &i;
  int* ptr2 = &j;
  debug(" *ptr1++ = %d", *ptr1++);
  debug(" *ptr1 = %d", *ptr1);
  debug(" ++*ptr2++ = %d",  ++*ptr2++); // *ptr execute first, then on that value preincremented so 20 + 1 == 21
  debug(" *ptr2 = %d", *ptr2);

}

int main (int argc, char **argv) {
  test();
  debug("Pointers Undestanding!");
  sun_test();
  return 0;
}

/**
   L=[43] [test] :|  *ptr1++ = 10
   L=[44] [test] :|  *ptr1 = 1839903056
   L=[45] [test] :|  ++*ptr2++ = 21
   L=[46] [test] :|  *ptr2 = 1826746544
   L=[48] [main] :| Pointers Undestanding!
   L=[30] [sun_test] :| *ptr=[11] ++*ptr++=[12] (*ptr)++=[22] *++ptr=[33], ++*ptr=[34]
 **/
