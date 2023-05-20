## Problem Statement

The N-Queen problem is a classic problem in computer science and mathematics. It involves placing N queens on an N x N chessboard such that no two queens threaten each other. A queen can attack horizontally, vertically, and diagonally.

The goal of the N-Queen problem is to find all possible configurations of placing N queens on the board without any two queens attacking each other.

## Algorithm:

Here's a popular algorithm called Backtracking to solve the N-Queens problem:

1. Start with an empty chessboard of size N x N.
2. Begin with the first row and iterate through each column:
 2.1 Place a queen in the current column of the first row.
 2.2 Recursively move to the next row and repeat step 2.
 2.3 If the current configuration violates the constraints (queens threatening each other), backtrack and try the next column in the current row.
 2.3 If all columns have been tried in the current row, backtrack to the previous row.
 2.4 Repeat this process until a valid solution is found or all possibilities have been exhausted.
3. Once a valid solution is found, print or store the configuration of queens on the chessboard.
4. Continue searching for all possible solutions by backtracking and exploring different configurations.
The Backtracking algorithm effectively explores the solution space by trying different configurations and backtracking when conflicts arise. It guarantees finding all possible solutions for the N-Queens problem.

It's worth noting that for large values of N, the Backtracking algorithm may become computationally expensive, and more advanced techniques like pruning, symmetry-breaking, or heuristic-based approaches can be employed to optimize the search process.

#### Example 1:

##### Output:

        Enter the board size (N): 4

                        - - Q - 
                        Q - - - 
                        - - - Q 
                        - Q - - 

                        - Q - - 
                        - - - Q 
                        Q - - - 
                        - - Q - 



```cpp


#include <iostream>
#include <vector>

using namespace std;

// Function prototype to print the solution (board configuration)
void printSolution(const vector<int> &queens);

// Function prototype to check if it is safe to place a queen at a given position
bool isSafe(const vector<int> &queens, int row, int col);

// Function prototype to solve the N-Queens problem
void solveNQueens(vector<int> &queens, int col);

// Function to solve the N-Queens problem based on user input
void solveNQueensUserInput(int N){
    vector<int> queens(N, -1); // Queens' positions initialized to -1

    solveNQueens(queens, 0);
}

// Recursive function to solve the N-Queens problem using backtracking
void solveNQueens(vector<int> &queens, int col){
    int N = queens.size();
    if (col == N){ // All columns are filled, a solution is found
        printSolution(queens);
        return;
    }

    for (int row = 0; row < N; row++){
        if (isSafe(queens, row, col)){
            queens[col] = row;             // Place the queen at the current position
            solveNQueens(queens, col + 1); // Recur for the next column
            queens[col] = -1;              // Remove the queen (backtracking)
        }
    }
}

// Function to check if it is safe to place a queen at the given position
bool isSafe(const vector<int> &queens, int row, int col){
    for (int i = 0; i < col; i++){
        if (queens[i] == row || queens[i] == row - (col - i) || queens[i] == row + (col - i))
            return false; // Conflict with previously placed queens
    }
    return true; // No conflicts, it is safe to place a queen
}

// Function to print the board configuration
void printSolution(const vector<int> &queens){
    int N = queens.size();
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
        {
            if (queens[j] == i)
                cout << "Q ";
            else
                cout << "- ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int N;
    cout << "Enter the board size (N): ";
    cin >> N;
    cout << endl;
    solveNQueensUserInput(N);
    return 0;
}


```

## Complexity:

#### 1. Time Complexity
In the backtracking algorithm for the N-Queen problem, the time complexity can be approximated as O(N!), where N is the size of the board or the number of queens to be placed.


#### 2. Space Complexity
The space complexity is typically O(N).





