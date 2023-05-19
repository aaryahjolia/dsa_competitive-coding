# Container with most water (Leetcode - 11, Medium)

- You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

- Find two lines that together with the x-axis form a container, such that the container contains the most water.

- Return the maximum amount of water a container can store.

- Notice that you may not slant the container.

## Example 1:
- Input: height = [1,8,6,2,5,4,8,3,7]
- Output: 49
- Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

## Example 2:
- Input: height = [1,1]
- Output: 1
 
## Constraints:
- n == height.length
- 2 <= n <= 105
- 0 <= height[i] <= 104

## Solution

```cpp
class Solution {
public:
    long int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, m;
        long int ans = INT_MIN;
        while(l <= r)
        {
            m = min(height[r], height[l]);
            ans = l_max(ans, m*(r - l));
            if(height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return(ans);
    }
    
    public: long int l_max(long int a, int b)
    {
        if(a > b)
        {
            return(a);
        }
        return(b);
    }
};
```
