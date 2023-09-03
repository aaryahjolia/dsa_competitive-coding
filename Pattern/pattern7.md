# Description 
In this code, a triangle pattern will be formed using for loop

# Code
```
#include <iostream>
using namespace std;

int main() {
    int i, j, n;
    cin >> n;
    for (i = 1; i <= n; i++) {
        int a = i;
        for (j = 1; j <= n - i; j++) {
            cout << "  ";
        }
        for (j = 1; j <= i; j++) {
            cout << a << " ";
            a++;
        }
        for (j = 1; j < i; j++) {
            a--;
            cout << a - 1 << " ";
        }
        cout << endl;
    }
    return 0;
}
```
# Test Cases
```
Sample-Test case 1:

Input: 5
Output:
        1 
      2 3 2 
    3 4 5 4 3 
  4 5 6 7 6 5 4 
5 6 7 8 9 8 7 6 5 

Sample-Test case 2:

Input: 3
Output:
    1
  2 3 2
3 4 5 4 3
```
