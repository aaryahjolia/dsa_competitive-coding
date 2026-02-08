## Description

Additional useful operations for Set manipulation and traversal.

## clear() - Remove all elements

```cpp
set<int> s = {10, 20, 30};
s.clear();
cout << s.size(); // 0
```

### Output

```cpp
0
```

## Iteration using iterators

```cpp
set<int> s = {10, 20, 30};

for(auto it = s.begin(); it != s.end(); it++) {
    cout << *it << " ";
}
```

### Output

```cpp
10 20 30
```

## lower_bound() - First element >= value

```cpp
set<int> s = {10, 20, 30, 40};
auto it = s.lower_bound(25);
cout << *it; // 30 (first element >= 25)
```

### Output

```cpp
30
```

## upper_bound() - First element > value

```cpp
set<int> s = {10, 20, 30, 40};
auto it = s.upper_bound(20);
cout << *it; // 30 (first element > 20)
```

### Output

```cpp
30
```

## Reverse iteration

```cpp
set<int> s = {10, 20, 30};

for(auto it = s.rbegin(); it != s.rend(); it++) {
    cout << *it << " ";
}
```

### Output

```cpp
30 20 10
```

## swap() - Swap two sets

```cpp
set<int> s1 = {10, 20};
set<int> s2 = {30, 40};
s1.swap(s2);

for(auto x : s1) cout << x << " "; // 30 40
```

### Output

```cpp
30 40
```

## Note

- `lower_bound()` and `upper_bound()` return iterators
- Always check iterator against `s.end()` before dereferencing
- `clear()` time complexity: O(n)
- Most other operations: O(log n) or O(1)
