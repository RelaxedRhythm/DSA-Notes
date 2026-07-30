# String Patterns

## 1. Frequency Counting

### Recognition

Think frequency array or HashMap when asked:

* Are two strings anagrams?
* Count occurrences
* Most frequent character
* Duplicate characters

### Template

```cpp
vector<int> freq(26, 0);

for (char c : s)
    freq[c - 'a']++;
```

### Common Problems

* Valid Anagram
* Ransom Note
* Find the Difference

---

## 2. Two Pointers

### Recognition

Use when:

* Checking palindrome
* Comparing from both ends
* Reversing
* Removing characters

### Template

```cpp
int left = 0;
int right = s.size() - 1;

while (left < right) {

    if (...) {
        left++;
    } else {
        right--;
    }
}
```

### Common Problems

* Valid Palindrome
* Reverse String
* Merge Strings Alternately

---

## 3. Sliding Window

### Recognition

Huge clue:

> "Substring"

Especially with:

* longest
* shortest
* unique
* distinct
* at most K
* exactly K

### Variable Window

```cpp
int left = 0;

for (int right = 0; right < n; right++) {

    // include s[right]

    while (window_invalid) {
        // remove s[left]
        left++;
    }

    // update answer
}
```

### Common Problems

* Longest Substring Without Repeating Characters
* Minimum Window Substring
* Longest Repeating Character Replacement
* Permutation in String

---

## 4. Sorting

### Recognition

Think sorting when:

* Order doesn't matter
* Comparing character sets
* Grouping anagrams

### Common Problems

* Valid Anagram
* Group Anagrams

---

## 5. String Parsing

Recognition:

* Numbers inside strings
* Tokens
* Words separated by spaces

Useful tools:

```cpp
stringstream
stoi()
to_string()
```

---

## 6. Stack

Recognition:

* Matching brackets
* Undo operations
* Nested expressions

Common Problems

* Valid Parentheses
* Decode String
* Remove All Adjacent Duplicates

---

## Common Interview Trick

Ask yourself:

```text
Characters?

↓

Need frequency?
↓

Need contiguous substring?
↓

Need both ends?
↓

Need ordering?
```

This quickly narrows down the pattern.
