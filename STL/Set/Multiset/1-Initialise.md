## Description

Multiset is similar to set but **allows duplicate elements**. It stores elements in sorted order using balanced BST (Red-Black Tree). All duplicates are stored.

## Different Ways to Initialise a Multiset

### Note : Multiset needs an additional include

```cpp
#include<set>
```

### 1. Empty multiset

```cpp
multiset<int> ms;
```

### 2. Multiset with initial values (duplicates allowed)

```cpp
multiset<int> ms = {10, 20, 10, 30, 20};
// All values stored: 10 10 20 20 30
```

### 3. Multiset from array

```cpp
int arr[] = {10, 20, 10, 30};
multiset<int> ms(arr, arr + 4);
```

### 4. Multiset with custom comparator

```cpp
multiset<int, greater<int>> ms; // Descending order
```

## Multiset Operations

**Most operations are similar to Set.** See [Set documentation](../1-Initialise.md) for details.

**Differences from Set:**

**count()** - Returns number of occurrences (can be > 1) - O(log n + k) where k is count

**equal_range()** - Returns pair of iterators for range of equal elements - O(log n)

### Common Operations (same as Set)

- insert() - O(log n)
- find() - O(log n)
- erase() - O(log n)
- size() - O(1)
- empty() - O(1)
- clear() - O(n)
- begin(), end() - O(1)
- lower_bound(), upper_bound() - O(log n)

### Key Differences from Set

✅ **Allows duplicates** - Same value can appear multiple times  
✅ **Sorted order** - Elements remain sorted  
✅ **count() returns frequency** - Not just 0 or 1  
✅ **All duplicates stored** - No automatic removal

## Example - Duplicates allowed

```cpp
multiset<int> ms;
ms.insert(10);
ms.insert(10);
ms.insert(20);
ms.insert(10);

for(auto x : ms) {
    cout << x << " ";
}
// Output: 10 10 10 20
```
