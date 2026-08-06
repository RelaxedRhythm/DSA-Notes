# 🌳 Boundary Traversal of Binary Tree

> **Traversal Definition:** Traverse the **boundary (perimeter)** of the binary tree in **anti-clockwise direction**, starting from the root.

> ⭐⭐⭐⭐ **Difficulty:** Medium

> ⭐⭐⭐⭐ **Interview Frequency:** High

---

# Table of Contents

1. Introduction
2. Boundary Definition
3. Visualization
4. Pattern Recognition
5. Complete Algorithm
6. Step 1 - Root
7. Step 2 - Left Boundary
8. Step 3 - Leaf Nodes
9. Step 4 - Right Boundary
10. Complete C++ Solution
11. Dry Run
12. Complexity Analysis
13. Pattern Connection
14. Common Mistakes
15. Interview Follow-ups
16. Related Questions
17. Company Favorites
18. Quick Revision

---

# 1. Introduction

Boundary Traversal prints all nodes lying on the **boundary** of a binary tree.

The traversal is performed in **anti-clockwise order**.

Unlike

- Level Order
- Vertical Order
- Top View

Boundary Traversal is **not a single traversal**.

It is a combination of multiple traversals.

---

# 2. Boundary Definition

Boundary consists of **four parts**.

```
1.

Root

↓

2.

Left Boundary

↓

3.

All Leaf Nodes

↓

4.

Right Boundary (Reverse)
```

Think of walking around the outside edge of the tree.

---

# Example

```
                1
             /     \
            2       3
          /   \      \
         4     5      6
              / \    /
             7   8  9
```

Boundary Traversal

```
1

↓

2

↓

4

↓

7

↓

8

↓

9

↓

6

↓

3
```

Output

```
1 2 4 7 8 9 6 3
```

---

# 3. Visualization

```
                1
             ↙     ↘

            2       3

          ↙           ↘

         4             6

        ↘             ↙

          7         9
```

Walk around the outer boundary.

---

# 4. Pattern Recognition

Keywords

- Boundary
- Perimeter
- Outside
- Anti-clockwise
- Edge Nodes

Think immediately

```
Root

+

Left Boundary

+

Leaves

+

Reverse Right Boundary
```

---

# 5. Complete Algorithm

```
Add Root

↓

Traverse Left Boundary

↓

Traverse All Leaves

↓

Traverse Right Boundary (Bottom → Top)
```

Notice

Leaves should **not** be added twice.

---

# Helper Function

```cpp
bool isLeaf(TreeNode* node){

    return node &&
           node->left==nullptr &&
           node->right==nullptr;
}
```

---

# 6. Step 1 - Root

If root is not a leaf,

add it.

```cpp
if(!isLeaf(root))
    ans.push_back(root->val);
```

Why?

Because leaves will already be added in Step 3.

---

# 7. Step 2 - Left Boundary

Rules

- Do not include leaf nodes.
- Prefer left child.
- If left child doesn't exist, move right.

---

Example

```
      1

     /

    2

     \

      4

       \

        7
```

Left Boundary

```
2

↓

4
```

---

## C++ Code

```cpp
void addLeftBoundary(TreeNode* root,
                     vector<int>& ans){

    TreeNode* curr=root->left;

    while(curr){

        if(!isLeaf(curr))
            ans.push_back(curr->val);

        if(curr->left)
            curr=curr->left;
        else
            curr=curr->right;
    }
}
```

---

# 8. Step 3 - Leaf Nodes

Visit every leaf using DFS.

Rule

```
Left

↓

Right
```

---

## C++ Code

```cpp
void addLeaves(TreeNode* root,
               vector<int>& ans){

    if(root==nullptr)
        return;

    if(isLeaf(root)){

        ans.push_back(root->val);

        return;
    }

    addLeaves(root->left,ans);

    addLeaves(root->right,ans);
}
```

---

# 9. Step 4 - Right Boundary

Rules

- Ignore leaf nodes.
- Prefer right child.
- If absent, move left.
- Store temporarily.
- Reverse before adding.

---

Why reverse?

Traversal must be

```
Bottom

↓

Top
```

---

Example

```
1

 \

 3

  \

   6

  /

 9
```

Collected

```
3

6
```

Output

```
6

3
```

---

## C++ Code

```cpp
void addRightBoundary(TreeNode* root,
                      vector<int>& ans){

    TreeNode* curr=root->right;

    vector<int> temp;

    while(curr){

        if(!isLeaf(curr))
            temp.push_back(curr->val);

        if(curr->right)
            curr=curr->right;
        else
            curr=curr->left;
    }

    for(int i=temp.size()-1;i>=0;i--)
        ans.push_back(temp[i]);
}
```

---

# 10. Complete C++ Solution

```cpp
class Solution {

    bool isLeaf(TreeNode* node){

        return node &&
               node->left==nullptr &&
               node->right==nullptr;
    }

    void addLeftBoundary(TreeNode* root,
                         vector<int>& ans){

        TreeNode* curr=root->left;

        while(curr){

            if(!isLeaf(curr))
                ans.push_back(curr->val);

            if(curr->left)
                curr=curr->left;
            else
                curr=curr->right;
        }
    }

    void addLeaves(TreeNode* root,
                   vector<int>& ans){

        if(root==nullptr)
            return;

        if(isLeaf(root)){

            ans.push_back(root->val);

            return;
        }

        addLeaves(root->left,ans);
        addLeaves(root->right,ans);
    }

    void addRightBoundary(TreeNode* root,
                          vector<int>& ans){

        TreeNode* curr=root->right;

        vector<int> temp;

        while(curr){

            if(!isLeaf(curr))
                temp.push_back(curr->val);

            if(curr->right)
                curr=curr->right;
            else
                curr=curr->left;
        }

        reverse(temp.begin(),temp.end());

        ans.insert(ans.end(),
                   temp.begin(),
                   temp.end());
    }

public:

    vector<int> boundary(TreeNode* root){

        vector<int> ans;

        if(root==nullptr)
            return ans;

        if(!isLeaf(root))
            ans.push_back(root->val);

        addLeftBoundary(root,ans);

        addLeaves(root,ans);

        addRightBoundary(root,ans);

        return ans;
    }
};
```

---

# 11. Dry Run

Tree

```
            1
          /   \
         2     3
        / \     \
       4   5     6
          / \   /
         7   8 9
```

Step 1

```
1
```

---

Step 2

```
2
```

---

Step 3

```
4

7

8

9
```

---

Step 4

Collected

```
3

6
```

Reverse

```
6

3
```

Final

```
1 2 4 7 8 9 6 3
```

---

# 12. Complexity Analysis

Let

```
n = Number of Nodes
```

## Time

Every node is visited at most once.

```
O(n)
```

---

## Space

Recursive DFS

```
O(h)
```

where

```
h = Height of Tree
```

---

# 13. Pattern Connection

Boundary Traversal combines multiple patterns.

| Part | Pattern |
|------|---------|
| Root | Single Node |
| Left Boundary | Iteration |
| Leaves | DFS |
| Right Boundary | Iteration + Reverse |

Unlike previous traversal problems,

this is a **composition problem**.

---

# 14. Common Mistakes

### ❌ Adding Leaves Twice

Leaves should appear only once.

Never include them in the left or right boundary.

---

### ❌ Forgetting to Reverse Right Boundary

Wrong

```
3 6
```

Correct

```
6 3
```

---

### ❌ Adding Root Twice

If the root is also a leaf (single-node tree),

don't add it twice.

---

### ❌ Only Following Left Edges

If a left child doesn't exist,

move to the right child.

Similarly,

for the right boundary,

move to the left child if the right child is absent.

---

# 15. Interview Follow-ups

### Q1. Why are leaves traversed separately?

Because leaves may belong to both the left and right boundaries.

A separate DFS ensures every leaf appears exactly once.

---

### Q2. Why reverse the right boundary?

Boundary Traversal is anti-clockwise.

The right boundary must therefore be printed from bottom to top.

---

### Q3. Can this be solved using one DFS?

Yes.

But the implementation becomes significantly more complex.

The four-step approach is clearer and is the standard interview solution.

---

### Q4. Is BFS useful here?

Not really.

Boundary Traversal is naturally expressed using DFS and iterative boundary walks.

---

# 16. Related Questions

## Medium

- Boundary Traversal of Binary Tree (GeeksforGeeks)

---

## Similar Pattern

- Left View
- Right View
- Leaf Traversal
- Anti-clockwise Tree Boundary

---

# 17. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐⭐ |
| Microsoft | ⭐⭐⭐ |
| Google | ⭐⭐⭐ |
| Adobe | ⭐⭐⭐ |
| Walmart | ⭐⭐⭐ |
| Atlassian | ⭐⭐⭐ |
| Oracle | ⭐⭐⭐ |
| Goldman Sachs | ⭐⭐⭐ |
| Flipkart | ⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐ |
| Accenture | ⭐⭐ |
| TCS Digital | ⭐⭐⭐ |

---

# 18. Quick Revision

✅ Boundary Formula

```
Root

↓

Left Boundary

↓

Leaves

↓

Reverse Right Boundary
```

---

✅ Ignore Leaves

```
Left Boundary

Right Boundary
```

---

✅ Reverse

```
Right Boundary
```

before adding.

---

✅ Time

```
O(n)
```

---

✅ Space

```
O(h)
```

---

# Boundary Traversal Cheat Sheet

| Step | Action |
|------|--------|
| 1 | Add Root |
| 2 | Add Left Boundary (excluding leaves) |
| 3 | Add All Leaves |
| 4 | Add Right Boundary in Reverse (excluding leaves) |

---

# Interview Checklist

- [ ] Did I add the root only once?
- [ ] Did I exclude leaves from the left boundary?
- [ ] Did I collect **all** leaf nodes?
- [ ] Did I exclude leaves from the right boundary?
- [ ] Did I reverse the right boundary before adding it?
- [ ] Is my solution O(n)?