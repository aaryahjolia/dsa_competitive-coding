## Description  
Linear search finds an element through a for loop by iterating over every element.

## Code  
```cpp
#include<bits/stdc++.h>
using namespace std;

// Function for Linear Search
int LinearSearch(int array[],int size,int to_find){
    // For loop to iterate over all elements
    for(int i=0;i<size;i++){
        // Returns index based on '0' (zero) if array element matches to element we want to find
        if(array[i]==to_find)return i;
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
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    cout<<"Enter element to search:"<<endl;
    int to_find_element;
    cin>>to_find_element;
    // Calling function with array, its size and element to find as arguments
    int index=LinearSearch(array,size,to_find_element);
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
## Run Code
https://ide.geeksforgeeks.org/b9566a29-c18d-436a-b290-6d1ba3435dc3

## Complexities
### Time complexity   : 
Best Case : O(1)  
Worst Case : O(n) 
### Space complexity  : 
O(1)
