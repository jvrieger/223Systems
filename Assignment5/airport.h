// Name: airport.h
// Purpose: Header file for airport

typedef struct {
    char code[5]; //three letter code for airport
    char name[50]; //airport name
    char city[50]; //city name
    char state[5]; //abbreviated state name
    char country[30]; //country name
} Airport;

//prototypes
void show(Airport airport); //formatted print of Airport