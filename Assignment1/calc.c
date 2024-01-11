#include <stdio.h>

int main(void) {
    int a, b, total;
    char o;

    do {
        printf("Enter an operation: ");
        scanf(" %c", &o);
        if (o == '0') {
            break;
        }
        printf("Enter a number: ");
        scanf("%d", &a);

        printf("Enter a number: ");
        scanf("%d", &b);

        if (o == '+') {total = a+b;}
        else if (o == '-') {total = a-b;}
        else if (o == '/') {total = a/b;}
        else if (o == '*') {total = a*b;}
        else {printf("Please enter a valid operator.\n");}

        printf("%d %c %d = %d\n", a, o, b, total);

    } while(o != 0);

    printf("Good-bye.");
} //main()