## Description : 
Binary search recursion finds an element in a sorted array with recursion. 

### Code
```cpp
#include<bits/stdc++.h>
using namespace std;

// Function for Binary Search with recursion
int BinarySearchRecursion(int array[], int size, int to_find, int min_range, int max_range){
    // Calculating mid element keeping overflow in mind
    int mid=min_range+(max_range-min_range)/2;
    // If middle element is same as element to find, return index
    if(array[mid]==to_find){
        return mid;
    }
    // If middle element is greater than element to find, calling same function but with a lower max_range (left array from middle element)
    else if(array[mid]>to_find){
        return BinarySearchRecursion(array,size,to_find,0,mid-1);
    }
    // else calling same function but with a higher min_range (right array from middle element)
    else{
        return BinarySearchRecursion(array,size,to_find,mid+1,max_range);
    }
    //If nothing found, return -1 
    return -1;
}

int main(){
    // Taking size and array elements
    cout<<"Enter size of Array:"<<endl;
    int size;
    cin>>size;
    int array[size];
    cout<<"Enter elements:"<<endl;
    // Insertion needs sorted array
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    cout<<"Enter element to search:"<<endl;
    int to_find_element;
    cin>>to_find_element;
    // Calling function with array, its size, element to find, first element and last element as arguments
    int index=BinarySearchRecursion(array,size,to_find_element,0,size-1);
    // Checking if index found and printing appropriate message
    if(index==-1){
        cout<<"Element is not present in array!"<<endl;
    }
    else{
        // Index is based on '0' (zero) numbering, Add 1 to index for 1 numbering
        cout<<"Element "<<array[index]<<" is present at index: "<<index<<" !"<<endl;
    }
return 0;
}
```

## Complexities:
### Time complexity   : 
Best Case : O(1)  
Worst Case : O(log n) 
### Space complexity  : 
O(log n)
