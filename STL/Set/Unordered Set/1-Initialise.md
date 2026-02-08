## Description

Unordered Set stores **unique elements in no particular order**. It is implemented using **hash table**. Much faster than set for insertion/search/deletion but no ordering.

## Different Ways to Initialise an Unordered Set

### Note : Unordered_set needs an additional include

```cpp
#include<unordered_set>
```

### 1. Empty unordered_set

```cpp
unordered_set<int> us;
```

### 2. Unordered_set with initial values

```cpp
unordered_set<int> us = {10, 20, 30, 5};
// Stored in random order (hash-based)
```

### 3. From array

```cpp
int arr[] = {10, 20, 30};
unordered_set<int> us(arr, arr + 3);
```

### 4. Copy

```cpp
unordered_set<int> us1 = {10, 20};
unordered_set<int> us2(us1);
```

## Unordered_Set Operations

**Most operations are similar to Set.** See [Set documentation](../1-Initialise.md) for details.

**Key Difference: Average O(1) time complexity instead of O(log n)**

### Common Operations (similar to Set)

- insert() - **O(1) average**
- find() - **O(1) average**
- erase() - **O(1) average**
- count() - **O(1) average**
- size() - O(1)
- empty() - O(1)
- clear() - O(n)
- begin(), end() - O(1)

The worst case complexity is O(n) when some collisions occur but the probability of collisions is very low.

### Operations NOT available

❌ lower_bound() - No ordering  
❌ upper_bound() - No ordering  
❌ Custom comparator - Uses hash function instead

### Hash-specific operations

- bucket_count() - Number of buckets
- load_factor() - Elements per bucket
- rehash() - Change bucket count
- reserve() - Reserve space for elements

### Key Characteristics

✅ **Unique elements** - No duplicates  
✅ **O(1) average** - Faster than set  
❌ **No ordering** - Random order  
❌ **No comparator** - Uses hash function

## Example - No ordering

```cpp
unordered_set<int> us = {30, 10, 20, 5};

for(auto x : us) {
    cout << x << " ";
}
// Output: Random order like: 5 20 10 30
```
