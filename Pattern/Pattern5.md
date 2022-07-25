## Description
In this code you will find how you can make pattern of square using numbers and stars by while loop

## code 
```cpp

#include<bits/stdc++.h>
using namespace std;

int main(){
    int row,n;
    cout << "Enter the number: ";
    cin >> n;
    row = 1;
    while(row<=n){
        // triangle 1
        int tri_one = n - row + 1;
        int col = 1;
        while(col<=tri_one){
            cout << col++;
        }

        // triangle 2
        int star = (row - 1) * 2;
        while(star){
            cout << "*";
            star--;
        }

        // triangle 3
        int tri_three = n - row + 1;
        while(tri_three){
            cout << tri_three--;
        }
        cout << endl;
        row++;
    }
    return 0;
}
```

## Output
```
n = 5;
1234554321
1234**4321
123****321
12******21
1********1

## 1st traingle
12345
1234
123
12
1

## 2nd triangle
**
****
******
********

## 3rd traingle
54321
4321
321
21
1
```

## Prerequisite 
Don't just watch the code use it and do changes for better understanding