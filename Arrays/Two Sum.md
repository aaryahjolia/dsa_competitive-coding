# Two Sum

### Problem Link : https://leetcode.com/problems/two-sum/

### Problem :

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

### Example 1:

Input: nums = [2,7,11,15], target = 9 <br />
Output: [0,1]  <br />
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

### Example 2:

Input: nums = [3,2,4], target = 6 <br />
Output: [1,2]

### Solution :

- In Python

```c
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        prevMap = {}  # val -> index

        for i, n in enumerate(nums):
            diff = target - n
            if diff in prevMap:
                return [prevMap[diff], i]
            prevMap[n] = i
```
- In C++

```c
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (m.find(complement) != m.end()) {
                result.push_back(m[complement]);
                result.push_back(i);
                break;
            } else {
                m.insert({nums[i], i});
            }
        }
        
        return result;
    }
};
```

### Time Complexity : O(n)
### Space Complexity : O(n)
