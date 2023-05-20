## Problem Statement
***
 Given an array arr[ ] of size N. Find the sum of the contiguous subarray within a arr[ ] with the largest sum. 

INPUT  : arr[]=  {-2,-3,4,-1,-2,1,5,-3}

OUTPUT :  The maximum contiguous array sum is 7

         4 + (-1) + (-2) + 1 + 5 = 7 
</br>

## Intuition

The idea of Kadane’s algorithm is to maintain a variable calc_sum that stores the maximum sum contiguous subarray ending at current index and a variable max_sum stores the maximum sum of contiguous subarray found so far, Everytime there is a positive-sum value in calc_sum compare it with max_sum and update max_sum if it is greater than max_sum.
</br>

## Time Complexity :- 
O(N)  as each element of array is iterated only once.
</br>

## Space Complexity :-
 O(1) 
</br>

## Code 


```
#include <bits/stdc++.h>
using namespace std;
  
int maxSubArraySum(int a[], int size){

    // initialize the max_sum with minimum value 
    // the maximum sum found so far gets updated in max_sum variable
    // calc_sum variable stores the current sum

    int max_sum = INT_MIN, calc_sum = 0;

    //Run a for loop from 0 to size-1 and for each index i: 

    for (int i = 0; i < size; i++) {

        //Add the a[i] to calc_sum

	    calc_sum = calc_sum + a[i]; 
        //If  max_sum is less than calc_sum then update max_sum to calc_sum. 
	    if (max_sum < calc_sum)
	        max_sum = calc_sum;
        //If calc_sum < 0 then update calc_sum = 0      
	    if (calc_sum < 0)
	    	calc_sum = 0;

	}
//return the larget sum calculated
return max_sum;
}

int main(){

    // defining an array
    int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };  
    int n = sizeof(a) / sizeof(a[0]);           

    // function to find the largest sum contiguous array
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0
}
```

