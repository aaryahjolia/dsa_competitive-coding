## Description

Pair elements can be accessed using `.first` and `.second` member variables.

## Accessing Elements

### Method 1 - Direct access using dot notation

```cpp
pair<int, string> p(1, "Hello");

// Accessing first element
cout << p.first;   // Output: 1

// Accessing second element
cout << p.second;  // Output: Hello
```

### Output

```cpp
1
Hello
```

### Method 2 - Modifying pair elements

```cpp
pair<int, int> p(10, 20);

// Modifying first element
p.first = 100;

// Modifying second element
p.second = 200;

cout << p.first << " " << p.second;
```

### Output

```cpp
100 200
```

### Method 3 - Accessing nested pairs

```cpp
pair<int, pair<int, int>> p(1, make_pair(2, 3));

// Accessing outer pair's first element
cout << p.first;          // Output: 1

// Accessing inner pair's first element
cout << p.second.first;   // Output: 2

// Accessing inner pair's second element
cout << p.second.second;  // Output: 3
```

### Output

```cpp
1
2
3
```
