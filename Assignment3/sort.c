//Julia Rieger
//Assignment 3 -> sort.c
//10-2-23

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int sorted(int n, int A[n]);
void iSort(int n, int A[n]);
void shuffle(int n, int A[n]);
int randint(int a, int b);
void swap(int A[], int i, int j);

int main(void) {
    srand(time(NULL));
    //initialize array of 10 ints so that A[i] = i
    int A[N];
    for (int i = 0; i < N; i++) {
        A[i] = i;
    }
    printf("TESTING SORTED\n");
    sorted(N, A); //should print sorted

    A[5] = -9; //put array out of order

    sorted(N, A); //should print unsorted

    printf("\nTESTING SORTING\n");
    //populate array with 1 through 10
    for (int i = 0; i < N; i++) {
        A[i] = i+1;
    }
    shuffle(N, A); //shuffle array with Fisher Yates shuffle
    sorted(N, A); //should print unsorted after shuffling

    iSort(N, A); //insertion sort shuffled array
    sorted(N, A); //should print sorted after insertion sort

    return 0;
}

int sorted(int n, int A[n]) {
    int min = A[0]; //establish min value
    int isSorted = 1; //assume sorted

    for (int i = 0; i < n; i++) { //for every element in array
      printf("%d ", A[i]);
      if (A[i] < min) {
          isSorted = 0; //if bigger than prev element, not sorted
       }
    }
    if (isSorted) {
        printf("\nsorted\n");
    }
    else {
        printf("\nunsorted\n");
    }
    return isSorted;
}

void iSort(int n, int A[n]) {
    int i, key, pos;
    for (int i = 1; i < n;i++) {
        key = A[i];
        pos = i-1;
        while ((pos >= 0) && (A[pos] > key)) {
            A[pos+1] = A[pos];
            pos = pos - 1;
        }
        A[pos+1] = key;
    }
}

void shuffle(int n, int A[n]) {
    for (int i = 0; i < n; i ++) {
        int j = randint(i, n);
        swap(A, i, j);
    }
}

int randint(int a, int b) {
    return a + (rand()%(b-a));
}

void swap(int A[], int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
