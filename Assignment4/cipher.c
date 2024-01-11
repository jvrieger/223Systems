//Julia Rieger
//Oct 29 2023
//Assignment 4- Cyphers and Pointers

#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 80

void encrypt1(char message[], char codedMsg[], int n, int shift);
// Encrypts the text in message[0..n-1] using Caesar Cipher with shift (1 <= shift <= 26). Result is left in codedMsg[]

void encrypt2(char *message, char *codedMsg, int shift);
// Encrypts the string in message[] using Caesar Cipher with shift (1 <= shift <= 26). Result is left in codedMsg.

int main(void) {

    char message[MAX_LENGTH + 1]; //message array to hold user input
    char codedMsg[MAX_LENGTH + 1]; //array to hold coded message
    int shift; //amount for each letter to be shifted

    printf("Enter message to be encrypted: ");
    gets(message);

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    encrypt1(message, codedMsg, MAX_LENGTH, shift);

    printf("Coded message encript1(): %s\n", codedMsg);

    encrypt2(message, codedMsg, shift);

    printf("Coded message encript2(): %s\n", codedMsg);

    return 0;
}

void encrypt1(char message[], char codedMsg[], int n, int shift) {

    for (int i = 0; i < n; i++) { //for each char in the array
        //if is an uppercase letter use formula for uppercase
        if (isupper(message[i]))
            codedMsg[i] = ((message[i] - 'A') + shift) % 26 + 'A';

        //if is a lowercase letter use formula for lowercase
        else if (islower(message[i]))
            codedMsg[i] = ((message[i] - 'a') + shift) % 26 + 'a';

        else { //leave all other chars alone
            codedMsg[i] = message[i];
        }
    }

}

void encrypt2(char *message, char *codedMsg, int shift) {
    
    char *p = message; //copy message into pointer var so we can increment
    char *p2 = codedMsg; //copy codedMsg into pointer var so we can increment

    while (*p != '\0') {     //message is null terminated--exit loop when see null
        //if is an uppercase letter use formula for uppercase
        if (isupper(*p)) 
            *p2 = ((*p - 'A') + shift) % 26 + 'A';

        //if is a lowercase letter use formula for lowercase
        else if (islower(*p)) 
            *p2 = ((*p - 'a') + shift) % 26 + 'a';

        else  //leave all other chars alone
            *p2 = *p;
        
        p++;
        p2++;
    }

}