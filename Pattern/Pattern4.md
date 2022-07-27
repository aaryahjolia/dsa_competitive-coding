## Description
In this code you will find how you can make pattern of triangle using numbers or stars by while loop

## code 
```cpp

#include<bits/stdc++.h>
using namespace std;

int main(){
    int row, n;
    cout << "Enter the number: ";
    cin >> n;
    row = 1;
    while(row<=n){
        // Print space for putting the number in middle
        int space = n - row;
        while(space){
            cout << " ";
            space--;
        }

        // Print 1st triangle
        int col = 1;
        while(col<=row){
            cout << col;
            // cout << "*";    // for priniting stars
            col++;
        }

        // Print 2nd triangle
        int num = row - 1;
        while(num){
            cout << num;
            // cout << "*";    // for printing stars
            num--;
        }
        cout << endl;
        row++;
    }
    return 0;
}
```

## Output
```
   1   
  121
 12321 
1234321
```
 
## GF IDE CODE
https://ide.geeksforgeeks.org/cfaf9649-f1cf-4b8f-95b9-bd8d3459caf7