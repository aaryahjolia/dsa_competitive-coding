## Description 
Queue's last element can be printed/displayed through back() method. The last element means the one which is inserted last.

## Display last Element of queue 

```cpp
queue<int> name;
// Inserting element for example purpose
name.push(10);
name.push(12);
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