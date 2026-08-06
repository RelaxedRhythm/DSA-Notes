# 🌳 Construct Binary Tree from Preorder and Inorder Traversal

> **Problem:** Given the **Preorder** and **Inorder** traversal of a binary tree, reconstruct the original binary tree.

> ⭐⭐⭐⭐ Difficulty: Medium

> ⭐⭐⭐⭐⭐ Interview Frequency: Extremely High

---

# Table of Contents

1. Introduction
2. Why is Reconstruction Possible?
3. Key Observations
4. Visualization
5. Pattern Recognition
6. Brute Force
7. Optimal Approach
8. Dry Run
9. Complexity Analysis
10. Common Mistakes
11. Interview Follow-ups
12. Related Questions
13. Company Favorites
14. Quick Revision

---

# 1. Introduction

This is one of the most frequently asked tree construction problems.

Companies love it because it tests

- Tree Traversals
- Recursion
- Divide & Conquer
- Hash Maps
- Index Management

---

Problem

Given

```
Preorder

3 9 20 15 7
```

and

```
Inorder

9 3 15 20 7
```

Construct

```
        3

      /   \

     9     20

          /  \

        15    7
```

---

# 2. Why is Reconstruction Possible?

A single traversal is **not enough**.

Example

```
Preorder

1 2 3
```

Many trees produce this preorder.

---

Adding Inorder removes ambiguity.

Why?

Because

```
Preorder

↓

tells us

ROOT
```

while

```
Inorder

↓

splits

LEFT

ROOT

RIGHT
```

Together, they uniquely identify the tree (assuming all node values are unique).

---

# 3. Key Observations

## Observation 1

Preorder

```
Root

↓

Left

↓

Right
```

Therefore,

the **first element** is always the root.

---

## Observation 2

Inorder

```
Left

↓

Root

↓

Right
```

Once we know the root,

everything to the left belongs to the left subtree,

everything to the right belongs to the right subtree.

---

## Observation 3

This process repeats recursively.

Every subtree behaves exactly like the original tree.

This is the classic **Divide & Conquer** pattern.

---

# 4. Visualization

Given

```
Preorder

3 9 20 15 7

Inorder

9 3 15 20 7
```

Step 1

Root

```
3
```

Locate it in inorder

```
9 | 3 | 15 20 7
```

Split

Left

```
9
```

Right

```
15 20 7
```

---

Now recursively solve

Left

```
Preorder

9
```

Right

```
Preorder

20 15 7
```

Repeat until the tree is built.

---

# 5. Pattern Recognition

If the interviewer says

- Construct Tree
- Build Tree
- Preorder + Inorder
- Reconstruct Binary Tree

Think immediately

```
Root

↓

Split Inorder

↓

Recursive Construction
```

---

# 6. Brute Force

Algorithm

For every recursive call

- Take first preorder element
- Search for it in inorder
- Split arrays
- Recurse

Searching the inorder array takes

```
O(n)
```

at each level.

Overall

```
O(n²)
```

---

# 7. Optimal Approach

## Key Improvement

Searching the inorder array repeatedly is wasteful.

Instead,

store every value and its inorder index in a hash map.

```cpp
unordered_map<int,int> index;
```

Now lookup becomes

```
O(1)
```

---

### Recursive Function

```cpp
build(preStart,
      inStart,
      inEnd)
```

Parameters

```
preStart

→ Current root index in preorder

inStart

→ Left boundary in inorder

inEnd

→ Right boundary in inorder
```

---

### Steps

```
Take preorder[preStart]

↓

Create Root

↓

Find Root Index in Inorder

↓

Left Size

↓

Build Left

↓

Build Right
```

---

### Left Subtree Size

Suppose

```
Inorder

4 2 5 1 6 3
```

Root

```
1
```

Index

```
3
```

Left subtree size

```
3 - 0 = 3
```

This value tells us exactly where the right subtree begins in preorder.

---

## C++ Code

```cpp
class Solution {

    unordered_map<int,int> pos;

    TreeNode* build(vector<int>& preorder,
                    int preStart,
                    int inStart,
                    int inEnd){

        if(inStart>inEnd)
            return nullptr;

        TreeNode* root =
            new TreeNode(preorder[preStart]);

        int index = pos[root->val];

        int leftSize = index - inStart;

        root->left = build(preorder,
                           preStart+1,
                           inStart,
                           index-1);

        root->right = build(preorder,
                            preStart+leftSize+1,
                            index+1,
                            inEnd);

        return root;
    }

public:

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder){

        for(int i=0;i<inorder.size();i++)
            pos[inorder[i]]=i;

        return build(preorder,
                     0,
                     0,
                     inorder.size()-1);
    }
};
```

---

# 8. Dry Run

Preorder

```
3 9 20 15 7
```

Inorder

```
9 3 15 20 7
```

---

Root

```
3
```

Split

```
9

|

3

|

15 20 7
```

---

Left

Root

```
9
```

No children.

---

Right

Root

```
20
```

Split

```
15

|

20

|

7
```

---

Create

```
15

7
```

Final

```
        3

      /   \

     9     20

          /  \

        15    7
```

---

# 9. Complexity Analysis

Using Hash Map

### Time

Every node is processed once.

```
O(n)
```

---

### Space

Hash Map

```
O(n)
```

Recursion Stack

```
O(h)
```

Worst case

```
O(n)
```

Balanced tree

```
O(log n)
```

---

# 10. Common Mistakes

### ❌ Searching Inorder Every Time

Causes

```
O(n²)
```

Use a hash map.

---

### ❌ Wrong Left Subtree Size

Correct

```cpp
leftSize = index - inStart;
```

---

### ❌ Incorrect Preorder Index

Right subtree starts at

```cpp
preStart + leftSize + 1
```

This is the line most candidates get wrong.

---

### ❌ Forgetting Base Case

```cpp
if(inStart > inEnd)
    return nullptr;
```

---

# 11. Interview Follow-ups

### Q1. Can we reconstruct using only preorder?

No.

Multiple trees can have the same preorder traversal.

---

### Q2. Can preorder + postorder reconstruct a unique tree?

Not always.

It is only unique for **full binary trees**.

---

### Q3. Why doesn't preorder need explicit boundaries?

Because the preorder index naturally advances as recursive calls consume nodes.

---

### Q4. What if duplicate values exist?

The hash map approach no longer works directly because values are not unique.

You would need additional information or a different representation.

---

# 12. Related Questions

- Construct Binary Tree from Postorder and Inorder
- Construct BST from Preorder
- Serialize and Deserialize Binary Tree
- Recover Binary Tree from Preorder Traversal

---

# 13. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐⭐⭐ |
| Microsoft | ⭐⭐⭐⭐⭐ |
| Google | ⭐⭐⭐⭐⭐ |
| Adobe | ⭐⭐⭐⭐ |
| Walmart | ⭐⭐⭐⭐ |
| Atlassian | ⭐⭐⭐⭐ |
| Oracle | ⭐⭐⭐⭐ |
| Goldman Sachs | ⭐⭐⭐⭐ |
| Flipkart | ⭐⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐⭐ |
| Accenture | ⭐⭐ |
| TCS Digital | ⭐⭐⭐ |

---

# 14. Quick Revision

### Recognition

```
Preorder

↓

Root First
```

---

### Formula

```
Left Size

=

Root Index

-

InStart
```

---

### Right Preorder Index

```
preStart

+

leftSize

+

1
```

---

### Complexity

```
Time

O(n)

Space

O(n)
```

---

# Construction Pattern

```
Find Root

↓

Split Inorder

↓

Build Left

↓

Build Right
```

---

# Interview Checklist

- [ ] Did I create the hash map?
- [ ] Did I calculate `leftSize` correctly?
- [ ] Did I compute the right subtree's preorder index correctly?
- [ ] Did I stop recursion when `inStart > inEnd`?
- [ ] Is my solution O(n)?

# 🌳 Construct Binary Tree from Postorder and Inorder Traversal

> **Problem:** Given the **Postorder** and **Inorder** traversals of a binary tree, construct the original binary tree.

> ⭐⭐⭐⭐ Difficulty: Medium  
> ⭐⭐⭐⭐⭐ Interview Frequency: Very High

---

# Table of Contents

1. Introduction
2. Why is Reconstruction Possible?
3. Key Observations
4. Visualization
5. Pattern Recognition
6. Brute Force
7. Optimal Approach
8. Dry Run
9. Complexity Analysis
10. Common Mistakes
11. Comparison with Preorder + Inorder
12. Interview Follow-ups
13. Related Questions
14. Company Favorites
15. Quick Revision

---

# 1. Introduction

This is one of the classic Binary Tree construction problems.

Just like **Preorder + Inorder**, we reconstruct the tree using two traversals.

The only difference is:

- Preorder gives the **root first**
- Postorder gives the **root last**

Everything else follows the same Divide & Conquer approach.

---

# 2. Why is Reconstruction Possible?

A single traversal cannot uniquely determine a binary tree.

Postorder tells us:

```
Left

↓

Right

↓

Root
```

Inorder tells us:

```
Left

↓

Root

↓

Right
```

Combining these two uniquely reconstructs the binary tree (assuming all node values are unique).

---

# 3. Key Observations

## Observation 1

The **last element** of Postorder is always the root.

Example

```
Postorder

9 15 7 20 3
```

Root = **3**

---

## Observation 2

Find the root in Inorder.

Everything left belongs to the left subtree.

Everything right belongs to the right subtree.

Example

```
9 | 3 | 15 20 7
```

Left Subtree

```
9
```

Right Subtree

```
15 20 7
```

---

## Observation 3

Since Postorder is

```
Left

↓

Right

↓

Root
```

we must build the **right subtree first**.

This is the biggest difference from the preorder version.

---

# 4. Visualization

Given

```
Postorder

9 15 7 20 3

Inorder

9 3 15 20 7
```

Step 1

```
Root = 3
```

Split inorder

```
9 | 3 | 15 20 7
```

Recursively build

```
Right

↓

Left
```

---

# 5. Pattern Recognition

If the interviewer says

- Construct Tree
- Build Tree
- Postorder + Inorder

Think immediately

```
Last Postorder Element

↓

Root

↓

Split Inorder

↓

Build Right First

↓

Build Left
```

---

# 6. Brute Force

Algorithm

- Take last postorder element
- Search in inorder
- Split arrays
- Recurse

Searching every time takes **O(n)**.

Overall complexity

```
O(n²)
```

---

# 7. Optimal Approach

## Step 1

Store inorder indices in a hash map.

```cpp
unordered_map<int,int> pos;
```

Lookup becomes

```
O(1)
```

---

## Step 2

Maintain a global postorder index.

Initially

```cpp
postIndex = postorder.size() - 1;
```

---

## Step 3

Recursive Function

```cpp
build(inStart, inEnd)
```

Algorithm

```
Take postorder[postIndex]

↓

Create Root

↓

postIndex--

↓

Find Root in Inorder

↓

Build Right

↓

Build Left
```

---

## Why Right First?

Postorder

```
Left

↓

Right

↓

Root
```

Reading backwards gives

```
Root

↓

Right

↓

Left
```

Therefore, after picking the root, the next node belongs to the **right subtree**, not the left.

---

## C++ Code

```cpp
class Solution {

    unordered_map<int,int> pos;
    int postIndex;

    TreeNode* build(vector<int>& postorder,
                    int inStart,
                    int inEnd){

        if(inStart > inEnd)
            return nullptr;

        TreeNode* root =
            new TreeNode(postorder[postIndex--]);

        int index = pos[root->val];

        root->right = build(postorder,
                            index + 1,
                            inEnd);

        root->left = build(postorder,
                           inStart,
                           index - 1);

        return root;
    }

public:

    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder){

        for(int i = 0; i < inorder.size(); i++)
            pos[inorder[i]] = i;

        postIndex = postorder.size() - 1;

        return build(postorder,
                     0,
                     inorder.size() - 1);
    }
};
```

---

# 8. Dry Run

Postorder

```
9 15 7 20 3
```

Inorder

```
9 3 15 20 7
```

Root

```
3
```

Split

```
9 | 3 | 15 20 7
```

Next postorder element

```
20
```

Belongs to the right subtree.

Continue recursively.

Final Tree

```
        3
      /   \
     9     20
          /  \
        15    7
```

---

# 9. Complexity Analysis

## Time

Each node is processed once.

```
O(n)
```

---

## Space

Hash Map

```
O(n)
```

Recursion Stack

Balanced Tree

```
O(log n)
```

Worst Case

```
O(n)
```

---

# 10. Common Mistakes

### ❌ Building Left Subtree First

Wrong.

Always build

```
Right

↓

Left
```

because we're traversing Postorder backwards.

---

### ❌ Forgetting to Decrement `postIndex`

```cpp
postIndex--;
```

must happen immediately after creating the root.

---

### ❌ Searching Inorder Every Time

Use a hash map.

Otherwise

```
O(n²)
```

---

### ❌ Incorrect Base Case

```cpp
if(inStart > inEnd)
    return nullptr;
```

---

# 11. Comparison with Preorder + Inorder

| Property | Preorder + Inorder | Postorder + Inorder |
|-----------|--------------------|---------------------|
| Root Position | First | Last |
| Traversal | Root → Left → Right | Left → Right → Root |
| Recursive Order | Left First | Right First |
| Time | O(n) | O(n) |
| Space | O(n) | O(n) |

---

# 12. Interview Follow-ups

### Q1. Why build the right subtree first?

Because reading Postorder backwards gives

```
Root

↓

Right

↓

Left
```

---

### Q2. Can Postorder alone reconstruct a tree?

No.

Multiple trees can produce the same Postorder traversal.

---

### Q3. What if duplicate values exist?

The hash map approach is no longer sufficient because values are not unique.

---

# 13. Related Questions

- Construct Binary Tree from Preorder + Inorder
- Construct BST from Preorder
- Serialize & Deserialize Binary Tree

---

# 14. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐⭐⭐ |
| Microsoft | ⭐⭐⭐⭐ |
| Google | ⭐⭐⭐⭐ |
| Adobe | ⭐⭐⭐⭐ |
| Walmart | ⭐⭐⭐ |
| Oracle | ⭐⭐⭐ |
| Goldman Sachs | ⭐⭐⭐ |
| Flipkart | ⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐ |
| Accenture | ⭐⭐ |
| TCS Digital | ⭐⭐⭐ |

---

# 15. Quick Revision

### Recognition

```
Postorder

↓

Last Element = Root
```

---

### Construction Order

```
Root

↓

Right

↓

Left
```

---

### Complexity

```
Time : O(n)

Space : O(n)
```

---

### Formula

```
Postorder (Reverse)

↓

Root

↓

Right

↓

Left
```

Remember this one line and you'll never forget why the right subtree is built first.

---

# Interview Checklist

- [ ] Did I create the inorder hash map?
- [ ] Did I initialize `postIndex` correctly?
- [ ] Did I build the **right subtree before the left**?
- [ ] Did I handle the base case correctly?
- [ ] Is my solution O(n)?


# 🌳 Construct Complete Binary Tree from Level Order Traversal

> **Problem:** Given the Level Order traversal of a binary tree, construct the corresponding **Complete Binary Tree**.

> ⭐⭐⭐ Difficulty: Easy-Medium  
> ⭐⭐⭐ Interview Frequency: Medium

---

# Table of Contents

1. Introduction
2. What is a Complete Binary Tree?
3. Key Observations
4. Pattern Recognition
5. Approach 1 - Queue (Recommended)
6. Approach 2 - Array Representation
7. Dry Run
8. Complexity Analysis
9. Common Mistakes
10. Interview Follow-ups
11. Related Questions
12. Company Favorites
13. Quick Revision

---

# 1. Introduction

This problem constructs a **Complete Binary Tree (CBT)** using its Level Order traversal.

Unlike previous construction problems,

- No recursion is required.
- No inorder traversal is needed.
- The tree is built level by level.

This is a common pattern used in

- Heaps
- Tree serialization
- Tree input parsing

---

# 2. What is a Complete Binary Tree?

A Complete Binary Tree is a binary tree where

- Every level except possibly the last is completely filled.
- Nodes on the last level are filled from **left to right**.

Example

```
        1
      /   \
     2     3
    / \   /
   4   5 6
```

Complete ✅

---

Not Complete

```
        1
      /   \
     2     3
      \     \
       5     7
```

Because left positions are empty before right ones.

---

# 3. Key Observations

Given

```
Level Order

1 2 3 4 5 6 7
```

The tree is

```
        1
      /   \
     2     3
    / \   / \
   4  5  6  7
```

Notice

Nodes are inserted **level by level**.

Parents are processed in the same order as they appear.

This naturally suggests using a **Queue**.

---

# 4. Pattern Recognition

If the interviewer says

- Level Order
- Complete Binary Tree
- Build Tree
- Input in Level Order

Think immediately

```
Queue

↓

Parent

↓

Left Child

↓

Right Child
```

---

# 5. Approach 1 - Queue (Recommended)

## Idea

The queue always stores nodes whose children are yet to be assigned.

Algorithm

```
Create Root

↓

Push Root

↓

Process Queue

↓

Assign Left Child

↓

Assign Right Child

↓

Push Newly Created Children
```

---

## C++ Code

```cpp
TreeNode* buildTree(vector<int>& levelOrder){

    if(levelOrder.empty())
        return nullptr;

    TreeNode* root = new TreeNode(levelOrder[0]);

    queue<TreeNode*> q;
    q.push(root);

    int index = 1;

    while(!q.empty() && index < levelOrder.size()){

        TreeNode* curr = q.front();
        q.pop();

        // Left Child
        curr->left = new TreeNode(levelOrder[index++]);
        q.push(curr->left);

        if(index >= levelOrder.size())
            break;

        // Right Child
        curr->right = new TreeNode(levelOrder[index++]);
        q.push(curr->right);
    }

    return root;
}
```

---

# 6. Approach 2 - Array Representation

Since a Complete Binary Tree has no gaps,

it can also be represented directly as an array.

For index

```
i
```

Children are

```
Left

2*i + 1
```

```
Right

2*i + 2
```

Parent

```
(i-1)/2
```

This representation is widely used in **Binary Heaps**.

---

# 7. Dry Run

Input

```
1 2 3 4 5 6 7
```

Queue

```
1
```

Process

```
1

↓

Attach

2

3
```

Queue

```
2

3
```

---

Process

```
2

↓

Attach

4

5
```

Queue

```
3

4

5
```

---

Process

```
3

↓

Attach

6

7
```

Final Tree

```
        1
      /   \
     2     3
    / \   / \
   4  5  6  7
```

---

# 8. Complexity Analysis

### Time

Every node is processed once.

```
O(n)
```

---

### Space

Queue stores at most one level.

Worst Case

```
O(n)
```

---

# 9. Common Mistakes

### ❌ Forgetting to Check Array Bounds

Always verify

```cpp
index < levelOrder.size()
```

before creating children.

---

### ❌ Pushing Null Nodes

Only push actual nodes into the queue.

---

### ❌ Assuming Every Node Has Two Children

The last parent may have only a left child.

Handle this case carefully.

---

### ❌ Confusing with General Binary Tree Construction

This algorithm works because the tree is **Complete**.

For arbitrary binary trees, Level Order alone is insufficient unless null markers are included.

---

# 10. Interview Follow-ups

### Q1. Can Level Order alone reconstruct any binary tree?

No.

It only works for complete trees or when null markers are provided.

---

### Q2. Why use a queue?

Because nodes are processed level by level,

matching Level Order traversal.

---

### Q3. Where is this used?

- Binary Heaps
- Tree input formats
- Serialization/Deserialization
- CBT Inserter problems

---

# 11. Related Questions

- Complete Binary Tree Inserter (LeetCode 919)
- Check Completeness of a Binary Tree
- Binary Heap Implementation
- Serialize and Deserialize Binary Tree

---

# 12. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐ |
| Microsoft | ⭐⭐ |
| Google | ⭐⭐ |
| Adobe | ⭐⭐ |
| Walmart | ⭐⭐⭐ |
| Oracle | ⭐⭐⭐ |
| Goldman Sachs | ⭐⭐ |
| Atlassian | ⭐⭐ |
| Flipkart | ⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐⭐ |
| Accenture | ⭐⭐⭐ |
| TCS Digital | ⭐⭐⭐ |

---

# 13. Quick Revision

### Recognition

```
Level Order

+

Complete Tree

↓

Queue
```

---

### Queue Pattern

```
Parent

↓

Left Child

↓

Right Child

↓

Repeat
```

---

### Array Representation

```
Left Child

2*i + 1
```

```
Right Child

2*i + 2
```

```
Parent

(i-1)/2
```

---

### Complexity

```
Time

O(n)

Space

O(n)
```

---

# Construction Summary

| Problem | Pattern | Time |
|---------|---------|------|
| Preorder + Inorder | Divide & Conquer | O(n) |
| Postorder + Inorder | Divide & Conquer | O(n) |
| BST from Preorder | Bounds | O(n) |
| BST from Sorted Array | Middle Element | O(n) |
| Complete Tree from Level Order | Queue | O(n) |

---

# Interview Checklist

- [ ] Did I create the root first?
- [ ] Did I process parents using a queue?
- [ ] Did I assign the left child before the right child?
- [ ] Did I check array bounds before creating children?
- [ ] Is my solution O(n)?