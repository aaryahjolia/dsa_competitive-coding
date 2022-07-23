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
n = 3;
A B C
B C D
C D E
```

## Prerequisite 
Don't just watch the code use it and do changes for better understanding