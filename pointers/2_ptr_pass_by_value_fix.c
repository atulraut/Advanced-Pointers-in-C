#include <stdio.h>

int a = 20;

void myfun(int* p) {
  printf("[%s] a = %d p=%p \n",__func__, a, p);
    *p = a;
  //  p = &a; // pass by value
  printf("[%s] a = %d p=%p \n",__func__, a, p);
}

int main() {
    int x = 10;
    int* p = &x;
    //  myfun(p); // Pointers are pass by value. i.e. the copy of address in pointer is created. When function return stack get created & lost content per diagram.
    myfun(&x);
    printf("[%s] x = %d p=%p \n",__func__, x, p);
    return 0;
}

/*
  => ./a.out
  [myfun] a = 20 p=0x7ffe1bb1763c
  [myfun] a = 20 p=0x7ffe1bb1763c
  [main] x = 20 p=0x7ffe1bb1763c
*/

/*
  Notes - only array & functions are passed by address.
*/
