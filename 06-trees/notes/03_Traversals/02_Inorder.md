# 🌳 Inorder Traversal

> **Traversal Order:** **Left → Root → Right (LNR)**

---

# Table of Contents

1. Introduction
2. Intuition
3. Visualization
4. Dry Run
5. Recursive Approach
6. Iterative Approach
7. Morris Inorder Traversal
8. Complexity Analysis
9. Why Inorder is Special
10. Interview Recognition
11. Common Mistakes
12. Related Questions
13. Company Favorites
14. Quick Revision

---

# 1. Introduction

**Inorder Traversal** is a **Depth First Search (DFS)** traversal where we:

1. Traverse the left subtree.
2. Visit the current node.
3. Traverse the right subtree.

Traversal Order

```
Left
↓

Root
↓

Right
```

Short Form

```
L → N → R
```

where

- **L** = Left Subtree
- **N** = Node (Root)
- **R** = Right Subtree

---

# Why is Inorder Important?

Among all traversals, **Inorder is the most important** because of one unique property.

> **Inorder traversal of a Binary Search Tree (BST) always produces nodes in sorted order.**

This single property is the basis for many BST interview questions.

Examples

- Validate BST
- Kth Smallest
- Kth Largest
- BST Iterator
- Recover BST
- Convert BST to Sorted DLL
- Range Queries

If you remember only one thing about inorder, remember this.

---

# 2. Visualization

Tree

```
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
```

Traversal

```
Go Left

Go Left

Visit 4

Backtrack

Visit 2

Visit 5

Backtrack

Visit 1

Go Right

Visit 6

Visit 3

Visit 7
```

Output

```
4 2 5 1 6 3 7
```

---

# 3. Intuition

Imagine reading a book.

You read:

- Left page
- Current page
- Right page

Similarly,

For every node,

finish the entire left subtree before processing the current node.

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

| Step | Current | Output |
|------|---------|--------|
| Go Left | 1 | |
| Go Left | 2 | |
| Visit | 4 | 4 |
| Backtrack | 2 | |
| Visit | 2 | 4 2 |
| Visit | 5 | 4 2 5 |
| Backtrack | 1 | |
| Visit | 1 | 4 2 5 1 |
| Visit | 3 | 4 2 5 1 3 |

Final Output

```
4 2 5 1 3
```

---

# 5. Recursive Approach

## Intuition

Every subtree follows exactly the same order.

```
Left

↓

Node

↓

Right
```

Recursion naturally fits this pattern.

---

## Algorithm

```
If node == NULL

    return

Traverse Left

Visit Node

Traverse Right
```

---

## C++ Code

```cpp
void inorder(TreeNode* root){

    if(root==nullptr)
        return;

    inorder(root->left);

    cout<<root->val<<" ";

    inorder(root->right);
}
```

---

# 6. Iterative Approach

## Why Iterative?

Interviewers often ask:

> "Can you solve it without recursion?"

The idea is to simulate recursion using a stack.

---

## Intuition

Keep moving left until you can't.

Then

Visit node.

Move to right child.

Repeat.

---

## Algorithm

```
Current = Root

While Current != NULL
or Stack not empty

    Push Current

    Move Left

Pop Stack

Visit Node

Move Right
```

---

## Dry Run

Tree

```
      2
     / \
    1   3
```

Stack

```
2

↓

1
```

Visit

```
1
```

Backtrack

Visit

```
2
```

Move Right

Visit

```
3
```

Output

```
1 2 3
```

---

## C++ Code

```cpp
vector<int> inorderTraversal(TreeNode* root){

    vector<int> ans;

    stack<TreeNode*> st;

    TreeNode* curr=root;

    while(curr || !st.empty()){

        while(curr){

            st.push(curr);

            curr=curr->left;
        }

        curr=st.top();

        st.pop();

        ans.push_back(curr->val);

        curr=curr->right;
    }

    return ans;
}
```

---

# 7. Morris Inorder Traversal

## Why Morris Traversal?

Both recursive and iterative solutions use extra memory.

Can we do inorder using **O(1)** extra space?

Yes.

Using **Morris Traversal**.

---

## Core Idea

Instead of using a stack,

temporarily connect

```
Inorder Predecessor

↓

Current Node
```

These temporary links are called **threads**.

After visiting the node,

restore the original tree.

No extra stack.

No recursion.

---

## Algorithm

For every node

### If Left Child Doesn't Exist

Visit node.

Move Right.

---

### If Left Child Exists

Find inorder predecessor.

If predecessor's right is NULL

Create thread.

Move Left.

Else

Remove thread.

Visit node.

Move Right.

---

## Visualization

Original

```
      4
     /
    2
     \
      3
```

Temporary Thread

```
3 ----> 4
```

After visiting 4

Thread removed.

Original tree restored.

---

## C++ Code

```cpp
vector<int> inorderTraversal(TreeNode* root){

    vector<int> ans;

    TreeNode* curr=root;

    while(curr){

        if(curr->left==nullptr){

            ans.push_back(curr->val);

            curr=curr->right;
        }

        else{

            TreeNode* pred=curr->left;

            while(pred->right && pred->right!=curr)
                pred=pred->right;

            if(pred->right==nullptr){

                pred->right=curr;

                curr=curr->left;
            }

            else{

                pred->right=nullptr;

                ans.push_back(curr->val);

                curr=curr->right;
            }
        }
    }

    return ans;
}
```

---

## Complexity

| Method | Time | Space |
|----------|------|-------|
| Recursive | O(n) | O(h) |
| Iterative | O(n) | O(h) |
| Morris | O(n) | **O(1)** |

---

## When to Use Morris?

Only when the interviewer specifically asks

- Constant space
- No recursion
- No stack

Otherwise,

iterative or recursive solutions are easier to write and explain.

---

# 8. Why Inorder is Special

Consider BST

```
        8
      /   \
     4     12
    / \   /  \
   2  6 10  14
```

Inorder

```
2

4

6

8

10

12

14
```

Notice

The output is completely sorted.

This property **only holds for BSTs**, not for general binary trees.

---

# 9. Interview Recognition

If the interviewer mentions

- Sorted order
- BST
- Kth smallest
- BST iterator
- Recover BST
- Validate BST
- Previous node
- Successor
- Predecessor

Immediately think

```
Inorder Traversal
```

---

# 10. Applications

Inorder is used in

- Validate BST
- Recover BST
- BST Iterator
- Kth Smallest
- Kth Largest (Reverse Inorder)
- Convert BST to Sorted DLL
- Merge BSTs
- Range Search
- Successor / Predecessor

---

# 11. Common Mistakes

### ❌ Visiting Root First

Wrong

```
Root

Left

Right
```

That's preorder.

---

### ❌ Forgetting to Move Right

Many beginners visit node

but forget

```
curr = curr->right;
```

Result

Infinite loop.

---

### ❌ Morris Traversal

Forgetting to remove the thread.

Always restore

```
pred->right = nullptr;
```

Otherwise,

the tree gets corrupted.

---

### ❌ Thinking Inorder Always Gives Sorted Output

False.

Only true for **BSTs**.

General Binary Tree

```
      5
     / \
    9   2
```

Inorder

```
9 5 2
```

Not sorted.

---

# 12. Related Questions

## Easy

- Binary Tree Inorder Traversal (94)

---

## Medium

- Validate BST (98)
- Kth Smallest in BST (230)
- BST Iterator (173)
- Recover BST (99)

---

## Hard

- Recover Binary Search Tree
- Convert BST to Circular Doubly Linked List

---

# 13. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐⭐⭐ |
| Microsoft | ⭐⭐⭐⭐⭐ |
| Google | ⭐⭐⭐⭐⭐ |
| Adobe | ⭐⭐⭐⭐ |
| Atlassian | ⭐⭐⭐⭐ |
| Walmart | ⭐⭐⭐⭐ |
| Oracle | ⭐⭐⭐⭐ |
| Goldman Sachs | ⭐⭐⭐⭐ |
| Flipkart | ⭐⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐⭐ |
| Accenture | ⭐⭐⭐ |
| TCS Digital | ⭐⭐⭐ |

---

# 14. Quick Revision

✅ Traversal Order

```
Left → Root → Right
```

✅ Short Form

```
LNR
```

✅ BST Property

```
Inorder = Sorted Order
```

✅ Time

```
O(n)
```

✅ Space

```
Recursive = O(h)

Iterative = O(h)

Morris = O(1)
```

✅ Most Important Uses

- Validate BST
- Kth Smallest
- BST Iterator
- Recover BST
- Successor
- Predecessor

---

# Interview Checklist

Before submitting:

- [ ] Did I process the left subtree first?
- [ ] Did I visit the node before moving right?
- [ ] If iterative, am I pushing all left nodes first?
- [ ] If Morris, did I remove every temporary thread?
- [ ] Am I assuming sorted output only for a BST?