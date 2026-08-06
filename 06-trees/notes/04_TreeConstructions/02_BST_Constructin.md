# 🌳 Construct Binary Search Tree (BST) from Preorder Traversal

> **Problem:** Given the **Preorder traversal** of a Binary Search Tree (BST), construct the original BST.

> ⭐⭐⭐⭐ Difficulty: Medium  
> ⭐⭐⭐⭐⭐ Interview Frequency: Very High

---

# Table of Contents

1. Introduction
2. Why Only Preorder is Enough for BST?
3. Key Observations
4. Pattern Recognition
5. Approach 1 - Brute Force
6. Approach 2 - Insert Every Node
7. Approach 3 - Optimal (Bounds Method)
8. Dry Run
9. Complexity Analysis
10. Common Mistakes
11. Interview Follow-ups
12. Related Questions
13. Company Favorites
14. Quick Revision

---

# 1. Introduction

Unlike a normal binary tree, a BST has an extra property:

```
Left Subtree

< Root

< Right Subtree
```

Because of this property, **Preorder alone is enough** to reconstruct the BST.

This is one of the most common BST construction problems in coding interviews.

---

# 2. Why Only Preorder is Enough for BST?

For a normal binary tree,

```
Preorder
```

is **not enough**.

Example

```
Preorder

1 2 3
```

can represent multiple trees.

---

For a BST,

the ordering property removes the ambiguity.

Example

```
Preorder

8 5 1 7 10 12
```

The BST is uniquely determined.

---

# 3. Key Observations

## Observation 1

The first element is always the root.

```
8
```

---

## Observation 2

All values

```
< 8
```

belong to the left subtree.

All values

```
> 8
```

belong to the right subtree.

---

## Observation 3

Instead of searching for the split point repeatedly,

we can maintain a **valid value range (bounds)** while building the tree.

This leads to the optimal solution.

---

# 4. Pattern Recognition

If the interviewer says

- BST
- Construct BST
- Preorder only
- Build BST

Think immediately

```
Bounds

↓

Recursion

↓

Single Index
```

---

# 5. Approach 1 - Brute Force

For every node,

search where the right subtree begins.

Recursively build left and right parts.

### Time

```
O(n²)
```

Not recommended.

---

# 6. Approach 2 - Insert Every Node

Algorithm

```
Create Empty BST

↓

Insert every preorder element
```

Insertion

```cpp
Root

↓

Compare

↓

Go Left / Right
```

Time

Balanced BST

```
O(n log n)
```

Worst Case

```
O(n²)
```

Easy to write but not optimal.

---

# 7. Approach 3 - Optimal (Bounds Method)

This is the interview-preferred solution.

---

## Idea

Maintain

```
Lower Bound

Upper Bound
```

Every node must lie inside this range.

Initially

```
(-∞, +∞)
```

---

### Rules

For left subtree

```
(min, root)
```

For right subtree

```
(root, max)
```

---

### Recursive Function

```cpp
build(lower, upper)
```

---

### Algorithm

```
Current Value

↓

Inside Bounds?

↓

Yes

Create Node

↓

Move Index

↓

Build Left

↓

Build Right
```

If the current value is outside the bounds,

return `nullptr`.

---

## C++ Code

```cpp
class Solution {

    int index = 0;

    TreeNode* build(vector<int>& preorder,
                    int lower,
                    int upper){

        if(index == preorder.size())
            return nullptr;

        int value = preorder[index];

        if(value < lower || value > upper)
            return nullptr;

        TreeNode* root = new TreeNode(value);

        index++;

        root->left = build(preorder,
                           lower,
                           value);

        root->right = build(preorder,
                            value,
                            upper);

        return root;
    }

public:

    TreeNode* bstFromPreorder(vector<int>& preorder){

        return build(preorder,
                     INT_MIN,
                     INT_MAX);
    }
};
```

---

# 8. Dry Run

Preorder

```
8 5 1 7 10 12
```

Bounds

```
(-∞, +∞)
```

Create

```
8
```

Left Bounds

```
(-∞, 8)
```

Create

```
5
```

Left Bounds

```
(-∞, 5)
```

Create

```
1
```

Next value

```
7
```

Not inside

```
(-∞, 1)
```

Return.

Now build right subtree of

```
5
```

Bounds

```
(5, 8)
```

Create

```
7
```

Continue.

Final BST

```
        8
      /   \
     5     10
    / \      \
   1   7      12
```

---

# 9. Complexity Analysis

## Optimal Approach

### Time

Each node is processed once.

```
O(n)
```

---

### Space

Recursion Stack

Balanced BST

```
O(log n)
```

Worst Case

```
O(n)
```

---

# 10. Common Mistakes

### ❌ Searching for Split Point

Unnecessary.

Use bounds instead.

---

### ❌ Forgetting Bounds Check

Always verify

```cpp
value < lower

||

value > upper
```

before creating a node.

---

### ❌ Passing Wrong Bounds

Correct

```cpp
Left

(lower, root->val)

Right

(root->val, upper)
```

---

### ❌ Resetting Index

The preorder index should be **global/shared** across recursive calls.

Do not pass it by value.

---

### ❌ Duplicate Values

This solution assumes **unique values**, which is the standard interview assumption unless stated otherwise.

If duplicates are allowed, clarify the BST rule:

- Duplicates go to the left?
- Duplicates go to the right?

Your bounds/checks must reflect that convention.

---

# 11. Interview Follow-ups

### Q1. Why is Preorder alone enough?

Because the BST property determines exactly where each node belongs.

---

### Q2. Why don't we need Inorder?

For a BST,

Inorder is always

```
Sorted
```

The BST property already provides the necessary ordering information.

---

### Q3. Why is the bounds solution O(n)?

Every node is visited exactly once.

There is no searching or repeated scanning.

---

### Q4. Can we build it iteratively?

Yes.

Using a stack.

However, the recursive bounds solution is shorter and more commonly expected.

---

# 12. Related Questions

- Validate BST
- Recover BST
- Construct BST from Postorder
- Construct BST from Sorted Array
- BST Iterator

---

# 13. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐⭐⭐ |
| Microsoft | ⭐⭐⭐⭐ |
| Google | ⭐⭐⭐⭐ |
| Adobe | ⭐⭐⭐⭐ |
| Walmart | ⭐⭐⭐⭐ |
| Oracle | ⭐⭐⭐⭐ |
| Goldman Sachs | ⭐⭐⭐ |
| Atlassian | ⭐⭐⭐⭐ |
| Flipkart | ⭐⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐ |
| Accenture | ⭐⭐ |
| TCS Digital | ⭐⭐⭐ |

---

# 14. Quick Revision

### Recognition

```
BST

+

Preorder

↓

Bounds Method
```

---

### Bounds

```
Left

(lower, root)

Right

(root, upper)
```

---

### Complexity

```
Time

O(n)

Space

O(h)
```

where

```
h = Height of BST
```

---

### Key Idea

```
Every node knows

the range of values

it is allowed to take.
```

This is the core intuition behind the optimal solution.

---

# Construction Summary

| Problem | Key Idea | Time |
|---------|----------|------|
| Preorder + Inorder | Root + Split Inorder | O(n) |
| Postorder + Inorder | Root Last + Split Inorder | O(n) |
| BST from Preorder | Bounds + Single Index | O(n) |

---

# Interview Checklist

- [ ] Did I recognize this is a BST problem?
- [ ] Did I use bounds instead of searching?
- [ ] Did I maintain a single global preorder index?
- [ ] Did I check bounds before creating the node?
- [ ] Is my solution O(n)?

# 🌳 Construct Height Balanced BST from Sorted Array

> **Problem:** Given a **sorted array (ascending order)**, construct a **Height Balanced Binary Search Tree (BST)**.

> ⭐⭐⭐ Difficulty: Easy-Medium  
> ⭐⭐⭐⭐⭐ Interview Frequency: Very High

---

# Table of Contents

1. Introduction
2. Problem Statement
3. What is a Height Balanced BST?
4. Key Observations
5. Pattern Recognition
6. Brute Force Approach
7. Optimal Approach (Divide & Conquer)
8. Dry Run
9. Complexity Analysis
10. Common Mistakes
11. Interview Follow-ups
12. Related Questions
13. Company Favorites
14. Quick Revision

---

# 1. Introduction

This is one of the easiest yet most important BST construction problems.

The challenge is not just to construct a BST, but to construct one that is **height balanced**.

This problem teaches the **Divide & Conquer** pattern, which appears in many tree interview questions.

---

# 2. Problem Statement

Given a sorted array,

```
nums = [-10, -3, 0, 5, 9]
```

Construct a **height-balanced BST**.

One possible answer

```
          0
        /   \
      -10     5
        \      \
        -3      9
```

Another valid answer

```
          0
        /   \
      -3      9
     /       /
   -10      5
```

Multiple answers are valid as long as

- BST property is maintained.
- Tree remains height balanced.

---

# 3. What is a Height Balanced BST?

A BST is height balanced if

```
For every node,

| Height(Left) - Height(Right) | ≤ 1
```

Example

Balanced

```
        4
      /   \
     2     6
    / \   / \
   1  3  5  7
```

Not Balanced

```
1
 \
  2
   \
    3
     \
      4
```

The second tree behaves like a linked list.

---

# 4. Key Observations

## Observation 1

The array is already sorted.

For any BST,

```
Inorder Traversal

↓

Sorted Order
```

The given array is effectively the inorder traversal of the required BST.

---

## Observation 2

Choosing the first element as root

```
1 2 3 4 5
```

gives

```
1
 \
 2
  \
   3
    \
     4
      \
       5
```

Worst-case height.

---

## Observation 3

Choosing the **middle element** as the root divides the array into two almost equal halves.

This naturally produces a balanced BST.

---

# 5. Pattern Recognition

If the interviewer says

- Sorted Array
- Balanced BST
- Height Balanced
- Minimum Height BST

Think immediately

```
Middle Element

↓

Root

↓

Divide & Conquer
```

---

# 6. Brute Force Approach

Insert every element one by one into an empty BST.

Example

```
1

↓

2

↓

3

↓

4
```

Produces

```
1
 \
 2
  \
   3
    \
     4
```

### Time

Worst Case

```
O(n²)
```

---

# 7. Optimal Approach (Divide & Conquer)

## Algorithm

Take

```
Middle Element
```

as root.

Everything left becomes the left subtree.

Everything right becomes the right subtree.

Repeat recursively.

---

### Recursive Function

```cpp
build(left, right)
```

Base Case

```cpp
left > right
```

Return

```
nullptr
```

---

### Steps

```
Find Middle

↓

Create Root

↓

Build Left

↓

Build Right
```

---

## C++ Code

```cpp
class Solution {

    TreeNode* build(vector<int>& nums,
                    int left,
                    int right){

        if(left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = build(nums,
                           left,
                           mid - 1);

        root->right = build(nums,
                            mid + 1,
                            right);

        return root;
    }

public:

    TreeNode* sortedArrayToBST(vector<int>& nums){

        return build(nums,
                     0,
                     nums.size() - 1);
    }
};
```

---

# 8. Dry Run

Input

```
[-10, -3, 0, 5, 9]
```

Step 1

Middle

```
0
```

Root

```
0
```

---

Left Half

```
[-10, -3]
```

Middle

```
-10
```

---

Right Half

```
[5, 9]
```

Middle

```
5
```

---

Repeat

Final Tree

```
          0
        /   \
     -10     5
        \      \
        -3      9
```

Balanced.

---

# 9. Complexity Analysis

### Time

Every element is used exactly once.

```
O(n)
```

---

### Space

Recursion Stack

Balanced Tree

```
O(log n)
```

Worst Case

```
O(log n)
```

Since the tree is balanced by construction.

---

# 10. Common Mistakes

### ❌ Choosing First Element

Produces a skewed BST.

---

### ❌ Choosing Last Element

Same problem.

---

### ❌ Incorrect Mid Calculation

Prefer

```cpp
left + (right - left) / 2
```

instead of

```cpp
(left + right) / 2
```

to avoid integer overflow.

---

### ❌ Wrong Base Case

Correct

```cpp
if(left > right)
    return nullptr;
```

---

### ❌ Assuming Only One Answer Exists

Multiple balanced BSTs are valid.

The online judge accepts any valid height-balanced BST.

---

# 11. Interview Follow-ups

### Q1. Why choose the middle element?

It minimizes the height by dividing the remaining elements as evenly as possible.

---

### Q2. Is the resulting BST always unique?

No.

For even-sized arrays,

choosing the left-middle or right-middle both produce valid balanced BSTs.

---

### Q3. Why is the recursion depth only O(log n)?

Each recursive call halves the input range.

---

### Q4. What if the array is not sorted?

This approach no longer works.

The sorted order is essential because it represents the inorder traversal of a BST.

---

# 12. Related Questions

- Convert Sorted Linked List to BST
- Validate BST
- Construct BST from Preorder
- Balance a Binary Search Tree

---

# 13. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐⭐ |
| Microsoft | ⭐⭐⭐⭐ |
| Google | ⭐⭐⭐ |
| Adobe | ⭐⭐⭐⭐ |
| Walmart | ⭐⭐⭐ |
| Atlassian | ⭐⭐⭐ |
| Oracle | ⭐⭐⭐⭐ |
| Goldman Sachs | ⭐⭐⭐ |
| Flipkart | ⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐ |
| Accenture | ⭐⭐ |
| TCS Digital | ⭐⭐⭐ |

---

# 14. Quick Revision

### Recognition

```
Sorted Array

↓

Balanced BST

↓

Middle Element
```

---

### Construction

```
Middle

↓

Root

↓

Left Half

↓

Right Half
```

---

### Complexity

```
Time

O(n)

Space

O(log n)
```

---

### Key Idea

```
Middle Element

↓

Keeps Left & Right

Subtrees Balanced
```

---

# Construction Summary

| Problem | Key Idea | Time |
|---------|----------|------|
| Preorder + Inorder | Split using Inorder | O(n) |
| Postorder + Inorder | Split using Inorder | O(n) |
| BST from Preorder | Bounds Method | O(n) |
| BST from Sorted Array | Middle Element | O(n) |

---

# Interview Checklist

- [ ] Did I choose the middle element as the root?
- [ ] Did I recurse on both halves correctly?
- [ ] Did I use the correct base case?
- [ ] Did I calculate `mid` safely?
- [ ] Is the resulting BST height balanced?