## Description
In this code you will find how you can make Hour-glass Pattern by using while loop

## code 
```cpp

#include <iostream>
using namespace std;
  
// Function definition
void pattern(int rows_no)
{
    //code for printing first invert number pyramid
    int row = 1;
    while(row<=rows_no){
        //printing spaces
        int space = row-1;
        while(space){
            cout << " ";
            space -= 1;
        }
        int col = 1;
        //printing rows count
        int count = row;
        while(col<=rows_no - row + 1){
            cout << count << " ";
            col += 1;
            count += 1;
        }  
        cout << " " << endl;
        row += 1;
    }
    //code for printing second number pyramid 
    row = 2;
    while(row<=rows_no){
        int space = rows_no-row;
        //printing spaces
        while(space){
            cout << " ";
            space -= 1;
        }
        // printing cols count
        int col = 1;
        int count = rows_no - row + 1;
        while(col<=row){
            cout << count << " ";
            col += 1;
            count += 1;
        }   
        cout << " " << endl;
        row += 1;
    }
}
  
// Driver code
int main()
{
    // taking rows value from the user
    int rows_no = 7;
  
    pattern(rows_no);
    return 0;
}

```

## Output
```
  1   2   3   4   5   6   7  
    2   3   4   5   6   7  
      3   4   5   6   7
        4   5   6   7
          5   6   7
            6   7
              7
            6   7
          5   6   7
        4   5   6   7
      3   4   5   6   7
    2   3   4   5   6   7
  1   2   3   4   5   6   7
```

## GFG IDE CODE
https://ide.geeksforgeeks.org/