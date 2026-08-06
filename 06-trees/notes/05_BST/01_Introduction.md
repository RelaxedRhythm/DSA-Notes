# 🌳 Binary Search Tree (BST) - Introduction

> ⭐⭐⭐⭐⭐ Importance: Extremely High
>
> **Interview Frequency:** Every Product Company + Most Service Companies

---

# Table of Contents

1. What is a Binary Search Tree?
2. BST Properties
3. BST vs Binary Tree
4. Why Do We Use BST?
5. BST Operations & Complexities
6. Balanced vs Unbalanced BST
7. Pattern Recognition
8. Common Interview Tricks
9. Common Mistakes
10. Related Problems
11. Company Favorites
12. Quick Revision

---

# 1. What is a Binary Search Tree?

A **Binary Search Tree (BST)** is a Binary Tree that follows a special ordering property.

For every node

```
Left Subtree

< Root

< Right Subtree
```

This rule must be true for **every node** in the tree.

Example

```
        8
      /   \
     5     10
    / \      \
   2   7      12
```

Every node satisfies the BST property.

---

Invalid BST

```
        8
      /   \
     5     10
    / \
   2   9
```

Here

```
9 > 8
```

but it is inside the left subtree of 8.

Therefore,

❌ Not a BST.

---

# 2. BST Properties

## Property 1

For every node

```
Left < Root < Right
```

---

## Property 2

Every subtree is itself a BST.

Example

```
        15
       /  \
      8    20
     / \
    5  12
```

The subtree rooted at

```
8
```

is also a valid BST.

---

## Property 3

Inorder Traversal of a BST is always sorted.

Example

```
        8
      /   \
     5     10
    / \      \
   2   7      12
```

Inorder

```
2 5 7 8 10 12
```

This property is used in many interview problems.

---

## Property 4

Searching depends on ordering.

Suppose we search

```
7
```

```
        8

↓

7 < 8

↓

Go Left

↓

5

↓

7 > 5

↓

Go Right

↓

7
```

No unnecessary nodes are visited.

---

# 3. BST vs Binary Tree

| Binary Tree | Binary Search Tree |
|-------------|--------------------|
| No ordering | Ordered |
| Search → O(n) | Search → O(log n) (Balanced) |
| Inorder not sorted | Inorder always sorted |
| Any structure | Must satisfy BST property |

---

# 4. Why Do We Use BST?

BST allows efficient

- Search
- Insert
- Delete
- Range Queries
- Finding Minimum
- Finding Maximum
- Floor & Ceil
- Successor & Predecessor
- Kth Smallest

without scanning every node.

---

# 5. BST Operations & Complexities

| Operation | Balanced BST | Worst Case |
|------------|--------------|------------|
| Search | O(log n) | O(n) |
| Insert | O(log n) | O(n) |
| Delete | O(log n) | O(n) |
| Min | O(log n) | O(n) |
| Max | O(log n) | O(n) |
| Floor | O(log n) | O(n) |
| Ceil | O(log n) | O(n) |

---

# 6. Balanced vs Unbalanced BST

Balanced BST

```
        4
      /   \
     2     6
    / \   / \
   1  3  5  7
```

Height

```
O(log n)
```

---

Unbalanced BST

```
1
 \
  2
   \
    3
     \
      4
```

Height

```
O(n)
```

Searching becomes as slow as a linked list.

---

# 7. Pattern Recognition

If the interviewer says

- Sorted order
- Kth smallest
- Successor
- Predecessor
- Floor
- Ceil
- Search
- Insert
- Delete
- Range

Think immediately

```
BST
```

---

Recognition examples

Question says

```
Find kth smallest
```

Think

```
Inorder Traversal
```

---

Question says

```
Search efficiently
```

Think

```
BST Property
```

---

Question says

```
Closest value
```

Think

```
Floor / Ceil
```

---

Question says

```
Values between L and R
```

Think

```
BST Pruning
```

---

# 8. Common Interview Tricks

### Trick 1

Interviewer says

```
Binary Tree
```

Do **not** assume it is a BST.

Always verify the problem statement.

---

### Trick 2

Whenever you hear

```
Sorted
```

ask yourself

```
Can BST help?
```

---

### Trick 3

Many BST problems become easy because

```
Inorder = Sorted
```

Remember this property.

---

### Trick 4

Avoid traversing both subtrees.

Use the BST property to eliminate half the tree.

Example

Searching

```
15
```

Current node

```
10
```

Since

```
15 > 10
```

Go right directly.

---

# 9. Common Mistakes

### ❌ Checking only immediate children

Wrong

```
      10
     /
    5
     \
      15
```

15 violates the BST property even though

```
15 > 5
```

Always consider the valid range.

---

### ❌ Assuming Balanced BST

A normal BST can become skewed.

Never assume

```
Height = log n
```

unless stated.

---

### ❌ Forgetting Duplicates

Different implementations handle duplicates differently.

Clarify during interviews.

Common rules

- Duplicates on left
- Duplicates on right
- No duplicates allowed

---

### ❌ Traversing Entire Tree

Many BST problems require visiting only one path.

Take advantage of ordering.

---

# 10. Related Problems

- Search in BST
- Insert into BST
- Delete Node in BST
- Validate BST
- Recover BST
- Lowest Common Ancestor
- Kth Smallest Element
- BST Iterator
- Floor & Ceil
- Range Sum of BST

---

# 11. Company Favorites

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

# 12. Quick Revision

### BST Rule

```
Left

<

Root

<

Right
```

---

### Most Important Property

```
Inorder Traversal

↓

Sorted Order
```

---

### Best Time Complexity

| Operation | Time |
|------------|------|
| Search | O(log n) |
| Insert | O(log n) |
| Delete | O(log n) |

(Balanced BST)

---

### Worst Case

```
Skew Tree

↓

O(n)
```

---

### Interview Keywords

| Keyword | Think |
|----------|-------|
| Sorted | BST |
| Kth Smallest | Inorder |
| Successor | BST |
| Floor | BST |
| Ceil | BST |
| Range | BST Pruning |
| Search | BST Property |

---

# Interview Checklist

- [ ] Is it really a BST?
- [ ] Can I use the ordering property?
- [ ] Can I avoid one subtree?
- [ ] Is the tree balanced?
- [ ] Is there a simpler inorder solution?