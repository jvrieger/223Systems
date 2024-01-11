//Name: Julia Rieger
//Date: 9/26/23
//mywc.c Assignment 2 CS223

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {

    char x;
    int lines = 0;
    int words = 0;
    int chars = 0;
    bool isWord = false;

    //read every char in input
    while ((x = getchar()) != EOF) {
        chars++;
        if(x == '\n') {
            lines++;
        }
        if(isspace(x)) {
            isWord = false;
        }
        else if(!isWord) {
            isWord = true;
            words++;
        }
    }

    printf("\n%d %d %d\n", lines, words, chars);

    return 0;
}