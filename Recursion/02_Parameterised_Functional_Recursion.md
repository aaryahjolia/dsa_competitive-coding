## 1. Parameterised Recursion

When the operations are done through parameters only, then it is called parameterised recursion.

Example of Sum of N numbers:
```cpp
#include <bits/stdc++.h>
using namespace std;

void calculateSum (int i, int sum){
    if(i<1){
        cout<<sum<<endl;
        return;
    }
    calculateSum(i-1, sum+i);
}

int main() {
    int n;
    cin>>n;
    calculateSum(n, 0);
    return 0;
}
```

## 2. Functional Recursion

When we want the function to return some values, then it is called functional recursion.

```cpp

```