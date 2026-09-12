/***

    sizeof is compile time operator, hence ++a never gets
    executed
    sizeof return unsgiend int

    gcc -g -o main -Wall -Wextra -pedantic -Wwrite-strings -fsanitize=address *.c -lm

    Date: Fri Sep 11 15:58:54 PDT 202
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

void test() {

  int a= 7;
  debug("Output = %ld", sizeof(++a));
  debug("Output = %d", a);
}

int main (int argc, char **argv) {
  test();
  return 0;
}

/**
   L=[30] [test] :| Output = 4
   L=[31] [test] :| Output = 7
**/
