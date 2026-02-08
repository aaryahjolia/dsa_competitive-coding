## Description

The `size()` function returns the number of elements in the set.

## Method - size()

```cpp
set<int> s = {10, 20, 30};
cout << s.size();
```

### Output

```cpp
3
```

## Example - After insertion and deletion

```cpp
set<int> s = {10, 20, 30};
cout << "Initial: " << s.size() << endl;

s.insert(40);
cout << "After insert: " << s.size() << endl;

s.erase(20);
cout << "After erase: " << s.size();
```

### Output

```cpp
Initial: 3
After insert: 4
After erase: 3
```

## Note

- Returns 0 for empty set
- Time complexity: O(1)
