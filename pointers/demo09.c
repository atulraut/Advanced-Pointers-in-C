#include <stdio.h>

void display(int *a) {
    int i;
    for (i = 0; i < 2; i++)
        printf("%d\n", a[i]);
}

int* generate() {
    static int arr[] = { 11, 22 };
    return arr;
}

int main() {
    int arr[] = { 11, 22 };
    display(arr);
    int i, *ptr = generate();
    for (i = 0; i < 2; i++)
        printf("%d\n", ptr[i]);
    return 0;
}

