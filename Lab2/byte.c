#include <stdio.h>

int leapYear(int year) {
return (((year%4==0) && (year%100!=0)) || (year%400==0));
} // leapYear()

int main(void) {
    int mon, day, yr, num=0;
   
      printf("Enter a date: ");
      scanf("%d/%d/%d", &mon, &day, &yr);
      for (int i = 1; i < mon; i++) {
        if (i == 2) {
            if (leapYear(yr)) {
                num += 29;
            }
            else {
                num += 28;
            }
        }
        else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            num += 31;
        }
        else {
            num += 30;
        }
      }
      num += day;
      printf("\n This is the %d day of the year\n", num);
}

