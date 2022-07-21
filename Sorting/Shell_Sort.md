## Description 
Shell sort is a variation version of the insertion-sort algorithm. It intially sorts elements that are far apart from each other and successively reduces the interval between the elements to be sorted.

## Code  
```cpp

#include <iostream>
using namespace std;


void ShellSort(int arr[], int n) {

  for (int level = n / 2; level > 0; level /= 2) {
    for (int i = level; i < n; i += 1) {
      int temp = arr[i];
      int j;
      for (j = i; j >= level && arr[j - level] > temp; j -= level) {
        arr[j] = arr[j - level];
      }
      arr[j] = temp;
    }
  }
}


void printArray(int array[], int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}


int main() {
  int arr[] = {10, 2, 3, 7, 4, 6, 5, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  ShellSort(arr, size);
  cout << "Sorted Array : \n";
  printArray(arr, size);
}

```

## Complexities
### Time complexity   : 
Best Case  : O(nlog n)

Worst Case : O(n<sup>2</sup>)

Average    : O(nlog n)

### Space complexity  : 
O(1)


