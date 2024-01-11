#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 30 // Assume no word will be more than 30 chars
#define N 10000 //Alice.txt has 2026 unique words

int search(char word[][MAX_WORD_LEN + 1], int n, char w[MAX_WORD_LEN]);
//void sort(int counts[], char words[][], int n);

int main(void) {
    char word[MAX_WORD_LEN+1];
    char wordList[N][MAX_WORD_LEN + 1];
    int counts[N] = {0}; //stores counts for each word
    int nw = 0; //num words stored so far

    while ((scanf("%s", word)) != EOF) {
        int p = search(wordList, N, word); //look for word in wordList

        if (p < 0) { //search returns -1 if word is not in list, index o/w
            strcpy(wordList[nw], word); //copy word to returned search-index in wordList
            nw++;
            counts[p]++;
        }
        else {
            counts[p]++;
        }
    }

    //sort(counts, wordList, nw);

    for (int i = 0; i < N; i++) {
        printf("%3d: %s\n", counts[i], wordList[i]);
    }
    return 0;
} // main()

int search(char word[][MAX_WORD_LEN + 1], int n, char w[MAX_WORD_LEN]) {
    //look for w in words
    //return -1 if not found or index if found -> words[index] = w

    for (int index = 0; index < n; index++) {
        if(strcmp(word[index], w) == 0) //if the word in the index is what we are looking for return index
            return index;
    }
    return -1;
    
} //search()

/*
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
} //swap()

void swap( char *ary, int idx1, int idx2, int rowlen ) {
    for ( int x=0; x<rowlen; x++ ) {
        char[][] temp = ary[idx1][x];
        ary[idx1][x] = ary[idx2][x];
        ary[idx2][x] = temp;
    }
}
 
void sort(int counts[], char words[][], int n) {
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (counts[j] < counts[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
           if(min_idx != i) {
            swap(&counts[min_idx], &counts[i]);
            for ()
            swap2(words[min_idx], words[i], N);
           }
    }
} //sort()
*/