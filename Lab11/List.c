//List.c
//Julia Rieger

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "List.h"

List *newList() { // Creates a new empty list
    List *L = malloc(sizeof(List));
    L->head = NULL;
    L->tail = NULL;
    L->size = 0;
    return L;
} // newList()

int size(const List *l) { // Returns the size of list-l
    return l->size;
} // size()

int empty(const List *l) { // is the list-l empty?
    return l->size == 0;
} // empty()

void add(List *l, void *item) { // Add item at end of list-l
    struct node *n = newNode(item); // Create a new node (item, NULL)
    if (l->size == 0) // Inserting in empty list
        l->head = l->tail = n;
    else { // Inserting in a non-empty list
        l->tail->next = n;
        l->tail = n;
    }
    l->size++; // We just inserted an item
} // add()

void print(const List *l) {
    struct node *n = l->head;
    printf("L(%d) = ", l->size);
/*     while (n != NULL) {
        printf("%s ", &n->data);
        n = n->next;
    } */
    printf("\n");
} // print()

void *get(const List *l, int index) {// Returns item at index in list-l
    if (index < 0 || index >= l->size) {
        printf("Error: List index out of bounds %d. Exiting!\n", index);
        exit(EXIT_FAILURE);
    }
    // index is valid, lets walk…
    struct node *n=l->head; // start at head
    for (int i=0; i < index; i++)
        n = n->next; // hop!
    return n->data; // we’re there!
} // get()

void clear(List *l) { // removes all items from list-l
    struct node *n = l->head;
    struct node *nxt;
    while (n != NULL) { // Visit each node and recycle it
        nxt = n->next;
        free(n);
        n = nxt;
    }
    l->head = l->tail = NULL; // All recycled! Now reset.
    l->size = 0;
} // clear()