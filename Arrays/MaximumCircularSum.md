# Maximum Circular Sum
This question involves the usage of an algorithm known as Kadane's Algorithm
## Question
You are provided n numbers (both +ve and -ve). Numbers are arranged in a circular form. You need to find the maximum sum of consecutive numbers.
```
Input Format
First line contains integer t which is number of test case.
For each test case, it contains an integer n which is the size of array and next line contains n space separated integers denoting the elements of the array.

Constraints
1<=t<=100
1<=n<=1000
|Ai| <= 10000

Output Format
Print the maximum circular sum for each testcase in a new line.
```

## Code
```
#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n; cin>>n;
    int i,arr[n];
    for(i=0; i<n; i++) cin>>arr[i];
    int maxSum=INT_MIN, minSum=INT_MAX, currsum1=0, currsum2=0;
    int TotalSum=0;
    for (i=0; i<n; i++){
        TotalSum+=arr[i]; currsum1+=arr[i]; currsum2+=arr[i];
        if (currsum1>maxSum) maxSum=currsum1;
        if (currsum2<minSum) minSum=currsum2;
        if (currsum1<0) currsum1=0;
        if (currsum2>0) currsum2=0;
    }
    if (minSum==TotalSum) cout<<maxSum;
    else {
        if (maxSum > TotalSum-minSum) cout<<maxSum;
        else cout<<TotalSum-minSum;
    }
    
    return 0;
} 
```
## Sample Test Case
```
Input
1
7
8 -8 9 -9 10 -11 12
Output
22

Explanation
Maximum Circular Sum = 22 (12 + 8 - 8 + 9 - 9 + 10)
```
