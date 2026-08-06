# 🌳 Level Order Traversal (Breadth First Search)

> **Traversal Order:** Visit nodes **level by level** from **left to right**.

---

# Table of Contents

1. Introduction
2. Why BFS?
3. Visualization
4. Dry Run
5. Queue Intuition
6. Standard Level Order Traversal
7. Level-wise Traversal
8. Complexity Analysis
9. Interview Recognition
10. Common Mistakes
11. Interview Follow-ups
12. Related Questions
13. Company Favorites
14. Quick Revision

---

# 1. Introduction

**Level Order Traversal** is a **Breadth First Search (BFS)** traversal.

Unlike DFS, which goes as deep as possible before backtracking, BFS visits all nodes at one level before moving to the next.

Traversal Order

```
Level 0

↓

Level 1

↓

Level 2

↓

...
```

Unlike DFS, **Level Order always uses a Queue**.

---

# DFS vs BFS

Example Tree

```
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
```

DFS (Preorder)

```
1 2 4 5 3 6 7
```

BFS (Level Order)

```
1 2 3 4 5 6 7
```

Notice the difference.

DFS explores a branch completely.

BFS explores one level completely.

---

# 2. Why BFS?

Imagine you're exploring a building floor by floor.

```
Floor 1

↓

Floor 2

↓

Floor 3
```

You don't jump directly to the basement before checking the rest of the first floor.

Tree traversal works the same way.

Visit every node on one level before moving to the next.

---

# 3. Visualization

Tree

```
              1
           /     \
         2         3
       /  \      /   \
      4    5    6     7
     / \
    8   9
```

Levels

```
Level 0

          1

------------------

Level 1

      2       3

------------------

Level 2

   4    5   6   7

------------------

Level 3

 8   9
```

Output

```
1

2 3

4 5 6 7

8 9
```

---

# 4. Why Queue?

Think about people standing in a line.

```
A

↓

B

↓

C
```

The first person entering the line leaves first.

Queue follows

```
FIFO

First In First Out
```

This perfectly matches Level Order Traversal.

---

# 5. Queue Intuition

Initially

Queue

```
1
```

Pop

```
Visit 1
```

Push children

```
2

3
```

Pop

```
Visit 2
```

Push children

```
3

4

5
```

Pop

```
Visit 3
```

Push children

```
4

5

6

7
```

Continue until the queue becomes empty.

---

# 6. Standard Level Order Traversal

## Algorithm

```
Push Root into Queue

While Queue is not empty

    Pop Front

    Visit Node

    Push Left Child

    Push Right Child
```

---

## C++ Code

```cpp
vector<int> levelOrder(TreeNode* root){

    vector<int> ans;

    if(root==nullptr)
        return ans;

    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()){

        TreeNode* curr=q.front();
        q.pop();

        ans.push_back(curr->val);

        if(curr->left)
            q.push(curr->left);

        if(curr->right)
            q.push(curr->right);
    }

    return ans;
}
```

---

# 7. Level-wise Traversal

Many interview questions require answers grouped by levels.

Example

```
[
 [1],
 [2,3],
 [4,5,6,7]
]
```

Instead of a single list.

---

## Key Idea

Before processing a level,

store

```
queue.size()
```

This tells us exactly how many nodes belong to the current level.

---

## Dry Run

Queue

```
1
```

Size

```
1
```

Process

```
1
```

Queue

```
2

3
```

Size

```
2
```

Process

```
2

3
```

Queue

```
4

5

6

7
```

Size

```
4
```

Process

```
4

5

6

7
```

Done.

---

## C++ Code

```cpp
vector<vector<int>> levelOrder(TreeNode* root){

    vector<vector<int>> ans;

    if(root==nullptr)
        return ans;

    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()){

        int size=q.size();

        vector<int> level;

        while(size--){

            TreeNode* curr=q.front();
            q.pop();

            level.push_back(curr->val);

            if(curr->left)
                q.push(curr->left);

            if(curr->right)
                q.push(curr->right);
        }

        ans.push_back(level);
    }

    return ans;
}
```

---

# 8. Complexity Analysis

Let

```
n = Number of Nodes
```

## Time Complexity

Every node is

- inserted once
- removed once

```
O(n)
```

---

## Space Complexity

Queue stores at most one complete level.

Worst case

```
O(n)
```

For a complete binary tree, the last level can contain approximately `n/2` nodes, so the queue size can grow to **O(n)**.

---

# 9. Why Level Order is Important?

Many interview questions are simply variations of Level Order Traversal.

Examples

- Zigzag Traversal
- Left View
- Right View
- Vertical Order
- Top View
- Bottom View
- Average of Levels
- Maximum Level Sum
- Cousins in Binary Tree
- Connect Next Right Pointer

Master Level Order once.

Many BFS problems become straightforward.

---

# 10. Interview Recognition

If the interviewer says

- Level by level
- Same level
- Nearest node
- Shortest path in an unweighted tree
- View from left
- View from right
- Width of tree
- Maximum level
- Average of every level

Think immediately

```
Queue

↓

Level Order Traversal
```

---

# 11. Common Mistakes

### ❌ Forgetting Empty Tree

Always handle

```cpp
if(root==nullptr)
    return {};
```

---

### ❌ Using Stack Instead of Queue

Wrong

```
Stack

↓

DFS
```

Correct

```
Queue

↓

BFS
```

---

### ❌ Not Storing Level Size

Without

```cpp
int size=q.size();
```

you cannot separate one level from the next.

---

### ❌ Accessing q.front() After pop()

Wrong

```cpp
q.pop();

q.front();
```

After popping, the front has changed.

Always save the node before popping.

Correct

```cpp
TreeNode* curr=q.front();

q.pop();
```

---

# 12. Interview Follow-ups

### Q1. Can Level Order be done recursively?

Yes.

Using DFS with a level parameter.

Example

```cpp
dfs(node, level)
```

If `level == ans.size()`, create a new vector.

However, the queue-based solution is simpler and is the standard interview approach.

---

### Q2. Why use Queue instead of Stack?

Queue preserves the order in which nodes are discovered at the same level.

A stack would immediately dive deeper, producing DFS instead of BFS.

---

### Q3. Can Level Order solve Left View and Right View?

Yes.

While processing each level:

- First node → Left View
- Last node → Right View

---

### Q4. Can BFS compute tree height?

Yes.

Count how many levels are processed.

This gives the tree height in terms of levels. If height is defined as the number of **edges**, subtract 1 for a non-empty tree.

---

# 13. Related Questions

## Easy

- Binary Tree Level Order Traversal (102)
- Maximum Depth of Binary Tree (104)
- Average of Levels in Binary Tree (637)

---

## Medium

- Binary Tree Zigzag Level Order Traversal (103)
- Binary Tree Right Side View (199)
- Find Largest Value in Each Tree Row (515)
- Maximum Level Sum of a Binary Tree (1161)

---

## Hard

- Vertical Order Traversal of a Binary Tree (987)
- Serialize and Deserialize Binary Tree (297) *(BFS approach)*

---

# 14. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐⭐⭐ |
| Microsoft | ⭐⭐⭐⭐⭐ |
| Google | ⭐⭐⭐⭐ |
| Adobe | ⭐⭐⭐⭐ |
| Walmart | ⭐⭐⭐⭐ |
| Atlassian | ⭐⭐⭐⭐ |
| Oracle | ⭐⭐⭐⭐ |
| Goldman Sachs | ⭐⭐⭐ |
| Flipkart | ⭐⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐⭐ |
| Accenture | ⭐⭐⭐ |
| TCS Digital | ⭐⭐⭐⭐ |

---

# 15. Quick Revision

✅ Traversal Type

```
Breadth First Search (BFS)
```

✅ Data Structure

```
Queue
```

✅ Traversal Order

```
Level by Level
```

✅ Time

```
O(n)
```

✅ Space

```
O(n)
```

✅ Level-wise Traversal Trick

```cpp
int size = q.size();
```

Process exactly `size` nodes before moving to the next level.

---

# Interview Checklist

Before submitting:

- [ ] Did I check for an empty tree?
- [ ] Am I using a **queue**, not a stack?
- [ ] Am I pushing the left child before the right child?
- [ ] If the problem is level-based, did I store `q.size()` before processing the level?
- [ ] Is my complexity **O(n)** time and **O(n)** space?