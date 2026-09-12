/***

   How struct -> operator internally works explain!

   If we have address of member, then we can get address of begining of the structure.
   e.g.
   Per below we struct member address int d, then we can get struct test base address.

   int* d = &v.d  // Here I have pointer to the member & use am getting base address to the structure test.
   struct test* qPtr = (struct test *)((char *)d - offset_of(struct test, d))

   Date: Sat Sep 12 11:57:56 PDT 2026
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

struct  __attribute__((packed)) test {
  short  a;  // 2
  char   b;  // 1
  double c;  // 8
  int    d;  // 4
};          //  15 : size of this struct

void test() {

  struct test v = {15, 'S', 4.94, 432};
  struct test* ptr;

  ptr = &v;

  debug("v.d = [%d] ptr->d = [%d]", v.d, ptr->d);
  debug("->[%d]", *(int *)((char *)&v + 11));
  debug("->[%d]", *(int *)((char *)ptr+11));

  ptr = NULL;
  // Accessing addresees for struct, not value so it didnt crash.
  debug(" &ptr->a = [%pK]  &ptr->b = [%pK]  &ptr->c = [%pK]  &ptr->d = [%pK]", &ptr->a,  &ptr->b,  &ptr->c,  &ptr->d);
L=[45] [test] :|  &ptr->a = [0x0K]  &ptr->b = [0x2K]  &ptr->c = [0x3K]  &ptr->d = [0xbK]}

int main (int argc, char **argv) {
  test();
  return 0;
}

/***
    &v - This represent whole of strut of size 15,
    &v + 11 == 15 * 11  take out of struct size so to
    access individual elements we needs to type cast
    it to char *. It help bype wise accessing the element.
    Same applied to ptr as well.
 */
/**

   L=[39] [test] :| v.d = [432] ptr->d = [432]
   L=[40] [test] :| ->[432]
   L=[41] [test] :| ->[432]
   L=[45] [test] :|  &ptr->a = [0x0K]  &ptr->b = [0x2K]  &ptr->c = [0x3K]  &ptr->d = [0xbK]
**/
