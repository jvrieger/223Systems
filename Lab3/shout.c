//Julia Rieger

#include <stdio.h>
#include <ctype.h>

int main() {

    char x;

    while ((x = getchar()) != EOF) {
        putchar(toupper(x));
    }

    return 0;
}