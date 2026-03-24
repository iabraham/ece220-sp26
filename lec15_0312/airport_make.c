#include <stdio.h>

struct geoloc {
  float lattitude;
  float longitude;
};

typedef struct flight {
  char code[8];
  unsigned int arrival_time;
  unsigned int depart_time;
  struct geoloc origin;
  struct geoloc destination;
} Flight;

int main(void) {
  int numplanes;
  Flight data;
  int i;
  FILE *outfile;
  printf("Enter number of planes to record:");
  scanf("%d", &numplanes);
  outfile = fopen("airport_data.bin", "ab");
  fwrite(&numplanes, sizeof(int), 1, outfile);

  for (i = 0; i < numplanes; i++) {
    printf("Enter details of record #%d\n", i + 1);
    printf("Enter airline code:\t");
    scanf("%s", data.code);
    printf("Enter arrival time:");
    scanf("%u", &data.arrival_time);
    printf("Enter departure time:");
    scanf("%u", &data.depart_time);
    printf("Enter origin lattitude:");
    scanf("%f", &data.origin.lattitude);
    printf("Enter origin longitude:");
    scanf("%f", &data.origin.longitude);
    printf("Enter destination lattitude:");
    scanf("%f", &data.destination.lattitude);
    printf("Enter destination longitude:");
    scanf("%f", &data.destination.longitude);
    fwrite(&data, sizeof(data), 1, outfile);
  }
  fclose(outfile);
  return 0;
}
