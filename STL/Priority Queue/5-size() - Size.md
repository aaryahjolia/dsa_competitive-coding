## Description

The `size()` function returns the number of elements present in the priority queue.

## Method - size()

```cpp
priority_queue<int> pq;
pq.push(10);
pq.push(30);
pq.push(20);

// Get size
cout << "Size: " << pq.size() << endl;

pq.pop();

cout << "Size after pop: " << pq.size();
```

### Output

```cpp
Size: 3
Size after pop: 2
```

## Example - Processing n elements

```cpp
priority_queue<int> pq;
pq.push(10);
pq.push(30);
pq.push(20);
pq.push(5);

int n = pq.size();
cout << "Total elements: " << n << endl;

// Process first 2 elements
for(int i = 0; i < 2 && !pq.empty(); i++) {
    cout << pq.top() << " ";
    pq.pop();
}

cout << endl << "Remaining elements: " << pq.size();
```

### Output

```cpp
Total elements: 4
30 20
Remaining elements: 2
```

## Note

- Returns 0 for an empty priority queue
- Time complexity: O(1)
