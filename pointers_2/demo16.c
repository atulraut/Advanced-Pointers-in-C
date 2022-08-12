#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(void* arr, int n, int elesize, int (*comp)(const void*, const void*)) {
    void* temp = malloc(elesize);
    int i, j;
    char* a = (char*)arr;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (comp(a + i * elesize, a + j * elesize) > 0) {
                memcpy(temp, a + i * elesize, elesize);
                memcpy(a + i * elesize, a + j * elesize, elesize);
                memcpy(a + j * elesize, temp, elesize);
            }
        }
    }
    free(temp);
}

int comp_int(const void* p1, const void* p2) {
    return *(int*)p1 - *(int*)p2;
}

int main() {
    int i, arr[5] = { 44, 22, 55, 11, 33 };
   // sort(arr, 5, sizeof(int), comp_int);
    qsort(arr, 5, sizeof(int), comp_int);
    for (i = 0; i < 5; i++)
        printf("%d, ", arr[i]);
    printf("\n");
    return 0;
}
