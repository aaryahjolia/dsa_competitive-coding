## Description

Hash-specific operations unique to unordered_set for managing buckets and performance.

## bucket_count() - Number of buckets

```cpp
unordered_set<int> us = {10, 20, 30};
cout << us.bucket_count();
```

### Output (example)

```cpp
7
```

## load_factor() - Average elements per bucket

```cpp
unordered_set<int> us = {10, 20, 30, 40, 50};
cout << us.load_factor();
// load_factor = size / bucket_count
```

### Output (example)

```cpp
0.714286
```

## bucket() - Get bucket index for value

```cpp
unordered_set<int> us = {10, 20, 30};
cout << "10 is in bucket: " << us.bucket(10);
```

### Output (example)

```cpp
10 is in bucket: 3
```

## reserve() - Reserve space

```cpp
unordered_set<int> us;
us.reserve(100); // Reserve for 100 elements
// Reduces rehashing during insertions
```

## rehash() - Change bucket count

```cpp
unordered_set<int> us = {10, 20, 30};
us.rehash(20); // Set bucket count to 20
cout << us.bucket_count();
```

### Output

```cpp
20
```

## Performance comparison

```cpp
// Unordered_set: O(1) average
unordered_set<int> us = {10, 20, 30};
auto it = us.find(20); // O(1)

// Set: O(log n)
set<int> s = {10, 20, 30};
auto it2 = s.find(20); // O(log n)
```

## When to use

**Use unordered_set when:**

- Need fast O(1) operations
- Don't need sorted order
- Working with large datasets

**Use set when:**

- Need sorted order
- Need lower_bound/upper_bound
- Need range queries
