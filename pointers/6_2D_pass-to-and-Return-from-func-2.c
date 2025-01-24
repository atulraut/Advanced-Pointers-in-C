/***
     Passing 2D Array to Function & returning from function
*/
#include <stdio.h>

/***
    int (*a)[4] - below converted by compiler
    a is Ptr to the block of 4 Int array
*/
// void print_arr(int (*a)[4]) { --> works
void print_arr(int a[][3][4]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
    printf("\n");
}


/**
   Returning 2D array from function
   ptr to the block of 2 Integers
*/
int (* generate()) [4] {
  static int arr[][4] = {11, 22, 33, 44};
  return arr;
}

/**
   returning 3D array from function
*/
int (* func() )[2][3] {
  static int arr[][2][3] = {11, 22, 33, 44};
  int (*ptr)[2][3] = arr;
  return arr;
}

int main() {
    int arr[3][4] = { {11, 22}, {33, 44, 55}, {66} };
    int i, j;

    int(*ptr)[2][3]; // Collect array into the Pointer

    //    print_arr(arr);

    ptr = func();
    print_arr(ptr);
}

/***
    => ./a.out
    11	22	0	0
    33	44	55	0
    66	0	0	0

    11	22	0	0
    33	44	55	0
    66	0	0	0

    11	22	33	44
    0	0	0	0
    0	0	0	0
*/
