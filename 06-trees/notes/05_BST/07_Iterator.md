# 🌳 Binary Search Tree Iterator

> **Problem:** Design an iterator over a Binary Search Tree (BST) that supports:
>
> - `next()` → Returns the next smallest element.
> - `hasNext()` → Returns whether another element exists.

> ⭐⭐⭐⭐ Difficulty: Medium  
> ⭐⭐⭐⭐⭐ Interview Frequency: Extremely High

---

# Table of Contents

1. Introduction
2. Problem Statement
3. Why Not Store Inorder?
4. Key Observation
5. Pattern Recognition
6. Approach 1 - Store Entire Inorder
7. Approach 2 - Lazy Inorder (Optimal)
8. Dry Run
9. Complexity Analysis
10. Common Mistakes
11. Interview Follow-ups
12. Related Questions
13. Company Favorites
14. Quick Revision

---

# 1. Introduction

A BST Iterator should behave like an iterator over a sorted array.

Example

```
BST

↓

Iterator

↓

2

↓

3

↓

4

↓

5

↓

6

↓

7

↓

8
```

Instead of returning everything at once,

it returns **one element at a time**.

---

# 2. Problem Statement

Implement

```cpp
BSTIterator(root)
```

```cpp
next()
```

```cpp
hasNext()
```

Example

```
BST

        7
      /   \
     3     15
          /  \
         9    20
```

Operations

```
next()

↓

3
```

```
next()

↓

7
```

```
next()

↓

9
```

```
next()

↓

15
```

```
next()

↓

20
```

---

# 3. Why Not Store Inorder?

Simple idea

```
Perform Inorder

↓

Store Vector

↓

Return Values
```

Works.

But

Space

```
O(n)
```

Interviewer usually expects better.

---

# 4. Key Observation

Inorder Traversal

```
Left

↓

Root

↓

Right
```

We do **not** need the complete traversal immediately.

We only need the **next** node.

Therefore,

store only the path to the next smallest element.

Use a **stack**.

---

# 5. Pattern Recognition

If the interviewer says

- BST Iterator
- Next Smallest
- Lazy Traversal
- Streaming BST

Think immediately

```
Stack

↓

Iterative Inorder
```

---

# 6. Approach 1 - Store Entire Inorder

### Algorithm

```
Inorder

↓

Vector

↓

Pointer
```

### Time

Construction

```
O(n)
```

### Space

```
O(n)
```

Easy but not optimal.

---

# 7. Approach 2 - Lazy Inorder (Optimal)

## Idea

Maintain a stack containing the path to the current smallest unvisited node.

### Initialization

Push all left nodes.

```
Root

↓

Left

↓

Left

↓

Left
```

Top of stack is the smallest element.

---

### next()

1. Pop the top node.
2. Save its value.
3. If it has a right child,
   push that right child and all its left descendants.
4. Return the saved value.

---

### hasNext()

Simply check whether the stack is empty.

---

## Visualization

Example

```
        7
      /   \
     3     15
          /  \
         9    20
```

Initialization

Stack

```
7

↓

3
```

Top

```
3
```

---

Call

```
next()
```

Return

```
3
```

Stack

```
7
```

---

Call

```
next()
```

Return

```
7
```

Move to right subtree

Push

```
15

↓

9
```

Stack

```
15

↓

9
```

Top

```
9
```

---

## C++ Code

```cpp
class BSTIterator {

    stack<TreeNode*> st;

    void pushLeft(TreeNode* node){

        while(node){

            st.push(node);
            node = node->left;
        }
    }

public:

    BSTIterator(TreeNode* root){

        pushLeft(root);
    }

    int next(){

        TreeNode* node = st.top();
        st.pop();

        if(node->right)
            pushLeft(node->right);

        return node->val;
    }

    bool hasNext(){

        return !st.empty();
    }
};
```

---

# 8. Dry Run

Tree

```
        5
      /   \
     3     7
    / \   / \
   2   4 6   8
```

Initialization

Stack

```
5

↓

3

↓

2
```

Top

```
2
```

---

next()

Return

```
2
```

---

next()

Return

```
3
```

Push

```
4
```

---

next()

Return

```
4
```

Continue similarly.

Output

```
2 3 4 5 6 7 8
```

---

# 9. Complexity Analysis

### Constructor

Time

```
O(h)
```

Space

```
O(h)
```

---

### next()

Worst Case

```
O(h)
```

Amortized

```
O(1)
```

Each node is pushed and popped exactly once over the lifetime of the iterator.

---

### hasNext()

Time

```
O(1)
```

---

# 10. Common Mistakes

### ❌ Forgetting to Push Left Chain

After visiting a node,

always push the leftmost path of its right subtree.

---

### ❌ Using Recursion

The iterator must preserve state between calls.

A stack is the natural choice.

---

### ❌ Claiming `next()` is Always O(1)

A single call may push multiple nodes.

The correct statement is

```
Worst Case

O(h)

Amortized

O(1)
```

---

### ❌ Returning Without Removing Node

Always

```
Pop

↓

Return
```

---

# 11. Interview Follow-ups

### Q1. Why is `next()` amortized O(1)?

Each node is

- pushed once
- popped once

Total work

```
O(n)
```

for

```
n
```

calls.

---

### Q2. Why use a stack?

It simulates recursive inorder traversal while preserving state.

---

### Q3. Can this support reverse iteration?

Yes.

Store the **rightmost path** instead of the leftmost.

This idea is used in the **Two Sum IV (BST)** problem.

---

### Q4. Can this be implemented using Morris Traversal?

Yes.

It achieves

```
O(1)
```

extra space,

but temporarily modifies the tree.

The stack solution is the standard interview answer.

---

# 12. Related Questions

- Kth Smallest in BST
- Two Sum IV - Input is a BST
- Recover BST
- Morris Traversal
- Validate BST

---

# 13. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐⭐⭐ |
| Microsoft | ⭐⭐⭐⭐⭐ |
| Google | ⭐⭐⭐⭐⭐ |
| Adobe | ⭐⭐⭐⭐ |
| Walmart | ⭐⭐⭐⭐ |
| Oracle | ⭐⭐⭐⭐ |
| Goldman Sachs | ⭐⭐⭐⭐ |
| Atlassian | ⭐⭐⭐⭐⭐ |
| Flipkart | ⭐⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐ |
| Accenture | ⭐⭐ |
| TCS Digital | ⭐⭐⭐ |

---

# 14. Quick Revision

### Recognition

```
BST Iterator

↓

Iterative Inorder

↓

Stack
```

---

### Initialization

```
Push

Root

↓

Left

↓

Left...
```

---

### next()

```
Pop

↓

Visit

↓

Push Left Chain of Right Subtree
```

---

### hasNext()

```
Stack Empty ?

↓

No → True

Yes → False
```

---

### Complexity

| Operation | Time | Space |
|-----------|------|--------|
| Constructor | O(h) | O(h) |
| next() | O(1) amortized (O(h) worst case) | O(h) |
| hasNext() | O(1) | O(h) |

---

### Core Interview Idea

Instead of storing the entire inorder traversal, maintain only the path to the next smallest node. This provides a **lazy inorder traversal**, saving space while efficiently supporting repeated `next()` calls.

---

# Interview Checklist

- [ ] Did I recognize this as iterative inorder traversal?
- [ ] Did I initialize the stack with the leftmost path?
- [ ] After `next()`, did I push the left chain of the right subtree?
- [ ] Did I correctly explain amortized O(1)?
- [ ] Does `hasNext()` simply check whether the stack is empty?