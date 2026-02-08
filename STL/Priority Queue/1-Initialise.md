## Description

Priority Queue is a container adapter in C++ STL that provides constant time lookup of the largest (by default) element. It is implemented as a heap data structure. By default, it is a max heap (largest element at top).
The values are stored in a tree data structure internally.

## Different Ways to Initialise a Priority Queue

### Note : Priority Queue needs an additional include

```cpp
#include<queue>
```

But everything will be included when we include <bits/stdc++.h>, so no need to import queue if we import all modules.

### Supported Datatypes :

int, char, string, pair, custom objects

### 1. Default Priority Queue (Max Heap)

```cpp
// Creates an empty max heap priority queue of int
priority_queue<int> pq;
```

### 2. Min Heap Priority Queue

```cpp
// Creates an empty min heap priority queue of int
priority_queue<int, vector<int>, greater<int>> pq;
```

### 3. Priority Queue with pairs

```cpp
// Max heap based on first element of pair
priority_queue<pair<int, int>> pq;
```

### 4. Priority Queue with initial values

```cpp
// Initialize with array
int arr[] = {10, 30, 20, 5, 15};
priority_queue<int> pq(arr, arr + 5);
```

### 5. Priority Queue with custom comparator

```cpp
// Custom comparator for min heap
priority_queue<int, vector<int>, greater<int>> pq;
```

## Priority Queue Operations

Priority Queue has **6 main functions**:

**push()** - Inserts an element into the priority queue - O(log n)

**top()** - Returns the top element (largest in max heap, smallest in min heap) - O(1)

**pop()** - Removes the top element - O(log n)

**empty()** - Returns true if the priority queue is empty - O(1)

**size()** - Returns the number of elements - O(1)

**swap()** - Swaps the contents of two priority queues - O(1)

### Time Complexities

- Insertion (push): O(log n)
- Access top element (top): O(1)
- Deletion (pop): O(log n)
- Size/Empty check: O(1)
