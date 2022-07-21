## Description 
Radix sort algorithm  sorts the elements by  grouping the individual digits of the same place value. Then, sort the elements according to the elements increasing/decreasing order.

## Code  
```cpp

#include <iostream>
using namespace std;


int getMax(int arr[], int size) {
  int max = arr[0];
  for (int i = 1; i < size; i++)
    if (arr[i] > max)
      max = arr[i];
  return max;
}


void CountingSort(int arr[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;


  for (int i = 0; i < size; i++)
    count[(arr[i] / place) % 10]++;


  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];


  for (int i = size - 1; i >= 0; i--) {
    output[count[(arr[i] / place) % 10] - 1] = arr[i];
    count[(arr[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    arr[i] = output[i];
}

void RadixSort(int arr[], int size) {

  int max = getMax(arr, size);

 
  for (int place = 1; max / place > 0; place *= 10)
    CountingSort(arr, size, place);
}


void printArray(int array[], int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}


int main() {
  int arr[] = {12, 132, 164, 23, 1, 45, 78};
  int size = sizeof(arr) / sizeof(arr[0]);
  RadixSort(arr, size);
  printArray(arr, size);
}
```

## Complexities
### Time complexity   : 
Best Case  : O(n+k)

Worst Case : O(n+k)

Average    : O(n+k)

### Space complexity  : 
O(max)


