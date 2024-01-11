#include <stdio.h>

int main(void) {
    int a, total;

    printf("Enter a number: ");
    scanf("%d", &a);
    total = a;

    while (a != 0) {
        printf("Enter a number: ");
        scanf("%d", &a);
        total += a;
    }

    printf("Sum: %d\n", total);
} //main()