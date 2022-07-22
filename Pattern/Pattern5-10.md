#include<bits/stdc++.h>
using namespace std;

/*
Pattern 6:
n = 4
*
**
***
****
*/  

int main(){
    int i, n;
    cout << "Enter the number: ";
    cin >> n;
    i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout << "* ";
            j++;
        }
        cout << endl;
        i++;
    }
}

/*
Pattern 7:
n = 4
1 
2 2
3 3 3 
4 4 4 4
int i,n;
    cout << "Enter the number: ";
    cin >> n;
    i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout << i << " ";
            j++;
        }
        cout << endl;
        i++;
    }


Pattern 9:
n = 4;
1 
2 3
4 5 6
7 8 9 10
int i,n,count;
    cout << "Enter the number: ";
    cin >> n;
    i=1;
    count = 1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout << count << " ";
            count++; 
            j++;
        }
        cout << endl;
        i++;
    }


Pattern 10:
n = 4;
1 
2 3
3 4 5
4 5 6 7
int i, n,count;
    cout << "Enter the number: ";
    cin >> n;
    i=1;
    while(i<=n){
        int j=1;
        count = i;
        while(j<=i){
            cout << count << " ";
            count++;
            // cout << (i + (j - 1)) << " ";    // Another way
            j++;
        }
        cout << endl;
        i++;
    }

*/