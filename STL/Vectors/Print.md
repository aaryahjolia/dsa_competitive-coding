## Description

Vector can be printed/displayed through a variety of methods.

## Method 1 - For Loop till total size of vector

```cpp
vector<int> first = {1,2,3,4,5,6};
// Printing all values (Like an array)
for(int i=0;i<first.size();i++){
    cout << first[i] << " ";
}
```

### Output

```cpp
1 2 3 4 5 6
```

## Method 2 - For Loop from start to end of vector using iterator

```cpp
vector<int> first = {1,2,3,4,5,6};
// Printing all values using iterator
for(auto it=first.begin();it!=first.end();it++){
    cout << *(it) << " ";
}
```

### Output

```cpp
1 2 3 4 5 6
```

- Iterator is a pointer to the memory location of the element.
- That's why we write `*it` to access the value at that memory location.

### Another method with Iterators

```cpp
vector<int> v = {1,2,3,4,5,6};
vector<int>::iterator it = v.begin();
while(it!=v.end()){
    cout << *(it) << " ";
    it++;
}
```

### Output

```cpp
1 2 3 4 5 6
```

- `vector<int>::iterator it = v.end();` is used to get the iterator to the end of the vector. Remember, it is pointing to the memory location _after_ the last element.

- `v.back()` is used to get the last element of the vector.
