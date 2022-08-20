## Description
In this code you will find how you can make square Alphabet pattern by using while loop

## code 
```cpp

#include<bits/stdc++.h>
using namespace std;

int main(){
    int row, n;
    cout << "Enter the number: ";
    cin >> n;
    row = 1;

    // Declared ch = A for starting
    char ch = 'A';
    while(row<=n){
        int col = 1;
        while(col<=n){

            // char(ch + (col - 1)) is the formula for printing next alphabet
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
A B C
B C D
C D E
```

## GFG IDE CODE
https://ide.geeksforgeeks.org/7518d39c-1fa6-4c6b-a71e-bf94e16bd94f