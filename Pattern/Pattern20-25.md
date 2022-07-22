#include<bits/stdc++.h>
using namespace std;

/*
Pattern 21:
n = 4;
   *
  **
 ***
**** 
*/

int main(){
int row, n;
    cout << "Enter the number: ";
    cin >> n;
    row = 1;
    while(row<=n){
        int space = n - row;
        while(space){
            cout << " ";
            space--;
        }
        int col = 1;
        while(col<=row){
            cout << "*";
            col++;
        }
        cout << endl;
        row++;
    }   
    return 0;
}

/*
Pattern 22:
n = 4;
****
***
**
* 
int row, n;
    cout << "Enter the number: ";
    cin >> n;
    row = 1;
    while(row<=n){
    int star = n - row + 1;
    int col = 1;
        while(star){
            cout << "*";
            star--;
        }
        cout << endl;
        row++;
    }    


Pattern 23:
n = 4;
****
 ***
  **
   *
int row, n;
    cout << "Enter the number: ";
    cin >> n;
    row = 1;
    while(row<=n){
        int space = row - 1;
        while(space){
            cout << " ";
            space--;
        }
        int col = 1;
        int star = n - row + 1;
        while(col<=star){
            cout << "*";
            col++;
        }
        cout << endl;
        row++;
    }


Pattern 24:
n = 4;
   1   
  121
 12321 
1234321  
int row, n;
    cout << "Enter the number: ";
    cin >> n;
    row = 1;
    while(row<=n){
        // Print space
        int space = n - row;
        while(space){
            cout << " ";
            space--;
        }

        // Print 1st triangle
        int col = 1;
        while(col<=row){
            cout << col;
            cout << "*";    // for star
            col++;
        }

        // Print 2nd triangle
        int num = row - 1;
        while(num){
            cout << num;
            cout << "*";    // for star
            num--;
        }
        cout << endl;
        row++;
    }


Pattern 25:
n = 4;
1 1 1 1
  2 2 2
    3 3
      4  
int row, n;
    cout << "Enter the number: ";
    cin >> n;
    row = 1;
    int count = 1;
    while(row<=n){
        int space = row - 1;
        while(space){
            cout << " ";
            space--;
        }
        int num = n - row + 1;
        while(num){
            cout << count;
            num--;
        }
        cout << endl;
        row++;
        count++;
    }

*/