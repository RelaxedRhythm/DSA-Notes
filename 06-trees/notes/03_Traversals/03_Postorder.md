# 🌳 Postorder Traversal

> **Traversal Order:** **Left → Right → Root (LRN)**

---

# Table of Contents

1. Introduction
2. Intuition
3. Visualization
4. Dry Run
5. Recursive Approach
6. Iterative Approaches
7. Complexity Analysis
8. Why Postorder is Important
9. Interview Recognition
10. Common Mistakes
11. Interview Follow-ups
12. Related Questions
13. Company Favorites
14. Quick Revision

---

# 1. Introduction

**Postorder Traversal** is a **Depth First Search (DFS)** traversal where we:

1. Traverse the left subtree.
2. Traverse the right subtree.
3. Visit the current node.

Traversal Order

```
Left
↓

Right
↓

Root
```

Short Form

```
L → R → N
```

where

- **L** = Left Subtree
- **R** = Right Subtree
- **N** = Node (Root)

---

# Why is Postorder Important?

Postorder is used whenever a node depends on the results of its children.

You cannot process the parent until both subtrees are completely processed.

Think:

- Calculate Height
- Diameter
- Maximum Path Sum
- Balanced Tree
- Delete Tree
- Evaluate Expression Tree
- Dynamic Programming on Trees

Almost every Tree DP problem is solved using **Postorder DFS**.

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

Visit 4

Visit 5

Visit 2

Go Right

Visit 6

Visit 7

Visit 3

Visit 1
```

Output

```
4 5 2 6 7 3 1
```

---

# 3. Intuition

Imagine deleting a folder.

```
Folder

├── Images

└── Documents
```

Can you delete the folder first?

❌ No.

You must first delete everything inside it.

Exactly the same idea applies to Postorder.

```
Children

↓

Parent
```

Parent is processed only after its children.

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
| Visit | 4 | 4 |
| Visit | 5 | 4 5 |
| Visit | 2 | 4 5 2 |
| Visit | 3 | 4 5 2 3 |
| Visit | 1 | 4 5 2 3 1 |

Final Output

```
4 5 2 3 1
```

---

# 5. Recursive Approach

## Intuition

Each subtree follows exactly the same pattern.

```
Left

↓

Right

↓

Node
```

This naturally leads to recursion.

---

## Algorithm

```
If node == NULL

    return

Traverse Left

Traverse Right

Visit Node
```

---

## C++ Code

```cpp
void postorder(TreeNode* root){

    if(root==nullptr)
        return;

    postorder(root->left);

    postorder(root->right);

    cout<<root->val<<" ";
}
```

---

# 6. Iterative Approaches

There are **two common iterative methods**.

---

## Method 1 — Two Stacks (Easy)

### Idea

Reverse the preorder traversal.

Normal preorder

```
Root Left Right
```

Modified preorder

```
Root Right Left
```

Reverse the output

```
Left Right Root
```

which is Postorder.

---

### Algorithm

```
Push Root into Stack1

While Stack1 not empty

    Pop node

    Push node into Stack2

    Push Left Child

    Push Right Child

Pop all elements from Stack2

This gives Postorder.
```

---

### C++ Code

```cpp
vector<int> postorderTraversal(TreeNode* root){

    vector<int> ans;

    if(root==nullptr)
        return ans;

    stack<TreeNode*> st1, st2;

    st1.push(root);

    while(!st1.empty()){

        TreeNode* curr=st1.top();
        st1.pop();

        st2.push(curr);

        if(curr->left)
            st1.push(curr->left);

        if(curr->right)
            st1.push(curr->right);
    }

    while(!st2.empty()){

        ans.push_back(st2.top()->val);
        st2.pop();
    }

    return ans;
}
```

---

## Complexity

Time

```
O(n)
```

Space

```
O(n)
```

---

## Method 2 — One Stack (Interview Favorite)

Instead of two stacks, use:

- one stack
- previous pointer

The previous pointer helps determine whether we are:

- moving down
- coming back from left
- coming back from right

Only visit a node after both children are processed.

---

### Algorithm

```
Push Left Nodes

Peek Stack

If Right Child Exists

Move Right

Else

Visit Node

Pop
```

---

### C++ Code

```cpp
vector<int> postorderTraversal(TreeNode* root){

    vector<int> ans;

    stack<TreeNode*> st;

    TreeNode* curr=root;
    TreeNode* lastVisited=nullptr;

    while(curr || !st.empty()){

        while(curr){

            st.push(curr);
            curr=curr->left;
        }

        TreeNode* node=st.top();

        if(node->right && lastVisited!=node->right){

            curr=node->right;
        }

        else{

            ans.push_back(node->val);

            lastVisited=node;

            st.pop();
        }
    }

    return ans;
}
```

---

## Which Method Should You Use?

| Method | Interview Recommendation |
|----------|--------------------------|
| Two Stacks | Easy to explain |
| One Stack | Preferred by product companies |
| Recursion | Best unless iterative is specifically requested |

---

# 7. Complexity Analysis

## Recursive

| Complexity | Value |
|------------|-------|
| Time | O(n) |
| Space | O(h) |

---

## Two Stacks

| Complexity | Value |
|------------|-------|
| Time | O(n) |
| Space | O(n) |

---

## One Stack

| Complexity | Value |
|------------|-------|
| Time | O(n) |
| Space | O(h) |

---

# 8. Why Postorder is Important

Many interview problems require information from both children before computing the answer.

Examples

Height

```
height(node)

=

1 + max(left,right)
```

Balanced Tree

Need heights of both children first.

Diameter

Need left height and right height.

Maximum Path Sum

Need left contribution and right contribution.

Delete Tree

Delete children before deleting parent.

Expression Tree

Evaluate operands before operators.

---

# 9. Interview Recognition

If the problem mentions

- Height
- Diameter
- Balanced
- Maximum Path Sum
- Delete Tree
- Expression Evaluation
- DP on Trees
- Bottom-up

Think immediately

```
Postorder DFS
```

---

# 10. Common Mistakes

### ❌ Visiting Root Early

Wrong

```
Root

Left

Right
```

That's Preorder.

---

### ❌ Forgetting Right Subtree

Many beginners write

```
Left

Root
```

and completely skip

Right.

---

### ❌ One Stack Solution

Forgetting to track

```
lastVisited
```

This often causes infinite loops.

---

### ❌ Updating Answer Too Early

For height/diameter problems,

compute after both recursive calls return.

---

# 11. Interview Follow-ups

### Q1. Can you solve it iteratively?

Yes.

Using

- Two Stacks
- One Stack

---

### Q2. Which iterative solution is preferred?

One Stack

because it uses less memory.

---

### Q3. Which traversal computes height?

Postorder

because children are processed before parent.

---

### Q4. Can Morris Traversal perform Postorder?

Yes.

But it is considerably more complex than Morris Inorder or Preorder.

Very rarely asked in interviews.

---

# 12. Related Questions

## Easy

- Binary Tree Postorder Traversal (145)

---

## Medium

- Balanced Binary Tree (110)
- Diameter of Binary Tree (543)
- Path Sum (112)
- Binary Tree Pruning (814)

---

## Hard

- Binary Tree Maximum Path Sum (124)
- Binary Tree Cameras (968)
- House Robber III (337)

---

# 13. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐⭐⭐ |
| Microsoft | ⭐⭐⭐⭐ |
| Google | ⭐⭐⭐⭐⭐ |
| Adobe | ⭐⭐⭐⭐⭐ |
| Atlassian | ⭐⭐⭐⭐ |
| Walmart | ⭐⭐⭐⭐ |
| Oracle | ⭐⭐⭐⭐ |
| Goldman Sachs | ⭐⭐⭐⭐ |
| Flipkart | ⭐⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐⭐ |
| Accenture | ⭐⭐ |
| TCS Digital | ⭐⭐⭐ |

---

# 14. Quick Revision

✅ Traversal Order

```
Left → Right → Root
```

✅ Short Form

```
LRN
```

✅ Best Used For

- Height
- Diameter
- Balanced Tree
- Maximum Path Sum
- Delete Tree
- Tree DP

✅ Recursive

```
Left

↓

Right

↓

Visit
```

✅ Time

```
O(n)
```

✅ Space

```
Recursive = O(h)

One Stack = O(h)

Two Stacks = O(n)
```

---

# Interview Checklist

Before submitting:

- [ ] Did I process both children before the parent?
- [ ] Is my base case (`nullptr`) correct?
- [ ] If iterative, am I handling the right child correctly?
- [ ] If using one stack, am I updating `lastVisited`?
- [ ] Am I solving a bottom-up problem? If yes, Postorder is likely the correct traversal.