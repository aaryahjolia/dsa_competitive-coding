## Description 
Quick Sort sorts an array on basis of a pivot point, a Point from which left side array are smaller and right side are bigger. Then we can apply same logic on left side and right side of that pivot point, eventually breaking it. So, rule of Divide and Conquer is used.

```cpp

#include<bits/stdc++.h>
using namespace std;

// Quick Sort Logic
// Function to return pivot index
int partition(int ar[],int low,int high){
    // Initially pivot point will be first element of array i.e.low
    int pivot=ar[low];
    int i=low+1;
    int j=high;

    // Looping till i and j don't cross each other 
    while(i<=j){
        // Looping to find biggest element from starting index
        while(ar[i]<=pivot){
            i++;
        }
        // Looping to find smallest element from last index
        while(ar[j]>pivot){
            j--;
        }
        // Swap both element as to make array look like smaller on left, bigger on right
        if(i<j){
            swap(ar[i],ar[j]);
        }
    }
    // At last, swap pivot point and j index so to make left side array of pivot smaller and right side bigger
    swap(ar[low],ar[j]);
    // Return this point as to break array into 2 i.e. left and right part
    return j;
}

// Function to partition array in 2 parts
void sort(int ar[],int low,int high){
    // Base condition to stop recursion when array has only 1 element left
    if(low<high){
        // Calculating pivot point
        int pivotIndex = partition(ar,low,high);
        // Breaking array from pivot point into left and right and applying same logic to both
        sort(ar,low,pivotIndex-1);
        sort(ar,pivotIndex+1,high);
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
    sort(ar,0,size-1);
    cout<<"After sort : "<<endl;
    for(int i=0;i<size;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
return 0;
}

```
## Run Code
https://ide.geeksforgeeks.org/online-cpp-compiler/501c6951-04c3-45e1-be71-82434c924fce

## Complexities
### Time complexity   : 
Best Case  : O(n)  
Worst Case : O(n^2) 
### Space complexity  : 
O(1)
