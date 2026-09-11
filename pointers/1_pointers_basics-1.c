/***

    Basics of Pointers
    gcc -g -o main -Wall -Wextra -pedantic -Wwrite-strings -fsanitize=address *.c -lm

    Date: Fri Sep 11 11:55:34 PDT 2026
    Folsom, CA.
 */

/*----------------------------------- Header --------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> // va_arg
#include <ctype.h>
#include <limits.h>
#include <string.h>  /* malloc */
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <stdint.h> /* uint32_t */
#include <unistd.h> /* sleep */

#define debug(str,args...) printf("L=[%d][%s]->[%s] :| "str"\n",__LINE__,__FILE__, __func__, ##args)

void test() {
  int a = 1;
  int *ptr = &a;
  int **ptr2 = &ptr;

  debug("Output = %d [%pK]", a, &a);
  debug("Output = [%pK] [%pK]-[%d]", ptr, &ptr, *ptr);
  debug("Output = [%pK] [%pK] [%pK] [%d]", ptr2, &ptr2, *ptr2, **ptr2);
}

int main (int argc, char **argv) {
  test();
  return 0;
}

/**
    L=[30][pointers/1_pointers_basics-1.c]->[test] :| Output = 1 [0x16fcb311cK]
    L=[31][pointers/1_pointers_basics-1.c]->[test] :| Output = [0x16fcb311cK] [0x16fcb3110K]-[1]
    L=[32][pointers/1_pointers_basics-1.c]->[test] :| Output = [0x16fcb3110K] [0x16fcb3108K] [0x16fcb311cK] [1]
 **/
