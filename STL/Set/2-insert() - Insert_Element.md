## Description

The `insert()` function adds an element to the set. If the element already exists, it is not inserted (duplicates ignored).

## Method - insert()

```cpp
set<int> s;
s.insert(10);
s.insert(5);
s.insert(20);
s.insert(10); // Ignored - duplicate
```

### Set now contains (sorted order)

```cpp
5 10 20
```

## Example - Inserting multiple elements

```cpp
set<int> s = {10, 20};
s.insert(5);
s.insert(30);
s.insert(15);

for(auto x : s) {
    cout << x << " ";
}
```

### Output

```cpp
5 10 15 20 30
```

## Return value

```cpp
set<int> s = {10, 20};
auto result = s.insert(15);
// result.first = iterator to inserted element
// result.second = true if inserted, false if already exists

cout << *(result.first) << " " << result.second; // 15 1
```

### Output

```cpp
15 1
```

## Note

- Duplicates are automatically ignored
- Elements always remain sorted
- Time complexity: O(log n)
