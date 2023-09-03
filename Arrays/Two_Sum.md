# Two Sum

## Description

Given an array of integers `nums` and an integer `target`, return the indices of two numbers in the array such that they add up to the `target`.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Link to problem: [Two Sum](https://leetcode.com/problems/two-sum/)

## Example

Example 1:
Input: `nums = [2,7,11,15]`, `target = 9`
Output: `[0,1]`
Explanation: Because `nums[0] + nums[1]` equals 9, we return [0, 1].

Example 2:
Input: `nums = [3,2,4]`, `target = 6`
Output: `[1,2]`

Example 3:
Input: `nums = [3,3]`, `target = 6`
Output: `[0,1]`

## Approach

The approach for solving this problem can be as follows:
1. For each number `x` in the array, calculate the complementary number `y` such that `y = target - x`.
2. Check if `y` exists in the hash table. If it does, return the indices of `x` and `y`.
3. If `y` is not found in the hash table, store `x` in the hash table with its index as the value.
4. If no two numbers are found that add up to the target, return `[0,0]`.

## Complexity

- Time complexity: `O(n)`
- Space complexity: `O(n)`

## Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(target - nums[i]) != mp.end())
                return {i, mp[target - nums[i]]};
            mp[nums[i]] = i;
        }
        return {0, 0};
    }
};
