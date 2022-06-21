## Description 
Deque can be printed/displayed through 2 methods.

## Method 1 - For Loop till total size of deque  

```cpp
deque<int> first = {1,2,3,4,5,6};
// Printing all values (Like an array)
for(int i=0;i<first.size();i++){
    cout << first[i] << " ";
}
```

### Output
```cpp
1 2 3 4 5 6
```

## Method 2 - For Loop from start to end of deque

```cpp
deque<int> first = {1,2,3,4,5,6};
// Printing all values using iterator
for(auto it=name.begin();it!=first.end();it++){
    cout << *it << " ";
}
```

### Output
```cpp
1 2 3 4 5 6
```