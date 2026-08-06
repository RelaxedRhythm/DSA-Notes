# 🌲 Types of Trees

> **Chapter 2 | Types of Trees**

---

# Table of Contents

1. Binary Tree
2. Full Binary Tree
3. Complete Binary Tree
4. Perfect Binary Tree
5. Balanced Binary Tree
6. Degenerate Tree
7. Binary Search Tree
8. AVL Tree
9. Red-Black Tree
10. Heap
11. Trie
12. Segment Tree
13. Fenwick Tree (BIT)
14. N-ary Tree
15. Threaded Binary Tree
16. B Tree
17. B+ Tree
18. Comparison Table
19. Placement Importance
20. Recognition Guide

---

# 1. Binary Tree

## Definition

A Binary Tree is a tree where every node has **at most two children**.

```
        A
       / \
      B   C
     /
    D
```

A node can have:

- 0 children
- 1 child
- 2 children

Never more than 2.

---

## Interview Recognition

Keywords:

- left child
- right child
- root
- recursive traversal

Usually solved using

- DFS
- BFS
- Recursion

---

## Complexity

Traversal

```
O(n)
```

Space

```
O(h)
```

where h is tree height.

---

## Common Questions

- Maximum Depth
- Same Tree
- Invert Tree
- Diameter
- Balanced Tree

---

# 2. Full Binary Tree

## Definition

Every node has either

- 0 children
- OR
- exactly 2 children

Never exactly one child.

```
        1
      /   \
     2     3
    / \
   4   5
```

Valid.

---

```
      1
     /
    2
```

Not Full.

---

## Recognition

Question mentions

- every internal node has two children

---

## Formula

If

```
Internal Nodes = I
```

Then

```
Leaf Nodes = I + 1
```

Very common MCQ.

---

# 3. Complete Binary Tree

Definition

Every level is completely filled

except possibly the last level.

The last level is filled

from left to right.

```
        1
      /   \
     2     3
    / \   /
   4  5  6
```

Complete.

---

Not Complete

```
      1
     / \
    2   3
     \
      5
```

Gap on left.

---

Recognition

Keywords

- nearly complete
- array representation
- heap

Think

Heap

---

Applications

Binary Heap

Priority Queue

Heap Sort

---

# 4. Perfect Binary Tree

Definition

Every internal node has

2 children

AND

All leaves are on the same level.

```
         1
      /     \
     2       3
    / \     / \
   4  5    6  7
```

Perfect.

---

Formula

Height = h

Nodes

```
2^(h+1)-1
```

Leaves

```
2^h
```

---

Interview Tip

Perfect trees are mostly asked

in aptitude

or theory.

Rare in coding rounds.

---

# 5. Balanced Binary Tree

Definition

For every node

```
|Left Height - Right Height| <=1
```

```
        4
      /   \
     2     6
    / \   /
   1  3  5
```

Balanced.

---

Recognition

Keywords

- height difference
- balanced

Pattern

Bottom-up DFS

---

Time

```
O(n)
```

---

Common Questions

Balanced Binary Tree

AVL Tree

Height

Diameter

---

# 6. Degenerate Tree

Every node has only one child.

Looks like

a Linked List.

```
1
 \
 2
  \
   3
    \
     4
```

Worst case

Height

```
n-1
```

Search

```
O(n)
```

---

Interview Tip

BST becomes slow

when it becomes degenerate.

Hence AVL and Red Black exist.

---

# 7. Binary Search Tree

Property

```
Left < Root < Right
```

```
       8
     /   \
    4    12
   / \   / \
  2  6 10 14
```

---

Recognition

Keywords

- sorted
- kth smallest
- predecessor
- successor
- range

---

Important Property

Inorder Traversal

gives

Sorted Order.

One of the most important interview facts.

---

Applications

Searching

Ranking

Ordered Sets

Maps

Databases

---

# 8. AVL Tree

Self-balancing BST.

Balance Factor

```
Left Height - Right Height
```

Allowed

```
-1

0

1
```

Otherwise

Rotations.

---

Rotations

LL

RR

LR

RL

---

Complexity

Search

Insert

Delete

All

```
O(log n)
```

---

Interview Importance

Mostly theoretical.

Need to know

rotations.

Coding asked rarely.

---

# 9. Red Black Tree

Self-balancing BST.

Rules

- Root Black
- Red node cannot have red child
- Every path has same black height

---

Applications

C++ STL

map

set

multiset

multimap

Java TreeMap

Linux Scheduler

---

Interview Importance

Know theory.

Implementation rarely asked.

---

# 10. Heap

Complete Binary Tree

+

Heap Property

Max Heap

Parent

>= Children

Min Heap

Parent

<= Children

---

Recognition

Keywords

Top K

Priority

Maximum

Minimum

Median

Priority Queue

---

Complexity

Insert

```
O(log n)
```

Top

```
O(1)
```

Delete

```
O(log n)
```

---

Applications

Priority Queue

Dijkstra

Heap Sort

Scheduling

Top K

---

# 11. Trie

Stores strings.

```
          root
         /   \
        a     b
       /
      p
     /
    p
```

---

Recognition

Keywords

Dictionary

Prefix

Autocomplete

Word Search

---

Complexity

Search

Insert

Prefix

```
O(length)
```

---

Applications

Google Search

Autocomplete

Spell Checker

Dictionary

IP Routing

---

# 12. Segment Tree

Supports

Range Query

Range Update

```
Array

↓

Segment Tree

↓

Fast Queries
```

---

Recognition

Keywords

Range Sum

Range Minimum

Range Maximum

Updates

---

Complexity

Build

```
O(n)
```

Query

```
O(log n)
```

Update

```
O(log n)
```

---

Interview Importance

Frequently asked

by

Google

Amazon

Atlassian

Adobe

---

# 13. Fenwick Tree (Binary Indexed Tree)

Simpler than Segment Tree.

Supports

Prefix Sum

Updates

```
O(log n)
```

Less memory.

Easy implementation.

---

Recognition

Prefix

Frequency

Running Sum

---

# 14. N-ary Tree

Every node

can have

multiple children.

```
        A
    /  |  \
   B   C   D
```

Examples

Folder Structure

HTML DOM

Organization Charts

---

# 15. Threaded Binary Tree

Null pointers

store predecessor

or successor.

Purpose

Fast inorder traversal

without stack.

---

Interview Importance

Know concept.

Coding almost never asked.

---

# 16. B Tree

Multi-way Search Tree.

Used in

Databases

File Systems

Disk Storage

Optimized for

Disk Access.

---

# 17. B+ Tree

Improved version

of B Tree.

All data

stored

in leaf nodes.

Leaves connected

using linked list.

Excellent for

Range Queries.

---

Applications

MySQL

PostgreSQL

Oracle

SQL Server

---

# Comparison Table

| Tree | Search | Insert | Delete | Balanced | Main Use |
|------|--------|--------|--------|----------|----------|
| Binary Tree | O(n) | O(n) | O(n) | ❌ | General hierarchy |
| BST | O(h) | O(h) | O(h) | ❌ | Ordered data |
| AVL | O(log n) | O(log n) | O(log n) | ✅ | Fast search |
| Red Black | O(log n) | O(log n) | O(log n) | ✅ | STL Maps/Sets |
| Heap | O(n) | O(log n) | O(log n) | Complete | Priority Queue |
| Trie | O(L) | O(L) | O(L) | — | Strings/Prefixes |
| Segment Tree | O(log n) | O(log n) | O(log n) | — | Range Queries |
| Fenwick Tree | O(log n) | O(log n) | O(log n) | — | Prefix Sum |
| B Tree | O(log n) | O(log n) | O(log n) | ✅ | Databases |
| B+ Tree | O(log n) | O(log n) | O(log n) | ✅ | Database Indexing |

---

# Placement Importance

★★★★★ Must Know
- Binary Tree
- BST
- Heap
- Trie

★★★★ Important
- AVL Tree
- Segment Tree
- Fenwick Tree

★★★ Theory Only
- Red Black Tree
- B Tree
- B+ Tree
- Threaded Tree

---

# Recognition Cheat Sheet

| If the problem says... | Think... |
|-------------------------|----------|
| Left < Root < Right | BST |
| Prefix Search | Trie |
| Top K | Heap |
| Priority | Heap |
| Range Sum | Segment Tree / Fenwick |
| Ordered Set | BST |
| Dictionary | Trie |
| Autocomplete | Trie |
| Database Index | B+ Tree |
| Nearly Complete | Heap |
| Self-balancing | AVL / Red-Black |

---

# Summary

- Binary Tree → General hierarchy
- BST → Ordered data
- AVL → Strict balancing
- Red-Black → Practical balanced BST
- Heap → Priority
- Trie → Prefix matching
- Segment Tree → Range queries
- Fenwick Tree → Prefix sums
- B Tree → Disk storage
- B+ Tree → Database indexing