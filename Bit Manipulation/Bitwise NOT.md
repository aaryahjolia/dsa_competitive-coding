### Bitwise NOT Operation
The bitwise NOT operation is a unary operation that works on individual bits of a binary number. 
Also known as bitwise complement, it flips each bit of the input number, changing 0s to 1s and 1s to 0s. The result is a new binary number with the complement of each bit from the original number.

Truth table for **Bitwise NOT** Operation: <br>
<p align="center">
  <img src="https://github.com/Ashutosh0120/dsa_competitive-coding-GSSOC-2023/assets/24804042/ebde6110-7050-4b19-89b5-6484103fa633" alt="Image">
</p>

Example: <br>
If A=10100, then
<p align="center">
  <img src="https://github.com/Ashutosh0120/dsa_competitive-coding-GSSOC-2023/assets/24804042/64fbf3b2-e1e6-43b2-987b-97ac591f8d9a" alt="Image">
</p>

## Code:
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
  int a=5, b=~a;
  cout<<c<<endl;   //NOT of a
  return 0;
}
```
## Output:
```cpp
1   //Since ~5=1
```
## Complexity:
```
Time Complexity: O(1)                                                            
Auxiliary Space: O(1)
```
