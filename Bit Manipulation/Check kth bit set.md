### Check kth bit set or not
In order to check whether the kth bit is set or not, we use below 2 methods: <br>
1. **Right Shift Operation** : To check the kth bit, you can left-shift the number by (k-1) positions and then perform a bitwise AND operation with 1. <br>
If the result is non-zero, it means the kth bit is set (1); otherwise, the kth bit is not set (0).<br>
```cpp
#include<bits/stdc++.h>
using namespace std;
int main() {
  int n = 5, k = 3;
  while(k--){
    n=n>>1;
  }
  if ((n & 1) != 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
```

2. **Bitwise Mask** : Alternatively, you can create a bitmask with only the kth bit set (1), and then perform a bitwise AND operation with the number. If the result is non-zero, the kth bit is set (1); otherwise, it is not set (0). <br>

```cpp
#include<bits/stdc++.h>
using namespace std;
int main() {
  int n = 5, k = 3;
  int m = 1 << (k - 1);
  return (n & m) != 0;
}
```
