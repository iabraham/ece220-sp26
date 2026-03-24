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
  Flight data;
  FILE *infile;
  int status;
  int num_flights = 0;

  infile = fopen("airport_data.bin", "rb");
  if (infile == NULL) {
    fprintf(stderr, "Error opening file\n");
    return 1;
  }
  fread(&num_flights, sizeof(num_flights), 1, infile);
  printf("Number of flights: %d\n", num_flights);
  do {
    status = fread(&data, sizeof(data), 1, infile);
    printf("Read flight code: %s arrives  at %u\n", data.code,
           data.arrival_time);
  } while (status == 1);

  fclose(infile);
  return 0;
}
