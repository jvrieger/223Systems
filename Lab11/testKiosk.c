#include <stdio.h>
#include "Kiosk.h"
#include "Customer.h"

int main(void) {
    Kiosk *ks[5];
    for (int i=0; i < 5; i++) {
        ks[i] = newKiosk();
    }
    for (int i=0; i < 5; i++) {
        printf("<%s: %d>\n", ks[i]->id, ks[i]->timeRemaining);
        printf("%s\n", kioskToString(ks[i]));
    }
    return 0;
} // main()