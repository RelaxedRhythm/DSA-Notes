# 🌳 Common Mistakes In Tree Problems

> Most tree interview failures happen because of small recursion, edge case, or logic mistakes.

This file contains mistakes to avoid before submitting solutions.

---

# 1. Wrong Base Cases

## Mistake

Not handling NULL nodes properly.

Example:

```cpp
int height(TreeNode* root){

    return 1 + max(
        height(root->left),
        height(root->right)
    );
}
```

Problem:

If root is NULL:

```
segmentation fault
```

---

# Correct

Always start recursion with:

```cpp
if(root == nullptr)
    return base_value;
```

---

# Base Values

| Problem | Return |
|---|---|
| Height | 0 |
| Count Nodes | 0 |
| Search | false/null |
| Path Sum | false |
| Diameter | 0 |

---

<br>

# 2. Height vs Depth Confusion

## Height

Distance:

```
Node → Deepest Leaf
```

---

## Depth

Distance:

```
Root → Node
```

---

Example:

```
        1
       /
      2
     /
    3
```

Height of node 1:

```
2
```

Depth of node 3:

```
2
```

---

# Common Interview Trap

Question:

"Maximum depth of binary tree"

Actually means:

```
Height of tree
```

---

<br>

# 3. Returning Wrong Values From Recursion

## Important Question

Before writing recursion:

Ask:

```
What should this function return?
```

---

Example:

Diameter problem.

Wrong:

Return diameter.

Correct:

Return height.

Because parent needs:

```
child height
```

---

# Rule

Parent should receive the information it needs.

---

<br>

# 4. Global Variable Misuse

Many tree problems use:

```cpp
int answer;
```

Examples:

- Diameter
- Maximum path sum

---

# Mistake

Not resetting between test cases.

Example:

```cpp
int diameter = 0;
```

should be inside solution function.

---

# Correct

```cpp
int solve(TreeNode* root){

    int answer = 0;

}
```

---

<br>

# 5. Recursion Stack Issues

## Problem

A skewed tree:

```
        1
         \
          2
           \
            3
             \
              4
```

has height:

```
n
```

---

Recursive depth:

```
O(n)
```

---

# Risk

Very large trees may cause:

```
stack overflow
```

---

# Solution

Use:

- Iterative DFS
- BFS
- Explicit stack

when needed.

---

<br>

# 6. Forgetting Leaf Node Condition

Many path problems require root-to-leaf.

---

# Wrong

```cpp
if(root)
    check sum
```

---

# Correct

A leaf means:

```cpp
!root->left && !root->right
```

---

# Example

```
       1
      /
     2
```

2 is leaf.

1 is not.

---

<br>

# 7. Duplicate Values Handling

## Problem

Trees may contain:

```
same values
```

Example:

```
        1
       / \
      2   2
```

---

# Mistake

Comparing only values.

---

# Correct

Compare:

```
value

+

structure
```

---

Used in:

- Same Tree
- Subtree
- Symmetry

---

<br>

# 8. Forgetting Tree Can Be Skewed

Many solutions assume:

```
balanced tree
```

---

Example:

```
1

 \

  2

   \

    3
```

---

# Impact

Operations become:

```
O(n)
```

instead of:

```
O(log n)
```

---

Especially important for:

- BST
- Recursion depth

---

<br>

# 9. Wrong Traversal Selection

Choosing traversal incorrectly causes many failures.

---

# Examples

## Height

Need:

```
Postorder
```

because children information is required.

---

## Serialization

Need:

```
Preorder
```

because root comes first.

---

## BST Sorted Output

Need:

```
Inorder
```

---

## Delete Tree

Need:

```
Postorder
```

because children must be deleted first.

---

<br>

# 10. Ignoring Negative Values

Important for:

- Maximum Path Sum
- Path problems

---

Example:

```
        -10
        /  \
       9    20
           / \
          15  7
```

---

# Mistake

Adding negative contribution.

---

# Correct

Ignore negative branches:

```cpp
max(0, contribution)
```

---

<br>

# 11. Integer Overflow

Tree values can be large.

Example:

```
Maximum Path Sum
```

---

Wrong:

```cpp
int answer = 0;
```

---

Better:

```cpp
long long answer;
```

when constraints require.

---

<br>

# 12. Forgetting Empty Tree Case

Always test:

```
root = NULL
```

---

Questions affected:

- Traversals
- Height
- Diameter
- Serialization

---

<br>

# 13. Incorrect Queue Handling In BFS

## Mistake

Not storing current level size.

Wrong:

```cpp
while(!q.empty())
```

for level problems.

---

Correct:

```cpp
int size = q.size();

while(size--)
{
}
```

---

Used in:

- Level order
- Views
- Zigzag traversal

---

<br>

# 14. Missing Visited Array After Adding Parent

Important for:

- Burning Tree
- Distance K

---

Before:

```
Tree
```

After adding parent:

```
Graph
```

---

Need:

```cpp
visited[node]
```

otherwise:

```
child → parent → child
```

cycle.

---

<br>

# 15. Confusing Diameter Counting

Diameter can be counted as:

## Number of Edges

Formula:

```
leftHeight + rightHeight
```

---

## Number of Nodes

Formula:

```
leftHeight + rightHeight + 1
```

---

Always check problem statement.

---

<br>

# 16. Not Doing Dry Run

Before submitting:

Test:

## Single Node

```
1
```

---

## Left Skewed

```
1
/
2
/
3
```

---

## Right Skewed

```
1
 \
  2
   \
    3
```

---

## Duplicate Values

```
1
/ \
2 2
```

---

## Negative Values

```
-1
```

---

# Final Tree Debug Checklist

Before submitting:

```
✓ Base case handled

✓ Null checked

✓ Correct traversal chosen

✓ Return value makes sense

✓ Global variables reset

✓ Single node tested

✓ Skew tree tested

✓ Duplicate values considered

✓ Complexity calculated
```

---

# Golden Rule

In tree recursion:

```
The hardest part is not coding.

The hardest part is deciding:

"What does this recursive function return?"
```

Once this is clear, most tree problems become straightforward.