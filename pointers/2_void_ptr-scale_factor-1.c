/***

    gcc -g -o main -Wall -Wextra -pedantic -Wwrite-strings -fsanitize=address *.c -lm

    Date: Sat 11 Jan 2025 06:01:33 AM PST
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

/***
    Notes on Scale Factore :
    Size of data type of pointer is known as Scale factor.

    Scale factor defines number of bytes to be read/written
    while dereferencing the pointer.

    Scale factor of different pointers -
    1] Pointer to primitive types: char* -1byte, short*-2bytes,
    int*, long*-8bytes, float*-4bytes, double*-8bytes
    2] Pointer to pointer: char**, short**, int**, long**, float**, double**,  - all 8 bytes
    3] Pointer to struct/union - Size of struct
    4] void*  - No scale factore defined - always needs to typecast.
    5] void** - 8 bypes or depending on your compiler - scale factor for void ** is sizeof(void *).
    5] Function Pointer - No scale factore defined

    • Scale factor plays significant role in pointer arithmetic.
    -> n locations ahead from current location
       ptr + n = (ptr + n * scale factor of ptr)
    -> n locations behind from current location
       ptr - n = (ptr - n * scale factor of ptr)
    -> number of locations in between (if ptr1 & ptr 2 different type then ptr1 type picked up)
       ptr1 - ptr2 = (ptr1 - ptr2) / scale factore of ptr1
*/
void test1() {
  int a = 10;
  void *p = &a;
  //  printf ("-> %d ", *p);  - Check below Foo Note A
  debug ("-> %d ", *(int *)p); // Note type cast as int* here
}

void test2() {
  debug ("Sizeof void* = %ld", sizeof(void *));
}

int main (int argc, char **argv) {
  test1();
  test2();
  return 0;
}

/**
   Foo Note A :
   2_void_ptr-scale_factor.c:26:21: warning: dereferencing ‘void *’ pointer
   26 |   printf ("-> %d ", *p);
   |                     ^~
   2_void_ptr-scale_factor.c:26:21: error: invalid use of void expression

**/

/***
    => ./a.out
    L=[49] [test1] :| -> 10
    L=[53] [test2] :| Sizeof void* = 8
*/
