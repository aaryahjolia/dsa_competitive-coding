//You are given a 0-indexed integer array nums consisting of 3 * n elements.
//You are allowed to remove any subsequence of elements of size exactly n from nums. The remaining 2 * n elements will be divided into two equal parts:
//The first n elements belonging to the first part and their sum is sumfirst.
//The next n elements belonging to the second part and their sum is sumsecond.
//The difference in sums of the two parts is denoted as sumfirst - sumsecond.

//For example, if sumfirst = 3 and sumsecond = 2, their difference is 1.
//Similarly, if sumfirst = 2 and sumsecond = 3, their difference is -1.
//Return the minimum difference possible between the sums of the two parts after the removal of n elements.

#include <bits/stdc++.h>
using namespace std;

int minimumDifference(vector<int>& nums) {
    int n = nums.size() / 3;
    int totalSum = 0;
    for (int num : nums) {
        totalSum += num;
    }

    // Sort the array in ascending order
    sort(nums.begin(), nums.end());

    int minDiff = INT_MAX;

    // Generate all possible combinations of removing n elements
    for (int i = 0; i <= n; i++) {
        int firstSum = 0;
        for (int j = 0; j < n; j++) {
            firstSum += nums[j];
        }

        int secondSum = totalSum - firstSum;
        int diff = firstSum - secondSum;
        minDiff = min(minDiff, abs(diff));

        if (i < n) {
            // Remove the largest n elements for the next iteration
            firstSum -= nums[n - 1 - i];
        }
    }

    return minDiff;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int result = minimumDifference(nums);
    cout << "The minimum difference between the sums of the two parts is: " << result << endl;

    return 0;
}
