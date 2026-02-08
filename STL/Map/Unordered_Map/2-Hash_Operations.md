## Description

Hash-specific operations unique to unordered_map for managing buckets and performance.

## bucket_count() - Number of buckets

```cpp
unordered_map<int, string> um = {{1, "One"}, {2, "Two"}};
cout << um.bucket_count();
```

### Output (example)

```cpp
7
```

## load_factor() - Average elements per bucket

```cpp
unordered_map<int, string> um = {{1, "One"}, {2, "Two"}};
cout << um.load_factor();
// load_factor = size / bucket_count
```

### Output (example)

```cpp
0.285714
```

## reserve() - Reserve space

```cpp
unordered_map<int, string> um;
um.reserve(100); // Reserve for 100 elements
// Reduces rehashing during insertions
```

## rehash() - Change bucket count

```cpp
unordered_map<int, string> um = {{1, "One"}, {2, "Two"}};
um.rehash(20); // Set bucket count to 20
cout << um.bucket_count();
```

### Output

```cpp
20
```

## Performance comparison

```cpp
// Unordered_map: O(1) average
unordered_map<int, string> um = {{1, "One"}};
um[2] = "Two"; // O(1)
auto it = um.find(1); // O(1)

// Map: O(log n)
map<int, string> m = {{1, "One"}};
m[2] = "Two"; // O(log n)
auto it2 = m.find(1); // O(log n)
```

## When to use

**Use unordered_map when:**

- Need fast O(1) operations
- Don't need sorted order
- Working with large datasets

**Use map when:**

- Need sorted order by key
- Need lower_bound/upper_bound
- Need range queries
- Need predictable iteration order
