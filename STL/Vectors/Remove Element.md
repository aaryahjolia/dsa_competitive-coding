## Description

Element can be removed from a vector using various methods.

## Method 1 - pop_back()

```cpp
vector<int> first = {1,2,4,6};
// popping (removing) elements
first.pop_back(); // 6 removed
first.pop_back(); // 4 removed
```

### Vector now contains

```cpp
1 2
```

## Method 2 - erase()

```cpp
// 10 20 30 40 50
v.erase(v.begin()+2); // Erases element at index 2
// 10 20 40 50
```

```cpp
// 10 20 30 40 50
v.erase(v.begin()+2,v.begin()+4); // Erases elements from index 2 to 4 but not including index 4
//  [start,end)
// 10 20 50
```
