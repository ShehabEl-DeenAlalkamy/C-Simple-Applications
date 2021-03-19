#include <stdio.h>
#include <stdlib.h>


struct TIME {
   int seconds;
   int minutes;
   int hours;
};

struct TIME differenceBetweenTimePeriod(struct TIME start, struct TIME stop)
{
   struct TIME diff;

   while (stop.seconds < start.seconds) {
      --start.minutes;
      start.seconds += 60;
   }


   diff.seconds = stop.seconds - start.seconds;


   while (stop.minutes < start.minutes) {
      --start.hours;
      start.minutes += 60;
   }
   diff.minutes = stop.minutes - start.minutes;
   diff.hours = stop.hours - start.hours;

   return diff;
}


int main() {
   struct TIME startTime, stopTime, difference;

   printf("Enter the start time. \n");
   printf("Enter hours, minutes and seconds: ");
   scanf("%d %d %d", &startTime.hours,
         &startTime.minutes,
         &startTime.seconds);

   printf("Enter the stop time. \n");
   printf("Enter hours, minutes and seconds: ");
   scanf("%d %d %d", &stopTime.hours,
         &stopTime.minutes,
         &stopTime.seconds);

   difference = differenceBetweenTimePeriod(startTime, stopTime);

   printf("\nTime Difference: %d:%d:%d - ", startTime.hours, startTime.minutes, startTime.seconds);

   printf("%d:%d:%d ", stopTime.hours, stopTime.minutes, stopTime.seconds);

   printf("= %d:%d:%d\n", difference.hours, difference.minutes, difference.seconds);


   return 0;
}



