# Description
In this code you will find how to make a pattern whose first half looks like a reverse pyramid and the other half looks like a pyramid.

## Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n ;
  cin>>n;
  // reversed pyramid star pattern
  for (int i = 0; i < n; i++) {
    // printing spaces
    for (int j = 0; j < i; j++) {
      cout << " ";
    }
    // printing star
    for (int k = 0; k < (n - i) * 2 - 1; k++) {
      cout << "*";
    }
    cout << "\n";
  }
  // pyramid star pattern
  for (int i = 2; i <= n; i++) {
    // printing spaces
    for (int j = n; j > i; j--) {
      cout << " ";
    }
    // printing star
    for (int k = 0; k < i * 2 - 1; k++) {
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
}
```
## Output
```
*********
 *******
  *****
   ***
    *
   ***
  *****
 *******
*********
```
## GFG IDE code
https://ide.geeksforgeeks.org/online-cpp-compiler/bbdb3822-127d-4674-a541-555a96475eff
