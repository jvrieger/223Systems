//des.c
//Julia Rieger

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "Customer.h"
#include "Kiosk.h"
#include "Queue.h"
//#define DEBUG

void simulate(int m, int k); //Simulates k kiosks over m minutes
int arrivals(); // Returns the number of customers that arrived (any value [0..3])
int randInt(int a, int b); //returns a rand int [a,b)
float queueLength = 0; //total of all queue lengths during simulation

int main(int argc, char *argv[]) {
    srand(time(NULL)); //seed time for random selection

    //check valid args submitted
    if (argc != 3) {
        printf("Command args formatted incorrectly.\n");
        exit(EXIT_FAILURE);
    }

    //start simulation with arguments supplied
    simulate(atoi(argv[1]),atoi(argv[2]));

    return 0;
} //main()

void simulate(int m, int k) { // simulate for m minutes on k kiosks
    // create k kiosks
    Kiosk *kiosks[k];
    for (int i=0; i < k; i++)
        kiosks[i] = newKiosk();

    #ifdef DEBUG //DEBUG PRINTS
    printf("There are %d kiosks.\n", k);
    printf("[ "); // Let us print out each kiosk…
    for (int i=0; i < k; i++)
        printf("%s ", kioskToString(kiosks[i]));
    printf("]\n\n");
    #endif

    // Create a queue of customers
    Queue *checkInQueue;
    checkInQueue = newQueue();
    int nc = 0; // Total customers arrived

    // for each minute…
    for (int t=1; t <= m; t++) { 
        // n Customers arrive
        int n = arrivals();

        // create and add each customer to the queue
        for (int i = 1; i <= n; i++) {
            Customer *c = newCustomer(t);
            insertQ(checkInQueue, c);
            nc++;
        }

        #ifdef DEBUG
        printf("At time %d there are %d customers on Q.\n", t, sizeQ(checkInQueue));
        #endif

        queueLength += sizeQ(checkInQueue); //incr total queue pop count

        // Assign customer(s) to kiosk(s)
        for (int j = 0; j < k; j++) {
            if (!busy(kiosks[j]) && !emptyQ(checkInQueue)) {
                Customer *c = removeQ(checkInQueue);
                assignCustomer(kiosks[j], c);
            }
        }
        
        // Kiosks run for 1 minute
        for (int p=0; p < k; p++)
            tick(kiosks[p]);          

        #ifdef DEBUG //DEBUGGING PRINTS
        printf("[ ");// print out status of all kiosks
        for (int i=0; i < k; i++)
            printf("%s ", kioskToString(kiosks[i]));
        printf("]\n\n");   
        #endif
    }

    //output end metrics
    printf("Simulation: %d minutes, with %d kiosks\n", m, k);
    printf("%d customers arrived\n", nc);
    printf("%d customers served\n", getNServed());
    printf("Average queue length: %.1f\n", queueLength/m);

} // simulate()

int arrivals() {
    return randInt(1,4);
}