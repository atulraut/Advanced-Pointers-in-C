// demo06.c
#include <stdio.h>

void check_1d_array() {
  int arr[5] = { 11, 22, 33 };
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

int main() {
    int arr[5] = { 11, 22, 33 };
    int i, *ptr = arr;

    check_1d_array();
    return 0;
    
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
    int* p1 = &arr[3];
    int* p2 = &arr[0];
    printf("diff = %d\n", p1 - p2);

    printf("arr = %p\n", arr);
    printf("arr + 1 = %p\n", arr + 1);
    printf("&arr = %p\n", &arr);
    printf("&arr + 1 = %p\n", &arr + 1);

    return 0;
}
/***
 * 
 [check_1d_array] arr      = 0x7ffff7c36500
 [check_1d_array] arr+1    = 0x7ffff7c36504
 [check_1d_array] arr+2    = 0x7ffff7c36508
 [check_1d_array] *arr     = 11
 [check_1d_array] *(arr+1) = 22
 [check_1d_array] *(arr+1) = 33
 [check_1d_array] *(arr+1) = 22
 [check_1d_array] *(arr+1) = 33
 [check_1d_array] ptr      = 0x7ffff7c36500
 [check_1d_array] ptr+1    = 0x7ffff7c36504
 [check_1d_array] arr+2    = 0x7ffff7c36508
 [check_1d_array] *ptr     = 11
 [check_1d_array] *(ptr+1) = 22
 [check_1d_array] *(ptr+1) = 33
 [check_1d_array] *(ptr+1) = 22
 [check_1d_array] *(ptr+1) = 33
*/
