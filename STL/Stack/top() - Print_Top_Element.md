## Description 
Stack's top element can be printed/displayed through top() method.

## Display Top Element of stack 

```cpp
stack<int> name;
// Inserting element for example purpose
name.push(10);
// Printing value(s)
cout << "Top Element : " << name.top() ;
```

### Output
```cpp
Top Element : 10
```

### You can also do some operations on top element

```cpp
// In above 'name' stack : 
name.top()-=3;
cout << name.top() ;
```

### Output
```cpp
7
```