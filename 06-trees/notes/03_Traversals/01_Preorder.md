# 🌳 Preorder Traversal

> **Traversal Order:** **Root → Left → Right (NLR)**

---

# Table of Contents

1. Introduction
2. Intuition
3. Visualization
4. Dry Run
5. Recursive Approach
6. Iterative Approach
7. Complexity Analysis
8. When to Use
9. Common Mistakes
10. Interview Recognition
11. Related Questions
12. Quick Revision

---

# 1. Introduction

**Preorder Traversal** is a **Depth First Search (DFS)** traversal where we process the **current node first**, then recursively traverse the left subtree, followed by the right subtree.

Traversal Order:

```
Root
↓
Left Subtree
↓
Right Subtree
```

Short form:

```
N → L → R
```

where:

- **N** = Node (Root)
- **L** = Left Subtree
- **R** = Right Subtree

---

# 2. Visualization

Consider the following tree:

```
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
```

Traversal:

```
Visit 1

Go Left

Visit 2

Go Left

Visit 4

Backtrack

Visit 5

Backtrack

Go Right

Visit 3

Go Left

Visit 6

Backtrack

Visit 7
```

Final Output

```
1 2 4 5 3 6 7
```

---

# 3. Why Root First?

Imagine you're copying an entire folder structure.

```
Folder

├── Images

└── Documents
```

You must first know the parent folder before copying its children.

Similarly,

Preorder always processes the parent before its descendants.

This is why it is commonly used for:

- Copying trees
- Serialization
- Expression trees
- Prefix expressions

---

# 4. Dry Run

Tree

```
        1
      /   \
     2     3
    / \
   4   5
```

| Step | Current Node | Output |
|------|--------------|--------|
| 1 | 1 | 1 |
| 2 | 2 | 1 2 |
| 3 | 4 | 1 2 4 |
| 4 | Backtrack | 1 2 4 |
| 5 | 5 | 1 2 4 5 |
| 6 | Backtrack | 1 2 4 5 |
| 7 | 3 | 1 2 4 5 3 |

Final Answer

```
1 2 4 5 3
```

---

# 5. Recursive Approach

## Intuition

At every node:

1. Visit current node.
2. Traverse left subtree.
3. Traverse right subtree.

Since the same operation is repeated for every subtree, recursion is the most natural solution.

---

## Algorithm

```
If node is NULL

    return

Visit node

Traverse Left

Traverse Right
```

---

## C++ Code

```cpp
void preorder(TreeNode* root) {

    if(root == nullptr)
        return;

    cout << root->val << " ";

    preorder(root->left);

    preorder(root->right);
}
```

---

## Recursion Tree

```
preorder(1)

│

├── preorder(2)

│     ├── preorder(4)

│     └── preorder(5)

│

└── preorder(3)

      ├── preorder(6)

      └── preorder(7)
```

Notice that every node becomes the root of its own subtree.

---

# 6. Iterative Approach

## Why Iterative?

Interviewers sometimes ask:

> "Can you solve it without recursion?"

This avoids recursion stack overflow on very deep trees.

We simulate recursion using a **stack**.

---

## Key Idea

Since a stack is **Last In First Out (LIFO)**:

- Push **Right Child First**
- Push **Left Child Second**

This ensures the left child is processed before the right child.

---

## Algorithm

```
Push Root

While Stack not empty

    Pop node

    Visit node

    Push Right Child

    Push Left Child
```

---

## Stack Dry Run

Tree

```
      1
     / \
    2   3
```

Initial Stack

```
1
```

Pop

```
Visit 1
```

Push Right

```
3
```

Push Left

```
2
3
```

Pop

```
Visit 2
```

Pop

```
Visit 3
```

Output

```
1 2 3
```

---

## C++ Code

```cpp
vector<int> preorderTraversal(TreeNode* root) {

    vector<int> ans;

    if(root == nullptr)
        return ans;

    stack<TreeNode*> st;

    st.push(root);

    while(!st.empty()) {

        TreeNode* curr = st.top();
        st.pop();

        ans.push_back(curr->val);

        if(curr->right)
            st.push(curr->right);

        if(curr->left)
            st.push(curr->left);
    }

    return ans;
}
```

---

# 7. Complexity Analysis

## Recursive

| Operation | Complexity |
|-----------|------------|
| Time | O(n) |
| Space | O(h) |

where

- **n** = Number of Nodes
- **h** = Height of Tree

Worst Case

```
Skew Tree

Height = n

Space = O(n)
```

Balanced Tree

```
Height = log n

Space = O(log n)
```

---

## Iterative

| Operation | Complexity |
|-----------|------------|
| Time | O(n) |
| Space | O(h) |

The stack stores at most one path from the root to a leaf.

---

# 8. Interview Recognition

If the interviewer says:

- Root first
- Copy tree
- Clone tree
- Serialize tree
- Prefix expression
- Build tree using preorder
- Parent before children

Think:

```
Preorder Traversal
```

---

# 9. Applications

Preorder is commonly used in:

- Tree Serialization
- Tree Cloning
- Prefix Expression Evaluation
- XML Parsing
- Folder Traversal
- AST (Abstract Syntax Tree) generation
- Building a tree from preorder sequence

---

# 10. Common Mistakes

### ❌ Visiting Left First

Wrong

```
Left

Root

Right
```

That's Inorder.

---

### ❌ Forgetting Base Case

Always check

```cpp
if(root == nullptr)
    return;
```

---

### ❌ Pushing Left Before Right

Wrong

```cpp
stack.push(left);

stack.push(right);
```

Output becomes

```
Root

Right

Left
```

Correct

```cpp
stack.push(right);

stack.push(left);
```

---

### ❌ Forgetting Empty Tree

Always handle

```
root == nullptr
```

before pushing into the stack.

---

# 11. Related Interview Questions

## Easy

- Binary Tree Preorder Traversal (LeetCode 144)
- Same Tree (100)
- Invert Binary Tree (226)

---

## Medium

- Construct Binary Tree from Preorder and Inorder (105)
- Flatten Binary Tree to Linked List (114)
- Serialize and Deserialize Binary Tree (297)

---

## Hard

- Recover a Tree From Preorder Traversal (1028)

---

# 12. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐⭐ |
| Microsoft | ⭐⭐⭐⭐ |
| Google | ⭐⭐⭐ |
| Adobe | ⭐⭐⭐⭐ |
| Walmart | ⭐⭐⭐ |
| Atlassian | ⭐⭐⭐ |
| Oracle | ⭐⭐⭐ |
| Flipkart | ⭐⭐⭐ |
| Goldman Sachs | ⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐ |
| Accenture | ⭐⭐ |
| TCS Digital | ⭐⭐ |

---

# 13. Quick Revision

✅ Traversal Order

```
Root → Left → Right
```

✅ Short Form

```
NLR
```

✅ Recursive

```
Visit

Left

Right
```

✅ Iterative

```
Stack

Push Right

Push Left
```

✅ Time

```
O(n)
```

✅ Space

```
O(h)
```

✅ Used In

- Serialization
- Tree Copy
- Prefix Expression
- Tree Construction

---

# Interview Checklist

Before submitting your solution, verify:

- [ ] Base case handles `nullptr`.
- [ ] Root is visited before recursive calls.
- [ ] Iterative solution pushes **right before left**.
- [ ] Time Complexity is **O(n)**.
- [ ] Space Complexity is **O(h)**.
- [ ] Dry run matches the expected preorder sequence.