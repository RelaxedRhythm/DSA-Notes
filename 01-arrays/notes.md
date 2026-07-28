# Arrays — Notes

## Core Idea

An array stores elements in contiguous memory and provides **O(1) random access** using an index.

### Complexity

| Operation             | Complexity |
| --------------------- | ---------: |
| Access by index       |       O(1) |
| Search                |       O(n) |
| Insert at end*        |       O(1) |
| Insert at beginning   |       O(n) |
| Delete from beginning |       O(n) |
| Delete from middle    |       O(n) |

*For a dynamic array such as `vector`, insertion at the end is amortized O(1).

---

## Important Techniques

### 1. Hashing

Use when you need:

* Frequency counting
* Duplicate detection
* Fast lookup
* Finding complements

Typical structures:

```cpp
unordered_map<int, int> freq;
unordered_set<int> seen;
```

---

### 2. Two Pointers

Commonly used when:

* The array is sorted
* Looking for pairs/triplets
* Processing elements from opposite ends
* Removing duplicates
* Partitioning an array

Typical complexity: **O(n)** after sorting/preprocessing.

---

### 3. Sliding Window

Use when dealing with a **contiguous subarray/substring** and looking for:

* Longest
* Shortest
* Maximum
* Minimum
* At most K
* Exactly K

Main idea:

```text
Expand → condition becomes invalid → shrink → update answer
```

---

### 4. Prefix Sum

Used for efficient range-sum queries.

For:

```text
nums = [2, 4, 1, 5, 3]
```

Build:

```text
prefix = [0, 2, 6, 7, 12, 15]
```

Range sum:

```text
sum(l...r) = prefix[r + 1] - prefix[l]
```

---

### 5. Kadane's Algorithm

Used to find the **maximum sum contiguous subarray**.

At every index:

```text
Start a new subarray
OR
Extend the previous subarray
```

Complexity:

```text
Time  : O(n)
Space : O(1)
```

---

### 6. Moore's Voting Algorithm

Used to find an element occurring **more than n/2 times**.

Complexity:

```text
Time  : O(n)
Space : O(1)
```

---

### 7. Intervals

For many interval problems:

```text
Sort intervals
        ↓
Process from left to right
        ↓
Compare current interval with previous
        ↓
Merge / count / remove
```

---

## Common Edge Cases

Always consider:

* Empty array
* Single element
* All elements equal
* Already sorted
* Reverse sorted
* Duplicate values
* Negative numbers
* Integer overflow
* Very large input
