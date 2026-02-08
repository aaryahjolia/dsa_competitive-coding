## Description

`make_pair()` is a utility function that creates a pair object without explicitly specifying template arguments. It automatically deduces the types from the arguments.

## Using make_pair() Function

### Method 1 - Basic usage

```cpp
// Instead of writing: pair<int, int> p(10, 20);
// Use make_pair:
auto p = make_pair(10, 20);

cout << p.first << " " << p.second;
```

### Output

```cpp
10 20
```

### Method 2 - With different datatypes

```cpp
// Automatically deduces types as int and string
auto p1 = make_pair(1, "Hello");

// Automatically deduces types as char and double
auto p2 = make_pair('A', 3.14);

cout << p1.first << " " << p1.second << endl;
cout << p2.first << " " << p2.second;
```

### Output

```cpp
1 Hello
A 3.14
```

### Method 3 - Creating nested pairs

```cpp
// Create nested pair easily
auto p = make_pair(1, make_pair(2, 3));

cout << p.first << " " << p.second.first << " " << p.second.second;
```

### Output

```cpp
1 2 3
```

### Method 4 - Passing to functions

```cpp
// Function accepting pair
void printPair(pair<int, int> p) {
    cout << p.first << " " << p.second;
}

// Call with make_pair
printPair(make_pair(10, 20));
```

### Output

```cpp
10 20
```

### Method 5 - Inserting into containers

```cpp
vector<pair<int, string>> v;

// Insert using make_pair
v.push_back(make_pair(1, "One"));
v.push_back(make_pair(2, "Two"));
v.push_back(make_pair(3, "Three"));

// Print all pairs
for(auto p : v) {
    cout << p.first << " " << p.second << endl;
}
```

### Output

```cpp
1 One
2 Two
3 Three
```
