#include<bits/stdc++.h>
using namespace std;

/*
Pattern 11:
n = 4;
1 
2 1 
3 2 1
4 3 2 1
*/

int main(){
int i,n,count;
    cout << "Enter the number: ";
    cin >> n;
    i=1;
    while(i<=n){
        int j=1;
        count = i;
        while(j<=i){
            cout << count << " ";                           
            count--;
            // cout << ((i - j) + 1) << " ";  // Another way
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}


/*
Pattern 12:
n = 3;
A A A
B B B
C C C 
int row, n;
    cout << "Enter the number: ";
    cin >> n;
    row = 1;
    char ch = 'A';
    while(row <= n){
        int col = 1;
        while(col <= n){
            // cout << ch << " ";
            cout << char(ch + (row - 1)) << " ";    // Another formula
            col++;
        }
        cout << endl;
        // ch++;
        row++;
    }


Pattern 13:
n = 3;
A B C
A B C
A B C
 int row,n;
    cout << "Enter the number: ";
    cin >> n;
    row = 1;
    while(row<=n){
        int col = 1;
        char ch = 'A';
        while(col<=n){
            cout << char('A' + (col - 1)) << " ";
            col++;
        }
        cout << endl;
        row++;
    }


Pattern 14:
n = 3;
A B C
D E F
G H I
int i,n;
    cout << "Enter the number: ";
    cin >> n;
    i = 1;
    char ch = 'A';
    while(i<=n){
        int j=1;
        while(j<=n){
            cout << ch++ << " ";
            j++;
        }
        cout << endl;
        i++;
    }


Pattern 15:
n = 3;
A B C
B C D
C D E
int row, n;
    cout << "Enter the number: ";
    cin >> n;
    row = 1;
    char ch = 'A';
    while(row<=n){
        int col = 1;
        while(col<=n){
            cout << char(ch + (col - 1)) << " ";
            col++;
        }
        cout << endl;
        ch++;
        row++;
    }
   
*/