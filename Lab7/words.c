#include <stdio.h>
#include <stdlib.h>
#define MAX_WORD_LEN 30 // Assume no word will be more than 30 chars

int main(void) {
    char word[MAX_WORD_LEN+1];

    while ((scanf("%s", word)) != EOF)
        printf("%s\n", word);

    return 0;
} // main()