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

#define debug(str,args...) printf("[%s] L=%d :"str"\n", __func__, __LINE__, ##args)

#define mysizeof(arr) ((char*)&arr+1 - (char*)&arr)
#define arrsz(x) sizeof(x) / sizeof(x[0])

void test_ptr() {
  int a[10], b[10];
  int* p = a;

  assert(sizeof(a) / sizeof(a[0]) == 10);
  assert(sizeof(p) == sizeof(int*));
  assert(sizeof(*p) == sizeof(int));
}

void test_sizeof() {
  int arr[] = {1,2,3,4};
  printf ("\nsz-->%ld \n", mysizeof(arr));
  printf ("\nsz-->%ld \n", arrsz(arr));
}

int a = 20;
void myfun(int* p) {
  p = &a;
}

void test() {
  int x = 10;
  int* p = &x;
  myfun(p);
  printf("x = %d\n", x);
}

int main() {
  test();
  test_sizeof();
  test_ptr();
  return 0;
}
