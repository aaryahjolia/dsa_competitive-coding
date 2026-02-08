## Description

Pair is a simple container in C++ STL that stores two heterogeneous objects as a single unit. It is defined in the `<utility>` header (included in `<bits/stdc++.h>`).

## Different Ways to Initialize a Pair

### Note: Pairs need an additional include

```cpp
#include<utility>
```

But everything will be included when we include `<bits/stdc++.h>`, so no need to import utility if we import all modules.

### Supported Datatypes:

Any valid C++ datatype including: char, int, float, double, long, string, and even other containers like vector, pair, etc.

### 1. Default initialization (garbage values)

```cpp
// Creates a pair of int and int with garbage values
pair<int, int> p1;
```

### 2. Direct initialization with values

```cpp
// Creates a pair with first = 10 and second = 20
pair<int, int> p2(10, 20);
```

### 3. Using make_pair() function

```cpp
// Creates a pair using make_pair function
pair<int, int> p3 = make_pair(10, 20);
```

### 4. Different datatypes in pair

```cpp
// Pair with int and string
pair<int, string> p4(1, "Hello");

// Pair with char and double
pair<char, double> p5('A', 3.14);
```

### 5. Copy initialization

```cpp
pair<int, int> p6(10, 20);
// Creates a copy of p6
pair<int, int> p7(p6);
// or
pair<int, int> p8 = p6;
```

### 6. Nested pairs (Pair of pairs)

```cpp
// Pair containing another pair
pair<int, pair<int, int>> p9(1, make_pair(2, 3));
// or
pair<int, pair<int, int>> p10 = {1, {2, 3}};
```
