#include <stdio.h>

int main() {
  // simple array
  int arr[] = {19, 25, 8,  22, 17, 7,  84, 9,  19, 25, 10, 3,  1,  7,  84, 9,
               19, 25, 10, 3,  1,  8,  22, 17, 19, 25, 10, 3,  1,  8,  22, 17,
               7,  84, 9,  33, 1,  8,  22, 17, 7,  84, 9,  19, 25, 10, 22, 17,
               7,  84, 9,  19, 25, 10, 3,  1,  8,  84, 9,  11, 23, 45, 5,  3};

  // using sizeof() operator to get length of array
  int len = sizeof(arr) / sizeof(arr[0]);

  printf("The length of int array is : %d ", len);
}
