//Header

#include <stdio.h>
#define H 4
#define W 4

void show(int col, int row, int arr[row][col]);
int getMove(void);

int main(void) {
    int arr[H][W] = {{1,10,15,4},{13,6,3,8},{2,9,12,7},{14,5,-1,11}};
    int input;
    int spaceI = 3;
    int spaceJ = 2;

    show(W, H, arr); //print board
    while((input = getMove()) != -1) { //user enters tile
    int inputI;
    int inputJ;
    //find input
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if (arr[i][j] == input) {
                inputI = i;
                inputJ = j;
            }
        }
    }

        //if input is not on the board
        if (input > 15) {
            printf("Invalid tile.");
        }            
        //else if input can be moved left or right
        else if (spaceI == inputI) {
            if (spaceJ - 1 == inputJ) {
                inputJ++; //move tile
                spaceJ--; //move space index
            }
            if (spaceJ + 1 == inputJ) {
                inputJ--; //move tile
                spaceJ++; //move space index
            }
        }
        //else if input can be moved up or down
        else if (spaceJ == inputJ) {
            if (spaceI - 1 == inputI) {
                inputI++; //move tile
                spaceI--; //move space index
            }
            if (spaceI + 1 == inputI) {
                //inputI--; //move tile
                //spaceI++; //move space index
            }
        }
        else {
            //cannot move
            printf("I can't move that tile.");
        }
        arr[inputI][inputJ] = input;
        arr[spaceI][spaceJ] = -1;
        show(W, H, arr);
    }

    return 0;
}

void show(int col, int row, int arr[row][col]) {
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(arr[i][i] == -1) {
                printf(" ");
            }
            else {
                printf("%3d", arr[i][j]);
            }
        }
        printf("\n");
    }
}

int getMove(void) {
    int input;
    scanf("Enter the tile you would like to move: %d", &input);

    return input;
}