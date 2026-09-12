#include <stdio.h>

int main(int argc, char *argv[]) {

  char** cp[] = { argv + 4, argv + 3, argv + 2, argv + 1 };

  char*** cpp = cp;

  printf("%s\n", **++cpp);
  printf("%s\n", *--*++cpp + 3);
  printf("%s\n", *cpp[-2]+3);
  printf("%s\n", cpp[-1][-1] + 1);
  return 0;
}

/**
   ./a.out
   TMPDIR=/var/folders/7s/234fcqp50bn9r2fxbvy3880w0000gn/T/
   zsh: segmentation fault  ./a.out
*/
