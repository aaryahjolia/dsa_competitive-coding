## Description

Pairs can be compared using relational operators. Comparison is done lexicographically - first elements are compared first, and if they are equal, second elements are compared.

## Comparison Operators

### Operator 1 - Equality (==)

```cpp
pair<int, int> p1(10, 20);
pair<int, int> p2(10, 20);
pair<int, int> p3(10, 30);

cout << (p1 == p2);  // true (1)
cout << (p1 == p3);  // false (0)
```

### Output

```cpp
1
0
```

### Operator 2 - Inequality (!=)

```cpp
pair<int, int> p1(10, 20);
pair<int, int> p2(10, 30);

cout << (p1 != p2);  // true (1)
```

### Output

```cpp
1
```

### Operator 3 - Less than (<)

```cpp
pair<int, int> p1(10, 20);
pair<int, int> p2(10, 30);
pair<int, int> p3(5, 40);

// Compares first elements first
cout << (p3 < p1);   // true (5 < 10)

// If first elements are equal, compares second
cout << (p1 < p2);   // true (10 == 10, but 20 < 30)
```

### Output

```cpp
1
1
```

### Operator 4 - Greater than (>)

```cpp
pair<int, int> p1(10, 20);
pair<int, int> p2(5, 30);

cout << (p1 > p2);   // true (10 > 5)
```

### Output

```cpp
1
```

### Operator 5 - Sorting pairs using comparison

```cpp
vector<pair<int, int>> v = {{30, 40}, {10, 20}, {10, 15}, {20, 35}};

// Sort in ascending order
sort(v.begin(), v.end());

// Print sorted pairs
for(auto p : v) {
    cout << p.first << " " << p.second << endl;
}
```

### Output

```cpp
10 15
10 20
20 35
30 40
```

### Operator 6 - Custom comparison for sorting

```cpp
vector<pair<int, int>> v = {{30, 40}, {10, 20}, {10, 15}, {20, 35}};

// Sort by second element in descending order
sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {
    return a.second > b.second;
});

// Print sorted pairs
for(auto p : v) {
    cout << p.first << " " << p.second << endl;
}
```

### Output

```cpp
30 40
20 35
10 20
10 15
```
