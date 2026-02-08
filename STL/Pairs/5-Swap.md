## Description

The `swap()` function exchanges the contents of two pairs. Both pairs must be of the same type.

## Using swap() Function

### Method 1 - Using member function

```cpp
pair<int, int> p1(10, 20);
pair<int, int> p2(30, 40);

cout << "Before swap:" << endl;
cout << "p1: " << p1.first << " " << p1.second << endl;
cout << "p2: " << p2.first << " " << p2.second << endl;

// Swap using member function
p1.swap(p2);

cout << "After swap:" << endl;
cout << "p1: " << p1.first << " " << p1.second << endl;
cout << "p2: " << p2.first << " " << p2.second << endl;
```

### Output

```cpp
Before swap:
p1: 10 20
p2: 30 40
After swap:
p1: 30 40
p2: 10 20
```

### Method 2 - Using std::swap()

```cpp
pair<int, string> p1(1, "Hello");
pair<int, string> p2(2, "World");

// Swap using std::swap
swap(p1, p2);

cout << "p1: " << p1.first << " " << p1.second << endl;
cout << "p2: " << p2.first << " " << p2.second << endl;
```

### Output

```cpp
p1: 2 World
p2: 1 Hello
```

### Method 3 - Swapping in algorithms

```cpp
vector<pair<int, int>> v = {{10, 20}, {30, 40}, {50, 60}};

// Swap first and last elements
swap(v[0], v[2]);

// Print after swap
for(auto p : v) {
    cout << p.first << " " << p.second << endl;
}
```

### Output

```cpp
50 60
30 40
10 20
```
