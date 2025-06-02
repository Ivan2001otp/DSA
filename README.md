# DSA
Problem solving patterns in C++ <br/> <br/> <br/>


## 🔧 Bit Manipulation Patterns in C++
This document summarizes **common bit manipulation tricks** that are highly useful in competitive programming, system programming, and algorithm design.<br/>

### 1. ✅ Check if i-th Bit is Set
```cpp
bool isSet = (n >> i) & 1;
```
<br/>

### 2. ✅ Set the i-th Bit
```cpp
n |= (1 << i);
```
<br/>

### 3.✅ Clear (Unset) the i-th Bit
```cpp
n &= ~(1 << i);
```
<br/>

### 4. ✅ Isolate Rightmost Set Bit
```cpp
int rsb = n & (-n);
```
<br/>


### 5. ✅ Toggle (Flip) the i-th Bit
```cpp
n ^= (1 << i);
```
<br/>

### 6. ✅ Check if Number is a Power of Two
```cpp
bool isPowerOfTwo = (n > 0) && ((n & (n - 1)) == 0);
```
<br/>

### 7.✅ Count Set Bits
```cpp
__builtin_popcount(n);       // For int (GCC/Clang)
__builtin_popcountll(n);     // For long long
```
<br/>

### 8.✅ Turn Off the Rightmost Set Bit
```cpp
n = n & (n - 1);
```
<br/>


### 9.✅ Generate All Subsets (Bitmask)
```cpp
for (int mask = 0; mask < (1 << n); ++mask) {
    for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
            // i-th element is in the subset
        }
    }
}
```
<br/>


### 10. ✅ Get Value of the Lowest Set Bit
```cpp
int bit = n & -n;
```
- Same as isolating the rightmost set bit.
<br/>


### 11. ✅ Find Highest Set Bit Position
```cpp
int pos = 31 - __builtin_clz(n);  // For int
```
- Returns the position (0-based) of the most significant set bit.
<br/>


