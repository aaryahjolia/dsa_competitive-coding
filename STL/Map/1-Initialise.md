## Description

Map is an associative container that stores key-value pairs in sorted order by key. Each key is unique. It is implemented as a balanced binary search tree (Red-Black Tree).

## Different Ways to Initialise a Map

### Note : Map needs an additional include

```cpp
#include<map>
```

But everything will be included when we include <bits/stdc++.h>, so no need to import map if we import all modules.

### Supported Datatypes :

Keys and values can be: int, char, string, pair, custom objects

### 1. Empty map

```cpp
map<int, string> m;
```

### 2. Map with initial values

```cpp
map<int, string> m = {{1, "One"}, {2, "Two"}, {3, "Three"}};
```

### 3. Copy of another map

```cpp
map<int, string> m1 = {{1, "One"}, {2, "Two"}};
map<int, string> m2(m1);
```

### 4. Map with custom comparator (descending order)

```cpp
map<int, string, greater<int>> m; // Sorted by key in descending order
```

## Map Operations

**insert()** - Inserts key-value pair (ignored if key exists) - O(log n)

**operator[]** - Access/insert value by key - O(log n)

**at()** - Access value by key (throws exception if not found) - O(log n)

**find()** - Finds key, returns iterator - O(log n)

**erase()** - Removes element by key or iterator - O(log n)

**size()** - Returns number of key-value pairs - O(1)

**empty()** - Checks if map is empty - O(1)

**clear()** - Removes all elements - O(n)

**count()** - Returns 1 if key exists, 0 otherwise - O(log n)

**begin()** - Returns iterator to first element - O(1)

**end()** - Returns iterator to position after last - O(1)

**lower_bound()** - First element with key >= given key - O(log n)

**upper_bound()** - First element with key > given key - O(log n)

**swap()** - Swaps two maps - O(1)

### Key Characteristics

- **Unique keys** - Each key appears only once
- **Sorted by key** - Elements sorted in ascending order by key (default)
- **Key-value pairs** - Stores pairs of (key, value)
- **Balanced BST** - Red-Black Tree implementation
- **No duplicate keys** - Inserting existing key updates value (with [])
