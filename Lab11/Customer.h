//Customer.h
//Julia Rieger

#ifndef _CUSTOMER_H
#define _CUSTOMER_H

typedef struct {
    char *id; // id is for form 'C'+# (e.g, C23, C9, etc.)
    int arrivalTime;
    int serviceTime;
} Customer;

// Given arrival time, create a new customer
Customer *newCustomer(int arrTime);
 // Creates a new customer, with an ID (up to 4 chars), whose
 // arrival time is arrTime, and service time is between 5-8 minutes (random)

// Accessors
char *getCustId(const Customer *c);
int getArrivalTime(const Customer *c);
int getServiceTime(const Customer *c);

// Print Representation
char *custToString(const Customer *c);
 // Print form: <id: arrivalTime, serviceTime>
 // e.g. <C23: 12, 7>, <C19, 42, 8>, etc.

 #endif