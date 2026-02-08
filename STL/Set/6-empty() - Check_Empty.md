## Description

The `empty()` function checks if the set is empty. Returns `true` if empty, `false` otherwise.

## Method - empty()

```cpp
set<int> s;
cout << s.empty(); // 1 (true)

s.insert(10);
cout << s.empty(); // 0 (false)
```

### Output

```cpp
1
0
```

## Example - Safe iteration

```cpp
set<int> s = {10, 20, 30};

while(!s.empty()) {
    cout << *s.begin() << " ";
    s.erase(s.begin());
}
```

### Output

```cpp
10 20 30
```

## Note

- Returns 1 (true) if empty, 0 (false) otherwise
- Time complexity: O(1)
