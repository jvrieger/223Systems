//testQueue.c
//Julia Rieger

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Queue.h"

int main(void) {

 
    Queue *Q;
    printf("here 2\n");
    Q = newQueue();
       printf("here 1\n");
    printf("Q Size = %d\n", sizeQ(Q));

    if (emptyQ(Q))
        printf("The queue is empty.\n");
    else
        printf("The queue is not empty.\n");
    
    int *n;
    printf("Adding: ");
    for (int i=0; i < 10; i++) { // Isert 10 #’s to Q
        n = malloc(sizeof(int));
        *n = rand()%100;
        printf("%d ", *n);
        insertQ(Q, n);
    }
    printf("\n");
    printf("Q Size = %d\n", sizeQ(Q));
    if (emptyQ(Q))
        printf("The queue is empty.\n");
    else
        printf("The queue is not empty.\n");

    for (int i = 0; i < 8; i++) { // Remove 8 #’s from Q
        n = removeQ(Q);
        printf("Removed: %d\n", *n);
    }

    printf("Q Size = %d\n", sizeQ(Q));
    if (emptyQ(Q))
        printf("The queue is empty.\n");
    else
        printf("the queue is not empty.\n");
    return 0;
} // main()