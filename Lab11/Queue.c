//Queue.c
//Julia Rieger

#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

// Creates a new Queue
Queue *newQueue() {
    Queue *Q = malloc(sizeof(Queue));
    Q->L = newList();
    return Q;
}

// Basic necesseties...
int sizeQ(const Queue *q) {
    return size(q->L);
}

int emptyQ(const Queue *q) {
    return empty(q->L);
}

// Core functions for a Queue
void insertQ(Queue *q, void *item) {
    add(q->L, item);
} //inserts data at the end of the queue (List tail)

void *removeQ(Queue *q) {
    if (emptyQ(q)) {
        printf("Tried to remove from empty Queue\n");
        exit(EXIT_FAILURE);
    }
    if (sizeQ(q) == 1) {
        struct node *n = q->L->head;
        q->L->head = q->L->tail = NULL;
        void *v = n->data;
        free(n);
        q->L->size = 0;
        //clear(q->L); did not work
        return (v);
    }
    else {
        struct node *n = q->L->head;
        q->L->head = n->next;
        void *v = n->data;
        free(n);
        q->L->size--;
        return v;
    }
} //removes data at the front of the queue (List head)