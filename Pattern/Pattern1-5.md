#include<bits/stdc++.h>
using namespace std;

/*
Pattern 1 :
n = 3;
***
***
***
*/

int main(){
    nt n, i=1;
    cout << "Enter the number: ";
    cin >> n;
    while(i<=n){
        int j = 1;
        while(j<=n){
            cout << "* ";
            j++;
        }
       cout << endl;
       i++;
    }
    return 0;
}

/*
Pattern 2 :
n = 4
1 1 1 1
2 2 2 2 
3 3 3 3
4 4 4 4
int i=1,n;
    cout << "Enter the number: ";
    cin >> n;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout << i << " ";
            j++;
        }
        cout << endl;
        i++;
    }


Pattern 3: 
n = 3;
1 2 3
1 2 3
1 2 3
int i, n;
    cout << "Enter the number: ";
    cin >> n;
    i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout << j << " ";
            j++;
        }
        cout << endl;
        i++;
    }   


Pattern 4: 
n = 3;
3 2 1
3 2 1
3 2 1
int i,n;
    cout << "Enter the number: ";
    cin >> n;
    i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            int r = (n - j) + 1;    // For reversing the number
            cout << r << " ";
            j++;
        }
        cout << endl;
        i++;
    }


Pattern 5:
n = 3;
1 2 3 
4 5 6 
7 8 9
int i, n, count;
    cout << "Enter the number: ";
    cin >> n;
    i = 1;
    count = 1;
    while(i<=n){
        int j = 1;
        while(j <= n){
            cout << count << " ";
            j++;
            count++;
        }
        cout << endl;
        i++;
    }

*/