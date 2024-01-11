#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

 FILE *fp;

 if (argc != 2) {
    printf("Cannot proceed: Missing file name.\n");
    exit(EXIT_FAILURE);
 }

 printf("Opening file: %s\n", argv[1]);
 fp = fopen(argv[1], "r");
 if (fp == NULL) {
 printf("Unable to open file %s.\n", argv[1]);
 exit(EXIT_FAILURE);
 }
 printf("Able to open file %s\n", argv[1]);

 fclose(fp);
 return(0);
} // main() 