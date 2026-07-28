# Array Patterns

## 1. Hashing

### Recognition

Think HashMap / HashSet when the problem asks:

* Have I seen this before?
* How many times does each value occur?
* Find a pair with a particular relationship
* Find duplicates
* Find a complement

### Common Problems

* Two Sum
* Contains Duplicate
* Majority Element
* Longest Consecutive Sequence
* Subarray Sum Equals K

---

## 2. Two Pointers

### Recognition

Think Two Pointers when:

* The array is sorted
* Looking for a pair/triplet
* Need to process from both ends
* Need to remove duplicates
* One pointer can move based on another

### Template

```cpp
int left = 0;
int right = n - 1;

while (left < right) {

    if (...) {
        left++;
    }
    else if (...) {
        right--;
    }
    else {
        // answer
    }
}
```

### Common Problems

* Two Sum II
* 3Sum
* Container With Most Water
* Remove Duplicates from Sorted Array
* Move Zeroes

---

## 3. Sliding Window

### Recognition

Strong clue:

> "contiguous subarray/substring"

Especially when combined with:

* longest
* shortest
* maximum
* minimum
* at most K
* exactly K

### Variable Window

```cpp
int left = 0;

for (int right = 0; right < n; right++) {

    // Add nums[right]

    while (window_is_invalid) {
        // Remove nums[left]
        left++;
    }

    // Update answer
}
```

### Fixed Window

```cpp
for (int right = 0; right < n; right++) {

    // Add nums[right]

    if (right - left + 1 == k) {

        // Process window

        // Remove nums[left]
        left++;
    }
}
```

### Common Problems

* Maximum Sum Subarray of Size K
* Longest Substring Without Repeating Characters
* Minimum Size Subarray Sum
* Max Consecutive Ones III
* Longest Repeating Character Replacement

---

## 4. Prefix Sum

### Recognition

Think Prefix Sum when:

* Repeated range sums are required
* Subarray sums are involved
* The problem asks for number of subarrays satisfying a sum condition

### Basic Template

```cpp
vector<int> prefix(n + 1, 0);

for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + nums[i];
}
```

### Important Combination

```text
Prefix Sum + HashMap
```

Common example:

> Subarray Sum Equals K

---

## 5. Kadane's Algorithm

### Recognition

Think Kadane when:

> Maximum sum contiguous subarray

### Template

```cpp
int current = nums[0];
int best = nums[0];

for (int i = 1; i < n; i++) {
    current = max(nums[i], current + nums[i]);
    best = max(best, current);
}
```

### Complexity

```text
O(n) time
O(1) space
```

---

## 6. Binary Search

### Recognition

Normal binary search:

> Search for a value in a sorted search space.

Binary search on answer:

> Find minimum/maximum X such that a condition becomes true.

Ask:

```text
Is the search space ordered or monotonic?
```

If yes → consider Binary Search.

---

## 7. Intervals

### Recognition

When input looks like:

```text
[start, end]
```

Think:

```text
Sort → Traverse → Compare → Merge / Count
```

Common Problems:

* Merge Intervals
* Insert Interval
* Non-overlapping Intervals
* Meeting Rooms

---

## 8. Moore's Voting

### Recognition

If asked:

> Find the element occurring more than n/2 times.

Think:

```text
Moore's Voting Algorithm
```

Complexity:

```text
O(n) time
O(1) space
```
