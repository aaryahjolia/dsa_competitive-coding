## Description

Set is an associative container in C++ STL that stores **unique elements** in **sorted order**. It is implemented as a balanced binary search tree (Red-Black Tree). Duplicate values are not allowed.

## Different Ways to Initialise a Set

### Note : Set needs an additional include

```cpp
#include<set>
```

But everything will be included when we include <bits/stdc++.h>, so no need to import set if we import all modules.

### Supported Datatypes :

int, char, string, pair, custom objects

### 1. Empty set

```cpp
set<int> s;
```

### 2. Set with initial values

```cpp
set<int> s = {10, 20, 30, 5, 15};
```

### 3. Set from array

```cpp
int arr[] = {10, 20, 30, 5, 15};
set<int> s(arr, arr + 5);
```

### 4. Copy of another set

```cpp
set<int> s1 = {10, 20, 30};
set<int> s2(s1); // Copy
```

### 5. Set with custom comparator (descending order)

```cpp
set<int, greater<int>> s; // Descending order
```

## Set Operations

**insert()** - Inserts element (ignored if duplicate) - O(log n)

**find()** - Finds element, returns iterator - O(log n)

**erase()** - Removes element by value or iterator - O(log n)

**size()** - Returns number of elements - O(1)

**empty()** - Checks if set is empty - O(1)

**clear()** - Removes all elements - O(n)

**count()** - Returns 1 if present, 0 otherwise - O(log n)

**begin()** - Returns iterator to first element - O(1)

**end()** - Returns iterator to position after last - O(1)

**lower_bound()** - First element >= value - O(log n)

**upper_bound()** - First element > value - O(log n)

**swap()** - Swaps two sets - O(1)

### Key Characteristics

- **Unique elements** - Duplicates automatically ignored
- **Sorted order** - Elements always in ascending order (by default)
- **Balanced BST** - Red-Black Tree implementation
- **No indexing** - Cannot access elements like `s[i]`
