## Description 
Queue's First element can be printed/displayed through front() method. The first element means the one which was inserted first.

## Display first Element of queue 

```cpp
queue<int> name;
// Inserting element for example purpose
name.push(10);
name.push(12);
// Printing value(s) of first element
cout << "First Element : " << name.front() ;
```

### Output
```cpp
First Element : 10
```

### You can also do some operations on First element

```cpp 
name.front()-=3;
cout << name.front() ;
```

### Output
```cpp
7
```