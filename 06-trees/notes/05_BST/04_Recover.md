# 🌳 Recover Binary Search Tree

> **Problem:** Two nodes in a Binary Search Tree (BST) have been swapped by mistake. Recover the BST without changing its structure.

> ⭐⭐⭐⭐ Difficulty: Medium-Hard  
> ⭐⭐⭐⭐⭐ Interview Frequency: Very High

---

# Table of Contents

1. Introduction
2. Problem Statement
3. Key Observation
4. Pattern Recognition
5. Approach 1 - Store Inorder (Better)
6. Approach 2 - Inorder Traversal (Optimal)
7. Dry Run
8. Complexity Analysis
9. Common Mistakes
10. Interview Follow-ups
11. Related Questions
12. Company Favorites
13. Quick Revision

---

# 1. Introduction

A valid BST has one important property:

```
Inorder Traversal

↓

Sorted Order
```

If two nodes are swapped,

the inorder sequence is no longer sorted.

The task is to find those two nodes and swap them back.

The structure of the tree must remain unchanged.

---

# 2. Problem Statement

Example

Original BST

```
        3
       / \
      1   4
         /
        2
```

Inorder

```
1 2 3 4
```

Suppose

```
2

and

3
```

are swapped.

Tree becomes

```
        2
       / \
      1   4
         /
        3
```

Inorder

```
1 3 2 4
```

This is not sorted.

Recover the original BST.

---

# 3. Key Observation

During inorder traversal,

every value should be greater than the previous value.

If

```
prev > current
```

then an inversion has occurred.

There can be

### Case 1: Adjacent Swap

```
1 3 2 4
```

Only one inversion.

---

### Case 2: Non-Adjacent Swap

```
1 5 3 4 2 6
```

Two inversions.

The algorithm should handle both.

---

# 4. Pattern Recognition

If the interviewer says

- Recover BST
- Two nodes swapped
- Fix BST
- Restore BST

Think immediately

```
Inorder Traversal

↓

Detect Inversions

↓

Swap Nodes
```

---

# 5. Approach 1 - Store Inorder

## Idea

1. Store inorder traversal.
2. Find the two misplaced values.
3. Traverse again and swap them.

### Algorithm

```
Inorder

↓

Store Values

↓

Find Two Wrong Values

↓

Traverse Again

↓

Swap
```

### Time

```
O(n)
```

### Space

```
O(n)
```

Easy to understand but not optimal.

---

# 6. Approach 2 - Inorder Traversal (Optimal)

## Idea

Maintain four pointers

```cpp
first
second
prev
current
```

Whenever

```
prev->val > current->val
```

an inversion is found.

### Rules

First inversion

```
first = prev

second = current
```

Second inversion

```
second = current
```

After traversal,

swap

```
first

and

second
```

---

## C++ Code

```cpp
class Solution {

    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root){

        if(root == nullptr)
            return;

        inorder(root->left);

        if(prev && prev->val > root->val){

            if(first == nullptr)
                first = prev;

            second = root;
        }

        prev = root;

        inorder(root->right);
    }

public:

    void recoverTree(TreeNode* root){

        inorder(root);

        swap(first->val, second->val);
    }
};
```

---

# 7. Dry Run

Tree

```
        3
       / \
      1   4
         /
        2
```

Inorder

```
1 3 2 4
```

Traversal

```
1

↓

3

↓

2
```

Since

```
3 > 2
```

First inversion

```
first = 3

second = 2
```

Continue

No more inversions.

Swap

```
3

2
```

Recovered tree.

---

Example 2

Inorder

```
1 5 3 4 2 6
```

First inversion

```
5 > 3
```

```
first = 5

second = 3
```

Second inversion

```
4 > 2
```

Update

```
second = 2
```

Swap

```
5

2
```

Recovered.

---

# 8. Complexity Analysis

## Better Approach

Time

```
O(n)
```

Space

```
O(n)
```

---

## Optimal Approach

Time

```
O(n)
```

Space

```
O(h)
```

where

```
h = height of tree
```

---

# 9. Common Mistakes

### ❌ Swapping Immediately

Do not swap during traversal.

Complete the traversal first.

---

### ❌ Missing Second Inversion

For non-adjacent swaps,

always update

```
second
```

whenever another inversion is found.

---

### ❌ Forgetting `prev`

Always compare with the previously visited node in inorder.

---

### ❌ Assuming Only One Inversion

Adjacent swaps have one inversion.

Non-adjacent swaps have two.

Your algorithm should handle both.

---

# 10. Interview Follow-ups

### Q1. Why does inorder work?

Because inorder traversal of a BST is sorted.

---

### Q2. Can this be done in O(1) extra space?

Yes.

Using **Morris Traversal**.

Time

```
O(n)
```

Space

```
O(1)
```

This is a common advanced follow-up.

---

### Q3. Why store node pointers instead of values?

The tree structure must remain unchanged.

Only node values are swapped.

---

# 11. Related Questions

- Validate BST
- BST Iterator
- Morris Traversal
- Kth Smallest in BST
- Largest BST in Binary Tree

---

# 12. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐⭐⭐ |
| Microsoft | ⭐⭐⭐⭐⭐ |
| Google | ⭐⭐⭐⭐⭐ |
| Adobe | ⭐⭐⭐⭐ |
| Walmart | ⭐⭐⭐⭐ |
| Oracle | ⭐⭐⭐⭐ |
| Goldman Sachs | ⭐⭐⭐ |
| Atlassian | ⭐⭐⭐⭐ |
| Flipkart | ⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐ |
| Accenture | ⭐⭐ |
| TCS Digital | ⭐⭐ |

---

# 13. Quick Revision

### Recognition

```
Two Nodes Swapped

↓

Inorder Traversal
```

---

### Inversion

```
prev > current
```

---

### First Inversion

```
first = prev

second = current
```

---

### Second Inversion

```
second = current
```

---

### Final Step

```
Swap

first

second
```

---

### Complexity

| Approach | Time | Space |
|----------|------|--------|
| Store Inorder | O(n) | O(n) |
| Pointer Method | O(n) | O(h) |
| Morris Traversal | O(n) | O(1) |

---

### Core Interview Idea

A valid BST produces a **sorted inorder traversal**.

Recovering the BST is equivalent to identifying the misplaced elements in that sorted sequence.

---

# Interview Checklist

- [ ] Did I detect every inversion?
- [ ] Did I update `second` on later inversions?
- [ ] Did I swap only after traversal?
- [ ] Did I handle adjacent and non-adjacent swaps?
- [ ] Is my solution O(n)?