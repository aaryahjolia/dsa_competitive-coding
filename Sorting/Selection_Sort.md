## Description 
Selection Sort runs on logic that it selects smallest values and swap it with the first value, then same operation on remaining array by swapping with second element and so on.

```cpp

#include<bits/stdc++.h>
using namespace std;

// Selection Sort Logic
void selection_sort(int ar[],int n){
    // Loop for traversing array to swap smallest value with the current element of loop
    for(int i=0;i<n-1;i++){
        // Storing index of smallest element in 'elem', initially same element (i)
        int elem=i;
        // Loop to identify smallest element and storing that index in 'elem'
        for(int j=i+1;j<n;j++){
            if(ar[elem]>ar[j]){
                elem=j;
            }
        }
        // Swapping smallest element (elem) with current element of loop (i)
        swap(ar[elem],ar[i]);
    }
}

// Sorting Algorithm Boiler code to take input of array, call the sorting function and print the array.
int main(){
    cout<<"Enter size of array : ";
    int size;
    cin>>size;
    int ar[size];
    for(int i=0;i<size;i++){
        cout<<"Enter element "<<(i+1)<<": ";
        cin>>ar[i];
    }    
    cout<<"Before Sort : "<<endl;
    for(int i=0;i<size;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    selection_sort(ar,size);
    cout<<"After sort : "<<endl;
    for(int i=0;i<size;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
return 0;
}

```
## Run Code
https://ide.geeksforgeeks.org/f6ce2387-7700-4e3f-8edf-98c2f3eed602

## Complexities
### Time complexity   : 
Best Case  : O(n^2)  
Worst Case : O(n^2) 
### Space complexity  : 
O(1)
