//testList.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "List.h"

int main(void) {
    srand(time(NULL));
    List L;
    L = newList();

    printf("EMPTY LIST\n");
    print(&L);

    for (int i=0; i < 10; i++)
        add(&L, rand()%100);
    
    printf("POPULATED LIST\n");
    print(&L);

    if (empty(&L))
        printf("The list is empty.\n");
    else
        printf("The list is not empty.\n");
        
    printf("The list contains %d elements.\n", size(&L));

    printf("TESTING GET\n");
    int randIndex = -1 + (rand()%(11));
    printf("index %d: %d\n", randIndex, get(&L, randIndex));

    printf("TESTING CONTAINS\n");
    printf("list contains %d at index %d.\n", get(&L, 0), contains(&L, get(&L,0)));
    printf("list contains %d at index %d.\n", get(&L, size(&L)-1), contains(&L, get(&L, size(&L)-1)));

    return(0);
} // main()