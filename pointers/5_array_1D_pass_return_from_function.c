#include <stdio.h>

// Array wont create copy, only we pass address.
void display(int *a) {
    int i;
    for (i = 0; i < 2; i++)
      printf("[%s] %d\n", __func__, a[i]);
}

int* generate() {
    static int arr[] = { 11, 22 };
  //int arr[] = { 11, 22 }; // No Static, it wont work
    return arr;
}

int main() {
    int arr[5] = { 11, 22, 33, 0, 0 };
    int *ptr = arr;
    display(arr);
    int i, *ptr2 = generate();
    for (i = 0; i < 2; i++)
      printf("[%s] ->%d\n",__func__, ptr2[i]);

    printf("[%s] ptr=%p ptr+2 =%p ptr-2->%p\n",__func__,ptr, ptr+2, ptr-2);

    printf("[%s] ptr=%p ptr+2 =%d \n",__func__,ptr, *(ptr+2));

    printf("[%s] ptr=%p ptr+2 =%d ptr-2->%d\n",__func__,ptr, *(ptr+2), *(ptr-2));

    printf("[%s] arr=%p arr+1 =%p arr+4 =%p &arr+1->%p\n",__func__, arr, arr+1, arr+4, &arr+1);

    return 0;
}

/***
=> ./a.out
[display] 11
[display] 22
[main] ->11
[main] ->22
[main] ptr=0x7ffd1213dd20 ptr+2 =0x7ffd1213dd28 ptr-2->0x7ffd1213dd18
[main] ptr=0x7ffd1213dd20 ptr+2 =33
[main] ptr=0x7ffd1213dd20 ptr+2 =33 ptr-2->6295616
[main] arr=0x7ffd1213dd20 arr+1 =0x7ffd1213dd24 arr+4 =0x7ffd1213dd30 &arr+1->0x7ffd1213dd34
*/
