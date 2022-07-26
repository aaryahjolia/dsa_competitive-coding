# 3Sum
This problem in some ways is a continuation of the two sum problem. So, if you have not yet solved the two Sum problem then you have to do so because it will help you understand the 3 Sum problem better.

Problem Link : https://leetcode.com/problems/3sum/

### Problem :

Given an integer array nums , return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and <br/> nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

### Example 1:

Input: nums = [-1,0,1,2,-1,-4] <br/>
Output: [[-1,-1,2],[-1,0,1]]

### Example 2:

Input: nums = [0,1,1] <br/>
Output: [] <br/>
Explanation: The only possible triplet does not sum up to 0.

### Solution : Efficient Solution
- Using three pointers
- The idea is to sort the array first, then run two loops to process the triplets. We fix the outer loop and move the two pointers (indexes) of the inner loop inwards to arrive at the result.

### In Python
```c
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        for i, a in enumerate(nums):
            if i > 0 and a == nums[i - 1]:
                continue
            l, r = i + 1, len(nums) - 1
            while l < r:
                threeSum = a + nums[l] + nums[r]
                if threeSum > 0:
                    r -= 1
                elif threeSum < 0:
                    l += 1
                else:
                    res.append([a, nums[l], nums[r]])
                    l += 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
        return res
```
### Time Complexity - O(n^2)
### Space Complexity - O(1)
### In C++
```c
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        int n = nums.size();
        if (n < 3) {
            return result;
        }
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            
            int j = i + 1;
            int k = n - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    j++;
                    
                    while (j < k && nums[k - 1] == nums[k]) {
                        k--;
                    }
                    k--;
                }
            }
        }
        
        return result;
    }
};
```
### Time Complexity - O(n^2)
### Space Complexity - O(n)