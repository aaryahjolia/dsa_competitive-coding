## Description 
Merge Sort sorts array with rule of divide and conquer. It breaks array into fragments, sorts them and then merges the array in sorting order. (Hence the name Merge sort)

```cpp

#include<bits/stdc++.h>
using namespace std;

// Merge Sort Logic
// Function to sort 2 sub arrays
void merge(int ar[],int low,int mid,int high){
    int i,j,k,b[1000];
    // Initialising i to low, j to midth element, and k to low. 
    // low to mid is 1 array, mid+1 to high is another array
    // k will be used as index to store sorted array in b 
    i=low;
    k=low;
    j=mid+1;
    // Loop till any of the array is completed traversing and storing lowest value in b
    while(i<=mid && j<=high){
        if(ar[i]>ar[j]){
            b[k]=ar[j];
            j++;
            k++;
        }
        else{
            b[k]=ar[i];
            i++;
            k++;
        }
    }
    // Loop to store elements left in array 1 (low to mid)
    while(i<=mid){
        b[k]=ar[i];
        i++;
        k++;
    }
    // Loop to store elements left in array 2 (mid+1 to high)
    while(j<=high){
        b[k]=ar[j];
        j++;
        k++;
    }
    // At last, storing array b to original array ar
    for(int e=low;e<=high;e++){
        ar[e]=b[e];
    }
}

// Function to partition array in 2 parts and merge them
void sort(int ar[],int low,int high){
    // Base condition to stop recursion when array has only 1 element left
    if(low<high){
        // Calculating mid element
        int mid=low + (high-low)/2;
        // Partitioning in 2 arrays
        sort(ar,low,mid);
        sort(ar,mid+1,high);
        // merging both sorted arrays
        merge(ar,low,mid,high);
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
    sort(ar,0,size);
    cout<<"After sort : "<<endl;
    for(int i=0;i<size;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
return 0;
}

```

## Run Code
https://ide.geeksforgeeks.org/a0945978-df8b-4b98-bfe5-ffa716a8a535

## Complexities
### Time complexity   : 
Best Case  : O(n)  
Worst Case : O(n^2) 
### Space complexity  : 
O(1)
