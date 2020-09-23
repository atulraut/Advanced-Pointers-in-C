#include <stdio.h>

/***
 * Whenever you are passing address of variable basically you are passing
 * copy of that address passing pointer by value.  
 * Remember pointers are passed by value. 
 * i.e. the copy of address in pointer is created
 */

int a = 20;
void myfun(int p) {
    p = a;
}
int main() {
    int x = 10;
    myfun(x);
    printf("x = %d\n", x);
    return 0;
}
