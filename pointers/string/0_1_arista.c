#include <stdio.h>

#define debug(str,args...) printf("L=[%d] [%s] :| "str"\n", __LINE__, __func__, ##args)

int non_working_arista() {
  char *s = "12345";
  // what do these print?
  debug( "s  ->[%d]", s ); // some address - fix compiler warning use %s
  debug( "*s ->[%d]", *s ); // 49
  debug( "*s ->[%c]", *s ); // 1
  debug( "*(s + 1) ->[%c]", *(s + 1) ); // 2
  debug( "s ->[%s]", s ); // 12345
  printf( "*s ->[%s]\n", *s ); // crash for %s, should be like Line-9
}

int working() {
    char *s = "12345";
  // what do these print?
  debug( "s  ->[%s]", s ); // some address - fix compiler warning use %s
  debug( "*s ->[%d]", *s ); // 49
  debug( "*s ->[%c]", *s ); // 1
  debug( "*(s + 1) ->[%c]", *(s + 1) ); // 2
  debug( "s ->[%s]", s ); // 12345
  printf( "*s ->[%d]\n", *s ); // crash for %s, should be like Line-
}

int main() {
  working();
  non_working_arista();
  return 0;
}

/**
   Note -
   => gcc str_arista.c
   str_arista.c: In function ‘main’:
   str_arista.c:3:35: warning: format ‘%d’ expects argument of type ‘int’, but argument 4 has type ‘char *’ [-Wformat=]
   3 | #define debug(str,args...) printf("L=[%d] [%s] :| "str"\n", __LINE__, __func__, ##args)
   |                                   ^~~~~~~~~~~~~~~~~
   str_arista.c:8:3: note: in expansion of macro ‘debug’
   8 |   debug( "s  ->[%d]", s ); // some address
   |   ^~~~~
   str_arista.c:13:19: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘int’ [-Wformat=]
   13 |   printf( "*s ->[%s]\n", *s ); // 12345
   |                  ~^      ~~
   |                   |      |
   |                   char * int
   |                  %d
**/

/**
   => ./a.out
   L=[19] [working] :| s  ->[12345]
   L=[20] [working] :| *s ->[49]
   L=[21] [working] :| *s ->[1]
   L=[22] [working] :| *(s + 1) ->[2]
   L=[23] [working] :| s ->[12345]
   *s ->[49]
   L=[8] [non_working_arista] :| s  ->[520052752]
   L=[9] [non_working_arista] :| *s ->[49]
   L=[10] [non_working_arista] :| *s ->[1]
   L=[11] [non_working_arista] :| *(s + 1) ->[2]
   L=[12] [non_working_arista] :| s ->[12345]
   Segmentation fault (core dumped)
**/
