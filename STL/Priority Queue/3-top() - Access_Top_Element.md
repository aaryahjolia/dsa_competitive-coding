## Description

The `top()` function returns the top element of the priority queue without removing it. For max heap, it returns the largest element; for min heap, it returns the smallest element.

## Method 1 - Accessing top element (Max Heap)

```cpp
priority_queue<int> pq;
pq.push(10);
pq.push(30);
pq.push(20);

// Access top element
cout << pq.top();
```

### Output

```cpp
30
```

## Method 2 - Accessing top element (Min Heap)

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
pq.push(10);
pq.push(30);
pq.push(20);
pq.push(5);

// Access top element (smallest)
cout << pq.top();
```

### Output

```cpp
5
```

## Method 3 - top() with pairs

```cpp
priority_queue<pair<int, string>> pq;
pq.push({85, "Bob"});
pq.push({95, "Alice"});
pq.push({75, "Charlie"});

// Access top pair
auto topElement = pq.top();
cout << topElement.first << " " << topElement.second;
```

### Output

```cpp
95 Alice
```

## Note

- `top()` does **NOT** remove the element from the priority queue
- Calling `top()` on an empty priority queue leads to undefined behavior
- Time complexity: O(1)
