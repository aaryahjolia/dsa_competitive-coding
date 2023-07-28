### Bitwise AND Operation
The bitwise AND operation is a fundamental operation in computer programming that works on individual bits of binary numbers. 

In this operation, if both input bits are 1, the resulting bit will be 1. Otherwise, if either or both of the input bits are 0, the corresponding resulting bit will be 0. Consequently, the bitwise AND operation can be seen as a way to extract common 1-bits from two binary numbers while setting all other bits to 0.

Truth table for **Bitwise AND** Operation: <br>
<p align="center">
  <img src="https://github.com/Ashutosh0120/dsa_competitive-coding-GSSOC-2023/assets/24804042/50b90107-8753-4fb2-b012-cc7394673329" alt="Image">
</p>

Example: <br>
If A=10100, B=10101, then
<p align="center">
  <img src="https://github.com/Ashutosh0120/dsa_competitive-coding-GSSOC-2023/assets/24804042/96ad669c-477f-40e5-a0cb-dae0816cf899" alt="Image">
</p>

## Code:
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
  int a=5, b=4;
  int c=a&b;
  cout<<c<<endl;   //AND of a and b
  return 0;
}
```
## Output:
```cpp
4   //Since 5&4=4
```
## Complexity:
```
Time Complexity: O(1)                                                            
Auxiliary Space: O(1)
```
