/***

    Basics size of each pointers & ++ works

    gcc -g -o main -Wall -Wextra -pedantic -Wwrite-strings -fsanitize=address *.c -lm

    Date: Fri Sep 11 14:25:50 PDT 2026
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

  char* cptr   = NULL; // 1
  short* sptr  = NULL; // 2
  float* fptr  = NULL; // 4
  double* dptr = NULL; // 8

  debug("cptr = %p sptr = %p fptr = %p dptr = %p",++cptr, ++sptr, ++fptr, ++dptr );
}

int main (int argc, char **argv) {
  test();
  return 0;
}

/**
    L=[32] [test] :| cptr = 0x1 sptr = 0x2 fptr = 0x4 dptr = 0x8
 **/

/***
    What does ++ptr do?
    For a pointer:
    ptr++;
    Does not necessarily mean +1 byte.
    It means:
    Move the pointer to the next object of its pointed-to type.
    Therefore:

    Pointer	Typical sizeof(type)	++pointer moves
    char *	1	                1 byte
    short *	2	                2 bytes
    float *	4	                4 bytes
    double *	8	                8 bytes

    So if, conceptually, NULL were address 0x0000:

    Remember this formula: new_address = old_address + sizeof(*ptr)
    So:
       char   *p;  p + 1;   // +1
       short  *p;  p + 1;   // +2
       float  *p;  p + 1;   // +4
       double *p;  p + 1;   // +8

    The pointer itself is usually 8 bytes on a 64-bit system, but that is not what determines the pointer-arithmetic scale.
    For example:

        sizeof(double *)  // typically 8
        sizeof(double)    // typically 8
 */
