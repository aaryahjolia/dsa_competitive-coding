## Description 
It performs sorting by counting objects having distinct key values like hashing. After that, it performs some arithmetic operations to calculate each object's index position in the output sequence.

```cpp

#include <iostream>  
  
using namespace std;  
  
int getMax(int a[], int n) {  
   int max = a[0];  
   for(int i = 1; i<n; i++) {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max; //maximum element from the array  
}  
  
void countSort(int a[], int n) // function to perform counting sort  
{  
   int output[n+1];  
   int max = getMax(a, n);  
   int count[max+1]; //create count array with size [max+1]  
  
  
  for (int i = 0; i <= max; ++i)   
  {  
    count[i] = 0; // Initialize count array with all zeros  
  }  
    
  for (int i = 0; i < n; i++) // Store the count of each element  
  {  
    count[a[i]]++;  
  }  
  
   for(int i = 1; i<=max; i++)   
      count[i] += count[i-1]; //find cumulative frequency  
  
  /* This loop will find the index of each element of the original array in count array, and 
   place the elements in output array*/  
  for (int i = n - 1; i >= 0; i--) {  
    output[count[a[i]] - 1] = a[i];  
    count[a[i]]--; // decrease count for same numbers  
}  
  
   for(int i = 0; i<n; i++) {  
      a[i] = output[i]; //store the sorted elements into main array  
   }  
}  
  
void printArr(int a[], int n) /* function to print the array */  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout<<a[i]<<" ";  
}  
  
int main() {  
    int a[] = { 31, 11, 42, 7, 30, 11 };  
    int n = sizeof(a)/sizeof(a[0]);  
    cout<<"Before sorting array elements are - \n";  
    printArr(a, n);  
    countSort(a, n);  
    cout<<"\nAfter sorting array elements are - \n";    
    printArr(a, n);  
    return 0;  
}

```
## Run code:
https://www.onlinegdb.com/

## Complexities
## Time complexities :
Worst time Complexity : O(n+k)
Best time Complexity : O(n+k)

## Space complexity :
Space Complexity : O(max)