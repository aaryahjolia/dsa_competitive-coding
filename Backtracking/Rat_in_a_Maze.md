## Problem Statement
Given a maze grid represented as a two-dimensional matrix, the goal is to find a path for a rat to reach the destination. The rat can move only in two directions: right and down. The maze contains obstacles represented by blocked cells, where the rat cannot pass through.

The maze grid is represented as follows:

'0' represents an empty cell where the rat can move.
'1' represents a blocked cell or obstacle.
'S' represents the starting cell.
'D' represents the destination cell.
The rat starts from the top-left cell (marked 'S') and wants to reach the bottom-right cell (marked 'D'). The rat can only move to adjacent cells (right or down) that are not blocked (marked '0'). The task is to find a path, if it exists, that leads the rat from the starting cell to the destination cell.

The goal is to find a valid path from 'S' to 'D' and return it as a sequence of movements (e.g., 'R' for moving right and 'D' for moving down), or return a message indicating that no path exists.

## Example:
Input: {[1,0,1,0,1],
        [1,1,1,1,1],
        [0,1,0,1,0],
        [1,0,0,1,1],
        [1,1,1,0,1]}

Output: {[1,0,0,0,0],
         [1,1,1,1,0],
         [0,0,0,1,0],
         [0,0,0,1,1],
         [0,0,0,0,1]}

## Intuition:
The "Rat in a Maze Problem" involves finding a path from a starting point to a destination point in a maze while avoiding obstacles. The intuition behind the problem is to explore all possible paths using a recursive backtracking approach. The rat makes decisions on which direction to move, prioritizing right, down, left, and up. It marks visited cells to avoid loops. The algorithm terminates when the destination cell is reached or when all paths have been explored. Understanding this intuition helps implement an efficient backtracking algorithm to solve the problem.

## Time Complexity
The time complexity of the rat in a maze is O(2^(n^2)). The recursion can run upper bound 2^(n^2) times. 

## Space Complexity
The space complexity is O(n^2) because output matrix is required, so an extra space of size n*n is needed.

## CPP Solution

```cpp

class Solution {
    public:
        bool isSafe(int **arr,int x,int y,int n){
            //to check if the next block/cell is available or not
            if(x<n && y<n && arr[x][y]==1){
                 return true;
            }
        return false;
        }
        
        bool ratInMaze(int **arr,int x,int y,int n,int** solArr){
            //to find the required path
            if(isSafe(arr,x,y,n)){
                  solArr[x][y]=1;
                  if(ratInMaze(arr,x+1,y,n,solArr)){
                    return true;
                  }
                  solArr[x][y]=0; //backtracking
                  return false;
            }
            if(x == n-1 && y == n-1){
                 solArr[x][y]==1;
                 return true;
            }
            return false;
        }
};
        
        int main(){
            int n;//no. of rows and columns
            cin>>n;
            int** arr=new int* [n];
            for(int i=0;i<n;i++){
                arr[i]=new int[n];
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;i++){
                    cin>>arr[i][j];
                }
            }

            int** solArr=new int* [n];
            for(int i=0;i<n;i++){
                solArr[i]=new int[n];
                for(int j=0;j<n;j++){
                    solArr[i][j]=0;
                }
            }
            if(ratInMaze(arr,0,0,n,solArr)){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        cout<<solArr[i][j];
                    }
                }
            }
            return 0;
        }
