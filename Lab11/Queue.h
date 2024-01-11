//Queue.h
//Julia Rieger

#ifndef _QUEUE_H
#define _QUEUE_H
#include "List.h"

typedef struct {
    List *L;
} Queue; // A Queue is just a linked list

// Creates a new Queue
Queue *newQueue();

// Basic necesseties...
int sizeQ(const Queue *q);
int emptyQ(const Queue *q);

// Core functions for a Queue
void insertQ(Queue *q, void *item);
void *removeQ(Queue *q);

#endif