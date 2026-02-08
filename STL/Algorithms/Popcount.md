# Popcount - Count Set Bits

## Description

`__builtin_popcount()` and `__builtin_popcountll()` are GCC built-in functions that count the number of set bits (1s) in the binary representation of a number.

### Difference

- `__builtin_popcount(int)` - For 32-bit integers
- `__builtin_popcountll(long long)` - For 64-bit integers

### Time Complexity

O(1) - Hardware instruction on most modern processors

## Method 1 - \_\_builtin_popcount()

```cpp
int n = 7; // Binary: 111
cout << __builtin_popcount(n);
```

### Output

```cpp
3
```

## Method 2 - \_\_builtin_popcountll()

```cpp
long long n = 15; // Binary: 1111
cout << __builtin_popcountll(n);
```

### Output

```cpp
4
```

## Example - Different numbers

```cpp
cout << __builtin_popcount(5) << endl;   // 101 -> 2
cout << __builtin_popcount(8) << endl;   // 1000 -> 1
cout << __builtin_popcount(15) << endl;  // 1111 -> 4
cout << __builtin_popcount(0) << endl;   // 0 -> 0
```

### Output

```cpp
2
1
4
0
```

## Example - Large numbers with popcountll

```cpp
long long n = 1023; // Binary: 1111111111 (10 ones)
cout << __builtin_popcountll(n);
```

### Output

```cpp
10
```

## Common Use Cases

### Check if power of 2

```cpp
int n = 16;
if(__builtin_popcount(n) == 1) {
    cout << "Power of 2";
}
```

### Count different bits between two numbers

```cpp
int a = 5;  // 101
int b = 7;  // 111
int xor_val = a ^ b; // 010
cout << __builtin_popcount(xor_val); // 1
```

### Check if odd number of set bits

```cpp
int n = 7; // 111
if(__builtin_popcount(n) % 2 == 1) {
    cout << "Odd number of set bits";
}
```

## Note

- GCC/Clang specific (not standard C++)
- Very fast (single CPU instruction)
- For portability, use `std::popcount()` in C++20
- Use `__builtin_popcountll()` for `long long` to avoid overflow
