## Description

Operations unique to multiset or behave differently than set.

## count() - Returns frequency

```cpp
multiset<int> ms = {10, 20, 10, 30, 10};
cout << ms.count(10); // 3
cout << ms.count(20); // 1
cout << ms.count(50); // 0
```

### Output

```cpp
3
1
0
```

## equal_range() - Get range of equal elements

```cpp
multiset<int> ms = {10, 20, 20, 20, 30};

auto range = ms.equal_range(20);
// range.first = iterator to first 20
// range.second = iterator after last 20

for(auto it = range.first; it != range.second; it++) {
    cout << *it << " ";
}
```

### Output

```cpp
20 20 20
```

## Erase all occurrences

```cpp
multiset<int> ms = {10, 10, 20, 10};
ms.erase(10); // Removes ALL 10's

for(auto x : ms) {
    cout << x << " ";
}
```

### Output

```cpp
20
```

## Erase single occurrence

```cpp
multiset<int> ms = {10, 10, 20, 10};
auto it = ms.find(10);
ms.erase(it); // Removes only one 10

for(auto x : ms) {
    cout << x << " ";
}
```

### Output

```cpp
10 10 20
```

## Use case - Frequency counting

```cpp
multiset<int> ms = {1, 2, 2, 3, 3, 3};

for(int val : {1, 2, 3, 4}) {
    cout << val << ": " << ms.count(val) << endl;
}
```

### Output

```cpp
1: 1
2: 2
3: 3
4: 0
```
