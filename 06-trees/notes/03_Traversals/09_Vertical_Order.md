# 🌳 Vertical Order Traversal

> **Traversal Definition:** Group all nodes having the same **Horizontal Distance (HD)** and print them from **leftmost column to rightmost column**.

---

# Table of Contents

1. Introduction
2. Coordinate System
3. Visualization
4. Pattern Recognition
5. BFS + Horizontal Distance (Recommended)
6. Dry Run
7. Complexity Analysis
8. Pattern Connection
9. Vertical Order vs Vertical Traversal
10. Interview Recognition
11. Common Mistakes
12. Interview Follow-ups
13. Related Questions
14. Company Favorites
15. Quick Revision

---

# 1. Introduction

Vertical Order Traversal groups nodes into **vertical columns**.

Unlike

- Top View
- Bottom View

we **do not discard any nodes**.

Instead,

every node belonging to the same Horizontal Distance is stored together.

---

Example

Tree

```
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
```

Horizontal Distances

```
HD

-2 → 4

-1 → 2

 0 → 1 5 6

+1 → 3

+2 → 7
```

Output

```
[
 [4],
 [2],
 [1,5,6],
 [3],
 [7]
]
```

Notice

Both

```
5

and

6
```

belong to the same vertical column.

---

# 2. Coordinate System

Exactly the same Horizontal Distance rules.

```
Root

HD = 0
```

Left

```
HD - 1
```

Right

```
HD + 1
```

---

Example

```
          1(0)

       /        \

   2(-1)       3(+1)

   /   \       /   \

4(-2) 5(0) 6(0) 7(+2)
```

Unlike Top View,

every node is stored.

---

# 3. Visualization

```
Vertical Columns

HD

-2   -1    0    +1    +2

 |     |     |      |      |

 4     2   1 5 6    3      7
```

Output

```
[
 [4],
 [2],
 [1,5,6],
 [3],
 [7]
]
```

---

# 4. Pattern Recognition

Keywords

- Vertical
- Column
- Same HD
- Group nodes
- Vertical lines

Immediately think

```
Queue

+

Horizontal Distance

+

Map

+

Vector
```

---

# 5. BFS + Horizontal Distance

## Why BFS?

BFS naturally visits

```
Top

↓

Bottom
```

Therefore,

nodes inside each column are stored in level order.

---

## Data Structures

Queue

```cpp
queue<pair<TreeNode*,int>>
```

Stores

```
Node

+

Horizontal Distance
```

---

Map

```cpp
map<int,vector<int>>
```

Stores

```
HD

↓

All Nodes
```

---

## Algorithm

```
Push (Root,0)

While Queue not empty

    Pop Front

    Append node to map[HD]

    Push Left Child

        HD-1

    Push Right Child

        HD+1

Print map
```

---

## C++ Code

```cpp
vector<vector<int>> verticalOrder(TreeNode* root){

    vector<vector<int>> ans;

    if(root==nullptr)
        return ans;

    map<int,vector<int>> mp;

    queue<pair<TreeNode*,int>> q;

    q.push({root,0});

    while(!q.empty()){

        auto [curr,hd]=q.front();

        q.pop();

        mp[hd].push_back(curr->val);

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
0 → [1]
```

---

Process

```
(2,-1)

(3,+1)
```

Map

```
-1 → [2]

0 → [1]

1 → [3]
```

---

Process

```
(4,0)

(5,0)
```

Map

```
-1 → [2]

0 → [1,4,5]

1 → [3]
```

Output

```
[
 [2],
 [1,4,5],
 [3]
]
```

---

# 7. Complexity Analysis

Let

```
n = Number of Nodes
```

## Time

Each node visited once.

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

Notice the progression.

| Problem | Keep |
|----------|------|
| Top View | First node |
| Bottom View | Last node |
| Vertical Order | All nodes |
| Vertical Traversal | All nodes + sorting rules |

The algorithm barely changes.

Only the map value changes.

```
Top View

HD → Node

↓

Bottom View

HD → Node

↓

Vertical Order

HD → Vector
```

---

# 9. Vertical Order vs Vertical Traversal

These two are **NOT** the same.

## Vertical Order

Within each column,

keep BFS order.

```
HD

↓

Visit Order
```

---

## Vertical Traversal (LeetCode 987)

Sort by

1. Column (HD)
2. Row (Level)
3. Node Value (if row and column are the same)

This requires extra data structures.

We'll cover it in the next file.

---

# 10. Interview Recognition

If the interviewer says

- Vertical Columns
- Group by Column
- Same Horizontal Distance
- Vertical Order

Think immediately

```
Queue

+

HD

+

map<int,vector<int>>
```

---

# 11. Common Mistakes

### ❌ Confusing Vertical Order with Vertical Traversal

Vertical Order

```
BFS Order
```

Vertical Traversal

```
Sorted by

Level

↓

Value
```

These are different problems.

---

### ❌ Overwriting Nodes

Wrong

```cpp
mp[hd]=value;
```

Correct

```cpp
mp[hd].push_back(value);
```

---

### ❌ Using unordered_map

Columns will appear in random order.

Always use

```cpp
map
```

unless the problem explicitly allows unordered output.

---

### ❌ Forgetting Horizontal Distance

Vertical problems are always HD-based.

Not level-based.

---

# 12. Interview Follow-ups

### Q1. Why BFS?

BFS preserves top-to-bottom order within each vertical column.

---

### Q2. Can DFS solve this?

Yes.

But you'll need to store the depth of every node and sort later if the required order depends on row.

BFS is simpler for standard Vertical Order.

---

### Q3. Difference from Top View?

Top View

```
One node
```

Vertical Order

```
All nodes
```

---

### Q4. Difference from Bottom View?

Bottom View

```
Last node
```

Vertical Order

```
Entire column
```

---

# 13. Related Questions

## Medium

- Binary Tree Vertical Order Traversal (LintCode / GFG variants)

---

## Hard

- Vertical Order Traversal of a Binary Tree (LeetCode 987)

---

## Similar Pattern

- Top View
- Bottom View
- Width of Binary Tree

---

# 14. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐⭐ |
| Microsoft | ⭐⭐⭐⭐ |
| Google | ⭐⭐⭐⭐ |
| Adobe | ⭐⭐⭐ |
| Walmart | ⭐⭐⭐⭐ |
| Atlassian | ⭐⭐⭐⭐ |
| Oracle | ⭐⭐⭐ |
| Goldman Sachs | ⭐⭐⭐ |
| Flipkart | ⭐⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐ |
| Accenture | ⭐⭐ |
| TCS Digital | ⭐⭐⭐ |

---

# 15. Quick Revision

✅ Horizontal Distance

```
Root = 0

Left = HD - 1

Right = HD + 1
```

---

✅ Rule

```
Store

Every Node

for

Every HD
```

---

✅ Data Structures

```cpp
queue<pair<Node*,int>>

map<int,vector<int>>
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

# View Problems Summary

| Problem | Map Value |
|----------|-----------|
| Top View | `map<int,int>` (first node) |
| Bottom View | `map<int,int>` (last node) |
| Vertical Order | `map<int,vector<int>>` |
| Vertical Traversal | `map<int,map<int,multiset<int>>>` (or equivalent sorted structure) |

---

# Interview Checklist

- [ ] Did I compute the correct Horizontal Distance?
- [ ] Am I storing **all** nodes for each HD?
- [ ] Am I using `map<int, vector<int>>`?
- [ ] Am I preserving BFS order inside each column?
- [ ] Did I confuse this with LeetCode 987?
- [ ] Is my complexity O(n log n)?