//You are given an m x n matrix mat that has its rows sorted in non-decreasing order and an integer k.
//You are allowed to choose exactly one element from each row to form an array.
//Return the kth smallest array sum among all possible arrays.

#include <bits/stdc++.h>
using namespace std;

struct Element {
    int sum;
    int rowIndex;
    int colIndex;

    Element(int s, int r, int c) : sum(s), rowIndex(r), colIndex(c) {}

    bool operator>(const Element& other) const {
        return sum > other.sum;
    }
};

int kthSmallest(vector<vector<int>>& mat, int k) {
    int m = mat.size();
    int n = mat[0].size();

    // Calculate the sum of the first row as the initial sum
    int initialSum = 0;
    for (int j = 0; j < n; j++) {
        initialSum += mat[0][j];
    }

    // Create a min heap
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;
    minHeap.push(Element(initialSum, 0, -1));

    // Maintain a set to track visited indices
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    // Perform k-1 iterations to find the kth smallest sum
    for (int i = 0; i < k - 1; i++) {
        Element current = minHeap.top();
        minHeap.pop();

        int currentSum = current.sum;
        int rowIndex = current.rowIndex;
        int colIndex = current.colIndex;

        // Explore the next element in the current row
        if (colIndex < n - 1) {
            int nextSum = currentSum - mat[rowIndex][colIndex] + mat[rowIndex][colIndex + 1];
            minHeap.push(Element(nextSum, rowIndex, colIndex + 1));
        }

        // Explore the first element of the next row
        if (rowIndex < m - 1 && colIndex == 0) {
            int nextSum = currentSum + mat[rowIndex + 1][0] - mat[rowIndex][0];
            minHeap.push(Element(nextSum, rowIndex + 1, 0));
        }
    }

    // The kth smallest sum is the top of the min heap after k-1 iterations
    return minHeap.top().sum;
}

int main() {
    vector<vector<int>> mat = {{1, 3, 5}, {4, 8, 9}, {10, 11, 13}};
    int k = 4;

    int result = kthSmallest(mat, k);
    cout << "The kth smallest array sum is: " << result << endl;

    return 0;
}
