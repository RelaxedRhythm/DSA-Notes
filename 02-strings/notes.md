# Strings — Notes

## Core Idea

A string is a sequence of characters.

In C++, `std::string` is a dynamic container that supports indexing, iteration, insertion, deletion, and many built-in operations.

---

## Time Complexities

| Operation   | Complexity |
| ----------- | ---------: |
| Access      |       O(1) |
| Traverse    |       O(n) |
| Compare     |       O(n) |
| Concatenate |       O(n) |
| Substring   |       O(k) |
| Find        |       O(n) |

---

## Important Techniques

### 1. Frequency Counting

Useful when checking:

* Anagrams
* Character frequency
* Duplicates

Common structures:

```cpp
unordered_map<char, int> freq;
vector<int> freq(26, 0);   // lowercase letters
```

---

### 2. Two Pointers

Useful for:

* Palindrome checking
* Removing characters
* Comparing strings
* Reversing

---

### 3. Sliding Window

Use when the problem involves:

* Substrings
* Longest
* Shortest
* At most K
* Exactly K

---

### 4. Hashing

Useful when searching for repeated patterns or comparing character counts.

---

### 5. String Building

Instead of repeatedly concatenating inside loops, consider:

```cpp
string ans;
ans.push_back(c);
```

or

```cpp
stringstream ss;
```

---

## Useful STL Functions

```cpp
s.length()
s.size()

reverse(s.begin(), s.end())

sort(s.begin(), s.end())

substr(pos, len)

find()

erase()

insert()

push_back()

pop_back()
```

---

## Common Edge Cases

Always consider:

* Empty string
* One character
* All characters same
* Uppercase vs lowercase
* Spaces
* Digits
* Special characters
* Unicode (if mentioned)
