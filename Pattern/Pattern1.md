## Description
In this code you will find how you can make * pattern by using while loop

## code 
```cpp

#include<bits/stdc++.h>
using namespace std;

int main(){
    int row, n;
    cout << "Enter the number: ";
    cin >> n;
    row=1;

    // This loop descire the row which will go till the value of n
    while(row<=n){    
        int col=1;

        // This loop run firstly for col till col<=n then again till row<=n
        while(col<=row){  
            
            // Print * for col<=n in each row loop
            cout << "* "; 
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}
```

## Output
```
*
* *
* * *
```

## GFG URL CODE
https://ide.geeksforgeeks.org/21afee75-c704-4fe7-a2dc-92c5f20eaa98