# 🌳 Tree Traversals

> Learn how to visit every node in a tree efficiently.

---

# Table of Contents

## Depth First Search (DFS)

1. Preorder Traversal
2. Inorder Traversal
3. Postorder Traversal

## Breadth First Search (BFS)

4. Level Order Traversal
5. Reverse Level Order Traversal
6. Zigzag Traversal

## View Traversals

7. Left View
8. Right View
9. Top View
10. Bottom View

## Special Traversals

11. Vertical Order Traversal
12. Boundary Traversal
13. Diagonal Traversal
14. Morris Traversal

---

# Why are Traversals Important?

A traversal defines the **order in which we visit every node of a tree**.

Almost every tree interview question starts with some form of traversal.

Examples:

- Height of Tree
- Diameter
- Maximum Path Sum
- Lowest Common Ancestor
- Serialize Tree
- Flatten Tree
- Validate BST
- Recover BST
- Path Sum
- Tree Views

If you understand traversals, you'll recognize solutions to a large portion of tree problems.

---

# Two Main Categories

## 1. DFS (Depth First Search)

Go as deep as possible before coming back.

Traversals:

- Preorder
- Inorder
- Postorder

Uses recursion or an explicit stack.

---

## 2. BFS (Breadth First Search)

Visit nodes level by level.

Uses a queue.

Traversals:

- Level Order
- Zigzag
- Left View
- Right View
- Vertical Order (commonly)
- Top View
- Bottom View

---

# Standard Tree

We'll use this tree throughout the traversal chapter.

```

        1
      /   \
     2     3
    / \   / \
   4   5 6   7

```

---

# Expected Traversal Outputs

| Traversal | Output |
|-----------|--------|
| Preorder | 1 2 4 5 3 6 7 |
| Inorder | 4 2 5 1 6 3 7 |
| Postorder | 4 5 2 6 7 3 1 |
| Level Order | 1 2 3 4 5 6 7 |
| Reverse Level Order | 4 5 6 7 2 3 1 |

---

# DFS vs BFS

| Feature | DFS | BFS |
|----------|-----|-----|
| Data Structure | Stack / Recursion | Queue |
| Strategy | Depth First | Level by Level |
| Memory | O(h) | O(n) |
| Good For | Paths, Height, DP | Levels, Views, Shortest Distance |
| Interview Frequency | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ |

---

# Recognition Guide

| If the question mentions... | Think... |
|-----------------------------|----------|
| Root → Left → Right | Preorder |
| Sorted output in BST | Inorder |
| Delete tree after children | Postorder |
| Level by level | BFS |
| Same level | Queue |
| Leftmost node of every level | Left View |
| Rightmost node | Right View |
| Columns | Vertical Order |
| Outside boundary | Boundary Traversal |
| No extra space | Morris Traversal |

---

# Interview Tips

- Draw the tree before coding.
- Write the traversal order on paper.
- Decide whether recursion or iteration is simpler.
- For BFS, think **Queue** first.
- For DFS, think **Recursion** first.
- If space optimization is asked, consider **Morris Traversal** (where applicable).

---

# Common Mistakes

- Mixing Preorder and Inorder sequences.
- Forgetting the base case (`nullptr`).
- Using a stack where a queue is required.
- Confusing level order with preorder.
- Forgetting to process one complete level before moving to the next in BFS.

---