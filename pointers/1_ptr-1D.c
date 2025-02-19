/***
    Pointers to 1-D array :

    1] arr and &arr[0] are same$
    2] arr and &arr are NOT same$

    gcc -g -o main -Wall -Wextra -pedantic -Wwrite-strings -fsanitize=address *.c -lm

    Date: Tue 18 Feb 2025 06:51:01 PM PST
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
  int arr[] = {1, 2, 3, 4};

  for (int i=0; i<4; ++i)
    debug ("Address[arr+%d]=[%pK]",i, arr+i);
  debug ("Address[arr+5]=[%pK]", arr+5);
  printf("\n");
  // arr and &arr[0] are same
  debug("Output arr=[%pK] &arr[0]=[%pK]", arr, &arr[0]);
  // arr and &arr are NOT same
  debug("Output arr+1=[%pK] &arr+1=[%pK]", arr+1, &arr+1);
}

int main (int argc, char **argv) {
  test();
  return 0;
}

/**
   L=[28] [test] :| Address[arr+0]=[0x7ffe6d230830K]
   L=[28] [test] :| Address[arr+1]=[0x7ffe6d230834K]
   L=[28] [test] :| Address[arr+2]=[0x7ffe6d230838K]
   L=[28] [test] :| Address[arr+3]=[0x7ffe6d23083cK]
   L=[29] [test] :| Address[arr+5]=[0x7ffe6d230844K]

   L=[32] [test] :| Output arr=[0x7ffe6d230830K] &arr[0]=[0x7ffe6d230830K]
   L=[34] [test] :| Output arr+1=[0x7ffe6d230834K] &arr+1=[0x7ffe6d230840K]
**/
