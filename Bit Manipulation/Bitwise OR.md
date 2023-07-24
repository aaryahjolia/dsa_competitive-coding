### Bitwise OR Operation
The bitwise OR operation is a fundamental operation in computer programming that works on individual bits of binary numbers. 

In this operation, if at least one of the input bits is 1, the resulting bit will be 1. Only when both input bits are 0 will the corresponding resulting bit be 0. Consequently, the bitwise OR operation can be seen as a way to combine the 1-bits from two binary numbers, while setting all other bits to 0 if they are both 0.

Truth table for **Bitwise OR** Operation: <br>
<p align="center">
  <img src="https://github.com/Ashutosh0120/dsa_competitive-coding-GSSOC-2023/assets/24804042/b4046a66-c1f5-4a91-b52e-5527016c654c" alt="Image">
</p>

Example: <br>
If A=10100, B=10101, then
<p align="center">
  <img src="https://github.com/Ashutosh0120/dsa_competitive-coding-GSSOC-2023/assets/24804042/b24b6548-fd91-4d77-8b0d-a280f1983cec" alt="Image">
</p>

## Code:
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
  int a=5, b=4;
  int c=a|b;
  cout<<c<<endl;   //OR of a and b
  return 0;
}
```
## Output:
```cpp
5   //Since 5|4=5
```
## Complexity:
```
Time Complexity: O(1)                                                            
Auxiliary Space: O(1)
```
