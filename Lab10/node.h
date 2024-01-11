//node.h

struct node {
    int data;
    struct node *next;
};

//prototypes
struct node *newNode(int item);