# Next Permutation

## Description

`next_permutation()` rearranges elements into the next lexicographically greater permutation. Returns `true` if next permutation exists, `false` if already at the last permutation (then resets to first).

### Include

```cpp
#include<algorithm>
```

### Time Complexity

O(n) where n is the number of elements

## Method 1 - Basic usage

```cpp
vector<int> v = {1, 2, 3};
next_permutation(v.begin(), v.end());

for(int x : v) cout << x << " ";
```

### Output

```cpp
1 3 2
```

## Method 2 - Generate all permutations

```cpp
vector<int> v = {1, 2, 3};
sort(v.begin(), v.end()); // Start from smallest

do {
    for(int x : v) cout << x << " ";
    cout << endl;
} while(next_permutation(v.begin(), v.end()));
```

### Output

```cpp
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
```

## Method 3 - With arrays

```cpp
int arr[] = {1, 2, 3};
int n = 3;

next_permutation(arr, arr + n);

for(int i = 0; i < n; i++) cout << arr[i] << " ";
```

### Output

```cpp
1 3 2
```

## Method 4 - String permutations

```cpp
string s = "abc";
sort(s.begin(), s.end());

do {
    cout << s << endl;
} while(next_permutation(s.begin(), s.end()));
```

### Output

```cpp
abc
acb
bac
bca
cab
cba
```

## Method 5 - Count permutations

```cpp
vector<int> v = {1, 2, 3};
sort(v.begin(), v.end());

int count = 1; // First permutation
while(next_permutation(v.begin(), v.end())) {
    count++;
}

cout << "Total permutations: " << count;
```

### Output

```cpp
Total permutations: 6
```

## Method 6 - Return value usage

```cpp
vector<int> v = {3, 2, 1}; // Last permutation

if(next_permutation(v.begin(), v.end())) {
    cout << "Next exists";
} else {
    cout << "No next, reset to first";
    for(int x : v) cout << x << " "; // 1 2 3
}
```

### Output

```cpp
No next, reset to first
1 2 3
```

## Common Use Cases

### Find next greater number with same digits

```cpp
int n = 123;
string s = to_string(n);
next_permutation(s.begin(), s.end());
int next_num = stoi(s);
cout << next_num; // 132
```

### Generate k-th permutation

```cpp
vector<int> v = {1, 2, 3};
int k = 4; // 4th permutation

sort(v.begin(), v.end());
for(int i = 1; i < k; i++) {
    next_permutation(v.begin(), v.end());
}

for(int x : v) cout << x << " "; // 2 3 1
```

## Note

- Must start from sorted (smallest) permutation to get all permutations
- Returns `false` and resets to first when at last permutation
- For previous permutation, use `prev_permutation()`
- Works with any comparable type (int, char, string, etc.)
