### count 0s and 1s in an array 
```approach
step 1: create a function to count 0s and 1s,and pass the array on a function
step 2: create two variables initialize with 0, and travers the array ;
int count_0s = 0;
int count_1s = 0;

step 3: count every index number 0 or 1, if index value is 0, increase count_0s;
          if index value is 1, increase count_1s;
          
step 4: return or print 0s and 1s;

Apporach
The time complexity of the count_0s_and_1s function is O(log n), where n is the number of bits in the binary number.
This is because the function iterates through the binary number, bit by bit, and at each step, it only needs to
perform a constant amount of work.

Here is a breakdown of the time complexity of the count_0s_and_1s function:

The first step is to initialize the variables count_0s and count_1s to 0. This takes O(1) time.
The next step is to iterate through the binary number, bit by bit. This takes O(log n) time.
At each step, the function checks the current bit and increments the appropriate counter. This takes O(1) time.
The final step is to return the values of the counters. This takes O(1) time.
The total time complexity of the count_0s_and_1s function is O(log n) + O(1) + O(1) = O(log n).
 
```
---
```cpp
#include<iostream>
using namespace std;

int count(int arr[], int size){
  //initialize variables with 0
        int zeros = 0;
        int ones = 0;
  // travers an array
        for(int i=0; i<size-1;i++){
          //count 0s 
            if(arr[i]==0){
                zeros++;
            }
          //count 1s
            if(arr[i]==1){
                ones++;
            }
        }
  // print 0s and 1s
        cout<<"zero's "<<zeros<<" "<<"ones "<<ones;
        return 0;
    }

int main(){
   int arr[] = {0,1,1,0,0,0,1,0,1,1,1,0,0};
   int size = sizeof(arr) / sizeof(arr[0]);
   count(arr,size);
  return 0;
}
```

