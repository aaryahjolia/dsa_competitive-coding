# Bits, Complements, and Operators

Computers work with bits: tiny switches that are either `0` or `1`. Let’s see how ordinary decimal numbers become bit patterns, then use those patterns to understand complements and bitwise operators.

## Decimal to binary

To convert a non-negative decimal number to binary, repeatedly divide it by `2` and write down each remainder. Stop when the quotient reaches `0`. The remainders are collected from bottom to top (reverse the order you found them) to get the binary number.

For `13`:

| Division | Quotient | Remainder |
| --- | ---: | ---: |
| `13 ÷ 2` | 6 | 1 |
| `6 ÷ 2` | 3 | 0 |
| `3 ÷ 2` | 1 | 1 |
| `1 ÷ 2` | 0 | 1 |

Read the remainders upward: **`13` in decimal is `1101` in binary.**

```cpp
#include <algorithm>
#include <string>
using namespace std;

string convertToBinary(int n) {
    if (n == 0) return "0";

    string result;
    while (n > 0) {
        result += (n % 2 == 1) ? '1' : '0';
        n /= 2;
    }

    reverse(result.begin(), result.end());
    return result;
}
```

Each division roughly halves the number, so the time and output space are both **O(log n)** for positive `n` (and constant for `n = 0`). This version handles non-negative `int` values.

## Binary to decimal

Now go the other way. Starting at the rightmost bit, multiply each bit by `2` to the power of its position: `0, 1, 2, ...`. Add the results together. A zero bit contributes nothing, so we can simply add the power of two wherever the bit is `'1'`.

For example, `1101₂` means:

`1 × 2³ + 1 × 2² + 0 × 2¹ + 1 × 2⁰ = 8 + 4 + 0 + 1 = 13`

```cpp
#include <string>
using namespace std;

int convertToDecimal(const string& bits) {
    int number = 0;
    int powerOfTwo = 1;

    for (int i = static_cast<int>(bits.length()) - 1; i >= 0; --i) {
        if (bits[i] == '1') {
            number += powerOfTwo;
        }
        if (i > 0) {
            powerOfTwo *= 2;
        }
    }

    return number;
}
```

For an input with `L` bits, this takes **O(L)** time and **O(1)** extra space. Since a number’s binary representation has about `log₂(n)` bits, that is also written as **O(log n)** in terms of the represented value `n`. The result must fit in an `int`; this simple version also assumes the string contains only `0`s and `1`s.

## How a signed integer uses its bits

On a typical system with a 32-bit `int`, the positive number `13` can be shown using 32 bits as:

```text
00000000 00000000 00000000 00001101
```

The zeros on the left are leading zeros. The low four bits are `1101`. The width of `int` is platform-dependent, so check your system rather than assuming every `int` is 32 bits.

For signed integers, the leftmost bit participates in the sign representation: `0` for non-negative values and `1` for negative values in the usual two’s-complement representation. The bit pattern for `-13` in 8 bits is made like this:

```text
 13: 00001101
flip: 11110010   (one’s complement)
 +1: 11110011   (two’s complement, or -13)
```

The same operation works at the chosen width (for example, 32 bits). Two’s complement is formed by flipping every bit and adding `1`.

For a signed 32-bit `int`, the largest value is `01111111 ... 11111111`, which is `2³¹ - 1` (`INT_MAX`). The smallest is `10000000 ... 00000000`, which is `-2³¹` (`INT_MIN`). One bit pattern is used for zero, leaving one more negative value than positive values.

## Bitwise operators

Let’s line up `13` and `7` as four-bit numbers: `13 = 1101₂` and `7 = 0111₂`. Each operator works on matching bit positions.

| Operator | Rule | Example |
| --- | --- | --- |
| AND (`&`) | The result bit is `1` only when **both** bits are `1`. | `1101 & 0111 = 0101` → `13 & 7 = 5` |
| OR (`\|`) | The result bit is `1` when **at least one** bit is `1`. | `1101 \| 0111 = 1111` → `13 \| 7 = 15` |
| XOR (`^`) | The result bit is `1` when the bits are **different** (equivalently, when there are an odd number of `1`s in that column). | `1101 ^ 0111 = 1010` → `13 ^ 7 = 10` |

## Shifting bits

### Right shift (`>>`)

For a non-negative number, shifting right by one moves every bit one place right and drops the bit that falls off the end:

```text
13       = 1101₂
13 >> 1  = 0110₂ = 6
13 >> 2  = 0011₂ = 3
```

For non-negative integers, shifting right by `k` is the same as integer division by `2ᵏ` (the fractional part is discarded). Thus `13 >> 1` is `13 / 2`, and `13 >> 2` is `13 / 4`. The behavior for negative signed values has language/version details, so these simple rules are for non-negative values.

### Left shift (`<<`)

For a non-negative number, shifting left by `k` places appends `k` zero bits on the right. When the result is representable, this multiplies the number by `2ᵏ`:

```text
13       = 1101₂
13 << 1  = 11010₂ = 26
```

Keep the type’s range in mind. When the mathematical result fits, a left shift acts like multiplication by `2ᵏ`. When it does not fit, the result depends on the C++ version: before C++20, an out-of-range signed left shift had undefined behavior; since C++20, the result is defined modulo the width of the type. For portable, predictable bit patterns across versions, use an appropriately sized unsigned type.

### Shifts near the limits

For a 32-bit signed `int`, the endpoints look like this:

```text
INT_MAX =  01111111 11111111 11111111 11111111 =  2³¹ - 1
INT_MIN =  10000000 00000000 00000000 00000000 = -2³¹
```

Shifting `INT_MAX` left by one place moves its leading `0` into the sign position. In C++20 and later, `INT_MAX << 1` on a 32-bit `int` is `-2` (the resulting bit pattern is `11111111 ... 11111110`). Before C++20, that signed shift had undefined behavior. Similarly, `1 << 31` is not a portable way to create `INT_MIN` across C++ versions. If you need bit patterns that wrap predictably, use an unsigned type of a known width, such as `uint32_t` from `<cstdint>`.

Right-shifting a non-negative maximum is safe and moves it toward zero: `INT_MAX >> 1` is `2³⁰ - 1` (`1073741823`). Right-shifting a negative value depends on the C++ version: C++20 and later shift in the sign bit, so `INT_MIN >> 1` is `-2³⁰`; for older language versions, don’t assume a particular result.

Finally, the shift count must be smaller than the width of the promoted left operand. For a 32-bit `int`, shifting by `32` or more is invalid; it does not mean “shift everything away.”

## NOT (`~`) and complements

NOT flips every bit in the integer’s representation. For a 32-bit `int`, the pattern for `5` ends in `...00000101`; `~5` becomes `...11111010`. Interpreted as a signed two’s-complement value, that is `-6`.

In C++, the handy identity is **`~x == -x - 1`** for integer values, so:

```text
~5   = -6
~-6  = 5
```

The width matters when you look at the bits: `~` flips all bits of the integer type after the usual integer promotions. Thinking of it as “flip a fixed-width bit pattern” helps connect NOT to one’s complement; adding one to a flipped pattern gives the two’s-complement negative value.
