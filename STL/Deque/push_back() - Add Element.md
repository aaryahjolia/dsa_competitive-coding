## Description 
Element can be inserted from last using push_back method or emplace_back method.

## Method
```cpp
deque<int> first = {1,2};
// Pushing (adding) element 4 and then 6 
first.push_back(4);
first.emplace_back(6);
```

### Deque now contains
```cpp
1 2 4 6
```