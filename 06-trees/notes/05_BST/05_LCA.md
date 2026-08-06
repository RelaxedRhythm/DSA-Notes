# 🌳 Lowest Common Ancestor (LCA) in Binary Search Tree

> **Problem:** Given a Binary Search Tree (BST) and two nodes `p` and `q`, find their Lowest Common Ancestor (LCA).

> ⭐⭐⭐ Difficulty: Easy-Medium  
> ⭐⭐⭐⭐⭐ Interview Frequency: Extremely High

---

# Table of Contents

1. Introduction
2. What is Lowest Common Ancestor?
3. Key Observation
4. Pattern Recognition
5. Approach 1 - Path Method
6. Approach 2 - BST Property (Optimal)
7. Recursive Solution
8. Iterative Solution
9. Dry Run
10. Complexity Analysis
11. Common Mistakes
12. Interview Follow-ups
13. Related Questions
14. Company Favorites
15. Quick Revision

---

# 1. Introduction

The **Lowest Common Ancestor (LCA)** of two nodes is the **lowest node** in the tree that has both nodes as descendants.

In a normal Binary Tree,

finding the LCA requires searching both subtrees.

In a **BST**, we can use the ordering property to eliminate half of the tree.

---

# 2. What is Lowest Common Ancestor?

Example

```
          6
        /   \
       2     8
      / \   / \
     0   4 7   9
        / \
       3   5
```

### Example 1

```
p = 2

q = 8
```

LCA

```
6
```

---

### Example 2

```
p = 3

q = 5
```

LCA

```
4
```

---

### Example 3

```
p = 2

q = 4
```

LCA

```
2
```

A node can be the ancestor of itself.

---

# 3. Key Observation

BST Property

```
Left

< Root

< Right
```

There are only three possibilities.

### Case 1

Both nodes are smaller.

```
p < root

q < root
```

Go Left.

---

### Case 2

Both nodes are larger.

```
p > root

q > root
```

Go Right.

---

### Case 3 ⭐

The nodes lie on different sides.

```
p < root

q > root
```

(or vice versa)

Current node is the answer.

---

# 4. Pattern Recognition

If the interviewer says

- Lowest Common Ancestor
- BST
- Common Parent
- Lowest Shared Node

Think

```
BST Property

↓

Compare Values

↓

Go Left / Right
```

---

# 5. Approach 1 - Path Method

Store

```
Root → p
```

and

```
Root → q
```

Compare both paths.

Last common node is the LCA.

### Time

```
O(n)
```

### Space

```
O(n)
```

Not preferred.

---

# 6. Approach 2 - BST Property (Optimal)

## Algorithm

```
Current Node

↓

Both Smaller?

↓

Yes

↓

Go Left

-------------------

Both Larger?

↓

Yes

↓

Go Right

-------------------

Otherwise

↓

Current Node is LCA
```

---

# 7. Recursive Solution

```cpp
TreeNode* lowestCommonAncestor(TreeNode* root,
                               TreeNode* p,
                               TreeNode* q){

    if(root == nullptr)
        return nullptr;

    if(p->val < root->val &&
       q->val < root->val)
        return lowestCommonAncestor(root->left,
                                    p,
                                    q);

    if(p->val > root->val &&
       q->val > root->val)
        return lowestCommonAncestor(root->right,
                                    p,
                                    q);

    return root;
}
```

---

# 8. Iterative Solution

Preferred in interviews because it avoids recursion.

```cpp
TreeNode* lowestCommonAncestor(TreeNode* root,
                               TreeNode* p,
                               TreeNode* q){

    while(root){

        if(p->val < root->val &&
           q->val < root->val){

            root = root->left;
        }

        else if(p->val > root->val &&
                q->val > root->val){

            root = root->right;
        }

        else{

            return root;
        }
    }

    return nullptr;
}
```

---

# 9. Dry Run

Tree

```
          6
        /   \
       2     8
      / \   / \
     0   4 7   9
        / \
       3   5
```

Find

```
p = 3

q = 5
```

Current

```
6
```

Both

```
3

5

< 6
```

Go Left.

---

Current

```
2
```

Both

```
3

5

> 2
```

Go Right.

---

Current

```
4
```

```
3 < 4

5 > 4
```

Nodes split.

Therefore

```
LCA = 4
```

---

# 10. Complexity Analysis

### Balanced BST

Time

```
O(log n)
```

Space

Recursive

```
O(log n)
```

Iterative

```
O(1)
```

---

### Worst Case

Skew Tree

Time

```
O(n)
```

---

# 11. Common Mistakes

### ❌ Treating it as a Binary Tree

You do not need to search both subtrees.

---

### ❌ Forgetting a Node Can Be the LCA

Example

```
p = 2

q = 4
```

Answer

```
2
```

---

### ❌ Ignoring BST Property

Always compare values before recursing.

---

### ❌ Assuming Balanced Tree

Worst-case complexity is still

```
O(n)
```

for a skewed BST.

---

# 12. Interview Follow-ups

### Q1. Why is this easier than LCA in a Binary Tree?

Because BST ordering tells us exactly which direction to move.

---

### Q2. Recursive or Iterative?

Both are accepted.

Iterative uses

```
O(1)
```

extra space.

---

### Q3. What if one node is the ancestor of the other?

That node is the LCA.

---

### Q4. Does this work for a normal Binary Tree?

No.

This solution depends entirely on the BST property.

---

# 13. Related Questions

- Lowest Common Ancestor in Binary Tree
- Search in BST
- Validate BST
- Delete Node in BST
- Range Sum of BST

---

# 14. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐⭐⭐ |
| Microsoft | ⭐⭐⭐⭐⭐ |
| Google | ⭐⭐⭐⭐⭐ |
| Adobe | ⭐⭐⭐⭐ |
| Walmart | ⭐⭐⭐⭐ |
| Oracle | ⭐⭐⭐⭐ |
| Goldman Sachs | ⭐⭐⭐⭐ |
| Atlassian | ⭐⭐⭐⭐ |
| Flipkart | ⭐⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐⭐ |
| Accenture | ⭐⭐⭐ |
| TCS Digital | ⭐⭐⭐⭐ |

---

# 15. Quick Revision

### Recognition

```
LCA

+

BST

↓

Compare Values
```

---

### Rules

```
Both Smaller

↓

Left
```

```
Both Larger

↓

Right
```

```
Different Sides

↓

Current Node
```

---

### Complexity

| Approach | Time | Space |
|----------|------|--------|
| Recursive | O(h) | O(h) |
| Iterative | O(h) | O(1) |

where

```
h = Height of BST
```

---

### Core Interview Idea

The first node where the paths to `p` and `q` diverge (or where one node equals the current node) is the Lowest Common Ancestor.

---

# Interview Checklist

- [ ] Did I use the BST property?
- [ ] Did I avoid searching both subtrees?
- [ ] Did I handle the case where one node is the ancestor?
- [ ] Is my solution O(h)?
- [ ] Can I explain why it is faster than LCA in a Binary Tree?