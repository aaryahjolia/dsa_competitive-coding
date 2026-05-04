# Hashing

**Hashing** is the technique of prestoring data to enable efficient fetching, typically in $O(1)$ time.

### Why Hashing?

Consider an array `[1, 2, 1, 3, 2, 4]` and $Q$ queries asking for the frequency of a certain number.

- **Brute Force:** Iterating through the array for each query takes $O(Q \times N)$ time. For $Q = 10^5$ and $N = 10^5$, this requires $10^{10}$ operations (~100 seconds in C++).
- **Hashing:** Precompute frequencies into a hash array. This reduces the time complexity to $O(N)$ for precomputation and $O(1)$ per query fetch.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Precompute
    int hash[13] = {0}; // Assuming max element is 12
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    // Fetch queries
    cin >> q;
    while (q--) {
        int number;
        cin >> number;
        cout << hash[number] << endl;
    }
    return 0;
}
```

### Array Size Limitations

Direct array hashing is constrained by maximum memory allocation limits:

- `int` arrays: $10^6$ inside `main()`, $10^7$ globally.
- `bool` arrays: $10^7$ inside `main()`, $10^8$ globally.

**Character Hashing:**
Characters automatically cast to their ASCII values. Thus, an array of size 256 safely covers all uppercase and lowercase letters without memory issues.

### Using Maps

For larger element values ($> 10^7$), arrays become impossible to instantiate. Instead, we use `map` or `unordered_map` which dynamically store key-value pairs (`number` $\rightarrow$ `frequency`) and consume memory proportionally only to the unique elements encountered.

```cpp
// Precompute
map<int, int> mp;
for (int i = 0; i < n; i++) {
    mp[arr[i]]++;
}

// Fetching
// Process queries using `mp[number]`. Returns 0 if key not found.
```

_(For character hashing, simply use `map<char, int>`)_

### Map vs Unordered Map

| Feature             | `map`                             | `unordered_map`                    |
| ------------------- | --------------------------------- | ---------------------------------- |
| **Ordering**        | Sorted by keys                    | Random structure                   |
| **Time Complexity** | $O(\log N)$ (best, avg, worst)    | $O(1)$ (best, avg), $O(N)$ (worst) |
| **Supported Keys**  | Any data structure (e.g., `pair`) | Primitive types only (e.g., `int`) |

_Note: The $O(N)$ worst-case traversal in `unordered_map` is rare and strictly occurs due to internal collisions._

### Collisions & Linear Chaining

Hashing internally maps values to memory indices. The most common mapping algorithm is the **Division Method** (`index = key % size`).

If multiple keys map to the same modulus (e.g., `28 % 10 = 8` and `18 % 10 = 8` in a 10-sized structure), a **Collision** occurs.

**Linear Chaining** resolves collisions by creating a linked list at the collided index. For example, index `8` stores a sorted chain: `18 -> 28`. When retrieving the frequency of `28`, the algorithm jumps to index `8` and searches the chain (typically via Binary Search).

**Worst-Case:** In extreme cases (e.g., `[8, 18, 28, 38, ...]`), all keys collide into the exact same chain. The single chain length becomes $N$, degrading the search time complexity to $O(N)$.
