# 🌳 Reverse Level Order Traversal

> **Traversal Order:** Visit nodes **from the bottom level to the top level**, while maintaining **left-to-right order within each level**.

---

# Table of Contents

1. Introduction
2. Visualization
3. Intuition
4. Method 1 - BFS + Reverse
5. Method 2 - Queue + Stack
6. Dry Run
7. Complexity Analysis
8. Interview Recognition
9. Common Mistakes
10. Interview Follow-ups
11. Related Questions
12. Company Favorites
13. Quick Revision

---

# 1. Introduction

Reverse Level Order Traversal is simply **Level Order Traversal in reverse**.

Instead of

```
Top

↓

Bottom
```

we print

```
Bottom

↑

Top
```

---

Example

Tree

```
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
```

Level Order

```
1

2 3

4 5 6 7
```

Reverse Level Order

```
4 5 6 7

2 3

1
```

---

# 2. Visualization

```
Level 0

          1

-----------------

Level 1

      2       3

-----------------

Level 2

   4    5   6   7
```

Traversal starts from the **lowest level**.

```
4 5 6 7

↓

2 3

↓

1
```

---

# 3. Intuition

There are two common approaches.

## Method 1

Perform a normal Level Order Traversal.

Store each level.

Reverse the final answer.

Simple and easy to understand.

---

## Method 2

Use

- Queue
- Stack

Queue performs normal BFS.

Stack reverses the visiting order.

---

# Method 1 - BFS + Reverse

## Algorithm

```
Perform Level Order

Store every level

Reverse the answer
```

---

## C++ Code

```cpp
vector<vector<int>> reverseLevelOrder(TreeNode* root){

    vector<vector<int>> ans;

    if(root==nullptr)
        return ans;

    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()){

        int size=q.size();

        vector<int> level;

        while(size--){

            TreeNode* curr=q.front();

            q.pop();

            level.push_back(curr->val);

            if(curr->left)
                q.push(curr->left);

            if(curr->right)
                q.push(curr->right);
        }

        ans.push_back(level);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
```

---

# Method 2 - Queue + Stack

Instead of reversing the final vector,

store nodes in a stack.

Important Trick

Push

```
Right Child

↓

Left Child
```

Why?

Because stack reverses the order.

If we push left first,

output becomes

```
7

6

5

4
```

which is incorrect.

---

## Algorithm

```
Push Root into Queue

While Queue not empty

    Pop node

    Push node into Stack

    Push Right Child

    Push Left Child

Pop Stack

Answer obtained
```

---

## C++ Code

```cpp
vector<int> reverseLevelOrder(TreeNode* root){

    vector<int> ans;

    if(root==nullptr)
        return ans;

    queue<TreeNode*> q;
    stack<TreeNode*> st;

    q.push(root);

    while(!q.empty()){

        TreeNode* curr=q.front();

        q.pop();

        st.push(curr);

        if(curr->right)
            q.push(curr->right);

        if(curr->left)
            q.push(curr->left);
    }

    while(!st.empty()){

        ans.push_back(st.top()->val);

        st.pop();
    }

    return ans;
}
```

---

# 4. Dry Run

Tree

```
      1
     / \
    2   3
```

Queue

```
1
```

Stack

```
1
```

Queue

```
3

2
```

Stack

```
1

2

3
```

Final Stack Output

```
2

3

1
```

Correct Reverse Level Order

---

# 5. Complexity Analysis

Method 1

| Complexity | Value |
|------------|-------|
| Time | O(n) |
| Space | O(n) |

---

Method 2

| Complexity | Value |
|------------|-------|
| Time | O(n) |
| Space | O(n) |

---

# Which Method Should You Use?

| Situation | Best Method |
|-----------|-------------|
| Levels required | BFS + Reverse |
| Single sequence required | Queue + Stack |
| Interview | BFS + Reverse (easier to explain) |

---

# 6. Interview Recognition

If the interviewer says

- Bottom level first
- Reverse BFS
- Reverse Level Order
- Last level to first
- Bottom-up traversal

Think

```
Level Order

+

Reverse
```

or

```
Queue

+

Stack
```

---

# 7. Applications

Reverse Level Order is useful in

- Bottom-up tree processing
- Printing trees
- Tree visualization
- Building trees from bottom
- Some dynamic programming problems
- File system hierarchy display

---

# 8. Common Mistakes

### ❌ Pushing Left Before Right

Wrong

```cpp
q.push(left);

q.push(right);
```

For the Queue + Stack approach, this produces the wrong order after reversal.

Correct

```cpp
q.push(right);

q.push(left);
```

---

### ❌ Forgetting to Reverse

For Method 1,

don't forget

```cpp
reverse(ans.begin(), ans.end());
```

---

### ❌ Mixing Levels

If the question asks for

```cpp
vector<vector<int>>
```

don't flatten everything into one vector.

---

### ❌ Confusing with Postorder

Reverse Level Order

```
Bottom

↓

Top
```

Postorder

```
Left

↓

Right

↓

Root
```

These are completely different traversals.

---

# 9. Interview Follow-ups

### Q1. Can this be solved without reversing?

Yes.

Using

- Queue
- Stack

---

### Q2. Which solution is simpler?

Level Order + Reverse.

Preferred in interviews.

---

### Q3. Does Reverse Level Order always match Postorder?

No.

Example

```
    1
   / \
  2   3
```

Reverse Level Order

```
2 3 1
```

Postorder

```
2 3 1
```

Here they match **by coincidence**.

Now consider

```
      1
     /
    2
   /
  3
```

Reverse Level Order

```
3 2 1
```

Postorder

```
3 2 1
```

Again they match.

But for a more general tree,

```
        1
      /   \
     2     3
    / \
   4   5
```

Reverse Level Order

```
4 5 2 3 1
```

Postorder

```
4 5 2 3 1
```

Still matching.

This often surprises people. The important point is **don't assume they're equivalent**. They are produced by different algorithms and are not guaranteed to match for arbitrary trees (especially when traversal definitions or ordering constraints vary).

---

### Q4. Is this BFS or DFS?

Always BFS.

---

# 10. Related Questions

## Easy

- Binary Tree Level Order Traversal II (LeetCode 107)

---

## Medium

- Binary Tree Zigzag Level Order Traversal (103)
- Binary Tree Right Side View (199)

---

## Hard

- Vertical Order Traversal (987)

---

# 11. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐ |
| Microsoft | ⭐⭐⭐ |
| Google | ⭐⭐ |
| Adobe | ⭐⭐⭐ |
| Oracle | ⭐⭐ |
| Walmart | ⭐⭐⭐ |
| Atlassian | ⭐⭐ |
| Goldman Sachs | ⭐⭐ |
| Flipkart | ⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐ |
| Accenture | ⭐⭐ |
| TCS Digital | ⭐⭐⭐ |

---

# 12. Quick Revision

✅ Traversal

```
Bottom Level

↓

Top Level
```

✅ Core Idea

```
Level Order

+

Reverse
```

or

```
Queue

+

Stack
```

✅ Time

```
O(n)
```

✅ Space

```
O(n)
```

✅ Queue + Stack Trick

```
Push Right

↓

Push Left
```

so that the stack restores the correct left-to-right order.

---

# Interview Checklist

Before submitting:

- [ ] Am I solving a bottom-up traversal?
- [ ] If using Queue + Stack, am I pushing **right before left**?
- [ ] If using BFS + Reverse, did I reverse the final result?
- [ ] Did I preserve left-to-right order within each level?
- [ ] Is my solution O(n) time?