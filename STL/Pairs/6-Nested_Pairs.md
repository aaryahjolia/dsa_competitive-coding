## Description

Nested pairs allow storing multiple values in a hierarchical structure. A pair's first or second element can itself be a pair.

## Creating Nested Pairs

### Method 1 - Pair as second element

```cpp
// Storing (int, (int, int))
pair<int, pair<int, int>> p;
p.first = 1;
p.second.first = 2;
p.second.second = 3;

cout << p.first << " " << p.second.first << " " << p.second.second;
```

### Output

```cpp
1 2 3
```

### Method 2 - Using make_pair for nested initialization

```cpp
// Create nested pair in one line
pair<int, pair<int, int>> p = make_pair(1, make_pair(2, 3));

cout << p.first << " " << p.second.first << " " << p.second.second;
```

### Output

```cpp
1 2 3
```

### Method 3 - Pair as first element

```cpp
// Storing ((int, int), int)
pair<pair<int, int>, int> p = {make_pair(1, 2), 3};

cout << p.first.first << " " << p.first.second << " " << p.second;
```

### Output

```cpp
1 2 3
```

### Method 4 - Complex nested pairs

```cpp
// Pair of pairs: ((int, int), (int, int))
pair<pair<int, int>, pair<int, int>> p;
p = {{1, 2}, {3, 4}};

cout << p.first.first << " " << p.first.second << " ";
cout << p.second.first << " " << p.second.second;
```

### Output

```cpp
1 2 3 4
```

### Method 5 - Vector of nested pairs

```cpp
// Store multiple 3D points
vector<pair<int, pair<int, int>>> points;

points.push_back({1, {2, 3}});
points.push_back({4, {5, 6}});
points.push_back({7, {8, 9}});

// Print all points
for(auto p : points) {
    cout << "(" << p.first << ", " << p.second.first << ", " << p.second.second << ")" << endl;
}
```

### Output

```cpp
(1, 2, 3)
(4, 5, 6)
(7, 8, 9)
```

### Method 6 - Pairs as a datatype (Array of pairs)

```cpp
// Array of pairs
pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};

for(int i = 0; i < 3; i++) {
    cout << arr[i].first << " " << arr[i].second << endl;
}
```

### Output

```cpp
1 2
3 4
5 6
```
