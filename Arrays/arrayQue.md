# Array Problems

This folder contains a collection of popular array problems and their solutions. Each problem comes with a detailed explanation and a solution implementation in various programming languages.

## Problems

1. **Problem 1: Reverse an Array**

   Description: Given an array of integers, write a function to reverse the elements in-place.

   Algorithm: The algorithm involves swapping the elements from both ends of the array and gradually moving towards the center until the entire array is reversed.

   Solution:
   - Python:
     ```python
     def reverse_array(arr):
         left = 0
         right = len(arr) - 1
         while left < right:
             arr[left], arr[right] = arr[right], arr[left]
             left += 1
             right -= 1
     ```
   - Java:
     ```java
     void reverseArray(int[] arr) {
         int left = 0;
         int right = arr.length - 1;
         while (left < right) {
             int temp = arr[left];
             arr[left] = arr[right];
             arr[right] = temp;
             left++;
             right--;
         }
     }
     ```

2. **Problem 2: Two Sum**

   Description: Given an array of integers and a target value, find two numbers in the array that add up to the target.

   Algorithm: The algorithm uses a hash table to store the complement of each element as we traverse the array. By checking if the complement exists in the hash table, we can find the pair of numbers that add up to the target.

   Solution:
   - Python:
     ```python
     def two_sum(nums, target):
         complement_map = {}
         for i, num in enumerate(nums):
             complement = target - num
             if complement in complement_map:
                 return [complement_map[complement], i]
             complement_map[num] = i
         return []
     ```
   - Java:
     ```java
     int[] twoSum(int[] nums, int target) {
         Map<Integer, Integer> complementMap = new HashMap<>();
         for (int i = 0; i < nums.length; i++) {
             int complement = target - nums[i];
             if (complementMap.containsKey(complement)) {
                 return new int[]{complementMap.get(complement), i};
             }
             complementMap.put(nums[i], i);
         }
         return new int[]{};
     }
     ```

3. **Problem 3: Maximum Subarray**

   Description: Given an array of integers, find the contiguous subarray with the largest sum.

   Algorithm: The solution uses Kadane's algorithm, which iterates through the array and keeps track of the maximum subarray sum by considering the current element and the maximum sum ending at the previous element.

   Solution:
   - Python:
     ```python
     def max_subarray(nums):
         max_sum = nums[0]
         curr_sum = nums[0]
         for i in range(1, len(nums)):
             curr_sum = max(nums[i], curr_sum + nums[i])
             max_sum = max(max_sum, curr_sum)
         return max_sum
     ```
   - Java:
     ```java
     int maxSubarray(int[] nums) {
         int maxSum = nums[0];
         int currSum = nums[0];
         for (int i = 1; i < nums.length; i++) {
             currSum = Math.max(nums[i], currSum + nums[i]);
             maxSum = Math.max(maxSum, currSum);
         }
         return maxSum;
     }
     ```

4. **Problem 4: Rotate Array**

   Description: Given an array, rotate the array to the right by k steps, where k is a non-negative integer.

   Algorithm: The algorithm involves reversing the entire array, then reversing the first k elements, and finally reversing the remaining elements to achieve the desired rotation.

   Solution:
   - Python:
     ```python
     def rotate_array(nums, k):
         k %= len(nums)
         reverse(nums, 0, len(nums) - 1)
         reverse(nums, 0, k - 1)
         reverse(nums, k, len(nums) - 1)

     def reverse(nums, start, end):
         while start < end:
             nums[start], nums[end] = nums[end], nums[start]
             start += 1
             end -= 1
     ```
   - Java:
     ```java
     void rotateArray(int[] nums, int k) {
         k %= nums.length;
         reverse(nums, 0, nums.length - 1);
         reverse(nums, 0, k - 1);
         reverse(nums, k, nums.length - 1);
     }

     void reverse(int[] nums, int start, int end) {
         while (start < end) {
             int temp = nums[start];
             nums[start] = nums[end];
             nums[end] = temp;
             start++;
             end--;
         }
     }
     ```

5. **Problem 5: Merge Intervals**

   Description: Given a collection of intervals, merge overlapping intervals.

   Algorithm: The solution sorts the intervals based on their start times and then iterates through the sorted intervals, merging any overlapping intervals to create a merged interval list.

   Solution:
   - Python:
     ```python
     def merge_intervals(intervals):
         merged = []
         intervals.sort(key=lambda x: x[0])
         for interval in intervals:
             if not merged or merged[-1][1] < interval[0]:
                 merged.append(interval)
             else:
                 merged[-1][1] = max(merged[-1][1], interval[1])
         return merged
     ```
   - Java:
     ```java
     List<Interval> mergeIntervals(List<Interval> intervals) {
         List<Interval> merged = new ArrayList<>();
         Collections.sort(intervals, Comparator.comparingInt(a -> a.start));
         for (Interval interval : intervals) {
             if (merged.isEmpty() || merged.get(merged.size() - 1).end < interval.start) {
                 merged.add(interval);
             } else {
                 merged.get(merged.size() - 1).end = Math.max(merged.get(merged.size() - 1).end, interval.end);
             }
         }
         return merged;
     }
     ```

6. **Problem 6: Missing Number**

   Description: Given an array containing n distinct numbers taken from 0 to n, find the missing number.

   Algorithm: The solution provides two approaches. One approach is to use the Gauss formula to calculate the expected sum and subtract the actual sum of the array to find the missing number. The other approach calculates the expected sum by assuming the missing number is the last element and subtracts the actual sum to find the missing number.

   Solution:
   - Python:
     ```python
     def missing_number(nums):
         n = len(nums)
         expected_sum = (n * (n + 1)) // 2
         actual_sum = sum(nums)
         return expected_sum - actual_sum
     ```
   - Java:
     ```java
     int missingNumber(int[] nums) {
         int n = nums.length;
         int expectedSum = (n * (n + 1)) / 2;
         int actualSum = 0;
         for (int num : nums) {
             actualSum += num;
         }
         return expectedSum - actualSum;
     }
     ```

7. **Problem 7: Product of Array Except Self**

   Description: Given an array nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

   Algorithm: The algorithm calculates the product of all elements to the left of each element and then multiplies it by the product of all elements to the right of each element to obtain the product of the array except self.

   Solution:
   - Python:
     ```python
     def product_except_self(nums):
         n = len(nums)
         left_products = [1] * n
         right_products = [1] * n
         output = [1] * n

         for i in range(1, n):
             left_products[i] = left_products[i - 1] * nums[i - 1]

         for i in range(n - 2, -1, -1):
             right_products[i] = right_products[i + 1] * nums[i + 1]

         for i in range(n):
             output[i] = left_products[i] * right_products[i]

         return output
     ```
   - Java:
     ```java
     int[] productExceptSelf(int[] nums) {
         int n = nums.length;
         int[] leftProducts = new int[n];
         int[] rightProducts = new int[n];
         int[] output = new int[n];

         leftProducts[0] = 1;
         for (int i = 1; i < n; i++) {
             leftProducts[i] = leftProducts[i - 1] * nums[i - 1];
         }

         rightProducts[n - 1] = 1;
         for (int i = n - 2; i >= 0; i--) {
             rightProducts[i] = rightProducts[i + 1] * nums[i + 1];
         }

         for (int i = 0; i < n; i++) {
             output[i] = leftProducts[i] * rightProducts[i];
         }

         return output;
     }
     ```

8. **Problem 8: Container With Most Water**

   Description: Given n non-negative integers representing the heights of vertical lines, find two lines that together with the x-axis form a container that contains the most water.

   Algorithm: The solution uses a two-pointer approach, starting from both ends of the array and gradually moving towards each other. The idea is to maximize the area by considering the maximum height of the two lines and the distance between them.

   Solution:
   - Python:
     ```python
     def max_area(heights):
         max_area = 0
         left = 0
         right = len(heights) - 1

         while left < right:
             area = min(heights[left], heights[right]) * (right - left)
             max_area = max(max_area, area)

             if heights[left] < heights[right]:
                 left += 1
             else:
                 right -= 1

         return max_area
     ```
   - Java:
     ```java
     int maxArea(int[] heights) {
         int maxArea = 0;
         int left = 0;
         int right = heights.length - 1;

         while (left < right) {
             int area = Math.min(heights[left], heights[right]) * (right - left);
             maxArea = Math.max(maxArea, area);

             if (heights[left] < heights[right]) {
                 left++;
             } else {
                 right--;
             }
         }

         return maxArea;
     }
     ```
