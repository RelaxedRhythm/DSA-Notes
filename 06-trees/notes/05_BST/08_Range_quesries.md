# 🌳 BST Range Queries

> **Problem:** Solve range-based queries efficiently using the Binary Search Tree property.

> ⭐⭐⭐ Difficulty: Medium  
> ⭐⭐⭐⭐ Interview Frequency: High

---

# Table of Contents

1. Introduction
2. Why BST Helps
3. Pattern Recognition
4. Range Sum of BST
5. Print Values in Range
6. Count Nodes in Range
7. Closest Value
8. Closest K Values (Follow-up)
9. Complexity Analysis
10. Common Mistakes
11. Interview Follow-ups
12. Related Questions
13. Company Favorites
14. Quick Revision

---

# 1. Introduction

Many BST interview questions ask you to process **only a subset of nodes**.

Examples

- Sum values between `L` and `R`
- Print nodes in a range
- Count nodes in a range
- Find the closest value

The biggest mistake is traversing the entire tree.

A BST lets us **prune** unnecessary subtrees.

---

# 2. Why BST Helps

BST Property

```
Left

< Root

< Right
```

Suppose

```
Range

[10, 20]
```

Current node

```
5
```

Since

```
5 < 10
```

Everything on the left is also

```
< 10
```

So

```
Skip Left Subtree
```

Only search the right subtree.

---

Similarly

Current node

```
25
```

Since

```
25 > 20
```

Everything on the right is too large.

```
Skip Right Subtree
```

---

# 3. Pattern Recognition

If the interviewer says

- Range
- Between L and R
- Interval
- Closest Value
- Values inside range

Think immediately

```
BST

↓

Prune One Subtree
```

---

# 4. Range Sum of BST

### Problem

Find the sum of all node values in

```
[L, R]
```

---

### Algorithm

```
Node < L

↓

Go Right
```

---

```
Node > R

↓

Go Left
```

---

Otherwise

```
Add Node

↓

Search Both
```

---

### C++ Code

```cpp
int rangeSumBST(TreeNode* root,
                int low,
                int high){

    if(root == nullptr)
        return 0;

    if(root->val < low)
        return rangeSumBST(root->right,
                           low,
                           high);

    if(root->val > high)
        return rangeSumBST(root->left,
                           low,
                           high);

    return root->val

        + rangeSumBST(root->left,
                      low,
                      high)

        + rangeSumBST(root->right,
                      low,
                      high);
}
```

---

# 5. Print Values in Range

Example

```
Range

[5, 10]
```

Output

```
5 6 7 8 9 10
```

Use inorder traversal with pruning.

```cpp
void printRange(TreeNode* root,
                int low,
                int high){

    if(root == nullptr)
        return;

    if(root->val > low)
        printRange(root->left,
                   low,
                   high);

    if(root->val >= low &&
       root->val <= high)
        cout << root->val << " ";

    if(root->val < high)
        printRange(root->right,
                   low,
                   high);
}
```

Output remains sorted because inorder traversal is used.

---

# 6. Count Nodes in Range

Exactly the same pruning logic.

Instead of

```
Sum
```

count qualifying nodes.

```cpp
int countNodes(TreeNode* root,
               int low,
               int high){

    if(root == nullptr)
        return 0;

    if(root->val < low)
        return countNodes(root->right,
                          low,
                          high);

    if(root->val > high)
        return countNodes(root->left,
                          low,
                          high);

    return 1

        + countNodes(root->left,
                     low,
                     high)

        + countNodes(root->right,
                     low,
                     high);
}
```

---

# 7. Closest Value

### Problem

Find the value closest to

```
target
```

---

### Idea

Maintain the best answer seen so far.

Move exactly as in BST search.

---

### Code

```cpp
int closestValue(TreeNode* root,
                 double target){

    int answer = root->val;

    while(root){

        if(abs(root->val - target) <
           abs(answer - target))
            answer = root->val;

        if(target < root->val)
            root = root->left;
        else
            root = root->right;
    }

    return answer;
}
```

---

# 8. Closest K Values (Follow-up)

Usually asked as a follow-up.

Common approaches

- Inorder + Sliding Window
- Two BST Iterators
- Max Heap

Typical complexity

```
O(n log k)
```

or better depending on the approach.

---

# 9. Complexity Analysis

| Problem | Time | Space |
|----------|------|--------|
| Range Sum | O(h + k)* | O(h) |
| Print Range | O(h + k)* | O(h) |
| Count Range | O(h + k)* | O(h) |
| Closest Value | O(h) | O(1) |

`*` Here, `k` is the number of nodes inside the range. In the worst case (when most nodes fall inside the range or the tree is skewed), the time becomes **O(n)**.

---

# 10. Common Mistakes

### ❌ Traversing Entire Tree

Use pruning.

Do not visit subtrees that cannot contain valid answers.

---

### ❌ Forgetting Equality

Use

```
>=

<=
```

when checking whether a node belongs to the range.

---

### ❌ Printing Before Left Subtree

If sorted output is required,

always use inorder traversal.

---

### ❌ Ignoring BST Property

Never recurse into both sides unless necessary.

---

# 11. Interview Follow-ups

### Q1. Why is BST faster than Binary Tree?

Because entire subtrees can be skipped.

---

### Q2. What is pruning?

Avoiding recursive calls that cannot contribute to the answer.

---

### Q3. Does this work for a Binary Tree?

No.

Pruning relies on the BST ordering property.

---

### Q4. What if there are many range queries?

Balanced BSTs with augmented data structures (or Segment Trees/Fenwick Trees for arrays) can answer repeated queries more efficiently.

---

# 12. Related Questions

- Search in BST
- Floor & Ceil
- Kth Smallest
- Closest Binary Search Tree Value
- Range Sum of BST

---

# 13. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐⭐ |
| Microsoft | ⭐⭐⭐⭐ |
| Google | ⭐⭐⭐⭐ |
| Adobe | ⭐⭐⭐ |
| Walmart | ⭐⭐⭐⭐ |
| Oracle | ⭐⭐⭐⭐ |
| Goldman Sachs | ⭐⭐⭐ |
| Atlassian | ⭐⭐⭐ |
| Flipkart | ⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐ |
| Accenture | ⭐⭐ |
| TCS Digital | ⭐⭐⭐ |

---

# 14. Quick Revision

### Recognition

```
Range Query

↓

BST

↓

Pruning
```

---

### Rules

```
Node < Low

↓

Right
```

```
Node > High

↓

Left
```

```
Otherwise

↓

Process Node

↓

Both Sides
```

---

### Closest Value

```
Normal BST Search

+

Track Best Answer
```

---

### Complexity

| Problem | Time |
|----------|------|
| Range Sum | O(h + k)* |
| Print Range | O(h + k)* |
| Count Range | O(h + k)* |
| Closest Value | O(h) |

`*` Worst-case: **O(n)**.

---

### Core Interview Idea

The BST property allows you to **prune** entire subtrees.

This is the main optimization behind almost every range-based BST problem.

---

# Interview Checklist

- [ ] Did I prune unnecessary subtrees?
- [ ] Did I recurse into both sides only when required?
- [ ] Did I use inorder when sorted output was needed?
- [ ] Did I handle inclusive bounds correctly?
- [ ] Did I mention the worst-case complexity?