#include <stdio.h>

int main(void) {
    int a, b;
    printf("Enter a number: ");
    scanf("%d", &a);

    printf("Enter a number: ");
    scanf("%d", &b);

    printf("%d + %d = %d\n", a, b, a+b);
} //main()