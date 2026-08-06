# 🌳 Right View of Binary Tree

> **View Definition:** The set of nodes visible when the tree is viewed from the **right side**.

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

The **Right View** of a binary tree consists of the **last visible node at every level** when looking at the tree from the right.

Like Left View, we print **exactly one node from each level**.

The only difference is **which node we choose**.

---

Example

Tree

```
          1
        /   \
       2     3
      / \     \
     4   5     6
          \
           7
```

Right View

```
1 3 6 7
```

Explanation

```
Level 0 → 1

Level 1 → 3

Level 2 → 6

Level 3 → 7
```

Always select the **last node** at every level.

---

# 2. Visualization

```
Right Side

↓

          1
         / \
        2   3
       / \   \
      4   5   6
           \
            7
```

Visible Nodes

```
1

↓

3

↓

6

↓

7
```

---

# 3. Pattern Recognition

The key observation is:

> **Right View = Last node of every level**

This immediately suggests **Level Order Traversal (BFS)**.

While processing each level,

the **last node** encountered belongs to the Right View.

---

# 4. Approach 1 - BFS (Recommended)

## Intuition

Process one level at a time.

When processing

```cpp
size
```

nodes,

the last node is

```cpp
i == size - 1
```

Store that node.

---

## Algorithm

```
Push Root

While Queue not empty

    size = Queue Size

    Process all nodes

        If last node

            Save Answer

        Push Left Child

        Push Right Child
```

---

## C++ Code

```cpp
vector<int> rightView(TreeNode* root){

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

            if(i==size-1)
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

DFS works by visiting the **right subtree first**.

Whenever a level is visited for the first time,

that node belongs to the Right View.

---

## Algorithm

```
DFS(node, level)

If node == NULL

    return

If level == answer size

    Save node

DFS Right

DFS Left
```

---

## C++ Code

```cpp
void dfs(TreeNode* root,int level,vector<int>& ans){

    if(root==nullptr)
        return;

    if(level==ans.size())
        ans.push_back(root->val);

    dfs(root->right,level+1,ans);

    dfs(root->left,level+1,ans);
}

vector<int> rightView(TreeNode* root){

    vector<int> ans;

    dfs(root,0,ans);

    return ans;
}
```

---

# Which Approach Should You Use?

| Approach | Recommendation |
|-----------|----------------|
| BFS | ⭐⭐⭐⭐⭐ Best for beginners |
| DFS | ⭐⭐⭐⭐ Elegant |
| Interview | Either |

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

Take

```
Last Node

↓

1
```

---

Queue

```
2

3
```

Take

```
3
```

---

Queue

```
4

5

6
```

Take

```
6
```

Final Answer

```
1 3 6
```

---

# 7. Complexity Analysis

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

---

# 8. Pattern Connection

Compare the view problems.

| View | Rule |
|------|------|
| Left View | First node of every level |
| Right View | Last node of every level |
| Top View | First node at every Horizontal Distance |
| Bottom View | Last node at every Horizontal Distance |

Notice the pattern.

```
Level

↓

First / Last

↓

View Problem
```

Learning this relationship makes recognition much easier during interviews.

---

# 9. Interview Recognition

If the interviewer says

- Right Side
- Visible from Right
- Rightmost node
- Last node at each level
- One node per level

Think immediately

```
Level Order

+

Last Node
```

or

```
DFS

+

Right First
```

---

# 10. Common Mistakes

### ❌ Taking the First Node

Wrong

```cpp
if(i==0)
```

That produces the Left View.

---

### ❌ DFS Visiting Left First

Wrong

```cpp
dfs(left)

dfs(right)
```

Correct

```cpp
dfs(right)

dfs(left)
```

---

### ❌ Forgetting Empty Tree

Always check

```cpp
if(root==nullptr)
```

---

### ❌ Mixing Up Queue Order

Even though we're computing the Right View,

children are still inserted in normal BFS order.

```cpp
left

↓

right
```

Only the **selected node** changes.

---

# 11. Interview Follow-ups

### Q1. Can this be solved recursively?

Yes.

Visit the right subtree before the left subtree.

---

### Q2. Why does DFS work?

Because the first node reached at every depth (while exploring right first) is the rightmost visible node.

---

### Q3. Can Left View and Right View be solved using one template?

Yes.

For BFS:

- First node → Left View
- Last node → Right View

For DFS:

- Left-first → Left View
- Right-first → Right View

---

### Q4. Which solution is preferred?

Both are accepted.

If the question already uses BFS, continue with BFS.

If recursion is already being used, DFS is concise and elegant.

---

# 12. Related Questions

## Easy

- Binary Tree Right Side View (LeetCode 199)

---

## Medium

- Binary Tree Level Order Traversal (102)
- Binary Tree Zigzag Level Order Traversal (103)

---

## Similar Pattern

- Left View
- Top View
- Bottom View
- Vertical Order

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
| Oracle | ⭐⭐⭐ |
| Goldman Sachs | ⭐⭐⭐ |
| Flipkart | ⭐⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐⭐ |
| Accenture | ⭐⭐ |
| TCS Digital | ⭐⭐⭐ |

---

# 14. Quick Revision

✅ Core Idea

```
Last Node

of

Every Level
```

---

✅ BFS

```cpp
if(i == size - 1)
```

Store Answer.

---

✅ DFS

```cpp
Visit Right

↓

Visit Left
```

Store the first node encountered at each depth.

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

# Left View vs Right View

| Left View | Right View |
|-----------|------------|
| First node of level | Last node of level |
| DFS: Left → Right | DFS: Right → Left |
| BFS: `i == 0` | BFS: `i == size-1` |

This comparison is frequently tested in interviews.

---

# Interview Checklist

Before submitting:

- [ ] Am I selecting the **last** node of each level?
- [ ] If using DFS, am I visiting the **right subtree first**?
- [ ] Did I process the tree level by level (BFS) if using a queue?
- [ ] Did I handle the empty tree?
- [ ] Is my solution O(n)?