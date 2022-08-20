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

- In Java

```c
class Solution {
    public void rotate(int[][] matrix) {
        //in this que for clockwise we do column reverse and for anticlockwise row reverse now after reversing we do the transpose of the matrix
        //1.Transpose of matrix
        for(int r=0;r<matrix.length;r++){
            for(int c=0;c<r;c++){
                int temp=matrix[r][c];
                matrix[r][c]=matrix[c][r];
                matrix[c][r]=temp;
            }
        }
            
        
        //2.we here reverse the column bcoz it is c.w
        int fc=0;  //firstcol
        int lc=matrix[0].length-1;  //lastcol
         while(fc<lc){
             //now here we are swapping the first
             for(int r=0;r<matrix.length;r++){
                 int temp=matrix[r][fc];
                 matrix[r][fc]=matrix[r][lc];
                 matrix[r][lc]=temp;
             }
             fc++; lc--;
         }
    }
}
```
- In C++

```c
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    //Transpose
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
            // Reverse
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```

### Time Complexity - O(n^2)
### Space Complexity - O(1)
