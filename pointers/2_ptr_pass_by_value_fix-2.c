/***
    Understand pass by value and pass by address
    gcc -g -o main -Wall -Wextra -pedantic -Wwrite-strings -fsanitize=address *.c -lm

    Date: Sat 11 Jan 2025 05:39:58 AM PST
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

void changePointer1(int **ptr) {
  static int y = 99;
  *ptr = &y; // Change the pointer to point to y
}

int test1() {
  int x = 10;
  int *p = &x;

  debug("Before: p points to %d\n", *p); // Output: p points to 10
  changePointer1(&p); // Pass the pointer by address
  debug("After: p points to %d\n", *p);  // Output: p points to 99

  return 0;
}


void changePointer2(int *ptr) {
  static int y = 99;
  //    ptr = &y; // Change the pointer to point to y  - Not work here
  *ptr = y;
}

int test2() {
  int x = 10;
  int *p = &x;

  debug("Before: p points to %d\n", *p); // Output: p points to 10
  changePointer2(&x); // Pass the pointer by address
  debug("After: p points to %d\n", *p);  // Output: p points to 99

  return 0;
}

int main() {
  test1();
  test2();
}

/**
   L=[32] [test1] :| Before: p points to 10

   L=[34] [test1] :| After: p points to 99

   L=[50] [test2] :| Before: p points to 10

   L=[52] [test2] :| After: p points to 99
**/
