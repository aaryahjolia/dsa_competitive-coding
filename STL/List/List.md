# List

List is a container in C++ STL that stores elements in a linear manner. It is defined in the `<list>` header (included in `<bits/stdc++.h>`).

```cpp
list<int> ls;
```

##### The only difference between list and vector is that list is implemented as a doubly linked list and vector is implemented as a dynamic array.

Additional functionality other than vector includes inserting the element at the begining of the list.

```cpp
list<int> ls;
ls.push_front(1); // Inserting 1 at the begining
ls.emplace_front(2); // Inserting 2 at the begining
```

Rest of the functions like push_back, emplace_back, pop_front, pop_back, etc. are same as vector.
