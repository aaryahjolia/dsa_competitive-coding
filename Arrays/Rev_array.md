## Description
Given an array and you have to reverse its elements.
e.g., arr[] = {1,2,4,5,6} 
      output -> arr[] = {6,5,4,2,1}

## Code
```cpp

// Method 1: Using for loop

#include <bits/stdc++.h>

using namespace std;

int main() {
  int numbers[] = {1, 2, 3, 4, 5};
  int size = sizeof(numbers) / sizeof(numbers[0]);

  for (int i = 0; i < size / 2; i++) {
    swap(numbers[i],numbers[size-i-1]);
  }

  for (int i = 0; i < size; i++) {
    cout << numbers[i] << " ";
  }

  cout << endl;

  return 0;
}

# Time complexity : O(size)
# Space complexity : O(1)


// Method 2: Using built-in function

#include <bits/stdc++.h>

using namespace std;

int main() {
  int numbers[] = {1, 2, 3, 4, 5};
  int size = sizeof(numbers) / sizeof(numbers[0]);

  reverse(numbers, numbers + size);

  for (int i = 0; i < size; i++) {
    cout << numbers[i] << " ";
  }

  cout << endl;

  return 0;
}

# Time complexity : O(size)
# Space complexity : O(1)

