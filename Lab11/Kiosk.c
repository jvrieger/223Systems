//Kiosk.c
//Julia Rieger

#include <stdlib.h>
#include <stdio.h>
#include "Kiosk.h"

static int countK = 0; //count for Kiosk ID
static int nServed = 0; //number of cust served at this Kiosk

//prototypes
char *genKioskId();

// Create a new Kiosk: K#
Kiosk *newKiosk() {
    Kiosk *K = malloc(sizeof(Kiosk));
    K->id = genKioskId();
    K->timeRemaining = -1;
    return K;
} //newKiosk()

// Accessors
char *getKioskId(const Kiosk *k) {
    return k->id;
} //getKioskId()

Customer *getCustomer(const Kiosk *k) {
    return k->nowServing;
} // Returns the customer being served (or NULL)

void assignCustomer(Kiosk *k, Customer *c) {
    k->nowServing = c;
    k->timeRemaining = c->serviceTime;
} // Assigns customer, c to kiosk, k

void tick(Kiosk *k) {
    if (busy(k)) {
        k->timeRemaining--;
    }
    if (k->timeRemaining == 0) { //customer finished
        k->nowServing = NULL;
        k->timeRemaining = -1;
        nServed++;
    }
} // Performs 1 minute of service to customer (if serving one)
  // If customer is completely served, it resets this kiosk (to no customer)

int busy(const Kiosk *k) {
    if (k->nowServing == NULL)
        return 0; //idle
    else
        return 1; //busy
} // Is Kiosk, k serving a customer?

int getNServed() {
    return nServed;
} // returns total# Customers served so far in simulation
  // How many total customers have been served so far

// Print representation of a Kiosk is K12: <C19: 42, 8> [3]
char *kioskToString(const Kiosk *k) {
    char* print = malloc(35);

    if (k->nowServing == NULL) {
        sprintf(print, "%s: %s, [%d]", getKioskId(k), "IDLE", getNServed(k));
    }
    else {
    sprintf(print, "%s: %s, [%d]", getKioskId(k), custToString(k->nowServing), getNServed(k));
    }
    
    return print;
} //kioskToString()

//local helper method
char *genKioskId() { // creates a unique id as 'K'+count (e.g. K1, K10, etc.)
    countK++;
    char *id = malloc(4*sizeof(char)); // Max 3-letters for ID +1 for ‘\0’
    sprintf(id, "K%d", countK);
    return id;
} // genKioskId()