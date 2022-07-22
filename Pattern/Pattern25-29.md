#include<bits/stdc++.h>
using namespace std;

/*
Pattern 26:
n = 4;
   1
  22
 333
4444
*/

int main(){
int row, n;
    cout << "Enter the number: ";
    cin >> n;
    row = 1;
    int num = 1;
    while(row<=n){
        int space = n - row;
        while(space){
            cout << " ";
            space--;
        }
        int col = row;
        while(col){
            cout << num;
            col--;
        }
        cout << endl;
        num++;
        row++;
    }    

    return 0;
}

/*
Pattern 27:
n = 4;
1 2 3 4
  2 3 4
    3 4
      4 
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
        int num = n - row + 1;
        int val = row;
        while(num){
            cout << val++;
            num--;
        }
        cout << endl;
        row++;
    }    


Pattern 28:
n = 4;
   1
  23
 456
78910 
int row,n,val;
    cout << "Enter the number: ";
    cin >> n;
    row = 1;
    val = 1;
    while(row<=n){
        int space = n - row;
        while(space){
            cout << " ";
            space--;
        }
        int num = row;
        while(num){
            cout << val++;
            num--;
        }
        cout << endl;
        row++;
    }    


Pattern 29:
n = 5;
1234554321
1234**4321
123****321
12******21
1********1
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

*/
