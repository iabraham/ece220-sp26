#include <stdio.h>

enum weekday { SUN = 1, MON, TUE, WED = 2, THR, FRI, SAT };

int is_workday(enum weekday day) {
  if (day > SUN && day < SAT)
    return 1;
  else
    return 0;
}

int main(void) {

  enum weekday today = THR;
  enum weekday day_after_next = today + 2;
  printf("The enums are: %d, %d, %d, %d, %d, %d, %d\n", SUN, MON, TUE, WED, THR,
         FRI, SAT);

  // printf("Today is day #%d of the week.\n", today);
  // printf("Today is %s\n", is_workday(today) ? "a workday" : "not a workday");

  // printf("\n");
  // printf("Day after tomorrow is day #%d of the week.\n", day_after_next);
  // printf("That day is %s\n",
  //        is_workday(day_after_next) ? "a workday" : "not a workday");
}
