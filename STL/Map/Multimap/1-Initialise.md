## Description

Multimap is similar to map but **allows duplicate keys**. Multiple values can be associated with the same key. Elements are stored in sorted order by key using balanced BST (Red-Black Tree).

## Different Ways to Initialise a Multimap

### Note : Multimap needs an additional include

```cpp
#include<map>
```

### 1. Empty multimap

```cpp
multimap<int, string> mm;
```

### 2. Multimap with initial values (duplicate keys allowed)

```cpp
multimap<int, string> mm = {{1, "One"}, {2, "Two"}, {1, "First"}};
// Key 1 has two values: "One" and "First"
```

### 3. Multimap with custom comparator

```cpp
multimap<int, string, greater<int>> mm; // Descending order by key
```

## Multimap Operations

**Most operations are similar to Map.** See [Map documentation](../1-Initialise.md) for details.

**Key Difference: Allows duplicate keys**

### Differences from Map

**count()** - Returns number of values for a key (can be > 1) - O(log n + k)

**equal_range()** - Returns pair of iterators for all values of a key - O(log n)

**No operator[]** - Cannot use `mm[key]` (which value to return?)

**insert()** - Always inserts (even if key exists) - O(log n)

### Common Operations (similar to Map)

- insert() - Always inserts, O(log n)
- find() - O(log n)
- erase() - O(log n)
- size() - O(1)
- empty() - O(1)
- clear() - O(n)
- begin(), end() - O(1)
- lower_bound(), upper_bound() - O(log n)

### Key Characteristics

**Duplicate keys allowed** - Same key with different values  
**Sorted by key** - Elements remain sorted  
**No operator[]** - Use insert() or find()  
**All values stored** - No automatic removal

## Example - Multiple values per key

```cpp
multimap<int, string> mm;
mm.insert({1, "One"});
mm.insert({1, "First"});
mm.insert({2, "Two"});

for(auto p : mm) {
    cout << p.first << ": " << p.second << endl;
}
// Output:
// 1: One
// 1: First
// 2: Two
```
