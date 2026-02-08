## Description

Additional operations for Map manipulation and queries.

## size() - Number of key-value pairs

```cpp
map<int, string> m = {{1, "One"}, {2, "Two"}};
cout << m.size();
```

### Output

```cpp
2
```

## empty() - Check if map is empty

```cpp
map<int, string> m;
cout << m.empty(); // 1

m[1] = "One";
cout << m.empty(); // 0
```

### Output

```cpp
1
0
```

## clear() - Remove all elements

```cpp
map<int, string> m = {{1, "One"}, {2, "Two"}};
m.clear();
cout << m.size();
```

### Output

```cpp
0
```

## lower_bound() - First element >= key

```cpp
map<int, string> m = {{10, "Ten"}, {20, "Twenty"}, {30, "Thirty"}};

auto it = m.lower_bound(15);
cout << it->first << ": " << it->second;
```

### Output

```cpp
20: Twenty
```

## upper_bound() - First element > key

```cpp
map<int, string> m = {{10, "Ten"}, {20, "Twenty"}, {30, "Thirty"}};

auto it = m.upper_bound(20);
cout << it->first << ": " << it->second;
```

### Output

```cpp
30: Thirty
```

## swap() - Swap two maps

```cpp
map<int, string> m1 = {{1, "One"}};
map<int, string> m2 = {{2, "Two"}};

m1.swap(m2);

cout << m1[2]; // Two
```

### Output

```cpp
Two
```

## Reverse iteration

```cpp
map<int, string> m = {{1, "One"}, {2, "Two"}, {3, "Three"}};

for(auto it = m.rbegin(); it != m.rend(); it++) {
    cout << it->first << ": " << it->second << endl;
}
```

### Output

```cpp
3: Three
2: Two
1: One
```

## count() - Check if key exists

```cpp
map<int, string> m = {{1, "One"}, {2, "Two"}};

cout << m.count(1); // 1
cout << m.count(5); // 0
```

### Output

```cpp
1
0
```

## Note

- `lower_bound()` and `upper_bound()` useful for range queries
- All operations return iterators (check against `m.end()`)
- `size()`, `empty()` are O(1)
- `clear()` is O(n)
- Most others are O(log n)
