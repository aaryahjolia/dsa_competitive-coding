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
n = 4;
A
B C 
C D E 
D E F G
```

## Prerequisite 
Don't just watch the code use it and do changes for better understanding