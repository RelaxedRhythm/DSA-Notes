# 🌳 Kth Smallest & Kth Largest Element in BST

> **Problem:** Find the Kth Smallest or Kth Largest element in a Binary Search Tree.

> ⭐⭐⭐ Difficulty: Medium  
> ⭐⭐⭐⭐⭐ Interview Frequency: Extremely High

---

# Table of Contents

1. Introduction
2. Key Observation
3. Pattern Recognition
4. Approach 1 - Store Inorder
5. Approach 2 - Optimal Inorder Traversal
6. Kth Largest
7. Dry Run
8. Complexity Analysis
9. Common Mistakes
10. Interview Follow-ups
11. Related Questions
12. Company Favorites
13. Quick Revision

---

# 1. Introduction

Finding the Kth element is one of the most common BST interview questions.

The solution depends on one important BST property.

```
Inorder Traversal

↓

Sorted Order
```

Therefore,

```
Kth Smallest

↓

Kth element in Inorder
```

Similarly,

```
Reverse Inorder

↓

Descending Order

↓

Kth Largest
```

---

# 2. Key Observation

Example

```
        5
      /   \
     3     7
    / \   / \
   2   4 6   8
```

Inorder

```
2 3 4 5 6 7 8
```

Reverse Inorder

```
8 7 6 5 4 3 2
```

So

```
3rd Smallest

↓

4
```

```
2nd Largest

↓

7
```

---

# 3. Pattern Recognition

If the interviewer says

- Kth Smallest
- Kth Largest
- Sorted order
- Rank
- Ordered statistics

Think immediately

```
BST

↓

Inorder
```

---

# 4. Approach 1 - Store Inorder

## Algorithm

```
Perform Inorder

↓

Store Values

↓

Return

values[k-1]
```

---

### Code

```cpp
void inorder(TreeNode* root,
             vector<int>& ans){

    if(root == nullptr)
        return;

    inorder(root->left, ans);

    ans.push_back(root->val);

    inorder(root->right, ans);
}

int kthSmallest(TreeNode* root,
                int k){

    vector<int> inorderList;

    inorder(root, inorderList);

    return inorderList[k-1];
}
```

---

### Complexity

Time

```
O(n)
```

Space

```
O(n)
```

---

# 5. Approach 2 - Optimal Inorder Traversal

Instead of storing every value,

count nodes during inorder traversal.

When count becomes

```
k
```

return the answer.

---

### Algorithm

```
Left

↓

Visit

↓

count++

↓

count == k ?

↓

Answer

↓

Right
```

---

### Code

```cpp
class Solution {

    int count = 0;
    int answer = -1;

    void inorder(TreeNode* root,
                 int k){

        if(root == nullptr || count >= k)
            return;

        inorder(root->left, k);

        count++;

        if(count == k){

            answer = root->val;
            return;
        }

        inorder(root->right, k);
    }

public:

    int kthSmallest(TreeNode* root,
                    int k){

        inorder(root, k);

        return answer;
    }
};
```

---

# 6. Kth Largest

The logic is exactly the same.

The only difference is the traversal order.

Instead of

```
Left

↓

Root

↓

Right
```

Use

```
Right

↓

Root

↓

Left
```

This is called **Reverse Inorder Traversal**.

---

### Code

```cpp
class Solution {

    int count = 0;
    int answer = -1;

    void reverseInorder(TreeNode* root,
                        int k){

        if(root == nullptr || count >= k)
            return;

        reverseInorder(root->right, k);

        count++;

        if(count == k){

            answer = root->val;
            return;
        }

        reverseInorder(root->left, k);
    }

public:

    int kthLargest(TreeNode* root,
                   int k){

        reverseInorder(root, k);

        return answer;
    }
};
```

---

# 7. Dry Run

Tree

```
        5
      /   \
     3     7
    / \   / \
   2   4 6   8
```

Find

```
3rd Smallest
```

Traversal

```
2

↓

3

↓

4
```

Count

```
1

↓

2

↓

3
```

Answer

```
4
```

---

Find

```
2nd Largest
```

Reverse Inorder

```
8

↓

7
```

Count

```
1

↓

2
```

Answer

```
7
```

---

# 8. Complexity Analysis

### Better Approach

| Time | Space |
|------|--------|
| O(n) | O(n) |

---

### Optimal Approach

| Time | Space |
|------|--------|
| O(h + k)* | O(h) |

`*` In the best and average cases, traversal stops as soon as the kth node is visited. In the worst case (e.g., `k = n`), the time becomes **O(n)**.

where

```
h = Height of BST
```

---

# 9. Common Mistakes

### ❌ Forgetting Inorder is Sorted

This is the core BST property.

---

### ❌ Using Zero-Based Count

Traversal count starts from

```
1
```

not

```
0
```

---

### ❌ Continuing After Finding Answer

Stop the recursion once the answer is found.

---

### ❌ Mixing Kth Largest

Remember

```
Largest

↓

Reverse Inorder
```

---

# 10. Interview Follow-ups

### Q1. Can this be done iteratively?

Yes.

Use an explicit stack for inorder traversal.

---

### Q2. Can it be done in O(1) extra space?

Yes.

Using **Morris Inorder Traversal**.

Time

```
O(n)
```

Space

```
O(1)
```

---

### Q3. What if many Kth queries are asked?

Augment each node with the **size of its subtree** (Order Statistic Tree).

This allows queries in

```
O(log n)
```

on a balanced BST.

---

### Q4. What if duplicates exist?

Clarify the BST definition.

The inorder traversal will include duplicates according to the chosen convention.

---

# 11. Related Questions

- BST Iterator
- Validate BST
- Recover BST
- Two Sum IV - Input is a BST
- Convert BST to Greater Tree

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
| Goldman Sachs | ⭐⭐⭐⭐ |
| Atlassian | ⭐⭐⭐⭐ |
| Flipkart | ⭐⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐⭐ |
| Accenture | ⭐⭐⭐ |
| TCS Digital | ⭐⭐⭐⭐ |

---

# 13. Quick Revision

### Recognition

```
Kth Smallest

↓

Inorder
```

```
Kth Largest

↓

Reverse Inorder
```

---

### Traversals

```
Smallest

Left

↓

Root

↓

Right
```

```
Largest

Right

↓

Root

↓

Left
```

---

### Complexity

| Method | Time | Space |
|---------|------|--------|
| Store Inorder | O(n) | O(n) |
| Count During Traversal | O(h + k)* | O(h) |
| Morris Traversal | O(n) | O(1) |

`*` Worst-case time is **O(n)**.

---

### Core Interview Idea

The BST property turns an inorder traversal into a sorted sequence.

The kth smallest/largest problem is simply finding the kth element of that ordered traversal efficiently.

---

# Interview Checklist

- [ ] Did I recognize that inorder gives sorted order?
- [ ] Did I stop traversal once the answer was found?
- [ ] Did I use reverse inorder for kth largest?
- [ ] Did I avoid storing the entire traversal when unnecessary?
- [ ] Did I mention the Morris Traversal follow-up if asked?