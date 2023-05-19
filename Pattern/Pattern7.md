## Description
This code prints a pattern of numbers in the form of an inverted pyramid. The number of rows in the pyramid is taken as input from the user. The numbers in each row start from 1 and increase incrementally up to the row number. After reaching the maximum row, the pattern is repeated in reverse order until reaching the starting row.

## code 
```cpp

#include <bits/stdc++.h> // Include the entire standard library for convenience in competitive coding
using namespace std;     // Import the std namespace


void printPattern(int n) {
    // Print upper half of the pattern
    for (int i = 1; i <= n; i++) {
        // Print numbers from 1 to i in each row
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }

    // Print lower half of the pattern
    for (int i = n - 1; i >= 1; i--) {
        // Print numbers from 1 to i in each row
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;

    printPattern(rows);

    return 0;
}

```

## Output
```
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1

```

## Time Complexity
```
The time complexity of this code is O(n^2), where n is the number of rows. The outer loops run n times for the upper half and n - 1 times for the lower half, resulting in a total of 2n - 1 iterations. The inner loops run i times for each iteration. Hence, the total number of iterations is 1 + 2 + 3 + ... + n + (n - 1) + ... + 1, which is equal to n^2. Therefore, the time complexity is O(n^2).
```

## Space Complexity
```
The space complexity of this code is O(1) because it only uses a constant amount of additional space to store loop variables and temporary values. The space required for outputting the pattern is not considered in the space complexity analysis.

```