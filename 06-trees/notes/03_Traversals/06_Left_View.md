# 🌳 Left View of Binary Tree

> **View Definition:** The set of nodes visible when the tree is viewed from the **left side**.

---

# Table of Contents

1. Introduction
2. Visualization
3. Pattern Recognition
4. Approach 1 - BFS (Recommended)
5. Approach 2 - DFS
6. Dry Run
7. Complexity Analysis
8. Pattern Connection
9. Interview Recognition
10. Common Mistakes
11. Interview Follow-ups
12. Related Questions
13. Company Favorites
14. Quick Revision

---

# 1. Introduction

The **Left View** of a binary tree consists of the **first visible node at every level** when looking at the tree from the left.

Unlike Level Order Traversal, we **don't print every node**.

We print **only one node per level**.

---

Example

Tree

```
          1
        /   \
       2     3
      / \     \
     4   5     6
    /
   7
```

Left View

```
1 2 4 7
```

Explanation

```
Level 0 → 1

Level 1 → 2

Level 2 → 4

Level 3 → 7
```

Always choose the **first node** seen at each level.

---

# 2. Visualization

```
Left Side

↓

          1
         / \
        2   3
       / \   \
      4   5   6
     /
    7
```

Visible Nodes

```
1

↓

2

↓

4

↓

7
```

---

# 3. Pattern Recognition

The key observation is:

> **Left View = First node of every level**

This immediately suggests **Level Order Traversal (BFS)**.

During BFS,

```
Queue

↓

Process one level

↓

Take first node
```

No additional processing is needed.

---

# 4. Approach 1 - BFS (Recommended)

## Intuition

We already know how to process one level using:

```cpp
int size = q.size();
```

The **first node processed** at each level is the leftmost node.

So,

```
if(i == 0)

store answer
```

---

## Algorithm

```
Push Root into Queue

While Queue not empty

    size = Queue Size

    For every node in this level

        If first node

            Save Answer

        Push Left Child

        Push Right Child
```

---

## C++ Code

```cpp
vector<int> leftView(TreeNode* root){

    vector<int> ans;

    if(root==nullptr)
        return ans;

    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()){

        int size=q.size();

        for(int i=0;i<size;i++){

            TreeNode* curr=q.front();
            q.pop();

            if(i==0)
                ans.push_back(curr->val);

            if(curr->left)
                q.push(curr->left);

            if(curr->right)
                q.push(curr->right);
        }
    }

    return ans;
}
```

---

# 5. Approach 2 - DFS

A DFS solution is also possible.

The idea is simple.

Whenever we visit a level **for the first time**, that node belongs to the Left View.

Since DFS explores the left subtree first,

the first node encountered at each depth is automatically the leftmost node.

---

## Algorithm

```
DFS(node, level)

If node == NULL

    return

If level == answer size

    Store node

DFS Left

DFS Right
```

---

## C++ Code

```cpp
void dfs(TreeNode* root, int level, vector<int>& ans){

    if(root==nullptr)
        return;

    if(level==ans.size())
        ans.push_back(root->val);

    dfs(root->left, level+1, ans);

    dfs(root->right, level+1, ans);
}

vector<int> leftView(TreeNode* root){

    vector<int> ans;

    dfs(root, 0, ans);

    return ans;
}
```

---

# Which Approach Should You Use?

| Approach | Recommendation |
|-----------|----------------|
| BFS | ⭐⭐⭐⭐⭐ Recommended |
| DFS | ⭐⭐⭐⭐ Excellent |
| Interview | Either is accepted |

If the problem already involves levels,

BFS feels more natural.

If you're already using recursion,

DFS is shorter.

---

# 6. Dry Run

Tree

```
          1
        /   \
       2     3
      / \     \
     4   5     6
```

Queue

```
1
```

Take first

```
1
```

---

Queue

```
2

3
```

Take first

```
2
```

---

Queue

```
4

5

6
```

Take first

```
4
```

Final Answer

```
1 2 4
```

---

# 7. Complexity Analysis

Let

```
n = Number of Nodes
```

## BFS

| Complexity | Value |
|------------|-------|
| Time | O(n) |
| Space | O(n) |

---

## DFS

| Complexity | Value |
|------------|-------|
| Time | O(n) |
| Space | O(h) |

where

```
h = Height of Tree
```

---

# 8. Pattern Connection

This is one of the most important sections for interview preparation.

| Problem | Core Observation |
|----------|------------------|
| Left View | First node at every level |
| Right View | Last node at every level |
| Top View | First node at every Horizontal Distance |
| Bottom View | Last node at every Horizontal Distance |
| Vertical Traversal | All nodes grouped by Horizontal Distance |

Notice the progression.

```
Level

↓

Horizontal Distance

↓

Coordinate System
```

Many tree interview problems are just variations of these ideas.

---

# 9. Interview Recognition

If the interviewer says

- Left Side
- Visible from Left
- First node of each level
- Leftmost node
- One node per level

Think immediately

```
Level Order

+

First Node
```

or

```
DFS

+

First Visit at Depth
```

---

# 10. Common Mistakes

### ❌ Taking the Last Node

Wrong

```cpp
if(i == size-1)
```

That gives the **Right View**, not the Left View.

---

### ❌ Visiting Right Before Left (DFS)

Wrong

```cpp
dfs(right)

dfs(left)
```

This changes the traversal and produces incorrect results.

Always visit

```cpp
left

↓

right
```

---

### ❌ Forgetting Empty Tree

Always handle

```cpp
if(root==nullptr)
```

---

### ❌ Using Level Order Without Level Size

Without

```cpp
int size = q.size();
```

you cannot determine the first node of a level.

---

# 11. Interview Follow-ups

### Q1. Can this be solved recursively?

Yes.

DFS with level tracking.

---

### Q2. Which approach is preferred?

Both are acceptable.

BFS is usually easier to explain.

DFS is shorter.

---

### Q3. What changes for Right View?

Instead of taking

```
First Node
```

take

```
Last Node
```

or visit the **right subtree before the left subtree** in DFS.

---

### Q4. Can this be done in O(1) extra space?

No.

Without modifying the tree, additional memory is required (queue or recursion stack).

---

# 12. Related Questions

## Easy

- Left View of Binary Tree (GeeksforGeeks)

---

## Medium

- Binary Tree Right Side View (LeetCode 199)
- Binary Tree Level Order Traversal (102)

---

## Similar Pattern

- Top View
- Bottom View
- Vertical Order Traversal

---

# 13. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐ |
| Microsoft | ⭐⭐⭐ |
| Google | ⭐⭐ |
| Adobe | ⭐⭐⭐ |
| Walmart | ⭐⭐⭐ |
| Atlassian | ⭐⭐⭐ |
| Oracle | ⭐⭐ |
| Goldman Sachs | ⭐⭐ |
| Flipkart | ⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐ |
| Accenture | ⭐⭐ |
| TCS Digital | ⭐⭐⭐ |

---

# 14. Quick Revision

✅ Core Idea

```
First Node

of

Every Level
```

---

✅ BFS

```cpp
if(i == 0)
```

Store Answer.

---

✅ DFS

```cpp
if(level == ans.size())
```

Store Answer.

---

✅ Time

```
O(n)
```

---

✅ Space

```
BFS → O(n)

DFS → O(h)
```

---

# Pattern Summary

```
First node of level

↓

Left View
```

Remember this single rule.

---

# Interview Checklist

Before submitting:

- [ ] Did I process exactly one level at a time?
- [ ] Am I taking the **first** node of every level?
- [ ] If using DFS, am I visiting the **left subtree before the right subtree**?
- [ ] Did I handle the empty tree?
- [ ] Is my complexity O(n)?