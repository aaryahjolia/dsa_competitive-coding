## Description  
Given an array, reverse every sub-array formed by consecutive k elements.
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
 void reverseInGroups(vector<long long>& arr, int n, int k){
       int i;
       if(n <= k){
           reverse(arr.begin(),arr.end());
       }
       else{
           for(i = 0; i < n; i+=k){
               if(i+k <= n-1)
               reverse(arr.begin()+i,arr.begin()+i+k);
               else
               reverse(arr.begin()+i,arr.begin()+(n));
           }
       } 
   }
};

int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
}
```
## Run Code
https://ide.geeksforgeeks.org/d31f1bac-9584-468c-a3bb-e54b244a8385

## Complexities
### Time complexity   : 
Best Case : O(1)  
Worst Case : O(n) 
### Auxiliary space   : 
O(1)
