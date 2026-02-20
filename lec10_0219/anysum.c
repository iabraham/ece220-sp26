#include <stdio.h>

int any_sum(int arr[], int arr_len) {
  int i, sum = 0;
  for (i = 0; i < arr_len; i++)
    sum += arr[i];
  return sum;
}

int your_sum(int arr[]) {
  int i, sum = 0;
  for (i = 0; i < sizeof(arr) / sizeof(int); i++)
    sum += arr[i];
  return sum;
}

int main(void) {
  int arr1[] = {1, 2, 3, 4, 5};
  int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  printf("sum(arr1): %d\n", any_sum(arr1, 5));
  printf("sum(arr2): %d\n", any_sum(arr2, 9));
}
