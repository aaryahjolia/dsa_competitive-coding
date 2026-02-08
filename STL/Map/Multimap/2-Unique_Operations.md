## Description

Operations unique to multimap or behave differently than map.

## count() - Returns number of values for key

```cpp
multimap<int, string> mm = {{1, "One"}, {1, "First"}, {2, "Two"}};

cout << mm.count(1); // 2
cout << mm.count(2); // 1
cout << mm.count(5); // 0
```

### Output

```cpp
2
1
0
```

## equal_range() - Get all values for a key

```cpp
multimap<int, string> mm = {{1, "One"}, {1, "First"}, {1, "Uno"}};

auto range = mm.equal_range(1);

for(auto it = range.first; it != range.second; it++) {
    cout << it->second << " ";
}
```

### Output

```cpp
One First Uno
```

## insert() always adds

```cpp
multimap<int, string> mm;
mm.insert({1, "One"});
mm.insert({1, "First"}); // Both stored

for(auto p : mm) {
    cout << p.first << ": " << p.second << endl;
}
```

### Output

```cpp
1: One
1: First
```

## Erase all values for a key

```cpp
multimap<int, string> mm = {{1, "One"}, {1, "First"}, {2, "Two"}};
mm.erase(1); // Removes ALL values with key 1

for(auto p : mm) {
    cout << p.first << ": " << p.second << endl;
}
```

### Output

```cpp
2: Two
```

## Erase single value by iterator

```cpp
multimap<int, string> mm = {{1, "One"}, {1, "First"}};
auto it = mm.find(1);
mm.erase(it); // Removes only one value

for(auto p : mm) {
    cout << p.first << ": " << p.second << endl;
}
```

### Output

```cpp
1: First
```

## Use case - One-to-many relationship

```cpp
multimap<string, string> contacts;
contacts.insert({"Alice", "111-1111"});
contacts.insert({"Alice", "222-2222"});
contacts.insert({"Bob", "333-3333"});

auto range = contacts.equal_range("Alice");
cout << "Alice's numbers: ";
for(auto it = range.first; it != range.second; it++) {
    cout << it->second << " ";
}
```

### Output

```cpp
Alice's numbers: 111-1111 222-2222
```

## Note

- Cannot use `operator[]` with multimap
- `count()` returns actual count, not just 0 or 1
- `equal_range()` essential for getting all values
