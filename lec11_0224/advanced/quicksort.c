#include <stdio.h>

/* Pushes integral elements `i1` and `i2` onto given `stack` with stack-pointer
 * `top` in that order */
void push(int *stack, int *top, int i1, int i2) {
  stack[++(*top)] = i1;
  stack[++(*top)] = i2;
}

/* Returns top most element of stack `stack` and updates provided stack-pointer
 * `top` */
int pop(int *stack, int *top) { return stack[(*top)--]; }

/* Swaps `one` with `two` */
void Swap(int *one, int *two) {
  int temp = *one;
  *one = *two;
  *two = temp;
}

int partition(int arr[], int start, int end) {

  // First elmenet is pivot
  int pivotVal = arr[start];

  // Initialize left, right pointers
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

/*Sorts part of array `arr` in ascending order. Takes as argument `start` and
 * `stop` which are indices determining sub-array of `arr` to sort */
void QuickSortIterative(int arr[], int start, int end) {

  // Initialize stack and stack pointer
  int stack[end - start + 1];
  int top = -1;

  // Push indices of first sub-array being sorted onto stack
  push(stack, &top, start, end);

  // Keep popping from stack while not empty
  while (top >= 0) {
    // Pop end and start
    end = pop(stack, &top);
    start = pop(stack, &top);

    // Sort & partition the array, pivotVal is the partition index
    int pivotVal = partition(arr, start, end);

    // If there are elements on left of the pivot, push left side onto stack
    if (start < pivotVal)
      push(stack, &top, start, pivotVal);

    // If there are elements on right of the pivot, push right side onto stack
    if (pivotVal + 1 < end)
      push(stack, &top, pivotVal + 1, end);
  }
}

void sort(int arr[], int n) { QuickSortIterative(arr, 0, n - 1); }
