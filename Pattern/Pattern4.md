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
n = 4;
   1   
  121
 12321 
1234321

## 1st triangle
   1
  12
 123
1234

## 2nd triangle
  1
  21
  321
```

## Prerequisite 
Don't just watch the code use it and do changes for better understanding