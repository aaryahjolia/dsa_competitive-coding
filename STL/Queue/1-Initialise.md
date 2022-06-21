## Description 
Queues are like array only but it works on principle of FIFO (First In First Out) so the element that is first inserted will be deleted first and no other elements from middle or last.

## Way(s) to Initialise a queue  

### Note : Queue need an additional include.
```cpp
#include<queue>
```
But Everything will be included when we include <bits/stdc++.h>, so no need to import queue if we import all modules.

### Supported Datatypes : 
int, char, string

### 1. 0 sized queue  

```cpp
// Creates a zero sized queue of int
queue<int> name;
```

### 2. Creating copy of queue

```cpp
// Directly copy whole queue from name
queue<int> name2(name);
// We can also copy elements from deque also by providing it's variable name as argument
```