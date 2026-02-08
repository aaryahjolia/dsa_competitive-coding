## Description

The `empty()` function checks whether the priority queue is empty or not. Returns `true` (1) if empty, `false` (0) otherwise.

## Method - empty()

```cpp
priority_queue<int> pq;

// Check if empty
cout << "Is empty: " << pq.empty() << endl;

pq.push(10);
pq.push(20);

cout << "Is empty after push: " << pq.empty() << endl;

pq.pop();
pq.pop();

cout << "Is empty after all pops: " << pq.empty();
```

### Output

```cpp
Is empty: 1
Is empty after push: 0
Is empty after all pops: 1
```

## Example - Safe extraction using empty()

```cpp
priority_queue<int> pq;
pq.push(30);
pq.push(10);
pq.push(20);

// Safely extract all elements
while(!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
}
```

### Output

```cpp
30 20 10
```

## Example - Conditional processing

```cpp
priority_queue<int> pq;
pq.push(50);
pq.push(30);

if(!pq.empty()) {
    cout << "Top element: " << pq.top() << endl;
    cout << "Size: " << pq.size();
}
```

### Output

```cpp
Top element: 50
Size: 2
```

## Note

- Always check `empty()` before calling `top()` or `pop()` to avoid undefined behavior
- Time complexity: O(1)
