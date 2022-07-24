## Question Link :

https://leetcode.com/problems/running-sum-of-1d-array/

## Code solution :

C++ 

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            ans[i] = ans[i-1] + nums[i];
        return ans;
    }
};