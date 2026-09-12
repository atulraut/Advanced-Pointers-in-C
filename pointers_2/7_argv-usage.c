/**

   How argv works in C

*/
#include <stdio.h>

int main(int argc, char *argv[]) {
  int i;
  for (i = 0; i < argc; i++) {
    puts(argv[i]);
  }
  return 0;
}

/**
  $ ./a.out 19
   ./a.out
   19
*/

