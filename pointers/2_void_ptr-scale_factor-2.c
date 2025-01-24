/***

    gcc -g -o main -Wall -Wextra -pedantic -Wwrite-strings -fsanitize=address *.c -lm

    Date: Wed 15 Jan 2025 07:17:59 AM PST
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

#include <stdio.h>
#include <stdlib.h>

void modifyPointer(void **p) {
  static int x = 42;
  *p = &x; // Modifies the original pointer
}

int main() {
  void *ptr = malloc(10); // Generic memory allocation
  debug("Before: ptr = %p\n", ptr);

  modifyPointer(&ptr); // Pass by address using void **
  debug("After: ptr = %p, points to value = %d\n", ptr, *(int *)ptr);

  free(ptr); // Only valid if ptr still points to malloc'd memory (not in this case)
  ptr = NULL;
  return 0;
}

/**
   L=[33] [main] :| Before: ptr = 0x555bd46172a0

   L=[36] [main] :| After: ptr = 0x555bc215b010, points to value = 42

   free(): invalid size
   Aborted (core dumped)

**/
