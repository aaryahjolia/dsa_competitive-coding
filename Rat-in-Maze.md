## Problem: Rat in a Maze: Finding all Possible Paths















### Problem Description
- Given a square matrix of size N x N representing a maze, where each cell can be either blocked (0) or accessible (1), the task is to find all possible paths for a rat to reach the destination at (N-1, N-1) starting from the source at (0, 0). 
- The rat can only move in four directions: up ('U'), down ('D'), left ('L'), and right ('R'). In a valid path, the rat cannot visit a cell more than once.

- If there are multiple valid paths, the solution should return them in lexicographically increasing order.



### Intuition
Approach:

- Start at the source(0,0) with an empty string and try every possible path i.e upwards(U), downwards(D), leftwards(L) and rightwards(R).
- As the answer should be in lexicographical order so it’s better to try the directions in lexicographical order i.e (D,L,R,U)
- Declare a 2D-array named visited because the question states that a single cell should be included only once in the path,so it’s important to keep track of the visited cells in a particular path.
- If a cell is in path, mark it in the visited array.
- Also keep a check of the “out of bound” conditions while going in a particular direction in the matrix. 
- Whenever you reach the destination(n,n) it’s very important to get back as shown in the recursion tree.
- While getting back, keep on unmarking the visited array for the respective direction.Also check whether there is a different path possible while getting back and if yes, then mark that cell in the visited array.
    
    
### Code in Java

```java
import java.util.*;

// m is the given matrix and n is the order of matrix
class Solution {
  private static void solve(int i, int j, int a[][], int n, ArrayList < String > ans, String move,
    int vis[][], int di[], int dj[]) {
    if (i == n - 1 && j == n - 1) {
      ans.add(move);
      return;
    }
    String dir = "DLRU";
    for (int ind = 0; ind < 4; ind++) {
      int nexti = i + di[ind];
      int nextj = j + dj[ind];
      if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n &&
        vis[nexti][nextj] == 0 && a[nexti][nextj] == 1) {

        vis[i][j] = 1;
        solve(nexti, nextj, a, n, ans, move + dir.charAt(ind), vis, di, dj);
        vis[i][j] = 0;

      }
    }
  }
  public static ArrayList < String > findPath(int[][] m, int n) {
    int vis[][] = new int[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        vis[i][j] = 0;
      }
    }
    int di[] = {
      +1,
      0,
      0,
      -1
    };
    int dj[] = {
      0,
      -1,
      1,
      0
    };
    ArrayList < String > ans = new ArrayList < > ();
    if (m[0][0] == 1) solve(0, 0, m, n, ans, "", vis, di, dj);
    return ans;
  }
}
class DSA {
  public static void main(String[] args) {

    int n = 4;
    int[][] a = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};

    Solution obj = new Solution();
    ArrayList < String > res = obj.findPath(a, n);
    if (res.size() > 0) {
      for (int i = 0; i < res.size(); i++)
        System.out.print(res.get(i) + " ");
      System.out.println();
    } else {
      System.out.println(-1);
    }
  }
}

```
