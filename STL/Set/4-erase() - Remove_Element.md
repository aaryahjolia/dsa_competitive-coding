## Description

The `erase()` function removes elements from the set. Can remove by value or by iterator.

## Method 1 - Erase by value

```cpp
set<int> s = {10, 20, 30, 40};
s.erase(20); // Removes 20

for(auto x : s) {
    cout << x << " ";
}
```

Takes logarithmic time.

### Output

```cpp
10 30 40
```

## Method 2 - Erase by iterator

```cpp
set<int> s = {10, 20, 30};
auto it = s.find(20);
if(it != s.end()) {
    s.erase(it);
}

for(auto x : s) {
    cout << x << " ";
}
```

Takes constant time.

### Output

```cpp
10 30
```

## Method 3 - Erase range

```cpp
set<int> s = {10, 20, 30, 40, 50};
auto it1 = s.find(20);
auto it2 = s.find(40);
s.erase(it1, it2); // Removes [20, 40)

for(auto x : s) {
    cout << x << " ";
}
```

### Output

```cpp
10 40 50
```

## Return value

```cpp
set<int> s = {10, 20, 30};
int removed = s.erase(20); // Returns if the element is removed or not
cout << removed; // 1 if removed, 0 if not found
```

### Output

```cpp
1
```

## Note

- Erase by value returns count of removed elements (0 or 1)
- Erase by iterator returns void
- Time complexity: O(log n)
