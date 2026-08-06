# 🌳 Validate Binary Search Tree

> **Problem:** Determine whether a given Binary Tree is a valid Binary Search Tree (BST).

> ⭐⭐⭐⭐ Difficulty: Medium
>
> ⭐⭐⭐⭐⭐ Interview Frequency: Extremely High

---

# Table of Contents

1. Introduction
2. Problem Statement
3. Key Observations
4. Pattern Recognition
5. Approach 1 - Brute Force
6. Approach 2 - Inorder Traversal
7. Approach 3 - Range Validation (Optimal)
8. Dry Run
9. Complexity Analysis
10. Common Mistakes
11. Interview Follow-ups
12. Related Questions
13. Company Favorites
14. Quick Revision

---

# 1. Introduction

This is one of the most frequently asked BST problems.

Many candidates solve it incorrectly because they only compare a node with its immediate children.

The interviewer wants to check whether you understand the **global BST property**.

---

# 2. Problem Statement

Determine whether the given tree satisfies the BST property.

Valid BST

```
        8
      /   \
     5     10
    / \      \
   2   7      12
```

Invalid BST

```
        8
      /   \
     5     10
      \
       9
```

Although

```
9 > 5
```

it is in the **left subtree of 8**.

Therefore

```
9 < 8
```

should have been true.

Hence

❌ Invalid BST.

---

# 3. Key Observations

The BST rule is

```
Left Subtree

< Root

< Right Subtree
```

This applies to **every ancestor**, not just the parent.

Every node has a valid range of values.

Example

```
        20
       /
      10
        \
         15
```

Node

```
15
```

must satisfy

```
10 < 15 < 20
```

The upper bound comes from the ancestor, not the parent.

---

# 4. Pattern Recognition

If the interviewer says

- Validate BST
- Check BST
- Is Valid BST

Think immediately

```
Valid Range

↓

Recursion
```

---

# 5. Approach 1 - Brute Force

For every node

- Find maximum in left subtree.
- Find minimum in right subtree.
- Compare.

Repeat for every node.

### Time

```
O(n²)
```

Not recommended.

---

# 6. Approach 2 - Inorder Traversal

Key Property

```
Inorder Traversal of a BST

↓

Strictly Increasing
```

Algorithm

- Perform inorder traversal.
- Store previous value.
- Current value must always be greater.

### C++ Code

```cpp
class Solution {

    long long prev = LLONG_MIN;

public:

    bool isValidBST(TreeNode* root){

        if(root == nullptr)
            return true;

        if(!isValidBST(root->left))
            return false;

        if(root->val <= prev)
            return false;

        prev = root->val;

        return isValidBST(root->right);
    }
};
```

---

# 7. Approach 3 - Range Validation (Optimal)

This is the interviewer-preferred solution.

Every node must lie inside a valid range.

Initially

```
(-∞, +∞)
```

For left subtree

```
(min, root)
```

For right subtree

```
(root, max)
```

---

## Algorithm

```
Node

↓

Inside Range?

↓

No

↓

Invalid

↓

Yes

↓

Check Left

↓

Check Right
```

---

## C++ Code

```cpp
class Solution {

    bool validate(TreeNode* root,
                  long long low,
                  long long high){

        if(root == nullptr)
            return true;

        if(root->val <= low ||
           root->val >= high)
            return false;

        return validate(root->left,
                        low,
                        root->val)

            &&

               validate(root->right,
                        root->val,
                        high);
    }

public:

    bool isValidBST(TreeNode* root){

        return validate(root,
                        LLONG_MIN,
                        LLONG_MAX);
    }
};
```

---

# 8. Dry Run

Tree

```
        8
      /   \
     5     10
      \
       9
```

Root

```
8
```

Range

```
(-∞, +∞)
```

---

Node

```
5
```

Range

```
(-∞, 8)
```

---

Node

```
9
```

Range

```
(5, 8)
```

Check

```
9 >= 8
```

Invalid.

Return

```
False
```

---

# 9. Complexity Analysis

## Inorder

Time

```
O(n)
```

Space

```
O(h)
```

---

## Range Validation

Time

```
O(n)
```

Space

```
O(h)
```

---

# 10. Common Mistakes

### ❌ Comparing Only Parent and Child

Wrong.

Always consider the valid range from all ancestors.

---

### ❌ Using INT_MIN / INT_MAX

Node values may equal these limits.

Use

```cpp
LLONG_MIN
LLONG_MAX
```

---

### ❌ Using Non-Strict Comparison

BST requires

```
Left < Root < Right
```

Use

```cpp
<=

>=
```

to detect invalid cases.

---

### ❌ Forgetting Duplicate Rules

Standard interview assumption

```
No duplicates
```

If duplicates are allowed,

clarify the convention.

---

# 11. Interview Follow-ups

### Q1. Which approach is better?

Range Validation.

It directly models the BST definition.

---

### Q2. Why does inorder work?

Because inorder traversal of a BST is always strictly increasing.

---

### Q3. Can we validate iteratively?

Yes.

Using iterative inorder traversal with a stack.

---

### Q4. Why is the brute-force solution O(n²)?

Each node repeatedly scans its subtrees to find min/max values.

---

# 12. Related Questions

- Recover Binary Search Tree
- Largest BST in a Binary Tree
- Kth Smallest Element in BST
- BST Iterator
- Delete Node in BST

---

# 13. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐⭐⭐ |
| Microsoft | ⭐⭐⭐⭐⭐ |
| Google | ⭐⭐⭐⭐⭐ |
| Adobe | ⭐⭐⭐⭐⭐ |
| Walmart | ⭐⭐⭐⭐ |
| Oracle | ⭐⭐⭐⭐⭐ |
| Goldman Sachs | ⭐⭐⭐⭐ |
| Atlassian | ⭐⭐⭐⭐ |
| Flipkart | ⭐⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐⭐ |
| Accenture | ⭐⭐⭐ |
| TCS Digital | ⭐⭐⭐⭐ |

---

# 14. Quick Revision

### Recognition

```
Validate BST

↓

Range Validation
```

---

### Alternative

```
Inorder

↓

Strictly Increasing
```

---

### Initial Range

```
(-∞, +∞)
```

---

### Left Child

```
(low, root)
```

---

### Right Child

```
(root, high)
```

---

### Complexity

| Approach | Time | Space |
|----------|------|--------|
| Inorder | O(n) | O(h) |
| Range Validation | O(n) | O(h) |

---

### Core Interview Idea

A node is **not** constrained only by its parent.

It is constrained by **all its ancestors**.

This is the key insight interviewers are testing.

---

# Interview Checklist

- [ ] Am I checking the entire valid range?
- [ ] Did I avoid comparing only parent and child?
- [ ] Did I use `LLONG_MIN` and `LLONG_MAX`?
- [ ] Am I handling duplicates correctly?
- [ ] Is my solution O(n)?