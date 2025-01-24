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

/***
  C   0  1  2   3
  R 0 11 22 0   0
    1 33 44 55  0
    2 66 0  0   0

         R-->     0            1          2
  Ptr      0  1  2  3   0   1  2  3  0  1  2  3  <-- C
  [100]--> 11 22 0  0   33  44 55 0  66 0  0  0
          100 +4 +8 +11 |116         +132
 */

int main() {
         // R  C
    int arr[3][4] = { {11, 22}, {33, 44, 55}, {66} };
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }
    printf("\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++)
            printf("%d\t", *(*(arr+i)+j));
        printf("\n");
    }
    printf("\n");

    debug("arr = %p ", arr);
    debug("*arr = %p ", *arr);
    debug("&arr = %p ", &arr);

    debug("arr+1 = %p ", arr+1);
    debug("*arr+1 = %p ", *arr+1);
    debug("&arr+1 = %p ", &arr+1);

    debug("arr[1][2]  --> %d ", arr[1][2]);
    debug("arr[2][-3] --> %d ", arr[2][-3]);

    int(*ptr)[4] = arr;
    debug ("ptr[-1][6] --> %d ", ptr[-1][6]);
    return 0;
}

/**
   => ./a.out
   11	22	0	0
   33	44	55	0
   66	0	0	0

   11	22	0	0
   33	44	55	0
   66	0	0	0

   L=[44] [main] :| arr = 0x7ffea55595d0
   L=[45] [main] :| *arr = 0x7ffea55595d0
   L=[46] [main] :| &arr = 0x7ffea55595d0
   L=[48] [main] :| arr+1 = 0x7ffea55595e0
   L=[49] [main] :| *arr+1 = 0x7ffea55595d4
   L=[50] [main] :| &arr+1 = 0x7ffea5559600
   L=[52] [main] :| arr[1][2]  --> 55
   L=[53] [main] :| arr[2][-3] --> 44
   L=[56] [main] :| ptr[-1][6] --> 0
*/
