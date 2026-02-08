## Description

The `erase()` function removes elements from the map by key or iterator.

## Method 1 - Erase by key

```cpp
map<int, string> m = {{1, "One"}, {2, "Two"}, {3, "Three"}};
m.erase(2); // Removes key 2

for(auto p : m) {
    cout << p.first << ": " << p.second << endl;
}
```

### Output

```cpp
1: One
3: Three
```

## Method 2 - Erase by iterator

```cpp
map<int, string> m = {{1, "One"}, {2, "Two"}, {3, "Three"}};

auto it = m.find(2);
if(it != m.end()) {
    m.erase(it);
}

for(auto p : m) {
    cout << p.first << ": " << p.second << endl;
}
```

### Output

```cpp
1: One
3: Three
```

## Method 3 - Erase range

```cpp
map<int, string> m = {{1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}};

auto it1 = m.find(2);
auto it2 = m.find(4);
m.erase(it1, it2); // Removes [2, 4)

for(auto p : m) {
    cout << p.first << ": " << p.second << endl;
}
```

### Output

```cpp
1: One
4: Four
```

## Return value

```cpp
map<int, string> m = {{1, "One"}, {2, "Two"}};
int removed = m.erase(2); // Returns 1 if removed, 0 if not found
cout << removed;
```

### Output

```cpp
1
```

## Note

- Erase by key returns 1 if removed, 0 if key not found
- Erase by iterator returns void
- Time complexity: O(log n)
