#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char code[5];   //code, etc. as named below
    char name[50];
    char city[50];
    char state[5];
    char country[30];
} Airport;

//Airport parse(char *str);
void parse(char *str, Airport *a); //parses data from file into Airport object
void readData(char *file, Airport list[], int *n); //reads and calls parse for Airports into airportList from file
void show(Airport airport); //formatted print of Airport

int main(int argc, char *argv[]) {
    Airport airportList[4000];
    int nA = 0;

    //if invalid input print error and exit
    if (argc != 2) {
        printf("Cannot proceed: Missing file name.\n");
        exit(EXIT_FAILURE);
    }

    readData(argv[1], airportList, &nA); 
    show(airportList[0]); 

    return(0);
} // main()

void show(Airport airport) {
    printf("%s - %s\n", airport.code, airport.name);
    printf("%s, %s (%s)\n", airport.city, airport.state, airport.country);
}

void readData(char *file, Airport list[], int *n) {

    FILE *fp;
    int i = 0; // # of airports read
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
        //list[i] = parse(line);
        parse(line, &list[i]);
        i++;
    } // reads and parses each line into an airport entry

    *n = i;
    fclose(fp);
    printf("...done. [%d]\n", i);
} // readData()

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
} // parse()

/*
Airport parse(char * str) { // Parse the string in str into Airport tokens
    Airport result;
    char *token;
    token = strtok(str, ",");
    strcpy(result.code, token);
    token = strtok(NULL, ",");
    strcpy(result.name, token);
    token = strtok(NULL, ",");
    strcpy(result.city, token);
    token = strtok(NULL, ",");
    strcpy(result.state, token);
    token = strtok(NULL, ",");
    strcpy(result.country, token);
    return result;
} // parse()
*/