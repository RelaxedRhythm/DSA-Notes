# 🌳 Serialize and Deserialize Binary Tree

> **Problem:** Design algorithms to serialize and deserialize a binary tree.

> ⭐⭐⭐⭐ Difficulty: Hard
> ⭐⭐⭐⭐⭐ Interview Frequency: Extremely High

---

# Table of Contents

1. Introduction
2. What is Serialization?
3. What is Deserialization?
4. Why is Null Information Necessary?
5. Pattern Recognition
6. Approach 1 - BFS (Recommended)
7. Approach 2 - DFS (Preorder)
8. Dry Run
9. Complexity Analysis
10. Common Mistakes
11. Interview Follow-ups
12. Related Questions
13. Company Favorites
14. Quick Revision

---

# 1. Introduction

Serialization means converting a binary tree into a format that can be

- Stored
- Sent over a network
- Saved to a database
- Reconstructed later

Deserialization is the reverse process.

```
Tree

↓

Serialize

↓

String

↓

Deserialize

↓

Same Tree
```

---

# 2. What is Serialization?

Convert

```
        1
      /   \
     2     3
          / \
         4   5
```

into

```
1,2,3,#,#,4,5,#,#,#,#
```

Here

```
#
```

represents

```
NULL
```

---

# 3. What is Deserialization?

Given

```
1,2,3,#,#,4,5,#,#,#,#
```

reconstruct

```
        1
      /   \
     2     3
          / \
         4   5
```

Exactly the same tree.

---

# 4. Why is Null Information Necessary?

Suppose we serialize

```
1 2 3
```

Can you determine

```
    1
   /
  2
 /
3
```

or

```
    1
   /
  2
   \
    3
```

Impossible.

Without storing NULLs,

multiple trees produce the same serialization.

Therefore

```
NULL markers are mandatory.
```

---

# 5. Pattern Recognition

If the interviewer says

- Store Tree
- Encode Tree
- Decode Tree
- Save Tree
- Restore Tree

Think

```
Traversal

+

NULL Markers
```

---

# 6. Approach 1 — BFS (Recommended)

## Serialization

Use Level Order Traversal.

Algorithm

```
Root

↓

Queue

↓

Store Node

↓

Push Children

↓

Store NULLs

↓

Repeat
```

---

### Serialize Code

```cpp
string serialize(TreeNode* root){

    if(!root)
        return "";

    queue<TreeNode*> q;
    q.push(root);

    string ans;

    while(!q.empty()){

        TreeNode* node=q.front();
        q.pop();

        if(node){

            ans+=to_string(node->val)+",";

            q.push(node->left);
            q.push(node->right);
        }
        else{

            ans+="#,";
        }
    }

    return ans;
}
```

---

## Deserialization

Read values one by one.

Use a queue.

Assign

```
Left

↓

Right
```

for every parent.

---

### Deserialize Code

```cpp
TreeNode* deserialize(string data){

    if(data.empty())
        return nullptr;

    stringstream ss(data);

    string value;

    getline(ss,value,',');

    TreeNode* root=new TreeNode(stoi(value));

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){

        TreeNode* curr=q.front();
        q.pop();

        getline(ss,value,',');

        if(value!="#"){

            curr->left=new TreeNode(stoi(value));
            q.push(curr->left);
        }

        getline(ss,value,',');

        if(value!="#"){

            curr->right=new TreeNode(stoi(value));
            q.push(curr->right);
        }
    }

    return root;
}
```

---

# 7. Approach 2 — DFS (Preorder)

Another common interview solution.

Serialize

```
Root

↓

Left

↓

Right
```

Store

```
#
```

for NULL.

Example

```
1

↓

2

↓

#

↓

#

↓

3

↓

#

↓

#
```

Serialized

```
1 2 # # 3 # #
```

Deserialization

Read values recursively.

Whenever

```
#
```

appears,

return

```
NULL
```

This solution is shorter and elegant.

---

# 8. Dry Run

Tree

```
        1
      /   \
     2     3
          / \
         4   5
```

Serialization

Queue

```
1
```

↓

Output

```
1
```

↓

Queue

```
2

3
```

↓

Output

```
1,2,3
```

↓

Queue

```
NULL

NULL

4

5
```

↓

Continue

Final

```
1,2,3,#,#,4,5,#,#,#,#
```

---

Deserialization

Read

```
1
```

↓

Create Root

↓

Read

```
2

3
```

↓

Attach

↓

Continue

Final tree reconstructed.

---

# 9. Complexity Analysis

## BFS

Time

```
O(n)
```

Space

```
O(n)
```

---

## DFS

Time

```
O(n)
```

Space

```
O(h)
```

Recursion Stack

---

# 10. Common Mistakes

### ❌ Forgetting NULL markers

Impossible to reconstruct correctly.

---

### ❌ Skipping trailing NULLs

Most interview implementations keep them.

Removing them requires additional handling.

---

### ❌ Queue underflow

Always check before accessing.

---

### ❌ Mixing DFS serialization with BFS deserialization

Traversal order must match.

---

### ❌ Forgetting delimiter

Use

```
,
```

or

```
space
```

between values.

---

# 11. Interview Follow-ups

### Q1. Why can't we serialize using only inorder?

Because inorder alone does not uniquely identify a tree.

---

### Q2. BFS vs DFS?

BFS

- Easier to understand
- Uses queue

DFS

- Shorter code
- Elegant recursion

Both are accepted.

---

### Q3. Why store NULLs?

Without NULLs,

different trees may serialize into the same sequence.

---

### Q4. Where is this used?

- Databases
- Distributed systems
- Network communication
- Caching
- File storage

---

# 12. Related Questions

- Construct Binary Tree
- Encode N-ary Tree
- Complete Binary Tree Inserter
- Flatten Binary Tree
- Binary Tree Cameras

---

# 13. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐⭐⭐ |
| Microsoft | ⭐⭐⭐⭐⭐ |
| Google | ⭐⭐⭐⭐⭐ |
| Adobe | ⭐⭐⭐⭐⭐ |
| Walmart | ⭐⭐⭐⭐ |
| Oracle | ⭐⭐⭐⭐ |
| Goldman Sachs | ⭐⭐⭐⭐ |
| Atlassian | ⭐⭐⭐⭐ |
| Flipkart | ⭐⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐ |
| Accenture | ⭐⭐ |
| TCS Digital | ⭐⭐ |

---

# 14. Quick Revision

### Recognition

```
Store Tree

↓

Traversal

+

NULL Markers
```

---

### BFS

```
Queue

↓

Level Order

↓

Store #

↓

Reconstruct
```

---

### DFS

```
Preorder

↓

#

↓

Recursion
```

---

### Complexity

| Method | Time | Space |
|---------|------|--------|
| BFS | O(n) | O(n) |
| DFS | O(n) | O(h) |

---

### Interview Trick

If the interviewer doesn't specify,

mention both approaches.

Then say

> "I'll implement the BFS version because it's straightforward for serialization and reconstruction."

This shows awareness of multiple solutions.

---

# Construction Module Summary

| Problem | Core Pattern | Time |
|----------|--------------|------|
| Preorder + Inorder | Divide & Conquer | O(n) |
| Postorder + Inorder | Divide & Conquer | O(n) |
| BST from Preorder | Bounds | O(n) |
| BST from Sorted Array | Middle Element | O(n) |
| Complete Binary Tree | Queue | O(n) |
| Serialize / Deserialize | BFS / DFS + NULL Markers | O(n) |

---

# Interview Checklist

- [ ] Did I store NULL nodes?
- [ ] Did serialization and deserialization use the same traversal?
- [ ] Did I handle an empty tree?
- [ ] Did I use delimiters correctly?
- [ ] Is my solution O(n)?