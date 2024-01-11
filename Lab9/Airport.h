// FILE: Airport.h
// Define the Airport data structure

typedef struct {
    char code[5]; // code
    char name[50]; // name of airport
    char city[30]; // city
    char state[5]; // state
    char country[20]; // duh
} Airport;

// Functions relating to Airport type
void show(Airport a); // prints out a given airport object
Airport parseAirport(char * str); // Parses str