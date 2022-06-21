## Description 
We can swap contents of 2 stack using swap() method.

## Swap 2 stack's content

```cpp
stack<int> name;
stack<int> name2;
// Inserting example data 1,2,3 in name (size:3)
name.push(1); name.push(2); name.push(3);
// Inserting example data 12,13 in name2 (size:2)
name2.push(12); name2.push(13);

// Swap 2 stacks
name.swap(name2);

cout << name.size() << " " << name2.size() ;
```

### Output
```cpp
2 3
```