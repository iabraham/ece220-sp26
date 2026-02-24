#include "search.h"

int search(int arr[], int n, int key) {
  int low = 0;      // Left pointer
  int high = n - 1; // Right pointer

  while (high >= low) {
    int mid = (high + low) / 2; // Pick middle element

    // Logic to focus search on left or right of mid
    if (key == arr[mid])
      return mid;
    else if (key < arr[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1; // Loop exited, element not present.
}
