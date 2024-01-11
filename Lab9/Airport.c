// FILE: Airport.c
#include <stdio.h>
#include <string.h>
#include "Airport.h"

void show(Airport a) { // print Airport object
    printf("%s - %s, %s, %s (%s).\n",a.code,a.name,a.city,a.state,a.country);
} // show()

Airport parseAirport(char * str) { // Parse srt into an Airport object
    Airport result;

   char *token;
   token = strtok(str, ",");	// code
   strcpy(result.code, token);

   token = strtok(NULL, ",");	// name
   strcpy(result.name, token);

   token = strtok(NULL, ",");	// city
   strcpy(result.city, token);

   token = strtok(NULL, ",");	// state
   strcpy(result.state, token);

   token = strtok(NULL, ",");	// country
   strcpy(result.country, token);
} // parseAirport()