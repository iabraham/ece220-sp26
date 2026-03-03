#include <stdio.h>

void Swap(int *one, int *two) {
  int temp = *one;
  *one = *two;
  *two = temp;
}

int partition(int arr[], int start, int end) {

  int pivotVal = arr[start];
  int left = start - 1;
  int right = end + 1;

  while (1) {
    do
      left++;
    while (arr[left] < pivotVal);

    do
      right--;
    while (arr[right] > pivotVal);

    if (left >= right)
      return right;

    Swap(&arr[left], &arr[right]);
  }
}

void QuickSort(int arr[], int start, int end) {
  if (start < end) {
    int split = partition(arr, start, end);
    QuickSort(arr, start, split);
    QuickSort(arr, split + 1, end);
  }
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
    printf("%d ", arr[i]);
  }
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("\n\n");
  QuickSort(arr, 0, n - 1);
  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}
