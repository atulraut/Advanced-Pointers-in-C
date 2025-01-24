// demo06.c
#include <stdio.h>
#define debug(str,args...) printf("L=[%d] [%s] :| "str"\n", __LINE__, __func__, ##args)

void check_1d_array() {
  int arr[5] = { 11, 22, 33 }; // [11 22 33 0 0] - compiler does it
  int i, *ptr = arr;

  printf("[%s] arr      = %p\n",__func__, arr);
  printf("[%s] arr+1    = %p\n",__func__, arr+1);
  printf("[%s] arr+2    = %p\n",__func__, arr+2);
  printf("[%s] *arr     = %d\n",__func__, *arr);
  printf("[%s] *(arr+1) = %d\n",__func__, *(arr+1));
  printf("[%s] *(arr+1) = %d\n",__func__, *(arr+2));
  printf("[%s] *(arr+1) = %d\n",__func__, arr[1]);
  printf("[%s] *(arr+1) = %d\n",__func__, arr[2]);

  printf("[%s] ptr      = %p\n",__func__, ptr);
  printf("[%s] ptr+1    = %p\n",__func__, ptr+1);
  printf("[%s] arr+2    = %p\n",__func__, ptr+2);
  printf("[%s] *ptr     = %d\n",__func__, *ptr);
  printf("[%s] *(ptr+1) = %d\n",__func__, *(ptr+1));
  printf("[%s] *(ptr+1) = %d\n",__func__, *(ptr+2));
  printf("[%s] *(ptr+1) = %d\n",__func__, ptr[1]);
  printf("[%s] *(ptr+1) = %d\n",__func__, ptr[2]);

  printf("\n");

}

void size_checks() {
  int arr[5] = { 11, 22, 33 }; // [11 22 33 0 0] - compiler does it
  int i, *ptr = arr;

  printf("\n");
  debug ("Sizeof PTR = %ld", sizeof(ptr));
  debug ("Sizeof ARR = %ld", sizeof(arr));
}

int main() {
  int arr[5] = { 11, 22, 33 };
  int i, *ptr = arr;

  check_1d_array();
  //    return 0;

  for (i = 0; i < 5; i++)
    printf("arr[%d] = %d\n", i, arr[i]);
  printf("\n");

  for (i = 0; i < 5; i++)
    printf("*(arr+%d) = %d\n", i, *(arr+i));
  printf("\n");

  for (i = 0; i < 5; i++)
    printf("*(%d+arr) = %d\n", i, *(i + arr));
  printf("\n");

  for (i = 0; i < 5; i++)
    printf("%d[arr] = %d\n", i, i[arr]);
  printf("\n");


  for (i = 0; i < 5; i++)
    printf("ptr[%d] = %d\n", i, ptr[i]);
  printf("\n");

  for (i = 0; i < 5; i++)
    printf("*(ptr+%d) = %d\n", i, *(ptr + i));
  printf("\n");

  for (i = 0; i < 5; i++)
    printf("*(%d+ptr) = %d\n", i, *(i + ptr));
  printf("\n");

  for (i = 0; i < 5; i++)
    printf("%d[ptr] = %d\n", i, i[ptr]);
  printf("\n");

  //short* p1 = &arr[3];
  /*
    ptr   arr
    [100]  [11] [22] [33] [0] [0] <-- Array Elements
    92  96 100  104  108  112 116 <-- Array Addresses
  */
  int* p1 = &arr[3]; // 112
  int* p2 = &arr[0]; // 100
  printf("diff = %ld\n", p1 - p2); // 112-100/4 (scale factor of ptr1 i.e. int) = 3 (Answer)

  printf("arr = %p\n", arr);
  printf("arr + 1 = %p\n", arr + 1);
  printf("&arr = %p\n", &arr);
  printf("&arr + 1 = %p\n", &arr + 1);

  size_checks();
  return 0;
}
/***
    => ./a.out
    [check_1d_array] arr      = 0x7ffdeb6c4a20
    [check_1d_array] arr+1    = 0x7ffdeb6c4a24
    [check_1d_array] arr+2    = 0x7ffdeb6c4a28
    [check_1d_array] *arr     = 11
    [check_1d_array] *(arr+1) = 22
    [check_1d_array] *(arr+1) = 33
    [check_1d_array] *(arr+1) = 22
    [check_1d_array] *(arr+1) = 33
    [check_1d_array] ptr      = 0x7ffdeb6c4a20
    [check_1d_array] ptr+1    = 0x7ffdeb6c4a24
    [check_1d_array] arr+2    = 0x7ffdeb6c4a28
    [check_1d_array] *ptr     = 11
    [check_1d_array] *(ptr+1) = 22
    [check_1d_array] *(ptr+1) = 33
    [check_1d_array] *(ptr+1) = 22
    [check_1d_array] *(ptr+1) = 33

    arr[0] = 11
    arr[1] = 22
    arr[2] = 33
    arr[3] = 0
    arr[4] = 0

    *(arr+0) = 11
    *(arr+1) = 22
    *(arr+2) = 33
    *(arr+3) = 0
    *(arr+4) = 0

    *(0+arr) = 11
    *(1+arr) = 22
    *(2+arr) = 33
    *(3+arr) = 0
    *(4+arr) = 0

    0[arr] = 11
    1[arr] = 22
    2[arr] = 33
    3[arr] = 0
    4[arr] = 0

    ptr[0] = 11
    ptr[1] = 22
    ptr[2] = 33
    ptr[3] = 0
    ptr[4] = 0

    *(ptr+0) = 11
    *(ptr+1) = 22
    *(ptr+2) = 33
    *(ptr+3) = 0
    *(ptr+4) = 0

    *(0+ptr) = 11
    *(1+ptr) = 22
    *(2+ptr) = 33
    *(3+ptr) = 0
    *(4+ptr) = 0

    0[ptr] = 11
    1[ptr] = 22
    2[ptr] = 33
    3[ptr] = 0
    4[ptr] = 0

    diff = 3
    arr = 0x7ffdeb6c4a70
    arr + 1 = 0x7ffdeb6c4a74
    &arr = 0x7ffdeb6c4a70
    &arr + 1 = 0x7ffdeb6c4a84

    L=[36] [size_checks] :| Sizeof PTR = 8
    L=[37] [size_checks] :| Sizeof ARR = 20
*/
