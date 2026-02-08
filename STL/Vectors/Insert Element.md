## Description

Element can be inserted from last using push_back method.

## Method 1 (push_back)

```cpp
vector<int> first = {1,2};
// Pushing (adding) element 4 and then 6
first.push_back(4);
first.push_back(6);
```

### Vector now contains

```cpp
1 2 4 6
```

## Method 2 (emplace_back)

```cpp
vector<int> first = {1,2};
// Pushing (adding) element 4 and then 6
first.emplace_back(4);
first.emplace_back(6);
```

### Vector now contains

```cpp
1 2 4 6
```

- The main difference between push_back and emplace_back is that emplace_back is faster than push_back because it constructs the element in the container storage directly, as opposed to push_back which either creates a temporary object or copies/moves an existing object into the container.

## Syntax for inserting in push_back and emplace_back

```cpp
vector<pair<int, int>> v;
// Pushing (adding) element 4 and then 6 via both methods
v.push_back({4, 6});
v.emplace_back(4, 6);
```

- We don't need to use brackets while using emplace_back because it automatically assumes the values as a pair and stores them.

## Method 3 (Insert Function)

### Insert at the begining

```cpp
vector<int> v = {1,2,3,4,5};
v.insert(v.begin(),10); // Inserting 10 at the begining
```

### Vector now contains

```cpp
10 1 2 3 4 5
```
