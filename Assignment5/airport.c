// File: airport.c
// Purpose: Implementation of airport functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "airport.h"

void show(Airport airport) {
    printf("%s - %s\n", airport.code, airport.name);
    printf("%s, %s (%s)\n", airport.city, airport.state, airport.country);
} //show()