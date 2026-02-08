## Description

Unordered_Map stores **unique key-value pairs in no particular order**. It is implemented using **hash table**. Much faster than map for insertion/search/deletion but no ordering.

## Different Ways to Initialise an Unordered_Map

### Note : Unordered_map needs an additional include

```cpp
#include<unordered_map>
```

### 1. Empty unordered_map

```cpp
unordered_map<int, string> um;
```

### 2. Unordered_map with initial values

```cpp
unordered_map<int, string> um = {{1, "One"}, {2, "Two"}};
// Stored in random order (hash-based)
```

### 3. Copy

```cpp
unordered_map<int, string> um1 = {{1, "One"}};
unordered_map<int, string> um2(um1);
```

## Unordered_Map Operations

**Most operations are similar to Map.** See [Map documentation](../1-Initialise.md) for details.

**Key Difference: Average O(1) time complexity instead of O(log n)**

### Common Operations (similar to Map)

- operator[] - **O(1) average**
- insert() - **O(1) average**
- find() - **O(1) average**
- erase() - **O(1) average**
- count() - **O(1) average**
- at() - **O(1) average**
- size() - O(1)
- empty() - O(1)
- clear() - O(n)
- begin(), end() - O(1)

The worst case complexity is O(n) when hash collisions occur but the probability is very low.

### Operations NOT available

lower_bound() - No ordering  
upper_bound() - No ordering  
Custom comparator - Uses hash function instead

### Hash-specific operations

- bucket_count() - Number of buckets
- load_factor() - Elements per bucket
- rehash() - Change bucket count
- reserve() - Reserve space

### Key Characteristics

**Unique keys** - Each key appears once  
**O(1) average** - Faster than map  
**No ordering** - Random order by key  
**No comparator** - Uses hash function  
**Has operator[]** - Like map

## Example - No ordering

```cpp
unordered_map<int, string> um = {{3, "Three"}, {1, "One"}, {2, "Two"}};

for(auto p : um) {
    cout << p.first << ": " << p.second << endl;
}
// Output: Random order like:
// 2: Two
// 1: One
// 3: Three
```
