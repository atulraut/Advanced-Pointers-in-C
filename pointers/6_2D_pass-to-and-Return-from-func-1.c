/***
     Passing 2D Array to Function & returning from function

     Check More here -
     https://github.com/atulraut/atclib/blob/master/array/basics/pass_return_2D_array.c

*/
#include <stdio.h>
#define debug(str,args...) printf("L=[%d] [%s] :| "str"\n", __LINE__, __func__, ##args)

/***
    int (*a)[4] - below converted by compiler
    a is Ptr to the block of 4 Int array
*/
// void print_arr(int (*a)[4]) { --> works
void print_arr(int a[][3][4]) {
  int i, j, k;

  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      for (k=0; k<4; k++) {
	printf("%d\t", a[i][j][k]);
	// printf("\n");
      }
      printf("\n");
    }
    //printf("\n");
  }
}

/**
   Returning 2D array from function
   ptr to the block of 2 Integers
*/
int (* generate() ) [3][4] {
  static int arr[][3][4] =  { {11, 22}, {33, 44, 55}, {66} };//{11, 22, 33, 44};
  return arr;
}

int main() {
  int arr[3][3][4] = { {11, 22}, {33, 44, 55}, {66} };
  int i, j, k;

  int(*ptr)[3][4] = arr; // Collect array into the Pointer

  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      for (k=0; k<4; k++) {
	printf("%d\t", ptr[i][j][k]);
	//printf("\n");
      }
      printf("\n");
    }
    //   printf("\n");
  }
  printf("\n");

  //    print_arr(arr);

  ptr = generate();
  debug ("ATUL ->");
  print_arr(ptr);
}

/***
    => ./a.out
    11	22	0	0	
    0	0	0	0	
    0	0	0	0	
    33	44	55	0	
    0	0	0	0	
    0	0	0	0	
    66	0	0	0	
    0	0	0	0	
    0	0	0	0	

    L=[61] [main] :| ATUL ->
    11	22	0	0	
    0	0	0	0	
    0	0	0	0	
    33	44	55	0	
    0	0	0	0	
    0	0	0	0	
    66	0	0	0	
    0	0	0	0	
    0	0	0	0
*/
