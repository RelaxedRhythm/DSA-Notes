# 🌳 BST Operations

> ⭐⭐⭐⭐⭐ Importance: Extremely High
>
> Every BST interview starts with these operations. Mastering them makes validation, LCA, iterators, range queries, and recovery much easier.

---

# Table of Contents

1. Search
2. Insert
3. Delete
4. Find Minimum
5. Find Maximum
6. Floor
7. Ceil
8. Successor
9. Predecessor
10. Complexity
11. Common Mistakes
12. Interview Tricks
13. Quick Revision

---

# Core Idea

Every BST operation uses one simple property.

```
target < node

↓

Go Left
```

```
target > node

↓

Go Right
```

Only one path is explored.

Unlike a Binary Tree,

you never need to search both subtrees.

---

# 1. Search in BST

## Idea

Compare the target with the current node.

- Equal → Found
- Smaller → Left
- Larger → Right

---

### Algorithm

```
Start at Root

↓

Target == Node ?

↓

Yes → Return

↓

No

↓

Target < Node ?

↓

Go Left

Else

↓

Go Right
```

---

### Recursive Code

```cpp
TreeNode* searchBST(TreeNode* root, int val) {

    if(root == nullptr || root->val == val)
        return root;

    if(val < root->val)
        return searchBST(root->left, val);

    return searchBST(root->right, val);
}
```

---

### Iterative Code

```cpp
TreeNode* searchBST(TreeNode* root, int val){

    while(root){

        if(root->val == val)
            return root;

        if(val < root->val)
            root = root->left;
        else
            root = root->right;
    }

    return nullptr;
}
```

---

Time

```
Balanced

O(log n)
```

Worst

```
O(n)
```

---

# 2. Insert into BST

## Idea

Search for the correct null position.

Insert the new node there.

---

Example

Insert

```
6
```

```
        8
      /   \
     5     10
    / \
   2   7
```

↓

```
        8
      /   \
     5     10
    / \
   2   7
    \
     6
```

---

### Recursive Code

```cpp
TreeNode* insertIntoBST(TreeNode* root, int val){

    if(root == nullptr)
        return new TreeNode(val);

    if(val < root->val)
        root->left = insertIntoBST(root->left, val);

    else
        root->right = insertIntoBST(root->right, val);

    return root;
}
```

---

Time

```
O(h)
```

where

```
h = height
```

---

# 3. Delete from BST

Deletion is the most important BST operation.

There are **three cases**.

---

## Case 1

Leaf Node

```
5
```

↓

Delete directly.

---

## Case 2

One Child

```
8
 \
 10
```

Replace the node with its child.

---

## Case 3

Two Children ⭐⭐⭐⭐⭐

Replace the node with

- Inorder Successor (minimum of right subtree)

or

- Inorder Predecessor (maximum of left subtree)

Delete that replacement node.

---

### Code

```cpp
TreeNode* findMin(TreeNode* root){

    while(root->left)
        root = root->left;

    return root;
}

TreeNode* deleteNode(TreeNode* root, int key){

    if(root == nullptr)
        return nullptr;

    if(key < root->val)
        root->left = deleteNode(root->left, key);

    else if(key > root->val)
        root->right = deleteNode(root->right, key);

    else{

        if(root->left == nullptr){

            TreeNode* temp = root->right;
            delete root;
            return temp;
        }

        if(root->right == nullptr){

            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = findMin(root->right);

        root->val = temp->val;

        root->right =
            deleteNode(root->right, temp->val);
    }

    return root;
}
```

---

# 4. Find Minimum

Minimum value is always

```
Leftmost Node
```

```cpp
while(root->left)
    root=root->left;
```

---

# 5. Find Maximum

Maximum value is

```
Rightmost Node
```

```cpp
while(root->right)
    root=root->right;
```

---

# 6. Floor

Floor

```
Largest Value

≤ Target
```

Example

```
Target = 11

BST

8 10 12

↓

Floor = 10
```

Algorithm

```
Target < Node

↓

Go Left

Target > Node

↓

Store Answer

↓

Go Right
```

---

# 7. Ceil

Ceil

```
Smallest Value

≥ Target
```

Example

```
Target = 11

↓

Ceil = 12
```

Algorithm

```
Target > Node

↓

Go Right

Target < Node

↓

Store Answer

↓

Go Left
```

---

# 8. Inorder Successor

Definition

Smallest value

```
>

Current Node
```

If right subtree exists

↓

Leftmost node of right subtree.

Otherwise

Keep moving from root,

tracking the last greater node.

---

# 9. Inorder Predecessor

Definition

Largest value

```
<

Current Node
```

If left subtree exists

↓

Rightmost node of left subtree.

Otherwise

Track the last smaller ancestor.

---

# 10. Complexity

| Operation | Balanced | Worst |
|------------|----------|--------|
| Search | O(log n) | O(n) |
| Insert | O(log n) | O(n) |
| Delete | O(log n) | O(n) |
| Min | O(log n) | O(n) |
| Max | O(log n) | O(n) |
| Floor | O(log n) | O(n) |
| Ceil | O(log n) | O(n) |
| Successor | O(log n) | O(n) |
| Predecessor | O(log n) | O(n) |

---

# 11. Common Mistakes

❌ Traversing both subtrees.

Use BST ordering.

---

❌ Forgetting the three deletion cases.

---

❌ Mixing up Floor and Ceil.

Remember

```
Floor ≤ Target

Ceil ≥ Target
```

---

❌ Forgetting to return the updated root after insertion or deletion.

---

# 12. Interview Tricks

If you hear

```
Closest value
```

Think

```
Floor + Ceil
```

---

If you hear

```
Next larger element
```

Think

```
Successor
```

---

If you hear

```
Previous smaller element
```

Think

```
Predecessor
```

---

If you hear

```
Delete Node
```

Immediately think

```
3 Cases
```

---

# 13. Quick Revision

### Navigation Rule

```
Target < Node

↓

Left

Target > Node

↓

Right
```

---

### Minimum

```
Leftmost Node
```

---

### Maximum

```
Rightmost Node
```

---

### Floor

```
Largest

≤ Target
```

---

### Ceil

```
Smallest

≥ Target
```

---

### Successor

```
Next Greater
```

---

### Predecessor

```
Previous Smaller
```

---

### Delete

```
Leaf

↓

One Child

↓

Two Children
```

---

# Interview Checklist

- [ ] Did I use the BST property?
- [ ] Did I avoid unnecessary traversal?
- [ ] Did I handle all three delete cases?
- [ ] Did I return the updated root?
- [ ] Is my complexity O(h)?