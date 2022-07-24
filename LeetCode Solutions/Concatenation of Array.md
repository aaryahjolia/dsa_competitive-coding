## Question Link :

https://leetcode.com/problems/concatenation-of-array/

## Code solution :

C++ 
class Solution {
 public:
  vector<int> getConcatenation(vector<int>& nums) {
    const int n = nums.size();

    for (int i = 0; i < n; ++i)
      nums.push_back(nums[i]);

    return nums;
  }
};


