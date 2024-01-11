#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Customer.h"

int main(void) {
    srand(time(NULL));
    Customer *cs[10]; // We will create 5 customers
    int t = 23;

    for (int i=0; i < 10; i++) {
        cs[i] = newCustomer(t);
        t++;
    }
    
    for (int i=0; i < 10; i++) {
        printf("<%s: %d, %d>\n", cs[i]->id, cs[i]->arrivalTime, cs[i]->serviceTime);
        printf("Customer id: %s, Arr: %d, Ser: %d\n", getCustId(cs[i]),
        getArrivalTime(cs[i]), getServiceTime(cs[i]));
        printf("%s\n", custToString(cs[i]));
        printf("-------------------\n");
    }
    return 0;
} // main()