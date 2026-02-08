## Description

Map supports insertion and access using `insert()`, `operator[]`, and `emplace()`.

## Method 1 - Using operator[]

```cpp
map<int, string> m;
m[1] = "One";
m[2] = "Two";
m[3] = "Three";

cout << m[1]; // One
```

### Output

```cpp
One
```

## Method 2 - Using insert()

```cpp
map<int, string> m;
m.insert({1, "One"});
m.insert({2, "Two"});
m.insert(make_pair(3, "Three"));

for(auto p : m) {
    cout << p.first << ": " << p.second << endl;
}
```

### Output

```cpp
1: One
2: Two
3: Three
```

## Method 3 - Using emplace()

```cpp
map<int, string> m;
m.emplace(1, "One");
m.emplace(2, "Two");

cout << m[1]; // One
```

### Output

```cpp
One
```

## insert() return value

```cpp
map<int, string> m = {{1, "One"}};
auto result = m.insert({1, "Updated"});
// result.first = iterator to element
// result.second = false (key already exists)

cout << result.second; // 0 (false)
cout << m[1]; // One (not updated)
```

### Output

```cpp
0
One
```

## Difference: [] vs insert()

```cpp
map<int, string> m;

// [] creates key if not exists
m[5] = "Five";

// insert() does not update if key exists
m.insert({5, "Updated"}); // Ignored
cout << m[5]; // Five

// [] updates if key exists
m[5] = "Updated";
cout << m[5]; // Updated
```

### Output

```cpp
Five
Updated
```

## Access using at()

```cpp
map<int, string> m = {{1, "One"}, {2, "Two"}};
cout << m.at(1); // One
// m.at(5); // Throws exception - key not found
```

### Output

```cpp
One
```

## Note

- `[]` creates key with default value if not found
- `insert()` ignores if key already exists
- `at()` throws exception if key not found
- `emplace()` constructs in place (more efficient)
- Time complexity: O(log n)
