#include <stdio.h>

struct flightType {
  char flightCode[20];
  unsigned int altitude;
  float longitude;
  float latitude;
  float airSpeed;
};

struct student {
  char name[80];
  unsigned long UIN;
  unsigned int year;
  float GPA;
};

int main(void) {
  struct student s1 = {"Garfield", 123456, 6, 3.5};
  struct student BL3[2] = {s1, {"Scooby", 234578164, 2, 4.0}};
  printf("Name is %s", BL3[1].name);
}
