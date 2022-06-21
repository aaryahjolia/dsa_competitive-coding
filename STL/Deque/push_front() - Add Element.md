## Description 
Element can be inserted from front using push_front method or emplace_front method.

## Method
```cpp
deque<int> first = {1,2};
// Pushing (adding) element 4 and then 6 
first.push_front(4);
first.emplace_front(6);
```

### Deque now contains
```cpp
6 4 1 2
```