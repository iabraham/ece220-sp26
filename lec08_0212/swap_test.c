void swap(int first, int second) {
  int temp;
  temp = first;
  first = second;
  second = temp;
}

int main() {
  int valueA;
  int valueB;
  valueA = 3;
  valueB = 4;
  swap(valueA, valueB);
  return 0;
}
