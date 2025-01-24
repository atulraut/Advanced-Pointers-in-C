/***

    gcc -g -o main -Wall -Wextra -pedantic -Wwrite-strings -fsanitize=address *.c -lm

    Date:
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
  int ret = 0;
  int arr[5] = { 11, 22, 33 }; // [11 22 33 0 0] - compiler does it
  int i, *ptr = arr;

  debug("Output = %d", *(ptr+2));
  debug("Output = %d", *(ptr-2));
}

int main (int argc, char **argv) {
  test();
  return 0;
}

/**
   => ./a.out   L=[28] [test] :| Output = 33
   L=[29] [test] :| Output = -194626000
**/
