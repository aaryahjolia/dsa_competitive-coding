# Max Element and Min Element

## Description

`max_element()` and `min_element()` find the largest and smallest elements in a range. They return **iterators** to the elements.

### Include

```cpp
#include<algorithm>
```

### Time Complexity

O(n) where n is the number of elements

## max_element()

### Basic usage

```cpp
vector<int> v = {5, 2, 8, 1, 9};
auto it = max_element(v.begin(), v.end());

cout << "Max: " << *it;
cout << " at index: " << (it - v.begin());
```

### Output

```cpp
Max: 9 at index: 4
```

## min_element()

### Basic usage

```cpp
vector<int> v = {5, 2, 8, 1, 9};
auto it = min_element(v.begin(), v.end());

cout << "Min: " << *it;
cout << " at index: " << (it - v.begin());
```

### Output

```cpp
Min: 1 at index: 3
```

## With arrays

```cpp
int arr[] = {5, 2, 8, 1, 9};
int n = 5;

int max_val = *max_element(arr, arr + n);
int min_val = *min_element(arr, arr + n);

cout << "Max: " << max_val << ", Min: " << min_val;
```

### Output

```cpp
Max: 9, Min: 1
```

## Custom comparator

```cpp
vector<int> v = {-5, 2, -8, 1, -9};

// Max by absolute value
auto it = max_element(v.begin(), v.end(), [](int a, int b) {
    return abs(a) < abs(b);
});

cout << "Max absolute: " << *it;
```

### Output

```cpp
Max absolute: -9
```

## With pairs - max by second element

```cpp
vector<pair<int, int>> v = {{1, 50}, {2, 30}, {3, 70}};

auto it = max_element(v.begin(), v.end(), [](auto a, auto b) {
    return a.second < b.second;
});

cout << "Max second: " << it->second;
```

### Output

```cpp
Max second: 70
```

## Finding both min and max

```cpp
vector<int> v = {5, 2, 8, 1, 9};

auto min_it = min_element(v.begin(), v.end());
auto max_it = max_element(v.begin(), v.end());

cout << "Min: " << *min_it << ", Max: " << *max_it;
cout << "\nRange: " << (*max_it - *min_it);
```

### Output

```cpp
Min: 1, Max: 9
Range: 8
```

## Partial range

```cpp
vector<int> v = {5, 2, 8, 1, 9};

// Max in first 3 elements
auto it = max_element(v.begin(), v.begin() + 3);
cout << *it;
```

### Output

```cpp
8
```

## Common Use Cases

### Find maximum in subarray

```cpp
vector<int> v = {1, 5, 3, 9, 2};
int l = 1, r = 3; // Range [l, r]

int max_val = *max_element(v.begin() + l, v.begin() + r + 1);
cout << max_val; // 9
```

### Count occurrences of max element

```cpp
vector<int> v = {5, 9, 2, 9, 1};
int max_val = *max_element(v.begin(), v.end());
int count = std::count(v.begin(), v.end(), max_val);

cout << "Max " << max_val << " occurs " << count << " times";
```

### Output

```cpp
Max 9 occurs 2 times
```

## Note

- Returns **iterator**, not value (use `*it` to get value)
- Returns `end()` if range is empty
- For value directly, dereference: `*max_element(...)`
- For index: `max_element(...) - v.begin()`
- Custom comparator works same as `sort()`
