#include<bits/stdc++.h>
using namespace std;

/*
Pattern 16:
n = 3
1
2 3 
3 4 5
*/

int main(){
    int row, n;
    cout << "Enter the number: ";
    cin >> n;
    row = 1;
    while(row <= n){
        int col = 1;
        while(col <= row){
            cout << (row + (col - 1)) << " ";
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}

/*
Pattern 17:
n = 3;
A 
B B
C C C
int row, n;
    cout << "Enter the number: ";
    cin >> n;
    row = 1;
    char ch = 'A';
    while(row<=n){
        int col = 1;
        while(col <= row){
            cout << ch << " ";
            // cout << char(ch + (row - 1)) << " ";    // By formula
            col++;
        }
        cout << endl;
        ch++;
        row++;
    }


Pattern 18:
n = 3;
A 
B C
D E F
int row, n;
    cout << "Enter the number: ";
    cin >> n;
    row = 1;
    char ch = 'A';
    while(row<=n){
        int col = 1;
        while(col<=row){
            cout << ch++ << " ";
            col++;
        }
        cout << endl;
        row++;
    }


Pattern 19:
n = 4;
A
B C 
C D E 
D E F G
int row, n;
    cout << "Enter the number: ";
    cin >> n;
    row = 1;
    char ch = 'A';
    while(row<=n){
        int col = 1;
        while(col <= row){
        cout << char(ch + (col - 1)) << " ";
        col++;
        }
        cout << endl;
        ch++;
        row++;
    }


Pattern 20:
n = 4;
D
C D
B C D
A B C D
int row, n;
   cout << "Enter the number: ";
   cin >> n;
   row = 1;
   char ch = 'D';
   while(row<=n){
    int col = 1;
    // char startCh = 'A' + n - row;    // Another way
    while(col<=row){
        cout << char(ch - (row - col)) << " ";
        // cout << startCh++ << " ";
        col++;
    }
    cout << endl;
    row++;
   }

*/