# 🌳 Zigzag (Spiral) Level Order Traversal

> **Traversal Order:** Visit the tree **level by level**, but alternate the direction at every level.

---

# Table of Contents

1. Introduction
2. Visualization
3. Intuition
4. Approach 1 - BFS + Reverse Index (Recommended)
5. Approach 2 - Two Stacks
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

Zigzag Traversal is a variation of **Level Order Traversal (BFS)**.

Instead of traversing every level from **left to right**, the direction changes after each level.

Pattern

```
Level 0 → Left → Right

Level 1 → Right → Left

Level 2 → Left → Right

Level 3 → Right → Left
```

This creates a zigzag (or spiral) pattern.

---

# Example

Tree

```
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
```

Output

```
[
 [1],
 [3,2],
 [4,5,6,7]
]
```

Notice

Level 0

```
1
```

↓

Level 1

```
3 2
```

↓

Level 2

```
4 5 6 7
```

---

# 2. Visualization

```
          1
        ↙   ↘

      2       3

       ↘     ↙

    4   5   6   7
```

Direction changes every level.

```
→

←

→

←
```

---

# 3. Intuition

The traversal is still **BFS**.

The only change is **how we store nodes for each level**.

Instead of changing the traversal itself, we change the position where values are inserted.

This makes the algorithm simple and efficient.

---

# 4. Approach 1 - BFS + Reverse Index (Recommended)

This is the standard interview solution.

### Idea

Perform a normal Level Order Traversal.

For each level:

- If direction is Left → Right, store normally.
- If direction is Right → Left, store values in reverse positions.

No extra reversal is needed.

---

## Algorithm

```
Push Root into Queue

leftToRight = true

While Queue not empty

    size = Queue Size

    Create vector of size elements

    Process all nodes

        If leftToRight

            index = i

        Else

            index = size - 1 - i

        Store value at index

    Toggle direction
```

---

## C++ Code

```cpp
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

    vector<vector<int>> ans;

    if(root == nullptr)
        return ans;

    queue<TreeNode*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()) {

        int size = q.size();

        vector<int> level(size);

        for(int i = 0; i < size; i++) {

            TreeNode* curr = q.front();
            q.pop();

            int index = leftToRight ? i : size - 1 - i;

            level[index] = curr->val;

            if(curr->left)
                q.push(curr->left);

            if(curr->right)
                q.push(curr->right);
        }

        ans.push_back(level);

        leftToRight = !leftToRight;
    }

    return ans;
}
```

---

# Why Use Reverse Index?

Suppose the current level contains

```
2 3
```

Normally

```
Index

0 1

↓

2 3
```

Reverse

```
Index

1 0

↓

2 3

↓

3 2
```

No call to `reverse()` is required.

This saves an extra pass over the level.

---

# 5. Approach 2 - Two Stacks

Another classic solution uses two stacks.

Stack 1

```
Current Level
```

Stack 2

```
Next Level
```

The order of pushing children changes based on the current direction.

Although correct, this approach is longer and less commonly preferred today.

---

## Algorithm

```
Push Root into Stack1

While either stack is not empty

    Process Stack1

        Push Left

        Push Right

    Process Stack2

        Push Right

        Push Left
```

---

## When is it Useful?

Mostly for understanding spiral traversal.

In interviews, **Approach 1 (Queue + Direction Flag)** is preferred because it is shorter, cleaner, and easier to explain.

---

# 6. Dry Run

Tree

```
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
```

Queue

```
1
```

Direction

```
Left → Right
```

Output

```
[1]
```

---

Queue

```
2

3
```

Direction

```
Right → Left
```

Stored as

```
3 2
```

---

Queue

```
4

5

6

7
```

Direction

```
Left → Right
```

Stored as

```
4 5 6 7
```

Final Answer

```
[
 [1],
 [3,2],
 [4,5,6,7]
]
```

---

# 7. Complexity Analysis

Let

```
n = Number of Nodes
```

| Complexity | Value |
|------------|-------|
| Time | O(n) |
| Space | O(n) |

Each node is processed exactly once.

---

# 8. Interview Recognition

If the interviewer mentions

- Spiral Traversal
- Zigzag Traversal
- Alternate Direction
- Left to Right then Right to Left
- Snake Pattern

Think

```
Level Order Traversal

+

Direction Flag
```

---

# 9. Applications

Zigzag Traversal appears in

- UI Tree Rendering
- Binary Tree Visualization
- Printing Hierarchical Data
- Competitive Programming
- Interview Variations of BFS

---

# 10. Common Mistakes

### ❌ Reversing the Queue

The queue should always preserve BFS order.

Only the **output of the current level** changes.

---

### ❌ Forgetting to Toggle Direction

Always do

```cpp
leftToRight = !leftToRight;
```

after finishing each level.

---

### ❌ Calling reverse() Every Time

Works correctly.

However,

using the reverse index technique avoids an additional traversal of the level.

---

### ❌ Changing Child Insertion Order

For the queue-based solution,

always enqueue

```cpp
left

↓

right
```

Changing enqueue order changes the BFS traversal itself and produces incorrect results.

---

# 11. Interview Follow-ups

### Q1. Can Zigzag be solved using DFS?

Yes.

Maintain the current level during DFS.

If the level is even,

append normally.

If odd,

insert at the beginning (or use a deque).

However,

BFS is simpler and the standard interview solution.

---

### Q2. Which approach is preferred?

Queue + Direction Flag.

It is the cleanest implementation.

---

### Q3. Why not reverse every level?

You can.

Time complexity remains **O(n)**.

However,

placing elements directly at the correct index is more elegant and avoids an extra reversal.

---

### Q4. Which data structures can be used?

- Queue + Vector (Recommended)
- Queue + Deque
- Two Stacks
- DFS + Level Tracking

---

# 12. Related Questions

## Medium

- Binary Tree Zigzag Level Order Traversal (LeetCode 103)

---

## Similar Problems

- Binary Tree Level Order Traversal (102)
- Binary Tree Right Side View (199)
- Average of Levels in Binary Tree (637)
- Find Largest Value in Each Tree Row (515)

---

# 13. Company Favorites

| Company | Frequency |
|----------|-----------|
| Amazon | ⭐⭐⭐⭐ |
| Microsoft | ⭐⭐⭐⭐ |
| Google | ⭐⭐⭐ |
| Adobe | ⭐⭐⭐⭐ |
| Walmart | ⭐⭐⭐ |
| Atlassian | ⭐⭐⭐ |
| Oracle | ⭐⭐⭐ |
| Goldman Sachs | ⭐⭐⭐ |
| Flipkart | ⭐⭐⭐⭐ |
| Infosys Specialist Engineer | ⭐⭐ |
| Accenture | ⭐⭐ |
| TCS Digital | ⭐⭐⭐ |

---

# 14. Quick Revision

✅ Traversal Type

```
Breadth First Search
```

---

✅ Data Structure

```
Queue
```

---

✅ Extra Variable

```cpp
bool leftToRight;
```

---

✅ Index Formula

```cpp
// Left → Right
index = i;

// Right → Left
index = size - 1 - i;
```

---

✅ Time Complexity

```
O(n)
```

---

✅ Space Complexity

```
O(n)
```

---

✅ Best Interview Solution

```
Queue

+

Direction Flag

+

Reverse Index
```

---

# Interview Checklist

Before submitting:

- [ ] Did I process nodes level by level?
- [ ] Did I toggle the direction after every level?
- [ ] Am I changing only the output order, not the BFS traversal?
- [ ] Am I using the correct reverse index?
- [ ] Is the complexity O(n) time and O(n) space?