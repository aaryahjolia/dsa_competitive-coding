## Description
In this code you will find how you can make * pattern by using while loop

## Code 
```cpp

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
   vector<string> yShapedPattern(int N) {
   int space = N - 1;
   vector<string> ans;
   for (int i = 1; i <= N/2; i++)
   {
       string temp;
       for (int j = 1; j <= i - 1; j++)
       {
           temp+=" ";
       }
       temp+="*";
       for (int j = 1; j <= space; j++)
       {
           temp+=" ";
       }
       temp+="*";
       for (int j = 1; j <= i - 1; j++)
       {
           temp+=" ";
       }
       space -= 2;
       ans.push_back(temp);
   }
   space = N/2;
   for (int i = 1; i <= N/2; i++)
   {
       string temp;
       for (int j = 1; j <= space; j++)
       {
           temp+=" ";
       }
       temp+="*";
       for (int j = 1; j <= space; j++)
       {
           temp+=" ";
       }
       ans.push_back(temp);
   }
   return ans;
   }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        vector<string> v = ob.yShapedPattern(N);
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << endl;
    }
    return 0;
}
```
## Input
```
N = 8
```
## Output
```
*       *
 *     * 
  *   *  
   * *   
    *
    *
    *
    *
```

## GFG URL CODE
[https://ide.geeksforgeeks.org/21afee75-c704-4fe7-a2dc-92c5f20eaa98](https://ide.geeksforgeeks.org/1333c2c2-783f-48ca-885b-4553f946fe45)
