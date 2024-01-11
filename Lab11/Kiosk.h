//Kiosk.h
//Julia Rieger

#ifndef _KIOSK_H
#define _KIOSK_H

#include "Customer.h"

typedef struct {
    char *id;
    Customer *nowServing; // Customer this kiosk is serving (or NULL)
    int timeRemaining; // How much time still remains to serve the customer being served
} Kiosk;

// Create a new Kiosk: K#
Kiosk *newKiosk();

// Accessors
char *getKioskId(const Kiosk *k);
Customer *getCustomer(const Kiosk *k); // Returns the customer being served (or NULL)
void assignCustomer(Kiosk *k, Customer *c); // Assigns customer, c to kiosk, k
void tick(Kiosk *k); // Performs 1 minute of service to customer (if serving one) // If customer is completely served, it resets this kiosk (to no customer)
int busy(const Kiosk *k); // Is Kiosk, k serving a customer?
int getNServed(); // returns total# Customers served so far in simulation // How many total customers have been served so far

// Print representation of a Kiosk is K12: <C19: 42, 8> [3]
char *kioskToString(const Kiosk *k);

#endif