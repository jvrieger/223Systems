#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 500

int rollDie();

int main(void) {
    srand(time(NULL));
    int freq[6] = {0};
    for (int i = 0; i < n; i++) {
        freq[rollDie()-1]++;
    }

    printf("empirical probability of 3: %.2f\n", ((float)freq[3]/(float)n));
    printf("%d %d %d %d %d %d", freq[0],freq[1],freq[2],freq[3],freq[4],freq[5]);
    return 0;
} //main()

int rollDie(void) {
    return 1 + (rand()%6);
} //rollDie()