//File: search.c
//Run a user experience to search for airports and return information

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "airport.h"

int contains(Airport list[], char code[], int n); //tests whether a list contains an airport
void parse(char *str, Airport *a); //parses data from file into Airport object
void readData(char *file, Airport list[], int *n); //reads and calls parse for Airports into airportList from file

int main(int argc, char *argv[]) {
    Airport airportList[4000];
    int numA = 0;

    //if filename input is invalid, exit
    if (argc != 2) {
        printf("Cannot proceed: Missing file name.\n");
        exit(EXIT_FAILURE);
    }
    
    //retrieve data from file into airportList
    readData(argv[1], airportList, &numA); 

    //run user interaction
    int searchAgain = 1; //search again if = 1, terminate otherwise
    char code[5]; //holds user input
    while(searchAgain==1) {
        printf("Enter the three-letter code for an airport: ");
        scanf("%s", code);
        getchar(); //skip newline
        int index = contains(airportList, code, numA);
        if (index != -1) {
            printf("Success: ");
            show(airportList[index]);
        }
        else {
            printf("Unsuccessful: %s is not a known airport.\n", code);
        }
        //prompt for repeat  
        char answer;
        printf("Would you like to search again (Y/N)? ");
        scanf("%c", &answer);
        getchar(); //skip newline
        if (answer == 'Y') {
            searchAgain = 1;
        }
        else if (answer == 'N') {
            searchAgain = 0;
        }
        else {
            printf("Invalid input.\n");
            exit(EXIT_FAILURE);
        }
    }
    printf("Goodbye!\n");
}

int contains(Airport list[], char code[], int n) {
    //if list contains Airport return index
    for (int i = 0; i < n; i++) {
        if (strcmp(list[i].code, code) == 0) {
            return i;
        } 
    }
    return -1; //-1 otherwise
} //contains()

void parse(char *str, Airport *a) {
    char *token;
    token = strtok(str, ",");
    strcpy(a->code, token);
    token = strtok(NULL, ",");
    strcpy(a->name, token);
    token = strtok(NULL, ",");
    strcpy(a->city, token);
    token = strtok(NULL, ",");
    strcpy(a->state, token);
    token = strtok(NULL, ",");
    strcpy(a->country, token);
} //parse()

void readData(char *file, Airport list[], int *n) {
    FILE *fp;
    int i = 0; //# of airports read
    fp = fopen(file, "r");
    if(fp == NULL) {
        printf("Unable to open file %s.\n", file);
        exit(EXIT_FAILURE);
    }
    printf("Able to open file %s.\n", file);
    printf("Reading data...");

    char line[80];
    fgets(line, sizeof(line), fp); //skip first line
    while ((fgets(line, sizeof(line), fp)) != NULL) { //while there is more to read
        int l = strlen(line);
        line[l-1] = '\0'; //change newline char to null char
        parse(line, &list[i]); //parse next line as Airport into list address
        i++;
    } //reads and parses each line into an airport entry

    *n = i; //store length of Airport list
    fclose(fp);
    printf("done. [%d airports!]\n", i);
} //readData()


