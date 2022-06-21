## Description 
You can know whether the queue is empty or not using empty() method. We use this method for printing all the element of queue with loop (See last code of this file).

## To Know whether queue is empty or not

```cpp
queue<int> name;
// Checking if queue is empty or not 
// (Returns 1 if empty, else 0)
cout << name.empty() ;
```

### Output
```cpp
1
```

### We use this method to iterate whole queue (You need to pop elements, so queue will be empty at last)

```cpp
// Iterating queue by printing front element and removing elements
queue<int> name;
// Example data
name.push(2);
name.push(4);
name.push(6);

// Iterate queue, Print all elements
while(!name.empty()){
    cout << name.front() << endl;
    name.pop();
}
```

### Output
```cpp
2
4
6
```