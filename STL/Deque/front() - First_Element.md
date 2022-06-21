## Description 
Deque's first element can be printed/displayed through front() method.

## Display First Element of deque 

```cpp
deque<int> name;
// Inserting element for example purpose
name.push_back(10);
name.push_back(12);
// Printing value(s) of last element
cout << "First Element : " << name.front() ;
```

### Output
```cpp
First Element : 10
```

### You can also do some operations on Last element

```cpp 
name.front()-=3;
cout << name.front() ;
```

### Output
```cpp
7
```