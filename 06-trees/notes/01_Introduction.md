# 🌳 Trees - Introduction

> **Chapter 1 | Foundations**

---

# Table of Contents

1. What is a Tree?
2. Why Trees?
3. Real World Examples
4. Tree Terminology
5. Types of Nodes
6. Tree Properties
7. Types of Binary Trees
8. Representation of Trees
9. Time Complexity Basics
10. Interview Insights
11. Common Mistakes
12. Quick Revision

---

# What is a Tree?

A **Tree** is a **non-linear hierarchical data structure** consisting of **nodes** connected by **edges**.

Unlike arrays or linked lists, trees represent **parent-child relationships**.

Example:

```
        A
      /   \
     B     C
    / \   / \
   D   E F   G
```

- Every circle is a **Node**
- Every line is an **Edge**

---

## Interview Definition

> A Tree is a connected acyclic graph.

Meaning:

✅ Connected

Every node can be reached.

✅ No Cycles

There is exactly one path between any two nodes.

---

# Why Trees?

Trees are used whenever data naturally forms a hierarchy.

Examples:

```
File System

C:
│
├── Users
│   ├── Rhythm
│   └── Guest
│
├── Windows
│
└── Program Files
```

---

```
Organization

CEO
├── CTO
│   ├── Engineers
│   └── Interns
│
└── CFO
```

---

```
HTML DOM

<html>

 ├── head

 └── body
      ├── div
      ├── img
      └── p
```

---

Google Search

Decision Trees

Trie Dictionary

Binary Search Tree

Heap

Compiler Syntax Tree

Expression Tree

XML / JSON

Database Indexes

Git Commit History (DAG)

---

# Why are Trees Important in Interviews?

Trees test several core skills at once:

- Recursion
- DFS
- BFS
- Divide & Conquer
- Dynamic Programming on Trees
- Backtracking
- Graph Thinking

This is why product companies ask tree questions very frequently.

---

# Basic Terminology

Consider

```
            1
          /   \
         2     3
       /  \     \
      4    5     6
```

---

## Root

Top-most node.

```
1
```

Every tree has exactly one root.

---

## Parent

Node directly above another node.

Example

```
Parent of 4 = 2
```

---

## Child

Node directly below another node.

```
Children of 2

4

5
```

---

## Siblings

Nodes having same parent.

```
4 and 5

are siblings.
```

---

## Edge

Connection between two nodes.

```
2 ---- 4
```

is one edge.

---

## Leaf Node

Node having no children.

```
4

5

6
```

are leaf nodes.

Also called

External Nodes

Terminal Nodes

---

## Internal Node

Any node having at least one child.

```
1

2

3
```

---

## Degree of Node

Number of children.

Example

```
Node 1 → degree = 2

Node 3 → degree = 1

Node 5 → degree = 0
```

---

## Degree of Tree

Maximum degree of any node.

Example

```
Maximum children = 2

Degree(Tree)=2
```

---

# Level

Level starts from **0** in most interview problems.

```
          1         Level 0

      2       3     Level 1

    4   5       6   Level 2
```

Some books start levels from **1**, but **LeetCode and interviews usually use level 0**. Always clarify if the interviewer specifies otherwise.

---

# Depth

Depth = Number of edges from Root to Current Node.

Example

```
Depth(1)=0

Depth(2)=1

Depth(5)=2
```

Formula

```
Depth(root)=0
```

---

# Height

Height = Number of edges on the longest path from the node to any leaf.

```
        1
      /   \
     2     3
    /
   4
```

Height(4)=0

Height(2)=1

Height(1)=2

---

### Easy way to remember

**Depth → Go Up ⬆️**

**Height → Go Down ⬇️**

---

# Ancestor

Every node on the path from root to current node.

Example

```
        1
       /
      2
     /
    4
```

Ancestors of 4

```
1

2
```

---

# Descendant

Every node below a node.

Example

Descendants of 2

```
4
```

---

# Subtree

A node together with all of its descendants.

Example

```
        2
       /
      4
```

is a subtree.

Subtree problems are among the most common interview questions.

---

# Path

A sequence of connected nodes.

Example

```
4

2

1

3
```

Length = Number of edges.

---

# Binary Tree

Every node has at most **2 children**.

```
        1
      /   \
     2     3
```

Children are called

Left Child

Right Child

---

# Tree Properties

For a tree with **N nodes**:

### Number of Edges

```
Edges = N - 1
```

Always true.

---

### Maximum Nodes at Level L

```
2^L
```

Example

Level 3

```
2³ = 8 nodes
```

---

### Maximum Nodes in Height H

```
2^(H+1)-1
```

Example

Height = 3

```
2⁴-1=15
```

---

### Minimum Height

```
log₂(N)
```

(Approximately, for a balanced binary tree.)

---

# Binary Tree vs Binary Search Tree

Many beginners confuse these.

### Binary Tree

```
      5
     / \
    9   2
```

Completely valid.

No ordering rule.

---

### Binary Search Tree

```
      5
     / \
    3   8
```

Every node follows:

```
Left < Root < Right
```

This property enables efficient searching.

---

# Representation in Code

```cpp
struct TreeNode {

    int val;

    TreeNode* left;

    TreeNode* right;

    TreeNode(int x){

        val=x;

        left=nullptr;

        right=nullptr;

    }

};
```

This is the standard definition used by LeetCode and many interview platforms.

---

# Time Complexity Basics

| Operation | General Binary Tree | BST (Balanced) |
|-----------|--------------------|----------------|
| Search | O(N) | O(log N) |
| Insert | O(N)\* | O(log N) |
| Delete | O(N)\* | O(log N) |

\* General binary trees do not maintain an order, so finding the insertion/deletion point may require traversal.

---

# Interview Insights

### Companies love asking:

- Height
- Depth
- Diameter
- LCA
- Path Sum
- Views
- Traversals
- Serialization
- BST Validation

Master the terminology first—many questions build directly on these concepts.

---

# Common Mistakes

❌ Height = number of nodes

Correct:

Height = number of **edges** (unless the problem explicitly defines otherwise).

---

❌ Confusing Height and Depth

Remember:

Depth → Root to Node

Height → Node to Leaf

---

❌ Thinking every Binary Tree is a BST

False.

BST is a special type of Binary Tree.

---

❌ Forgetting that:

```
Edges = Nodes - 1
```

This is true for every valid tree.

---

# Quick Revision

✅ Tree = Connected + No Cycles

✅ Root = Top Node

✅ Leaf = No Children

✅ Internal Node = Has Child

✅ Degree = Number of Children

✅ Level = Distance by Layers

✅ Depth = Root → Node

✅ Height = Node → Deepest Leaf

✅ Binary Tree = Max 2 Children

✅ BST = Left < Root < Right

✅ Edges = Nodes − 1

✅ Maximum Nodes at Level L = 2^L

✅ Maximum Nodes in Height H = 2^(H+1) − 1

---

# Interview Checklist

Before solving any tree problem, ask yourself:

- Is it a Binary Tree or a BST?
- Does the problem mention root-to-leaf or any-node-to-any-node?
- Is recursion the simplest approach?
- Will DFS or BFS fit better?
- Can I solve it in one traversal?
- What should my recursive function return?
- Is my base case (`nullptr`) correct?
- Am I counting edges or nodes?

---

