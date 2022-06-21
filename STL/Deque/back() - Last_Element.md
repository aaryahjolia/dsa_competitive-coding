## Description 
Deque's last element can be printed/displayed through back() method. The last element means the one which is inserted last.

## Display last Element of deque 

```cpp
deque<int> name;
// Inserting element for example purpose
name.push_back(10);
name.push_back(12);
// Printing value(s) of last element
cout << "Last Element : " << name.back() ;
```

### Output
```cpp
Last Element : 12
```

### You can also do some operations on Last element

```cpp 
name.back()-=3;
cout << name.back() ;
```

### Output
```cpp
9
```