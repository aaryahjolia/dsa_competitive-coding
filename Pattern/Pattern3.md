## Description
In this code you will find how you can make triangle Alphabet pattern by using while loop

## code 
```cpp

#include<bits/stdc++.h>
using namespace std;

int main(){
    int row, n;
    cout << "Enter the number: ";
    cin >> n;
    row = 1;
    char ch = 'A';
    while(row<=n){
        int col = 1;
        while(col <= row){
        // Formula for getting next alphabet in each iterate 
        cout << char(ch + (col - 1)) << " ";
        col++;
        }
        cout << endl;
        ch++;
        row++;
    }
    return 0;
}
```

## Output
```
A
B C 
C D E 
D E F G
```

## GFG IDE CODE
https://ide.geeksforgeeks.org/46017047-3878-4098-8e60-e979b2b39980