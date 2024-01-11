//node.c

#include <stdlib.h>
#include "node.h"

struct node *newNode(int item) { //creates new node with item
    struct node *n = malloc(sizeof(struct node)); //stdlib.h is needed for malloc/sizeof
    n->data = item;
    n->next = NULL;
} //newNode()