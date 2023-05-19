# Median of Two Sorted Arrays

This is a solution to the problem of finding the median of two sorted arrays, `nums1` and `nums2`. The solution has a runtime complexity of O(log(m+n)), where `m` and `n` are the sizes of the arrays.

## Problem Description

Given two sorted arrays, `nums1` and `nums2`, of sizes `m` and `n` respectively, the task is to find the median of the two arrays. The median is the middle value of a sorted list of numbers. If the combined size of the two arrays is even, the median is the average of the two middle elements.

## Example

**Input:**

`nums1 = [1, 3]`

`nums2 = [2]`

**Output:**

`2.00000`

**Explanation:**

The merged array is `[1, 2, 3]`, and the median is 2.

## Constraints

- `nums1.length` is equal to `m`
- `nums2.length` is equal to `n`
- 0 <= `m` <= 1000
- 0 <= `n` <= 1000
- 1 <= `m` + `n` <= 2000
- -106 <= `nums1[i]`, `nums2[i]` <= 106

## Approach 1 (Basic Approach)
The given code provides a solution to the problem using a different approach. Here's the explanation of the approach used in the provided code:

1. First, the code calculates the total size of the combined arrays `nums1` and `nums2` and stores it in the variable `m`.
2. Next, the code iterates over each element in `nums2` and appends it to `nums1` using `push_back()`. This step effectively merges the two arrays.
3. After merging the arrays, the code sorts the merged array using `sort()` function from the `<algorithm>` library. This step ensures that the array is in sorted order.
4. The code then checks if the total size of the merged array `m` is even or odd by checking `m % 2 == 0`. If it is even, the code calculates the median as the average of the two middle elements, `nums1[m/2-1]` and `nums1[m/2]`. If it is odd, the code simply assigns the middle element `nums1[(m-1)/2]` as the median.
5. Finally, the code returns the calculated median.

While this approach gives the correct median, the time complexity of the code is O((m+n) log(m+n)) due to the `sort()` function. 

To find the median of the two sorted arrays, we can use the concept of binary search. The idea is to partition the arrays into two halves such that the elements on the left side are smaller than the elements on the right side. By doing so, we can ensure that the median will be at the boundary of the two halves.

## Code
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     double median = 0;
        int m = nums1.size() + nums2.size();
       
    for(int i=0;i<nums2.size();i++)
    {
        nums1.push_back(nums2[i]);
    }
        sort(nums1.begin(),nums1.end());
       if(m%2==0)
       {
           median = (double)(nums1[m/2-1]+ nums1[m/2])/2;
       }
        else
        {
            median = (double)nums1[(m-1)/2];
        }
        return median;
    }
};


## Approach 2
1. First, we initialize two variables, `left` and `right`, to represent the range of indices in the `nums1` array where the median can be located. Initially, `left` is set to 0, and `right` is set to the length of `nums1`.
2. We start a binary search loop, where the search continues until `left` is less than or equal to `right`.
3. Inside the binary search loop, we calculate the partition indices, `partition1` and `partition2`, which divide the two arrays into left and right halves.
4. We use the formula `partition1 = (left + right) // 2` to calculate the partition index in the `nums1` array.
5. We calculate the partition index in the `nums2` array using the formula `partition2 = ((m + n + 1) // 2) - partition1`.
6. Next, we calculate four values: `maxLeft1`, `maxLeft2`, `minRight1`, and `minRight2`. These values represent the maximum element on the left side of the partitions and the minimum element on the right side of the partitions for both arrays.
7. We check if `maxLeft1` is less than or equal to `minRight2` and `maxLeft2` is less than or equal to `minRight1`. If this condition is satisfied, it means we have found the correct partition.
8. If the condition is not satisfied, we adjust the `left` and `right` variables based on the values of `maxLeft1` and `maxLeft2`. If `maxLeft1` is greater than `minRight2`, it means the partition index in the `nums1` array is too far to the right, so we move the `right` variable to the left. If `maxLeft2` is greater than `minRight1`, it means the partition index in the `nums1` array is too far to the left

, so we move the `left` variable to the right.
9. We repeat steps 3-8 until we find the correct partition.
10. After finding the correct partition, we calculate the median based on the length of the combined arrays and whether the total size is even or odd. If the combined size is odd, the median is the maximum of `maxLeft1` and `maxLeft2`. If the combined size is even, the median is the average of the maximum of `maxLeft1` and `maxLeft2` and the minimum of `minRight1` and `minRight2`.
11. Finally, we return the calculated median as the output.

This approach ensures that we find the median in O(log(m+n)) time complexity.

## Code

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array for partitioning
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int left = 0;
        int right = m;
        
        while (left <= right) {
            int partition1 = (left + right) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;
            
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];
            
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((m + n) % 2 == 0) {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    return max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                right = partition1 - 1;
            } else {
                left = partition1 + 1;
            }
        }
        
        // Arrays are not sorted, return an error value
        return -1;
    }
};
