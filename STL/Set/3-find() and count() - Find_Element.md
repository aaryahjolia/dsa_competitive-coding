## Description

The `find()` function searches for an element in the set. Returns an iterator to the element if found, otherwise returns `s.end()`.

## Method - find()

```cpp
set<int> s = {10, 20, 30, 40};

auto it = s.find(20);
if(it != s.end()) {
    cout << "Found: " << *it;
} else {
    cout << "Not found";
}
```

### Output

```cpp
Found: 20
```

## Example - Element not found

```cpp
set<int> s = {10, 20, 30};

auto it = s.find(50);
if(it != s.end()) {
    cout << "Found";
} else {
    cout << "Not found";
}
```

### Output

```cpp
Not found
```

## Example - Using count() instead

```cpp
set<int> s = {10, 20, 30};

if(s.count(20)) {
    cout << "Exists";
} else {
    cout << "Does not exist";
}
```

### Output

```cpp
Exists
```

## Note

- Returns iterator, not the value
- Must check against `s.end()` before dereferencing
- `count()` returns 1 or 0 (can be used for existence check)
- Time complexity: O(log n)
