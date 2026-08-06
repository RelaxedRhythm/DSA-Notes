# 🌳 Top View of Binary Tree

> **View Definition:** The set of nodes visible when the tree is viewed from the **top**.

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

The **Top View** of a binary tree consists of the **first node visible** at every **Horizontal Distance (HD)** when looking at the tree from above.

Unlike Left View and Right View, we are **not concerned with levels**.

Instead, we group nodes by their **Horizontal Distance**.

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

Top View

```
2 1 3 6
```

Why?

```
HD = -1 → 2

HD =  0 → 1

HD = +1 → 3

HD = +2 → 6
```

Although nodes **4** and **5** also have HD = 0, they are hidden because **1** appears first.

---

# 2. Coordinate System (Horizontal Distance)

This is the most important concept.

Assign every node a **Horizontal Distance (HD)** from the root.

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

Both **5** and **6** have

```
HD = 0
```

This is why we need a rule to decide which one belongs to the Top View.

---

# Top View Rule

> **The first node encountered at each Horizontal Distance is part of the Top View.**

Since BFS visits nodes level by level,

the first node seen at an HD is always the topmost one.

---

# 3. Visualization

```
               ▲
          Top View

               |

               1

          /         \

         2           3

       /   \       /   \

      4     5     6     7
```

Horizontal Distances

```
      -2  -1   0   +1   +2
```

Top View

```
4 2 1 3 7
```

Nodes **5** and **6** are hidden.

---

# 4. Pattern Recognition

Observe the keywords.

```
Top

Visible

Columns

Horizontal
```

Immediately think

```
Horizontal Distance

+

BFS

+

Map
```

Unlike Left View,

we are **not processing one level at a time**.

We are grouping nodes into **vertical columns**.

---

# 5. Approach - BFS + Horizontal Distance

## Why BFS?

Suppose two nodes have the same Horizontal Distance.

```
      1

     /

    2

     \

      3
```

HD

```
1 → 0

2 → -1

3 → 0
```

Both **1** and **3** have HD = 0.

The Top View should contain

```
1
```

because it appears first from the top.

BFS guarantees this naturally.

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

First Node
```

A `map` keeps the HDs sorted from leftmost to rightmost.

---

## Algorithm

```
Push (Root, 0)

While Queue not empty

    Pop Front

    If HD not present

        Store Node

    Push Left Child

        HD - 1

    Push Right Child

        HD + 1

Print Map
```

---

## C++ Code

```cpp
vector<int> topView(TreeNode* root){

    vector<int> ans;

    if(root==nullptr)
        return ans;

    map<int,int> mp;

    queue<pair<TreeNode*,int>> q;

    q.push({root,0});

    while(!q.empty()){

        auto [curr,hd]=q.front();

        q.pop();

        if(mp.find(hd)==mp.end())
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

HD = 0 already exists.

Ignore both.

Final Map

```
-1 → 2

0 → 1

1 → 3
```

Output

```
2 1 3
```

---

# 7. Complexity Analysis

Let

```
n = Number of Nodes
```

## Time

Each node is visited once.

Each map insertion/search takes

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

> **Interview Tip:** If the problem doesn't require sorted output, `unordered_map` can reduce map operations to average O(1). However, for Top View, we usually need the output from leftmost HD to rightmost HD, so `map` is the standard choice.

---

# 8. Pattern Connection

This is one of the most important interview patterns.

| Problem | Rule |
|----------|------|
| Left View | First node of every level |
| Right View | Last node of every level |
| Top View | First node at every HD |
| Bottom View | Last node at every HD |
| Vertical Order | Store **all** nodes at every HD |

Notice the progression.

```
Level Problems

↓

Horizontal Distance Problems

↓

Coordinate Problems
```

Once you recognize **Horizontal Distance**, most view problems become much easier.

---

# 9. Interview Recognition

If the interviewer says

- Top View
- Visible from Top
- Vertical Columns
- Horizontal Distance
- Overlapping Nodes

Think immediately

```
Queue

+

Horizontal Distance

+

Map
```

---

# 10. Common Mistakes

### ❌ Using DFS Without Extra Care

A simple DFS may visit a deeper node before a shallower one at the same HD.

BFS naturally processes nodes level by level, making it the preferred approach.

If using DFS, you must also track the depth and only update the map when a node is higher (smaller depth).

---

### ❌ Overwriting Existing Nodes

Wrong

```cpp
mp[hd] = curr->val;
```

This replaces the first node.

Correct

```cpp
if(mp.find(hd)==mp.end())
    mp[hd]=curr->val;
```

---

### ❌ Forgetting Horizontal Distance

Many students solve Left View instead of Top View because they think only in terms of levels.

Top View depends on **HD**, not just the level.

---

### ❌ Using unordered_map Directly

`unordered_map` does not maintain key order.

If you iterate over it directly, the output will not be left-to-right.

---

# 11. Interview Follow-ups

### Q1. Why is BFS preferred?

Because BFS guarantees that the first node seen at a given HD is the topmost node.

---

### Q2. Can DFS solve this?

Yes.

But you must store both:

- Horizontal Distance
- Depth

Only replace a node if the new node has a **smaller depth**.

---

### Q3. Why use a map?

To print the answer in increasing order of HD.

```
Left

↓

Right
```

---

### Q4. How does Bottom View differ?

Only one rule changes.

Instead of keeping the **first** node at each HD,

keep the **last** node.

Everything else remains almost identical.

---

# 12. Related Questions

## Medium

- Top View of Binary Tree (GeeksforGeeks)

---

## Similar Pattern

- Bottom View of Binary Tree
- Vertical Order Traversal
- Vertical Traversal (LeetCode 987)
- Width of Binary Tree

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
First Node

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

# Pattern Summary

```
Horizontal Distance

+

First Node

↓

Top View
```

---

# Interview Checklist

Before submitting:

- [ ] Did I assign the correct Horizontal Distance?
- [ ] Am I using BFS to ensure topmost nodes are processed first?
- [ ] Am I storing only the **first** node at each HD?
- [ ] Does my map produce output from leftmost HD to rightmost HD?
- [ ] Is my complexity O(n log n) with `map`?