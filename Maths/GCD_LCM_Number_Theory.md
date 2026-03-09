# GCD, LCM & Number Theory

## Table of Contents

- [GCD (Greatest Common Divisor / HCF)](#gcd-greatest-common-divisor--hcf)
- [LCM (Least Common Multiple)](#lcm-least-common-multiple)
- [Prime Numbers](#prime-numbers)
- [Modular Arithmetic](#modular-arithmetic)
- [Fast Exponentiation](#fast-exponentiation)
- [Factorial & Combinations](#factorial--combinations)

---

## GCD (Greatest Common Divisor / HCF)

### Description

GCD (also called HCF - Highest Common Factor) is the largest positive integer that divides both numbers without remainder.

**Example:** GCD(12, 18) = 6

### Include

```cpp
#include <algorithm> // For __gcd()
#include <numeric>   // For std::gcd() (C++17)
```

### Time Complexity

O(log(min(a, b)))

---

### Method 1: Euclidean Algorithm (Recursive)

Basic Concept of Euclidean Algorithm:

```
GCD(a, b) = GCD(a-b, b) if a > b
```

Since (a-b) can consume a lot of time, we use a % b instead.

```cpp
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
```

**Usage:**

```cpp
cout << gcd(12, 18); // Output: 6
cout << gcd(48, 18); // Output: 6
```

---

### Method 2: Euclidean Algorithm (Iterative)

```cpp
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
```

---

### Method 3: Built-in Functions

#### C++17 std::gcd

```cpp
#include <numeric>

int a = 12, b = 18;
cout << std::gcd(a, b); // Output: 6
```

#### \_\_gcd (GCC compiler)

```cpp
#include <algorithm>

int a = 12, b = 18;
cout << __gcd(a, b); // Output: 6
```

---

### GCD of Multiple Numbers

```cpp
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int gcd_array(vector<int>& arr) {
    int result = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        result = gcd(result, arr[i]);
        if (result == 1) return 1; // Optimization
    }
    return result;
}
```

**Usage:**

```cpp
vector<int> v = {12, 18, 24};
cout << gcd_array(v); // Output: 6
```

---

### GCD Properties

- **GCD(a, 0) = a**
- **GCD(a, b) = GCD(b, a)** (Commutative)
- **GCD(a, b) = GCD(a - b, b)** if a > b
- **GCD(a, 1) = 1** for any a
- **a × b = GCD(a, b) × LCM(a, b)**

---

## LCM (Least Common Multiple)

### Description

LCM is the smallest positive integer that is divisible by both numbers.

**Example:** LCM(12, 18) = 36

### Time Complexity

O(log(min(a, b))) - same as GCD

---

### Formula-based LCM

```cpp
long long lcm(int a, int b) {
    return (long long)a / gcd(a, b) * b; // Avoid overflow
}
```

**Usage:**

```cpp
cout << lcm(12, 18); // Output: 36
cout << lcm(4, 6);   // Output: 12
```

---

### C++17 Built-in

```cpp
#include <numeric>

cout << std::lcm(12, 18); // Output: 36
```

---

### LCM of Multiple Numbers

```cpp
long long lcm_array(vector<int>& arr) {
    long long result = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        result = lcm(result, arr[i]);
    }
    return result;
}
```

**Usage:**

```cpp
vector<int> v = {4, 6, 8};
cout << lcm_array(v); // Output: 24
```

---

## Prime Numbers

### Check if Prime

```cpp
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
```

**Time Complexity:** O(√n)

---

### Sieve of Eratosthenes

Find all primes up to n.

```cpp
vector<bool> sieve(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    return prime;
}
```

**Usage:**

```cpp
vector<bool> is_prime = sieve(50);
for (int i = 0; i <= 50; i++) {
    if (is_prime[i]) cout << i << " ";
}
// Output: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47
```

**Time Complexity:** O(n log log n)  
**Space Complexity:** O(n)

---

### Prime Factorization

```cpp
vector<int> primeFactors(int n) {
    vector<int> factors;

    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    if (n > 2) factors.push_back(n);
    return factors;
}
```

**Usage:**

```cpp
vector<int> factors = primeFactors(60);
// factors = {2, 2, 3, 5}
```

**Time Complexity:** O(√n)

---

## Modular Arithmetic

### Modulo Addition

```cpp
long long modAdd(long long a, long long b, long long mod) {
    return ((a % mod) + (b % mod)) % mod;
}
```

---

### Modulo Multiplication

```cpp
long long modMul(long long a, long long b, long long mod) {
    return ((a % mod) * (b % mod)) % mod;
}
```

---

### Modulo Subtraction

```cpp
long long modSub(long long a, long long b, long long mod) {
    return ((a % mod) - (b % mod) + mod) % mod;
}
```

---

### Modular Inverse

Using Fermat's Little Theorem (when mod is prime):

```cpp
long long power(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}

long long modInverse(long long a, long long mod) {
    return power(a, mod - 2, mod);
}
```

---

## Fast Exponentiation

### Binary Exponentiation

Compute a^b efficiently.

```cpp
long long power(long long a, long long b) {
    long long result = 1;
    while (b > 0) {
        if (b & 1) result *= a;
        a *= a;
        b >>= 1;
    }
    return result;
}
```

**Time Complexity:** O(log b)

---

### Modular Exponentiation

Compute (a^b) % mod.

```cpp
long long modPower(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}
```

**Usage:**

```cpp
const long long MOD = 1e9 + 7;
cout << modPower(2, 10, MOD); // Output: 1024
cout << modPower(2, 1000000000, MOD);
```

---

## Factorial & Combinations

### Compute Factorial with Modulo

```cpp
const long long MOD = 1e9 + 7;

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}
```

---

### Precompute Factorials

```cpp
const int MAXN = 1e6;
const long long MOD = 1e9 + 7;
long long fact[MAXN + 1];

void precomputeFactorials() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}
```

---

### nCr (Combinations) with Modulo

```cpp
long long nCr(int n, int r) {
    if (r > n) return 0;
    long long numerator = fact[n];
    long long denominator = (fact[r] * fact[n - r]) % MOD;
    return (numerator * modInverse(denominator, MOD)) % MOD;
}
```

**Usage:**

```cpp
precomputeFactorials();
cout << nCr(5, 2); // Output: 10
cout << nCr(10, 3); // Output: 120
```

---

## Common Problem Patterns

### 1. Co-prime Check

Two numbers are co-prime if GCD(a, b) = 1.

```cpp
bool isCoprime(int a, int b) {
    return gcd(a, b) == 1;
}
```

---

### 2. Reduce Fraction

Simplify a fraction a/b to its lowest terms.

```cpp
pair<int, int> reduceFraction(int a, int b) {
    int g = gcd(a, b);
    return {a / g, b / g};
}
```

**Usage:**

```cpp
auto [num, den] = reduceFraction(12, 18);
// num = 2, den = 3
```

---

### 3. Count Divisors

```cpp
int countDivisors(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            if (i != n / i) count++;
        }
    }
    return count;
}
```

**Time Complexity:** O(√n)

---

### 4. Sum of Divisors

```cpp
int sumDivisors(int n) {
    int sum = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) sum += n / i;
        }
    }
    return sum;
}
```

---

## Important Notes

- **Always use long long** when dealing with products to avoid overflow
- **LCM formula:** `a / gcd(a, b) * b` (divide first to prevent overflow)
- **For competitive programming:** MOD = 10^9 + 7 is commonly used
- **GCD(0, n) = n** is a useful base case
- **Euclidean algorithm** works because GCD(a, b) = GCD(b, a % b)
