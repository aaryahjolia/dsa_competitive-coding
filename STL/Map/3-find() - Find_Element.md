## Description

The `find()` function searches for a key in the map. Returns iterator to the key-value pair if found, otherwise returns `m.end()`.

## Method - find()

```cpp
map<int, string> m = {{1, "One"}, {2, "Two"}, {3, "Three"}};

auto it = m.find(2);
if(it != m.end()) {
    cout << it->first << ": " << it->second;
}
```

### Output

```cpp
2: Two
```

## Example - Key not found

```cpp
map<int, string> m = {{1, "One"}, {2, "Two"}};

auto it = m.find(5);
if(it != m.end()) {
    cout << "Found";
} else {
    cout << "Not found";
}
```

### Output

```cpp
Not found
```

## Using count() for existence check

```cpp
map<int, string> m = {{1, "One"}, {2, "Two"}};

if(m.count(2)) {
    cout << "Key 2 exists: " << m[2];
}
```

### Output

```cpp
Key 2 exists: Two
```

## Iterating through map

```cpp
map<int, string> m = {{1, "One"}, {2, "Two"}, {3, "Three"}};

for(auto it = m.begin(); it != m.end(); it++) {
    cout << it->first << ": " << it->second << endl;
}
```

### Output

```cpp
1: One
2: Two
3: Three
```

## Range-based for loop

```cpp
map<int, string> m = {{1, "One"}, {2, "Two"}};

for(auto p : m) {
    cout << p.first << ": " << p.second << endl;
}
```

### Output

```cpp
1: One
2: Two
```

## Note

- Returns iterator to pair, not just value
- Must check against `m.end()` before dereferencing
- `count()` returns 1 or 0 (can be used for existence check)
- Time complexity: O(log n)
