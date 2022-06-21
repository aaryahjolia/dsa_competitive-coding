## Description 
You can know whether the stack is empty or not using empty() method. We use this method for printing all the element of stack (See last code of this file).

## To Know whether stack is empty or not

```cpp
stack<int> name;
// Checking if stack is empty or not 
// (Returns 1 if empty, else 0)
cout << name.empty() ;
```

### Output
```cpp
1
```

### We use this method to iterate whole stack (You need to pop elements, so stack will be empty at last)

```cpp
// Iterating stack by printing and removing elements
stack<int> name;
// Example data
name.push(2);
name.push(4);
name.push(6);

// Iterate stack, Print all elements
while(!name.empty()){
    cout << name.top() << endl;
    name.pop();
}
```

### Output
```cpp
6
4
2
```