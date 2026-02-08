# Sort Algorithm

## Description

`sort()` is a standard library algorithm that sorts elements in ascending order by default. It uses **IntroSort** (hybrid of QuickSort, HeapSort, and InsertionSort).

### Include

```cpp
#include<algorithm>
```

### Time Complexity

O(n log n) average and worst case

## Method 1 - Ascending Order (Default)

```cpp
vector<int> v = {5, 2, 8, 1, 9};
sort(v.begin(), v.end());

for(int x : v)
    cout << x << " ";
```

### Output

```cpp
1 2 5 8 9
```

## Method 2 - Descending Order

```cpp
vector<int> v = {5, 2, 8, 1, 9};
sort(v.begin(), v.end(), greater<int>());

for(int x : v)
    cout << x << " ";
```

### Output

```cpp
9 8 5 2 1
```

## Method 3 - Sorting Arrays

```cpp
int arr[] = {5, 2, 8, 1, 9};
int n = 5;
sort(arr, arr + n);

for(int i = 0; i < n; i++) cout << arr[i] << " ";
```

### Output

```cpp
1 2 5 8 9
```

## Method 4 - Sorting Pairs (by first element)

```cpp
vector<pair<int, int>> v = {{3, 5}, {1, 2}, {2, 4}};
sort(v.begin(), v.end());

for(auto p : v) {
    cout << "(" << p.first << "," << p.second << ") ";
}
```

### Output

```cpp
(1,2) (2,4) (3,5)
```

## Method 5 - Custom Comparator (Lambda)

### Sort by second element

```cpp
vector<pair<int, int>> v = {{3, 5}, {1, 2}, {2, 4}};

sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
});

for(auto p : v) {
    cout << "(" << p.first << "," << p.second << ") ";
}
```

### Output

```cpp
(1,2) (2,4) (3,5)
```

## Method 6 - Custom Comparator (Function)

```cpp
bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second; // Descending by second
}

vector<pair<int, int>> v = {{3, 5}, {1, 2}, {2, 4}};
sort(v.begin(), v.end(), compare);

for(auto p : v) {
    cout << "(" << p.first << "," << p.second << ") ";
}
```

### Output

```cpp
(3,5) (2,4) (1,2)
```

## Method 7 - Sorting by Multiple Criteria

```cpp
// Sort by first ascending, if equal then by second descending
sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {
    if(a.first != b.first) return a.first < b.first;
    return a.second > b.second;
});
```

## Method 8 - Partial Sort

```cpp
vector<int> v = {5, 2, 8, 1, 9, 3};
sort(v.begin(), v.begin() + 3); // Sort first 3 elements

for(int x : v) cout << x << " ";
```

### Output

```cpp
2 5 8 1 9 3
```

## Common Use Cases

### Sorting by array indices

```cpp
int arr[] = {40, 10, 30, 20};
int idx[] = {0, 1, 2, 3};

sort(idx, idx + 4, [&](int i, int j) {
    return arr[i] < arr[j];
});

// idx now contains: {1, 3, 2, 0} (sorted indices by array values)
```

## Note

- Default: Ascending order
- `greater<int>()`: Descending order
- Custom comparator: Return `true` if first argument should come before second
- Stable sort: Use `stable_sort()` if you need to preserve relative order of equal elements
