# Handy Bit Tricks

Bits are tiny, but they can do some surprisingly useful jobs. Here are a few classic tricks, explained one step at a time.

## 1. Swap two numbers with XOR

The familiar way to swap `a` and `b` is to save one value in a temporary variable:

```cpp
int temp = a;
a = b;
b = temp;
```

XOR gives us another way. The key facts are:

- `x ^ x` is `0`: matching bits cancel out.
- `x ^ 0` is `x`: XOR with zero leaves a value unchanged.
- XOR is associative and commutative, so values can be regrouped or reordered: `(a ^ b) ^ b` is the same as `a ^ (b ^ b)`.

Now apply those facts one step at a time:

```cpp
a = a ^ b;  // a now holds old_a ^ old_b
b = a ^ b;  // (old_a ^ old_b) ^ old_b = old_a
a = a ^ b;  // (old_a ^ old_b) ^ old_a = old_b
```

The values have traded places, without a temporary variable. For example, starting with `a = 5` and `b = 9`, the three lines leave `a = 9` and `b = 5`.

This takes **O(1)** time and **O(1)** extra space. It is a fun way to learn XOR, though a temporary variable is usually clearer in everyday code. The XOR version also requires `a` and `b` to be two distinct variables; if they refer to the same storage, the value becomes zero.

## 2. Check whether bit `i` is set

We count bit positions from the right, starting at zero. For `13`, whose binary form is `1101`, the positions are:

```text
bit position:  3  2  1  0
bit value:     1  1  0  1
```

So bit `0` is the rightmost bit, and bit `2` is the third bit from the right. In `13`, bit `2` is set (`1`). This zero-based numbering is why “the second bit” can be ambiguous; below, `i` always means the zero-based position.

The examples assume `n` is non-negative and `i` is a valid position for its integer type. For masks that use the highest bit, prefer an unsigned integer type.

### Method A: shift the number right

Shift bit `i` all the way to the right, then use AND with `1` to keep only that last bit:

```cpp
bool isSet = ((n >> i) & 1) == 1;
```

For `n = 13` and `i = 2`:

```text
1101 >> 2 = 0011
0011 & 0001 = 0001  → bit 2 is set
```

The result of the AND is either `1` (set) or `0` (not set).

### Method B: move a mask to the bit

Instead of moving the number, move `1` left until it lines up with bit `i`. Then AND it with `n`:

```cpp
bool isSet = (n & (1 << i)) != 0;
```

For `n = 13` and `i = 2`, the mask is `0100`:

```text
1101 & 0100 = 0100  → bit 2 is set
```

If the result is nonzero, the bit was set. It does not have to be greater than `1`: for bit `0`, a set result is just `1`.

Both methods take **O(1)** time and **O(1)** extra space. Make sure `i` is a valid bit position for the integer type; C++ shift counts must be smaller than the type’s width.

## 3. Set bit `i` to `1`

OR is perfect for turning one chosen bit on: `0 | 1` becomes `1`, and `1 | 1` stays `1`. The other bits stay unchanged because OR with `0` leaves a bit alone.

Build a mask with only bit `i` set, then OR it with `n`:

```cpp
n = n | (1 << i);
// Shorthand: n |= (1 << i);
```

For example, set bit `1` in `13` (`1101`):

```text
  1101
| 0010   (1 << 1)
  ----
  1111   = 15
```

If bit `i` was already `1`, the number stays the same. This takes **O(1)** time and **O(1)** extra space. As above, keep `i` within the valid range for the integer type.
