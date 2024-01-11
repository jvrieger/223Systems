//Customer.c
//Julia Rieger

#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"

static int countC = 0; //count of Customer ID

//prototypes
int randInt(int a, int b);
char *genCustId();

// Given arrival time, create a new customer
Customer *newCustomer(int arrTime) {
    Customer *C = malloc(sizeof(Customer));
    C->id = genCustId();
    C->arrivalTime = arrTime;
    C->serviceTime = randInt(5,9); //randInt[a,b)
    return C;
} // Creates a new customer, with an ID (up to 4 chars), whose
  // arrival time is arrTime, and service time is between 5-8 minutes (random)

// Accessors
char *getCustId(const Customer *c) {
    return c->id;
} //getCustId()

int getArrivalTime(const Customer *c) {
    return c->arrivalTime;
} //getArrivalTime()

int getServiceTime(const Customer *c) {
    return c->serviceTime;
} //getServiceTime()

// Print Representation
char *custToString(const Customer *c) {
    char* print = malloc(15);
    sprintf(print, "<%s: %d, %d>", getCustId(c), getArrivalTime(c), getServiceTime(c));
    return print;
} // Print form: <id: arrivalTime, serviceTime>
  // e.g. <C23: 12, 7>, <C19, 42, 8>, etc.

//local helper methods
int randInt(int a, int b) {
    return (rand() % (b-a) + a);
} //randInt()

char *genCustId() { // creates a unique id as 'C'+count (e.g. C23, C9, etc.)
    countC++;
    char *id = malloc(5*sizeof(char)); // Max 4-letters for ID +1 for ‘\0’
    sprintf(id, "C%d", countC);
    return id;
} // genCustId()
