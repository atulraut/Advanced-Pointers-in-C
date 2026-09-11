/***

    void **ptr - scale factor

    gcc -g -o main -Wall -Wextra -pedantic -Wwrite-strings -fsanitize=address *.c -lm

    Date: Fri Sep 11 13:02:33 PDT 2026
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
    void **ptr
    here :
    ptr is a pointer
    *ptr is a void *
    **ptr is the value obtained by dereferencing that void *

    But there is an important catch:
      void *p;
      *p;          // ❌ cannot dereference void * directly
      Because void has no size, the compiler doesn't know how many bytes to access.

    What about pointer arithmetic?
      This is where “scale factor” matters.
      For:
          int *p;
          p + 1;  <-- the address increases by: sizeof(int) usually 4 bytes.
      For:
      char *p;
      p + 1;      <-- the address increases by: sizeof(char) = 1

      On a typical 64-bit system:
      sizeof(void *) = 8 bytes
      So :
         void **ptr;
         ptr + 1  <-- moves 8 bytes

      The scale factor for pointer arithmetic is the size of the type the pointer
      points to.
      For void **ptr, ptr points to void *, so ptr + 1 advances by sizeof(void *),
      typically 8 bytes on a 64-bit system.
      ONE subtel distinction :
               void *p
               p + 1   // Not standard C
      but :
               void **ptr;
               ptr + 1 // Valid; advances by sizeof(void *)
                     <-- Because void ** points to an actual object type: void *.
*/

void test() {
  int a = 10;
  int b = 20;

  void *ptr = &a;
  void **pptr = &ptr;

  debug("ptr       = %p", ptr);
  debug("ptr + 1   = %p", (char *)ptr + 1);

  debug("pptr      = %p", (void *)pptr);
  debug("pptr + 1  = %p", (void *)(pptr + 1));

  debug("sizeof(void *)  = %zu", sizeof(void *));
  debug("sizeof(void **) = %zu", sizeof(void **));

}

int Test2(void) {

  int x = 10;
  void *ptr = &x;

  debug("ptr     = %p", ptr);
  debug("ptr + 1 = %p", ptr + 1);   // GCC extension

  return 0;
}

int main (int argc, char **argv) {
  test();
  debug("Test 2");
  Test2();
  return 0;
}

/**
   L=[72] [test] :| ptr       = 0x16fde308c
   L=[73] [test] :| ptr + 1   = 0x16fde308d
   L=[75] [test] :| pptr      = 0x16fde3080
   L=[76] [test] :| pptr + 1  = 0x16fde3088
   L=[78] [test] :| sizeof(void *)  = 8
   L=[79] [test] :| sizeof(void **) = 8
   L=[96] [main] :| Test 2
   L=[88] [Test2] :| ptr     = 0x16d71707c
   L=[89] [Test2] :| ptr + 1 = 0x16d71707d
**/

/***
    Notice:
            (char *)ptr + 1 <-- Moves 1 byte because char is 1 byte.
    But:
            pptr + 1        <-- Moves 8 bytes, because pptr points to a void *:

    void **pptr
         |
         v
    +----------+
    | void *   |  8 bytes
    +----------+

    So the scale factor is:

    pptr + 1
           ↑
           sizeof(void *) = 8
 */
