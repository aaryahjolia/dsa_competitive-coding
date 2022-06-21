## Description 
Vector are also called as dynamic arrays. It work like arrays and it is part of containers.

## Different Ways to Initialise a vector  

### Note : Vectors need an additional include.
```cpp
#include<vector>
```
But Everything will be included when we include <bits/stdc++.h>, so no need to import vector if we import all modules.

### Supported Datatypes : 
char, uchar, short, ushort, int, uint, float, long, and ulong

### 1. 0 sized vector  

```cpp
// Creates a zero sized vector of int
vector<int> name;
```
 
### 2. n-sized vector

```cpp
// Creates a n sized vector of int
vector<int> name1(n);
```

### 3. Creating copy of vector

```cpp
// 1st way - Creates a copy of vector name1 by iterating
vector<int> name3(name1.begin(),name1.end());

// 2nd way - Directly copying whole vector from name3
vector<int> name4(name3);
```

### 4. n-sized vector with default value m

```cpp
// Creates a n sized vector of int with default value m
vector<int> name5(n,m);
```

### 5. Vector with pre defined values

```cpp
// Creates a vector with user values
vector<int> name6 = {1,2,3,4,5,6};
```