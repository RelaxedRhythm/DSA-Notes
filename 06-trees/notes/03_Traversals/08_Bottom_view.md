# 🌳 Bottom View of Binary Tree

> **View Definition:** The set of nodes visible when the tree is viewed from the **bottom**.

---

# Table of Contents

1. Introduction
2. Coordinate System (Horizontal Distance)
3. Visualization
4. Pattern Recognition
5. Approach - BFS + Horizontal Distance (Recommended)
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

The **Bottom View** of a binary tree consists of the **last visible node** at every **Horizontal Distance (HD)** when looking at the tree from below.

This is almost identical to **Top View**.

The only difference is **which node we keep**.

---

Example

Tree

```
           1
         /   \
        2     3
         \   / \
          4 5   6
```

Horizontal Distances

```
HD = -1 → 2

HD =  0 → 1,4,5

HD = +1 → 3

HD = +2 → 6
```

Bottom View

```
2 5 3 6
```

Node **5** hides **1** and **4** because it is the lowest visible node at HD = 0.

---

# 2. Coordinate System (Horizontal Distance)

The same coordinate system from **Top View** is used.

Rules

```
Root

HD = 0
```

Moving Left

```
HD - 1
```

Moving Right

```
HD + 1
```

---

Example

```
          1(0)

        /      \

   2(-1)      3(+1)

    /   \      /   \

4(-2) 5(0) 6(0) 7(+2)
```

Notice

```
5

and

6
```

share the same HD.

Unlike Top View,

we **do not stop** after seeing the first node.

We continue updating.

---

# Bottom View Rule

> **The last node encountered at every Horizontal Distance belongs to the Bottom View.**

Since BFS visits the tree level by level,

deeper nodes naturally overwrite shallower ones.

---

# 3. Visualization

```
              1

           /     \

         2         3

       /   \     /   \

      4     5   6     7

             \
              8
```

Horizontal Distances

```
-2   -1    0    +1    +2
```

Bottom View

```
4 2 5 8 7
```

---

# 4. Pattern Recognition

Keywords

```
Bottom

Visible

Columns

Horizontal Distance
```

Immediately think

```
Queue

+

Horizontal Distance

+

Overwrite Map
```

---

# 5. Approach - BFS + Horizontal Distance

## Intuition

Unlike Top View,

we **always overwrite** the current value stored for an HD.

The last processed node becomes the answer.

---

## Data Structures

```cpp
queue<pair<TreeNode*, int>>
```

Stores

```
Node

+

Horizontal Distance
```

---

```cpp
map<int,int>
```

Stores

```
HD

↓

Latest Node
```

---

## Algorithm

```
Push (Root,0)

While Queue not empty

    Pop Node

    Update Map

    Push Left Child

        HD-1

    Push Right Child

        HD+1

Print Map
```

---

## C++ Code

```cpp
vector<int> bottomView(TreeNode* root){

    vector<int> ans;

    if(root==nullptr)
        return ans;

    map<int,int> mp;

    queue<pair<TreeNode*,int>> q;

    q.push({root,0});

    while(!q.empty()){

        auto [curr,hd]=q.front();

        q.pop();

        mp[hd]=curr->val;

        if(curr->left)
            q.push({curr->left,hd-1});

        if(curr->right)
            q.push({curr->right,hd+1});
    }

    for(auto &it:mp)
        ans.push_back(it.second);

    return ans;
}
```

---

# 6. Dry Run

Tree

```
          1
        /   \
       2     3
        \   /
         4 5
```

Queue

```
(1,0)
```

Map

```
0 → 1
```

---

Process

```
(2,-1)

(3,+1)
```

Map

```
-1 → 2

0 → 1

1 → 3
```

---

Process

```
(4,0)

(5,0)
```

Updates

```
0 → 4

↓

0 → 5
```

Final Map

```
-1 → 2

0 → 5

1 → 3
```

Output

```
2 5 3
```

---

# 7. Complexity Analysis

Let

```
n = Number of Nodes
```

## Time

Each node is processed once.

Each map operation

```
O(log n)
```

Total

```
O(n log n)
```

---

## Space

Queue

```
O(n)
```

Map

```
O(n)
```

Overall

```
O(n)
```

---

# 8. Pattern Connection

This table is worth memorizing.

| Problem | Rule |
|----------|------|
| Left View | First node of every level |
| Right View | Last node of every level |
| Top View | First node at every HD |
| Bottom View | Last node at every HD |
| Vertical Order | Store all nodes at every HD |

Notice

Only **one line changes** between Top View and Bottom View.

Top View

```
Keep First
```

Bottom View

```
Keep Last
```

---

# 9. Interview Recognition

If the interviewer mentions

- Bottom View
- Visible from Bottom
- Lowest Node
- Vertical Columns
- Horizontal Distance

Think

```
Queue

+

Horizontal Distance

+

Overwrite
```

---

# 10. Common Mistakes

### ❌ Using Top View Logic

Wrong

```cpp
if(mp.find(hd)==mp.end())
```

That computes the Top View.

---

Correct

```cpp
mp[hd]=curr->val;
```

Always overwrite.

---

### ❌ Forgetting Horizontal Distance

Bottom View is **not** a level problem.

It is a **column problem**.

---

### ❌ Using DFS Without Tracking Depth

A simple DFS cannot guarantee the bottommost node.

If using DFS, you must compare node depths and keep the deepest node for each HD.

BFS avoids this extra bookkeeping because it processes levels from top to bottom.

---

### ❌ Using unordered_map

Iteration order is undefined.

Output may not be left-to-right.

---

# 11. Interview Follow-ups

### Q1. Why does overwriting work?

BFS processes higher levels before lower levels.

Therefore,

later updates naturally represent lower (or equally deep but later visited) nodes.

---

### Q2. Can DFS solve this?

Yes.

Track

- Horizontal Distance
- Depth

Update the map only if the current node is deeper.

---

### Q3. Difference between Top View and Bottom View?

Only one statement.

Top View

```cpp
if(mp.find(hd)==mp.end())
    mp[hd]=value;
```

Bottom View

```cpp
mp[hd]=value;
```

---

### Q4. What if two nodes have the same HD and the same depth?

Different platforms define tie-breaking differently.

For example, GeeksforGeeks and LeetCode variants may specify different expectations.

When solving an interview problem, always follow the problem statement's tie-breaking rule if one is given.

---

# 12. Related Questions

## Medium

- Bottom View of Binary Tree (GeeksforGeeks)

---

## Similar Pattern

- Top View
- Vertical Order Traversal
- Vertical Traversal (LeetCode 987)
- Width of Binary Tree

---

# 13. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐⭐ |
| Microsoft | ⭐⭐⭐ |
| Google | ⭐⭐⭐ |
| Adobe | ⭐⭐⭐ |
| Walmart | ⭐⭐⭐ |
| Atlassian | ⭐⭐⭐ |
| Oracle | ⭐⭐⭐ |
| Goldman Sachs | ⭐⭐⭐ |
| Flipkart | ⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐ |
| Accenture | ⭐⭐ |
| TCS Digital | ⭐⭐⭐ |

---

# 14. Quick Revision

✅ Horizontal Distance

```
Root = 0

Left = HD - 1

Right = HD + 1
```

---

✅ Rule

```
Last Node

at

Every HD
```

---

✅ Data Structures

```cpp
queue<pair<Node*, int>>
map<int,int>
```

---

✅ Time

```
O(n log n)
```

---

✅ Space

```
O(n)
```

---

# Top View vs Bottom View

| Top View | Bottom View |
|----------|-------------|
| First node at HD | Last node at HD |
| Do not overwrite | Always overwrite |
| First visible | Lowest visible |

Remember:

```
Same Algorithm

↓

One Line Changes
```

---

# Interview Checklist

Before submitting:

- [ ] Did I assign the correct Horizontal Distance?
- [ ] Am I overwriting the value for each HD?
- [ ] Am I using a `map` to maintain left-to-right order?
- [ ] Did I handle the empty tree?
- [ ] Is my solution O(n log n)?