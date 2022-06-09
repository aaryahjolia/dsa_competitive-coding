## Description 
Insertion Sort uses logic of making a sorted array by starting as small sorted array from first element and then moving elements in sorted order to the small sorted array on it's left side.

```cpp

#include<bits/stdc++.h>
using namespace std;

// Insertion Sort Logic
void insertion_sort(int ar[],int n){
    // Loop to start from 1st index as first element is sorted
    for(int i=1;i<n;i++){
        int temp=ar[i];
        int j=i;
        // Loop to Move elements right side until proper index is emptied to store the element so that array will remain sorted  
        while(ar[j-1]>temp && j-1>=0){
            ar[j]=ar[j-1];
            j--;
        }
        // Finally placing element at proper index
        ar[j]=temp;
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
    insertion_sort(ar,size);
    cout<<"After sort : "<<endl;
    for(int i=0;i<size;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
return 0;
}

```

## Complexities
### Time complexity   : 
Best Case  : O(n)  
Worst Case : O(n^2) 
### Space complexity  : 
O(1)
