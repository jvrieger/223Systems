// FILE: a6.c
// Purpose: To define a data type using structs
//		Enables the reading of a database of airport codes
//		from a file code.txt
// 		and allows user to search for airports by their code
// Usage:	./airports code.txt
// Written By: Deepak Kumar
// Date: October 15, 2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Airport.h"

// Functions for handling Airport database load and search
void readData(char *file, Airport list[], int *n);
int search(Airport list[], int n, char *code);
int more();

int main(int argc, char *argv[]) {

   Airport airportList[4000];	// A list of all airports
   int nA = 0;			// How many airports known
  
   // Load database... 
   if (argc != 2) {
      printf("Cannot proceed: Missing file name.\n");
      exit(EXIT_FAILURE);
   }
   readData(argv[1], airportList, &nA);

   // Begin user interaction
   char code[5];
   int result;
   do {
       printf("Enter the three-letter code for an airport: ");
       scanf("%s", code);
       printf("Searching: %s\n", code);

       if ((result = search(airportList, nA, code)) >= 0) {
          printf("Success: ");
          show(airportList[result]);
       }
       else
          printf("Unsuccessful: %s is not a known airport.\n", code);

   } while (more());
   printf("Goodbye!\n");

   return(0);
} // main() 

int search(Airport list[], int n, char *code) {
   // Returns the index of code in list[], -1 o/w using linear search
   for (int i=0; i < n; i++) {
      if (strcmp(list[i].code, code) == 0)
	 return i;
   }
   return -1;
} // search()

int more() {
   char resp[5];
   while (1) {
       printf("Would you like to search again (Y/N)? ");
       scanf("%s", resp);
       if ((strcmp(resp, "Y") == 0) || (strcmp(resp, "y") == 0))
	  return 1;
       else if ((strcmp(resp, "N") == 0) || (strcmp(resp, "n") == 0))
	  return 0;
       else
          printf("Please enter a Y or a N.\n");
   }
} // more()

void readData(char *file, Airport list[], int *n) {
   // Load airport database into list[] from file, set n

   FILE *fp;

   int i = 0;

   printf("Opening file: %s\n", file);
   fp = fopen(file, "r");
   if (fp == NULL) {
      printf("Unable to open file %s.\n", file);
      exit(EXIT_FAILURE);
   }
   printf("Opened file %s.\n", file);
   printf("Reading...");

   char line[80];
   fgets(line, sizeof(line), fp); // ignore first line
   while ( (fgets(line, sizeof(line), fp)) != NULL) {
      int l = strlen(line);
      line[l-1] = '\0';
      list[i] = parseAirport(line);
      i++;
   }

   *n = i;
   fclose(fp);
   printf("...done. [%d]\n", i);
} // readData() 
