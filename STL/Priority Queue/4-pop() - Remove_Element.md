## Description

Element can be removed from the top of priority queue using `pop()` method. It removes the element with highest priority (largest in max heap, smallest in min heap).

## Method - pop()

```cpp
priority_queue<int> pq;
pq.push(10);
pq.push(30);
pq.push(20);
pq.push(5);

cout << "Before pop: " << pq.top() << endl;

// Removing top element
pq.pop(); // Removes 30

cout << "After pop: " << pq.top() << endl;

pq.pop(); // Removes 20

cout << "After second pop: " << pq.top();
```

### Output

```cpp
Before pop: 30
After pop: 20
After second pop: 10
```

## Example - Extracting all elements

```cpp
priority_queue<int> pq;
pq.push(10);
pq.push(30);
pq.push(20);
pq.push(5);

// Extract all elements in priority order
while(!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
}
```

### Output

```cpp
30 20 10 5
```

## Note

- `pop()` does **NOT** return the removed element, it only removes it
- Use `top()` before `pop()` if you need the value
- Calling `pop()` on an empty priority queue leads to undefined behavior
- Time complexity: O(log n)
