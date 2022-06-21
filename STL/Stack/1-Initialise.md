## Description 
Stack are container which stores elements in bottom-top movement and you can only remove the top most (Last element). So, it uses LIFO structure (Last In, First Out).

## Different Ways to Initialise a stack  

### Note : Stack need an additional include.
```cpp
#include<stack>
```
But Everything will be included when we include <bits/stdc++.h>, so no need to import vector if we import all modules.

### Supported Datatypes : 
int, char, string

### 1. 0 sized stack  

```cpp
// Creates a zero sized stack of int
stack<int> name;
```

### 2. Creating copy of stack

```cpp
// Directly copy whole stack from name
stack<int> name2(name);
// We can also copy elements from deque also by providing it's variable name as argument
```