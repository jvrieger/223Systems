#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tokenize(char *str, char *code, char *name, char *city, char *state, char *country);

int main(int argc, char *argv[]) {

    char code[30]; // iata code etc.
    char name[40];
    char city[30];
    char state[30];
    char country[30];

    //work on opening the file
    FILE *fp;
    if (argc != 2) {
        printf("Cannot proceed: Missing file name.\n");
        exit(EXIT_FAILURE);
}
    printf("Opening file: %s\n", argv[1]);
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Unable to open file %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    printf("Able to open file %s.\n", argv[1]);
    printf("Reading from file %s.\n", argv[1]);

    //work on reading the file
    char line[80];
    while ((fgets(line, sizeof(line), fp)) != NULL) {
        int l = strlen(line);
        line[l-1] = '\0'; // Eliminate the EOL char ‘\n’
    }

    printf("%s\n", line);
    printf("Parsing <%s> into tokens...\n", line);
    tokenize(line, code, name, city, state, country);

    printf("%s\n", code); // Test: Print data from last line
    printf("%s\n", name);
    printf("%s\n", city);
    printf("%s\n", state);
    printf("%s\n", country);

    fclose(fp);
    return(0);
} // main() 


void tokenize(char *str, char *code, char *name, char *city, char *state, char *country) {
    // Split the string in str into five tokens/strings
    char *token;
    token = strtok(str, ",");
    strcpy(code, token);
    token = strtok(NULL, ",");
    strcpy(name, token);
    token = strtok(NULL, ",");
    strcpy(city, token);
    token = strtok(NULL, ",");
    strcpy(state, token);
    token = strtok(NULL, ",");
    strcpy(country, token);
} // tokenize()