//List.h

typedef struct {
    int size;
    struct node *head;
    struct node *tail;
} List;

//prototypes
List newList(); // Creates a new empty list
int size(const List *l); // Returns the size of list-l
int empty(const List *l); // is the list-l empty?
void clear(List *l); // removes all items from list-l
void add(List *l, int item); // Add item at end of list-l
int get(const List *l, int index); // Returns item at index in list-l
int contains(const List *l, int item); // Does list-l have item? Return index or -1 if not
void print(const List *l); // prints contents of list (test only)