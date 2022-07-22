## Description 
Shell sort is a based on the insertion-sort algorithm. It intially sorts elements that are far apart from each other and successively reduces the interval between the elements to be sorted.

## Code  
```
//shell sort in c++

#include <iostream>

using namespace std;

//shell sort function
void shell_Sort(int array[],int size){
    
    int g = size/2;
    
    while(g > 0)
    {
        for(int i = g ; i < size; i++)
        {
            int temp = array[i];
        
            int j = i;
            
             //shifting earlier g elements up the correct index
            while(j >= g && array[j - g] > temp)
            {
                array[j] = array[j - g];
                j -= g;
            }
            
            //  putting temp in the original array[i] 
            array[j] = temp;
        }
    
        g = g/2;
    }
}

// main function or driver function
int main() {
    int size;
    cout<< "Enter Number of elements :" ;
    cin >> size ;
    int array[size];
    
    //getting array elements
    for(int i=0; i < size; i++ ){
        cout<<"array["<<i<<"] :";
        cin>>array[i];
    }
    
    //print original array
    cout<<"\n Original Array: ";
    for (int i= 0; i <size; i++ ){
        
         cout<<array[i]<<", ";
    }
    
    //calling shell_sort function
    shell_Sort(array,size);
    
    
    //print sorted array
    cout<<"\n Sorted array Array :";
    for (int i= 0; i <size; i++ ){
        
         cout<<array[i]<<", ";
    }
    
    
    return 0;
}

```

## Complexities
### Time complexity   : 
Best Case  : O(nlog n)

Worst Case : O(n<sup>2</sup>)

Average    : O(nlog n)

### Space complexity  : 
O(1)


