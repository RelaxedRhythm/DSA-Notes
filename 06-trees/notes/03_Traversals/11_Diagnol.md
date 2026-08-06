# 🌳 Diagonal Traversal of Binary Tree

> **Traversal Definition:** Group nodes lying on the same **diagonal** and print them from **top-right to bottom-left**.

> ⭐⭐⭐ **Difficulty:** Medium

> ⭐⭐⭐ **Interview Frequency:** Medium

---

# Table of Contents

1. Introduction
2. What is a Diagonal?
3. Visualization
4. Pattern Recognition
5. Approach 1 - BFS + Queue (Recommended)
6. Approach 2 - DFS + Map
7. Dry Run
8. Complexity Analysis
9. Pattern Connection
10. Common Mistakes
11. Interview Follow-ups
12. Related Questions
13. Company Favorites
14. Quick Revision

---

# 1. Introduction

Diagonal Traversal groups nodes that lie on the same **diagonal line**.

Unlike

- Vertical Traversal (Horizontal Distance)
- Level Order (Depth)

Diagonal Traversal follows a completely different rule.

Instead of moving vertically,

we move **along diagonals**.

---

Example

```
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
```

Diagonal Traversal

```
1 3 7 2 5 6 4
```

Notice

The tree is divided into diagonal groups.

---

# 2. What is a Diagonal?

Imagine drawing lines from the **top-right corner** towards the **bottom-left corner**.

Nodes on the same line belong to the same diagonal.

---

Diagonal Number Rules

Assign every node a **Diagonal Number (D)**.

```
Root

D = 0
```

Moving Right

```
Same Diagonal
```

```
D
```

remains unchanged.

---

Moving Left

```
Next Diagonal
```

```
D + 1
```

---

Example

```
              1(D0)

          /          \

     2(D1)          3(D0)

     /   \          /   \

4(D2) 5(D1) 6(D1) 7(D0)
```

Diagonal Groups

```
D0 → 1 3 7

D1 → 2 5 6

D2 → 4
```

---

# 3. Visualization

```
Diagonal 0

1 ---- 3 ---- 7

------------------

Diagonal 1

2 ---- 5 ---- 6

------------------

Diagonal 2

4
```

Output

```
1 3 7 2 5 6 4
```

---

# 4. Pattern Recognition

Keywords

- Diagonal
- Slant
- Same diagonal
- Top-right
- Bottom-left

Immediately think

```
Right Child

↓

Same Diagonal

Left Child

↓

Next Diagonal
```

---

# 5. Approach 1 - BFS + Queue (Recommended)

## Core Idea

The trick is simple:

- Move continuously along the **right pointers**.
- Whenever a **left child** is found, store it for processing later.

Think of it as processing **one diagonal at a time**.

---

## Algorithm

```
Push Root

While Queue not empty

    Pop Front

    Traverse Right Chain

        Print Node

        If Left Child Exists

            Push Left Child

        Move Right
```

---

## C++ Code

```cpp
vector<int> diagonal(TreeNode* root){

    vector<int> ans;

    if(root==nullptr)
        return ans;

    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()){

        TreeNode* curr=q.front();

        q.pop();

        while(curr){

            ans.push_back(curr->val);

            if(curr->left)
                q.push(curr->left);

            curr=curr->right;
        }
    }

    return ans;
}
```

---

# Why Does This Work?

Suppose

```
        1
      /   \
     2     3
          / \
         6   7
```

When visiting

```
1
```

we keep moving right

```
1

↓

3

↓

7
```

These belong to the same diagonal.

Whenever we encounter a left child

```
2

6
```

we save them for the next diagonal.

---

# 6. Approach 2 - DFS + Map

Assign every node a diagonal number.

Rules

```
Left Child

↓

Diagonal + 1
```

```
Right Child

↓

Same Diagonal
```

---

Store

```cpp
map<int, vector<int>>
```

where

```
Diagonal

↓

All Nodes
```

---

## DFS Code

```cpp
void dfs(TreeNode* root,
         int diagonal,
         map<int,vector<int>>& mp){

    if(root==nullptr)
        return;

    mp[diagonal].push_back(root->val);

    dfs(root->left,
        diagonal+1,
        mp);

    dfs(root->right,
        diagonal,
        mp);
}
```

---

Complete Driver

```cpp
vector<int> diagonal(TreeNode* root){

    vector<int> ans;

    map<int,vector<int>> mp;

    dfs(root,0,mp);

    for(auto &it:mp){

        ans.insert(ans.end(),
                   it.second.begin(),
                   it.second.end());
    }

    return ans;
}
```

---

# Which Approach Should You Use?

| Approach | Recommendation |
|----------|----------------|
| Queue | ⭐⭐⭐⭐⭐ Standard Interview Solution |
| DFS + Map | ⭐⭐⭐⭐ Easy to understand |
| Interview | Queue is preferred |

---

# 7. Dry Run

Tree

```
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
```

Queue

```
1
```

Traverse

```
1

↓

3

↓

7
```

Output

```
1 3 7
```

Queue

```
2

6
```

---

Process

```
2

↓

5
```

Output

```
1 3 7 2 5
```

Queue

```
6

4
```

---

Process

```
6
```

Output

```
1 3 7 2 5 6
```

---

Process

```
4
```

Final

```
1 3 7 2 5 6 4
```

---

# 8. Complexity Analysis

## Queue Approach

### Time

Each node is visited exactly once.

```
O(n)
```

---

### Space

Queue stores at most one diagonal.

Worst Case

```
O(n)
```

---

## DFS + Map

Time

```
O(n log n)
```

because of map insertions.

Space

```
O(n)
```

---

# 9. Pattern Connection

Compare all coordinate-based traversals.

| Problem | Coordinate |
|----------|------------|
| Level Order | Level |
| Vertical Order | Horizontal Distance |
| Vertical Traversal | Column + Row |
| Top View | Horizontal Distance |
| Bottom View | Horizontal Distance |
| Diagonal Traversal | Diagonal Number |

Notice

Every traversal problem changes only the coordinate system.

---

# 10. Common Mistakes

### ❌ Changing Diagonal for Right Child

Wrong

```
Right

↓

Diagonal + 1
```

Correct

```
Right

↓

Same Diagonal
```

---

### ❌ Forgetting Left Child

Always push the left child into the queue.

Otherwise,

entire diagonals are skipped.

---

### ❌ Confusing with Vertical Traversal

Vertical Traversal uses

```
Horizontal Distance
```

Diagonal Traversal uses

```
Diagonal Number
```

---

### ❌ Using Level Order

Diagonal Traversal is **not** level based.

---

# 11. Interview Follow-ups

### Q1. Why move continuously along the right chain?

Because all nodes connected through right edges belong to the same diagonal.

---

### Q2. Why are left children queued?

A left move always enters the next diagonal.

They must therefore be processed later.

---

### Q3. Can DFS solve this?

Yes.

Assign every node a diagonal number and group them in a map.

---

### Q4. Which solution is preferred?

The queue-based solution is shorter, more efficient (`O(n)`), and is the standard interview approach.

---

# 12. Related Questions

## Medium

- Diagonal Traversal of Binary Tree (GeeksforGeeks)

---

## Similar Problems

- Boundary Traversal
- Vertical Order
- Top View
- Bottom View

---

# 13. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐ |
| Microsoft | ⭐⭐⭐ |
| Google | ⭐⭐ |
| Adobe | ⭐⭐⭐ |
| Walmart | ⭐⭐⭐ |
| Atlassian | ⭐⭐ |
| Oracle | ⭐⭐⭐ |
| Goldman Sachs | ⭐⭐ |
| Flipkart | ⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐ |
| Accenture | ⭐ |
| TCS Digital | ⭐⭐ |

---

# 14. Quick Revision

✅ Diagonal Rules

```
Root

↓

Diagonal = 0
```

---

Left Child

```
Diagonal + 1
```

---

Right Child

```
Same Diagonal
```

---

✅ Queue Algorithm

```
Pop Node

↓

Traverse Right Chain

↓

Queue Left Children
```

---

✅ Time

```
Queue

↓

O(n)
```

---

✅ Space

```
O(n)
```

---

# Coordinate Pattern Summary

| Traversal | Coordinate Used |
|-----------|-----------------|
| Level Order | Level |
| Vertical Order | Horizontal Distance |
| Vertical Traversal | Column + Row |
| Diagonal Traversal | Diagonal Number |

---

# Interview Checklist

- [ ] Did I keep the right child on the same diagonal?
- [ ] Did I push every left child into the queue?
- [ ] Did I traverse the complete right chain before processing the next diagonal?
- [ ] Is my solution O(n) using the queue approach?
- [ ] Did I avoid confusing diagonals with Horizontal Distance?