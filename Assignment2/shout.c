//Name: Julia Rieger
//Date: 9/26/23
//shout.c Assignment 2 CS223

#include <stdio.h>
#include <ctype.h>

#define NUMLETTERS 26

int main(){

    int counts[NUMLETTERS] = {0};
    char x;

    //read every char in input
    while ((x = getchar()) != EOF) {
        if(isalpha(x)) {
            x = toupper(x);
            counts[x - 'A']++;
        }
    }

    printf("Letter Frequency Counts:\n");
    for(int i = 0; i < NUMLETTERS; i++) {
        printf("%c: %d\n", ('A'+i), counts[i]);
    }
    
    return 0;
}