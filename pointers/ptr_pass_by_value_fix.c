#include <stdio.h>

int a = 20;

void myfun(int* p) {
  printf("[%s] a = %p p=%p \n",__func__, a, p);
  *p = a;
  printf("[%s] a = %p p=%p \n",__func__, a, p);
}

int main() {
    int x = 10;
    int* p = &x;
    myfun(p);
    printf("[%s] x = %d p=%p \n",__func__, x, p);
    return 0;
}
