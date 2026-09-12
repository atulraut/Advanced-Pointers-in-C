
#include <stdio.h>

struct emp {
  int id;
  char name[12];
  double sal;
};

void func_by_val(struct emp x) {
  printf("[byVal]: %d, %s, %lf\n", x.id, x.name, x.sal);
}

void func_by_addr(struct emp *y) {
  printf("[byAddr]: %d, %s, %lf\n", y->id, y->name, y->sal);
}

int main() {
  struct emp e = { 1, "Abc", 12.34 };
  func_by_val(e);
  func_by_addr(&e);
  return 0;
}

/**
   [byVal]:  1, Abc, 12.340000
   [byAddr]: 1, Abc, 12.340000
*/
