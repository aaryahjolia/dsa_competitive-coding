## Description 
Deque also known as double-ended queues, are indexed sequence containers part of the STL. The benefit of a deque is that it has the ability to expand and contract at both the ends (front and back)

## Different Ways to Initialise a deque  

### Note : deque need an additional include.
```cpp
#include<deque>
```
But Everything will be included when we include <bits/stdc++.h>, so no need to import vector if we import all modules.

### Supported Datatypes : 
int, char, string , etc.

### 1. 0 sized deque  

```cpp
// Creates a zero sized deque of int
deque<int> name;
```
 
### 2. n-sized deque

```cpp
// Creates a n sized vector of int
deque<int> name1(n);
```

### 3. Creating copy of deque

```cpp
// 1st way - Creates a copy of deque name1 by iterating
deque<int> name3(name1.begin(),name1.end());

// 2nd way - Directly copying whole deque from name3
deque<int> name4(name3);
```

### 4. n-sized deque with default value m

```cpp
// Creates a n sized deque of int with default value m
deque<int> name5(n,m);
```

### 5. Deque with pre defined values

```cpp
// Creates a deque with user values
deque<int> name6 = {1,2,3,4,5,6};
```