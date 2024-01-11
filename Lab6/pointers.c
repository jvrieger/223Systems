#include <stdio.h>

#define N 10

int *find_largest(int n, int a[n]);

int main(void){
    int data[N] = {0, 1, 2, 3, 42, 5, 6, 7, 8, 9};

    int *max = find_largest(N, data);
    printf("largest element: %d\n", *max);
    return 0;
}

int *find_largest(int n, int a[n]) {
    int *max = a;
    for (int *p = a; p < a + n; p++) {
        if (*p > *max) {
            max = p;
        }
    }
    return max;
}