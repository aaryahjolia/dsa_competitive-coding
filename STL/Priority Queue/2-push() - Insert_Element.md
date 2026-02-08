## Description

Element can be inserted into priority queue using `push()` or `emplace()` method. The element is automatically placed in its correct position based on priority.

## Method 1 - push()

```cpp
priority_queue<int> pq;
// Pushing elements
pq.push(10);
pq.push(30);
pq.push(20);
pq.push(5);
```

### Priority Queue now contains (Max Heap - largest on top)

```cpp
30 // Top element
20
10
5
```

## Method 2 - emplace()

```cpp
priority_queue<int> pq;
// Emplacing elements (constructs in place)
pq.emplace(10);
pq.emplace(30);
pq.emplace(20);
```

### Priority Queue now contains

```cpp
30 // Top element
20
10
```

## Method 3 - push() with pairs

```cpp
priority_queue<pair<int, string>> pq;
// Pushing pairs (sorted by first element)
pq.push({85, "Bob"});
pq.push({95, "Alice"});
pq.push({75, "Charlie"});
```

### Priority Queue now contains

```cpp
{95, "Alice"} // Top element (highest first value)
{85, "Bob"}
{75, "Charlie"}
```

## Method 4 - push() in Min Heap

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
// Pushing elements in min heap
pq.push(10);
pq.push(30);
pq.push(20);
pq.push(5);
```

### Priority Queue now contains (Min Heap - smallest on top)

```cpp
5 // Top element
10
20
30
```
