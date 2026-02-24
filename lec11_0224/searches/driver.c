#include "search.h"
#include <stdio.h>

/* Driver code */
int main(void) {
  int arr[] = {17, 43, 9, 40, 11, 68, 13};
  int len = sizeof(arr) / sizeof(arr[0]);
  int i, idx;
  int key = 40;

  for (i = 0; i < len; i++)
    printf("%d ", arr[i]);

  printf("\n");

  idx = search(arr, len, key);

  if (idx >= 0)
    printf("Found %d at index %d with value %d\n", key, idx, arr[idx]);
}
