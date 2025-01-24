/***

    Note - Sizeof is compile time operator.
    It is evaluated at compile time only ( NOT runtime.
    gcc -g -o main -Wall -Wextra -pedantic -Wwrite-strings -fsanitize=address *.c -lm

    Date: Wed 15 Jan 2025 07:47:03 AM PST
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

void test_1() {
  int a = 3;
  // Note sizeof is compile time operator
  debug("sz of int = %ld", sizeof(++a)); // sizeof int 4, ++a never executed
  debug("sz of int = %d", a);
}

void test_sizeof() {
  int *ptr;
  int arr[5] = {11, 22, 33}; // [11 22 33 0 0] comipiler

  debug("sz of int = %ld", sizeof(int));
  debug("sz of ptr = %ld", sizeof(ptr));
  debug("sz of ptr = %ld", sizeof(arr));
}

int main (int argc, char **argv) {
  test_1();
  test_sizeof();
  return 0;
}

/**
   => ./a.out
   L=[28] [test] :| sz of int = 4
   L=[29] [test] :| sz of ptr = 8
   L=[30] [test] :| sz of ptr = 20
**/
