#include <stdio.h>
#include <stdlib.h>
#define FILE_NAME "code.txt"
int main(void) {

 FILE *fp;
 printf("Opening file: %s\n", FILE_NAME);
 fp = fopen(FILE_NAME, "r");
 if (fp == NULL) {
 printf("Unable to open file %s.\n", FILE_NAME);
 exit(EXIT_FAILURE);
 }
 printf("Able to open file %s\n", FILE_NAME);

 fclose(fp);
 return(0);
} // main()