## Problem Statement

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.



#### Example 1:

##### Input: board = 
                
                [["5","3",".",".","7",".",".",".","."],

                ["6",".",".","1","9","5",".",".","."],
                
                [".","9","8",".",".",".",".","6","."],
                
                ["8",".",".",".","6",".",".",".","3"],
                
                ["4",".",".","8",".","3",".",".","1"],
                
                ["7",".",".",".","2",".",".",".","6"],
                
                [".","6",".",".",".",".","2","8","."],
                
                [".",".",".","4","1","9",".",".","5"],
                
                [".",".",".",".","8",".",".","7","9"]]
                

##### Output:         

                [["5","3","4","6","7","8","9","1","2"],
                
                ["6","7","2","1","9","5","3","4","8"],
                
                ["1","9","8","3","4","2","5","6","7"],
                
                ["8","5","9","7","6","1","4","2","3"],
                
                ["4","2","6","8","5","3","7","9","1"],
                
                ["7","1","3","9","2","4","8","5","6"],
                
                ["9","6","1","5","3","7","2","8","4"],
                
                ["2","8","7","4","1","9","6","3","5"],
                
                ["3","4","5","2","8","6","1","7","9"]]



##  Intuition:-

- check if row == n,then we have completely filled our grid so return true
- if current column == n-1,then we have to move to the next row by incrementing current row by 1 and making current column as 0.
- else we have to move to the next right cell by keeping the row same and incrementing current column by 1.

- If the current cell is already filled then we will simpliy move to the next cell.
- Otherwise, we'll explore all the 9 possibilities.
- Now for the current value we have to first check if it is valid or not ,for that we have to check if there isn't any same value present in the current row and in the current column and in the current sub grid.
- if its not present in the current row ,current column and current sub grid then it is a valid value for the current cell,so return true.
- if the above conditions doesn't holds then return false and explore the other possibilities.
- Once we have found that its a valid value then update the current cell's value to the current value.
- Even after exploring all the 9 possibilities,if we haven't got a value to fill a cell ,then return false and undo the changes and explore other possibilities.


#### 1. Time Complexity = O(9^n* n) or O(exponential) ,since we are having 9 possibilities for each cell.
#### 2. Space Complexity = can't say exactly but somewhat equals to O(n^2).






```cpp


class Solution {
public:
    
    //function to check if the current value is present or not in the ROW
    bool isRowValid(vector<vector<char>>&board,int currVal,int currRow,int n)
    {
        //iterating over the current row
        //to check if current value is present or not
        //if it isn't present then its a valid value for the current row
        //therefore return true
        //else return false
        for(int col = 0;col<n;col++)
        {
            if(board[currRow][col] == char(currVal+'0'))
                return false;
        }
        return true;
    }
    
    
    //function to check if the current value is present or not in the COLUMN
    bool isColValid(vector<vector<char>>&board,int currVal,int currCol,int n)
    {
        //iterating over the current col to check if current val is present or not
        //if it isn't present then it means its a valid value for the current col
        //and hence return true 
        //else return false;
        for(int row = 0; row<n; row++)
        {
            if(board[row][currCol] == char(currVal+'0'))
                return false;
        }
        return true;
    }
    
    
    //function to check if the current value is present or not in the SUB GRID
    bool isSubGridValid(vector<vector<char>>&board,int currVal,int currRow,int currCol,int n)
    {
        //finding the starting cordinates of the current subgrid
        int startRow = 3*(currRow/3);
        int startCol = 3*(currCol/3);
        
        //iterating over the current sub grid
        //to check if current vaule is present or not 
        //if it isn't present we'll return true 
        //else false
        for(int row = startRow; row<=startRow+2;row++)
        {
            for(int col = startCol; col<=startCol+2;col++)
            {
                if(board[row][col] == char(currVal+'0'))
                    return false;
            }
        }
        return true;
    }
    
    
    //function to check if the current value is valid or not
    bool isValid(vector<vector<char>>&board,int currVal,int currRow,int currCol,int n)
    {
        //if the current row is valid i.e. the current value isn't present in the current row
        //if the current col is vaild i.e. the current value isn't present in the current column
        //and if it isn't present in the current sub grid
        //then it means we can fill the current value in the current  cell
        //so return true
        if(isRowValid(board,currVal,currRow,n) && isColValid(board,currVal,currCol,n) && 
           isSubGridValid(board,currVal,currRow,currCol,n))
            return true;
        
        //return false otherwise
        else
            return false;
    }
    
    
    //function to solve the sudoko
    bool sudokoSolver(vector<vector<char>>& board,int currRow,int currCol,int n)
    {
        //if we have reached n
        //i.e. we have filled the board completely
        //return true
        if(currRow == n) 
            return true;
        
        int nextRow = -1;
        int nextCol = -1;
        
        
        //if we have not yet reached the end of the current row
        //then we can still move one step right by keeping the row same & incrementing the col
        if(currCol != n-1)
        {
            nextRow = currRow;
            nextCol = currCol + 1;
        }
        
        
        //if we have reached the end of the current row .i.e. currCol == n-1
        //then we have to go to the next row and the 0-th column
        else
        {
            nextRow = currRow+1;
            nextCol = 0;
        }
        
        //if board[currRow][currCol] != "." ,i.e. the current cell isn't empty
        //if current cell is already filled then we just have to move to the next cell
        if(board[currRow][currCol] != '.')
            return sudokoSolver(board,nextRow,nextCol,n);
        
        //if the current cell isn't filled
        //we'll explore all the 9 possibilities
        for(int currVal = 1;currVal<=9;currVal++)
        {
            //check if the current Value is valid 
            //i.e. whether we can fill the current cell with the current value or not
            if(isValid(board,currVal,currRow,currCol,n))
            {
                //if the current value is valid 
                //then update current cell's value with current value
                //and move to the next cell
                board[currRow][currCol] = char(currVal+'0');
                //if the current configuration leads to the complete filling of the sudoko
                //then return true
                if(sudokoSolver(board,nextRow,nextCol,n))
                    return true;
                
                //if the current configuration doesn't leads to the complete filling of the sudoko
                //then undo the change
                board[currRow][currCol] = '.'; //line 58
            }
        }
        //if we haven't got any valid value to fill the current cell after traversing the entire for loop
        //that means the previous changes we did wasn't valid ,so return false
        //after this return statement controls goes to line 58
        return false;   
    }
    
    
    //control starts from here
    void solveSudoku(vector<vector<char>>& board)
    {
        sudokoSolver(board,0,0,board.size());
    }
};



```
