//List.h
//Julia Rieger

#ifndef _LIST_H
#define _LIST_H
#include "node.h"

typedef struct {
    int size;
    struct node *head;
    struct node *tail;
} List;

//prototypes
List *newList(); // Creates a new empty list
int size(const List *l); // Returns the size of list-l
int empty(const List *l); // is the list-l empty?
void clear(List *l); // removes all items from list-l
void add(List *l, void *item); // Add item at end of list-l
void *get(const List *l, int index); // Returns item at index in list-l
void print(const List *l); // prints contents of list (test only)
#endif