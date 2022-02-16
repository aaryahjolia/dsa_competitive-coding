### Description : 
Binary search finds an element in a sorted array with Loops.

```cpp
#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int array[], int size, int to_find){
    int low=0,high=size-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(array[mid]==to_find){
            return mid;
        }
        else if(array[mid]>to_find){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int main(){
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
    int index=BinarySearch(array,size,to_find_element);
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
Best Case  : O(1)  
Worst Case : O(log n) 
### Space complexity  : 
O(1)
