//Julia Rieger

#include <stdio.h>

#define NUMSCORES 51

int main(){
    int count = 0;
    float total = 0;
    int counts[NUMSCORES] = {0};
    int score;
    scanf("%d", &score);
    count++;
    
    while(scanf("%d", &score) == 1) {
        counts[score]++; //increase count of score (index) by 1
    }

    for(int i = 0; i < NUMSCORES; i++) {
        printf("%d: ", i);
        for (int j = 0; j < counts[i]; j++) {
            count++;
            total += i;
            printf("X");
        }
        printf("\n");
    }

    printf("The average score for %d students is %.2f\n", count, (total/count));

    return 0;
}