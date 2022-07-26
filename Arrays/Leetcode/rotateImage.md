# Rotate Image

### Problem Link : https://leetcode.com/problems/rotate-image/

## Problem :

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

![image](https://user-images.githubusercontent.com/87513713/180652071-b7fe6e19-28b5-40dd-981e-e36e8ddaeb81.png)


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]] <br />
Output: [[7,4,1],[8,5,2],[9,6,3]]

## Solution :

- In Python

```c
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        l, r = 0, len(matrix) - 1
        while l < r:
            for i in range(r - l):
                top, bottom = l, r
                # save the topleft
                topLeft = matrix[top][l + i]
                # move bottom left into top left
                matrix[top][l + i] = matrix[bottom - i][l]
                # move bottom right into bottom left
                matrix[bottom - i][l] = matrix[bottom][r - i]
                # move top right into bottom right
                matrix[bottom][r - i] = matrix[top + i][r]
                # move top left into top right
                matrix[top + i][r] = topLeft
            r -= 1
            l += 1
```
- In C++

```c
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```

### Time Complexity - O(n^2)
### Space Complexity - O(1)