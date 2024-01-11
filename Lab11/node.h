//node.h
//Julia Rieger

#ifndef _NODE_H
#define _NODE_H

struct node {
    void *data;
    struct node *next;
};

//prototypes
struct node *newNode(void *item);
#endif