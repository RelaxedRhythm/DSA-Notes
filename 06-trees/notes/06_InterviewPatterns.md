# 🌳 Tree Interview Patterns

> Complete pattern recognition guide for solving Tree problems in coding interviews.

> Goal:
>
> Understand **how to identify the pattern before coding**.

---

# 1. Traversal Pattern

## Pattern Explanation

Traversal means visiting every node of a tree systematically.

Almost every tree problem begins with choosing the correct traversal.

The major traversals are:

```
DFS

- Preorder
- Inorder
- Postorder


BFS

- Level Order
```

The choice of traversal depends on what information the problem requires.

---

# How to Identify

Look for:

- Visit every node
- Print all nodes
- Count nodes
- Sum nodes
- Find maximum/minimum
- Convert tree
- Copy tree
- Search entire tree

Think:

```
Traversal
```

---

# Core Intuition

The question is:

> "When should I process the current node?"

There are three positions.

---

## Preorder

```
Root

↓

Left

↓

Right
```

Process node before children.

### Use when:

- Copying tree
- Serialization
- Constructing tree
- Flattening tree


---

## Inorder

```
Left

↓

Root

↓

Right
```

Process node between children.

### Use when:

- BST problems
- Sorted order
- Kth smallest/largest
- Validate BST


---

## Postorder

```
Left

↓

Right

↓

Root
```

Process node after children.

### Use when:

- Height calculation
- Diameter
- Tree DP
- Delete tree
- Maximum path sum


---

# BFS / Level Order

Uses queue.

Traversal happens level by level.

Example:

```
        1
      /   \
     2     3
    / \
   4   5
```

Output:

```
1

2 3

4 5
```

---

# Complexity

For all traversals:

Time:

```
O(n)
```

because every node is visited once.

Space:

DFS:

```
O(h)
```

BFS:

```
O(width)
```

---

# Common Mistakes

## Wrong traversal selection

Example:

Finding height.

Wrong:

```
Preorder
```

Correct:

```
Postorder
```

because children information is required.

---

## Ignoring recursion return value

Many tree problems depend on:

```
What does the child return?
```

---

# Related Problems

- Binary Tree Traversal
- Level Order Traversal
- Zigzag Traversal
- Vertical Traversal
- Boundary Traversal

---

<br>

# 2. DFS Pattern

## Pattern Explanation

Depth First Search explores one branch completely before moving to another.

Tree DFS usually uses:

- Recursion
- Stack

Flow:

```
Root

↓

Explore Left

↓

Explore Right
```

---

# How to Identify

Keywords:

- Root to leaf
- Path
- All paths
- Subtree
- Ancestor
- Height
- Depth
- Longest path
- Maximum contribution

Think:

```
DFS Recursion
```

---

# Core Intuition

Every recursive DFS function should answer:

> "What information should this node return to its parent?"

Examples:

Height:

```
Return height
```

Path Sum:

```
Return whether path exists
```

Diameter:

```
Return maximum height contribution
```

---

# General Template

```cpp
int dfs(TreeNode* root){

    if(root == nullptr)
        return 0;


    int left = dfs(root->left);

    int right = dfs(root->right);


    return answer;
}
```

---

# DFS Types

## 1. Simple DFS

Only visit nodes.

Examples:

- Count nodes
- Search value

---

## 2. DFS With Return Value

Most interview problems.

Example:

Height:

```
1 + max(left,right)
```

---

## 3. DFS With Global Answer

Used when:

answer cannot be returned directly.

Examples:

- Diameter
- Maximum Path Sum

---

# Brute Force vs Optimal Example

Problem:

Diameter of Binary Tree.

---

Brute Force:

For every node:

- Calculate left height
- Calculate right height

Time:

```
O(n²)
```

---

Optimal:

Calculate height once.

Time:

```
O(n)
```

---

# Complexity

Time:

```
O(n)
```

Space:

```
O(h)
```

---

# Common Mistakes

## Forgetting base case

Always:

```cpp
if(root == nullptr)
```

---

## Not knowing return value

Before coding:

Ask:

```
What should this DFS return?
```

---

## Using global variables incorrectly

Reset answer before every new test case.

---

# Related Problems

Easy:

- Maximum Depth
- Same Tree
- Path Sum


Medium:

- Diameter
- Balanced Tree
- LCA


Hard:

- Maximum Path Sum
- Serialize/Deserialize

---

<br>

# 3. BFS Pattern

## Pattern Explanation

Breadth First Search processes nodes level by level.

Implemented using:

```
Queue
```

---

# How to Identify

Keywords:

- Level
- Floor
- Distance
- Minimum steps
- Nearest
- Same level
- View

Think:

```
BFS / Queue
```

---

# Core Algorithm

1. Push root into queue.
2. Process current level.
3. Push children.
4. Repeat.

---

# Template

```cpp
vector<vector<int>> levelOrder(TreeNode* root){

    vector<vector<int>> ans;

    if(root == nullptr)
        return ans;


    queue<TreeNode*> q;

    q.push(root);


    while(!q.empty()){

        int size = q.size();

        vector<int> level;


        while(size--){

            TreeNode* node = q.front();

            q.pop();


            level.push_back(node->val);


            if(node->left)
                q.push(node->left);


            if(node->right)
                q.push(node->right);
        }


        ans.push_back(level);
    }


    return ans;
}
```

---

# Common Uses

## Level Order Traversal

Direct BFS.

---

## Right View

Take last node of every level.

---

## Left View

Take first node of every level.

---

## Zigzag Traversal

Alternate direction every level.

---

## Minimum Distance

BFS gives shortest path in unweighted trees.

---

# Complexity

Time:

```
O(n)
```

Space:

```
O(width)
```

---

# Common Mistakes

## Using DFS for shortest distance

For minimum steps:

Use BFS.

---

## Forgetting level size

For level problems:

Store:

```cpp
int size = q.size();
```

before processing.

---

# Related Problems

- Level Order Traversal
- Zigzag Traversal
- Right View
- Left View
- Distance K
- Burning Tree

---

# 4. Tree DP Pattern

## Pattern Explanation

Tree DP means:

> Solve a problem by collecting information from children and using it at the parent.

Unlike normal recursion where we only traverse,

Tree DP stores and combines results from subtrees.

Most Tree DP follows:

```
Left Subtree Answer

+

Right Subtree Answer

↓

Current Node Answer
```

---

# How to Identify

Keywords:

- Maximum
- Minimum
- Longest
- Best answer
- Contribution
- Subtree information
- Need information from children

Think:

```
Postorder DFS + DP
```

---

# Core Intuition

A node cannot solve the problem alone.

It needs information from:

```
Left Child

+

Right Child
```

The recursion returns that information.

---

# General Template

```cpp
int dfs(TreeNode* root){

    if(root == nullptr)
        return base;


    int left = dfs(root->left);

    int right = dfs(root->right);


    int answer = combine(left,right);


    return answer;
}
```

---

# Common Tree DP Problems

## Height of Binary Tree

Return:

```
1 + max(left,right)
```

---

## Diameter of Binary Tree

Need:

```
left height

+

right height
```

---

## Maximum Path Sum

Need:

```
maximum contribution from children
```

---

## Balanced Binary Tree

Need:

```
height difference
```

---

# Brute Force vs Optimal

Example:

Balanced Tree.

Brute force:

For every node:

- Calculate left height
- Calculate right height

Complexity:

```
O(n²)
```

---

Tree DP:

Calculate height while checking balance.

Complexity:

```
O(n)
```

---

# Complexity

Most Tree DP:

Time:

```
O(n)
```

Space:

```
O(h)
```

---

# Common Mistakes

## Returning wrong information

Ask:

```
What does parent need?
```

---

## Updating answer incorrectly

Some problems require:

```
global maximum
```

instead of returning the answer.

---

## Confusing subtree answer and path answer

Example:

Diameter is not just height.

---

# Related Problems

- Diameter
- Maximum Path Sum
- Balanced Tree
- Largest BST
- House Robber III

---

<br>

# 5. Path Problems Pattern

## Pattern Explanation

Path problems involve moving through connected nodes and finding information along a path.

A path can be:

```
Root → Leaf

or

Any Node → Any Node
```

---

# How to Identify

Keywords:

- Path sum
- Root to leaf
- Maximum path
- All paths
- Print paths
- Target sum

Think:

```
DFS + Backtracking
```

---

# Types of Paths

## Root to Leaf Path

Example:

```
        1
       /
      2
     /
    3
```

Path:

```
1 → 2 → 3
```

---

## Any Node to Any Node

Example:

```
       1
      / \
     2   3
```

Path:

```
2 → 1 → 3
```

Requires Tree DP.

---

# Root To Leaf Template

```cpp
void dfs(TreeNode* root,
         vector<int>& path){

    if(root == nullptr)
        return;


    path.push_back(root->val);


    if(!root->left &&
       !root->right){

        // process path
    }


    dfs(root->left,path);

    dfs(root->right,path);


    path.pop_back();
}
```

---

# Why Backtracking?

Because the path belongs only to the current branch.

Example:

```
      1
    /   \
   2     3
```

After exploring:

```
1 → 2
```

remove 2 before exploring:

```
1 → 3
```

---

# Common Problems

## Path Sum

Check if root-to-leaf sum equals target.

---

## Path Sum II

Return all valid paths.

---

## Binary Tree Paths

Print all root-to-leaf paths.

---

## Maximum Path Sum

Uses Tree DP.

---

# Complexity

Visiting every node:

```
O(n)
```

Path storage:

```
O(h)
```

---

# Common Mistakes

## Forgetting backtracking

Missing:

```cpp
path.pop_back();
```

---

## Checking leaf condition incorrectly

Leaf:

```cpp
!left && !right
```

---

## Confusing path types

Root-to-leaf:

Starts from root.

Any-node path:

Needs DP.

---

# Related Problems

- Path Sum
- Path Sum II
- Maximum Path Sum
- Binary Tree Paths
- Sum Root to Leaf Numbers

---

<br>

# 6. Subtree Problems Pattern

## Pattern Explanation

Subtree problems ask about:

```
A complete tree inside another tree
```

A subtree contains:

- Node
- All descendants

---

# How to Identify

Keywords:

- Subtree
- Contains tree
- Match structure
- Duplicate subtree
- Check if tree exists inside another tree

Think:

```
DFS + Tree Matching
```

---

# Core Idea

For every node:

Ask:

```
Can the subtree starting here match?
```

---

# Same Tree Helper

Most subtree problems require:

```cpp
bool same(TreeNode* a,
          TreeNode* b)
{
    if(a==nullptr || b==nullptr)
        return a==b;


    return a->val == b->val

        && same(a->left,b->left)

        && same(a->right,b->right);
}
```

---

# Subtree Check

Algorithm:

```
Start from root

↓

Compare current subtree

↓

Move left

↓

Move right
```

---

# Brute Force

For every node:

Run tree comparison.

Complexity:

```
O(n*m)
```

where:

```
n = main tree size

m = subtree size
```

---

# Better Approach

Serialize both trees.

Use pattern matching.

Example:

```
Tree Serialization

+

KMP
```

Complexity:

```
O(n+m)
```

---

# Common Subtree Problems

- Subtree of Another Tree
- Duplicate Subtrees
- Largest Subtree
- Count Complete Subtrees

---

# Common Mistakes

## Ignoring structure

Values alone are not enough.

Structure matters.

---

## Forgetting null comparison

These are different:

```
null

and

node
```

---

# Related Problems

- Same Tree
- Serialize Deserialize
- Mirror Tree

---

<br>

# 7. Ancestor Problems Pattern

## Pattern Explanation

Ancestor problems deal with finding relationships between nodes.

Examples:

- Lowest Common Ancestor
- Find ancestors
- Distance from ancestor

---

# How to Identify

Keywords:

- Common parent
- Ancestor
- Lowest shared node
- Parent relationship

Think:

```
DFS + LCA
```

---

# Core Idea

A node is an ancestor if:

```
One target exists below it
```

---

# Binary Tree LCA Idea

At every node:

Search:

```
Left subtree

Right subtree
```

Cases:

Both sides return nodes:

```
Current node is LCA
```

---

# BST LCA

Use ordering:

```
Both smaller

↓

Left


Both larger

↓

Right


Different sides

↓

Answer
```

---

# Common Problems

- Lowest Common Ancestor
- Kth Ancestor
- Distance Between Nodes
- Find Parent

---

# Complexity

Binary Tree:

```
O(n)
```

BST:

```
O(h)
```

---

# Common Mistakes

## Assuming BST logic works everywhere

It does not.

---

## Forgetting node can be ancestor of itself

Example:

```
LCA(5,5)

=

5
```

---

# Related Problems

- LCA Binary Tree
- LCA BST
- Distance Between Nodes

---
# 8. View Problems Pattern

## Pattern Explanation

View problems ask:

> "What nodes are visible when looking at a tree from a particular direction?"

Types:

- Left View
- Right View
- Top View
- Bottom View

---

# How to Identify

Keywords:

- View from left
- View from right
- Visible nodes
- First node of level
- Last node of level

Think:

```
Level Order BFS
```

or

```
DFS with level tracking
```

---

# 1. Left View

## Idea

The first node visible at every level.

Example:

```
        1
      /   \
     2     3
    / \
   4   5
```

Left view:

```
1 2 4
```

---

## BFS Approach

For every level:

Take first node.

```cpp
if(i == 0)
    answer.push_back(node->val);
```

---

## DFS Approach

Order:

```
Root

↓

Left

↓

Right
```

Store first node encountered at every depth.

---

# 2. Right View

## Idea

The last node visible at every level.

Example:

```
        1
      /   \
     2     3
          /
         4
```

Right view:

```
1 3 4
```

---

## BFS

Take last node of every level.

```cpp
if(i == size-1)
```

---

## DFS

Order:

```
Root

↓

Right

↓

Left
```

---

# 3. Top View

## Idea

Nodes visible from top.

Need horizontal distance.

Assign:

```
Root = 0

Left = -1

Right = +1
```

For every horizontal distance:

store first node.

---

## Algorithm

Use:

```
BFS

+

HashMap
```

because BFS naturally gives the topmost node.

---

# 4. Bottom View

Opposite of top view.

For every horizontal distance:

store the last node.

Use:

```
BFS + HashMap
```

---

# Complexity

All view problems:

Time:

```
O(n)
```

Space:

```
O(n)
```

---

# Common Mistakes

## Mixing top and bottom view

Top:

```
First encountered
```

Bottom:

```
Last encountered
```

---

## Forgetting horizontal distance

Vertical-based views need:

```
column tracking
```

---

# Related Problems

- Binary Tree Right Side View
- Top View
- Bottom View
- Vertical Order Traversal


---

<br>

# 9. Distance Problems Pattern

## Pattern Explanation

Distance problems ask about:

- Distance between nodes
- Nodes at distance K
- Minimum distance
- Nearest nodes

---

# How to Identify

Keywords:

- Distance
- K distance
- Nearest
- Steps
- Minimum moves

Think:

```
Convert Tree into Graph

+

BFS
```

---

# Core Idea

Trees only have:

```
Child → Parent
```

movement.

But distance problems need:

```
Child ↔ Parent
```

movement.

So create parent pointers.

---

# Parent Map Technique

Example:

```
        1
       /
      2
     /
    3
```

Create:

```
2 → 1

3 → 2
```

Now movement:

```
Left

Right

Parent
```

is possible.

---

# Nodes At Distance K

Algorithm:

1. Build parent map.
2. Start BFS from target node.
3. Move in three directions:

```
left

right

parent
```

4. Stop after K levels.

---

# Complexity

Time:

```
O(n)
```

Space:

```
O(n)
```

---

# Common Mistakes

## Forgetting visited array

Tree becomes graph after adding parents.

Without visited:

infinite loop.

---

## Using DFS for minimum distance

For shortest distance:

use BFS.

---

# Related Problems

- All Nodes Distance K
- Burning Tree
- Minimum Time to Burn Tree
- Distance Between Two Nodes


---

<br>

# 10. Diameter Pattern

## Pattern Explanation

Diameter means:

> Longest path between any two nodes.

Path can pass through:

```
Root

or

Any node
```

---

# How to Identify

Keywords:

- Longest path
- Maximum distance
- Farthest nodes
- Number of edges between nodes

Think:

```
Tree DP
```

---

# Core Formula

For every node:

```
Diameter through node

=

Left Height

+

Right Height
```

---

# Algorithm

Use postorder DFS.

At every node:

1. Find left height.
2. Find right height.
3. Update diameter.
4. Return height.

---

# Template

```cpp
int dfs(TreeNode* root){

    if(!root)
        return 0;


    int left = dfs(root->left);

    int right = dfs(root->right);


    diameter = max(
        diameter,
        left + right
    );


    return 1 + max(left,right);
}
```

---

# Complexity

Time:

```
O(n)
```

Space:

```
O(h)
```

---

# Common Mistakes

## Confusing height and diameter

Height:

```
Longest root-to-leaf path
```

Diameter:

```
Longest node-to-node path
```

---

## Adding current node

If diameter counts edges:

use:

```
left + right
```

not:

```
left + right + 1
```

---

# Related Problems

- Diameter of Binary Tree
- Longest Path in Tree
- Tree Height Problems


---

<br>

# 11. Maximum Path Sum Pattern

## Pattern Explanation

Find maximum sum path between any two nodes.

Example:

```
        10
       /  \
      5    20
```

Maximum path:

```
5 → 10 → 20
```

---

# How to Identify

Keywords:

- Maximum sum
- Highest value path
- Any node to any node
- Path contribution

Think:

```
Tree DP + Global Answer
```

---

# Core Idea

A node contributes only the best one-side path to its parent.

Why?

A parent cannot take both sides.

Example:

```
      10
     /  \
    5    20
```

Parent cannot continue both:

```
5 + 10 + 20
```

upwards.

---

# Algorithm

For every node:

Calculate:

```
left contribution

right contribution
```

Ignore negative values.

Update:

```
left + node + right
```

Return:

```
node + max(left,right)
```

---

# Template

```cpp
int dfs(TreeNode* root){

    if(!root)
        return 0;


    int left =
    max(0,dfs(root->left));


    int right =
    max(0,dfs(root->right));


    answer=max(
        answer,
        left+right+root->val
    );


    return root->val+
           max(left,right);
}
```

---

# Complexity

Time:

```
O(n)
```

Space:

```
O(h)
```

---

# Common Mistakes

## Forgetting negative values

Negative contribution should be removed.

---

## Returning complete path

Only one side can be returned upward.

---

## Confusing with diameter

Diameter:

```
counts nodes/edges
```

Maximum path sum:

```
uses values
```

---

# Related Problems

- Binary Tree Maximum Path Sum
- Path Sum
- Diameter of Binary Tree

---

# 12. Balanced Tree Pattern

## Pattern Explanation

A balanced binary tree means:

For every node,

```
Height(left subtree)

-

Height(right subtree)

<= 1
```

The difference should not be more than 1.

---

# How to Identify

Keywords:

- Balanced
- Height difference
- AVL condition
- Check if tree is skewed

Think:

```
Postorder DFS
```

---

# Core Intuition

To check balance:

Every node needs:

```
Left Height

+

Right Height
```

So calculate height while checking balance.

---

# Brute Force

For every node:

1. Calculate left height.
2. Calculate right height.
3. Check difference.

Problem:

Height calculation repeats.

Complexity:

```
O(n²)
```

---

# Optimal Approach

Return height.

If imbalance occurs:

return special value.

Example:

```
-1 means unbalanced
```

---

# Template

```cpp
int height(TreeNode* root){

    if(!root)
        return 0;


    int left = height(root->left);

    if(left == -1)
        return -1;


    int right = height(root->right);

    if(right == -1)
        return -1;


    if(abs(left-right)>1)
        return -1;


    return 1 + max(left,right);
}
```

---

# Complexity

Time:

```
O(n)
```

Space:

```
O(h)
```

---

# Common Mistakes

## Calculating height separately

Avoid:

```cpp
height(left)

height(right)
```

for every node.

---

## Returning boolean only

Height information is needed.

---

# Related Problems

- Balanced Binary Tree
- AVL Tree
- Height Problems


---

<br>

# 13. Symmetry Pattern

## Pattern Explanation

A tree is symmetric if:

The left subtree is a mirror image of the right subtree.

Example:

```
        1
       / \
      2   2
     /     \
    3       3
```

---

# How to Identify

Keywords:

- Mirror
- Symmetric
- Same from both sides

Think:

```
Recursive Comparison
```

---

# Core Idea

Compare two trees:

```
Left subtree

with

Right subtree
```

Rules:

Values must match.

Structure must match.

---

# Mirror Condition

For nodes:

```
left.val == right.val
```

Then compare:

```
left.left

with

right.right
```

and

```
left.right

with

right.left
```

---

# Template

```cpp
bool mirror(TreeNode* a,
            TreeNode* b){

    if(!a || !b)
        return a == b;


    return a->val == b->val

        && mirror(a->left,b->right)

        && mirror(a->right,b->left);
}
```

---

# Complexity

Time:

```
O(n)
```

Space:

```
O(h)
```

---

# Common Mistakes

## Comparing same direction

Wrong:

```
left-left

right-right
```

Correct:

```
left-left

right-right
```

for mirrored positions:

```
left.left

right.right
```

---

# Related Problems

- Symmetric Tree
- Mirror Tree
- Same Tree


---

<br>

# 14. Serialization Pattern

## Pattern Explanation

Serialization means:

Convert tree into a string.

Deserialization means:

Convert string back into tree.

---

# How to Identify

Keywords:

- Store tree
- Send tree over network
- Save tree
- Reconstruct tree

Think:

```
Traversal + Encoding
```

---

# Core Intuition

A tree structure must preserve:

- Values
- Null children

Example:

Tree:

```
    1
   /
  2
```

Without null information:

```
1,2
```

cannot know whether 2 is left or right.

---

# Common Approach

Use preorder.

Format:

```
Root

Left

Right
```

Add marker:

```
#
```

for null.

Example:

```
1,2,#,#,3,#,#
```

---

# Serialization Algorithm

DFS:

1. Store node value.
2. Serialize left.
3. Serialize right.

---

# Deserialization

Read values sequentially.

If:

```
#
```

return null.

Otherwise:

Create node.

Build left.

Build right.

---

# Complexity

Time:

```
O(n)
```

Space:

```
O(n)
```

---

# Common Mistakes

## Forgetting null markers

Structure is lost.

---

## Using inorder alone

Inorder cannot uniquely reconstruct a tree.

---

# Related Problems

- Serialize and Deserialize Binary Tree
- Construct Tree


---

<br>

# 15. Construction Pattern

## Pattern Explanation

Construction problems rebuild a tree from traversal information.

Common combinations:

```
Preorder + Inorder

Postorder + Inorder
```

---

# How to Identify

Keywords:

- Construct tree
- Build tree
- Given traversals
- Reconstruct

Think:

```
HashMap + Recursion
```

---

# Core Intuition

Inorder tells:

```
Left | Root | Right
```

Preorder tells:

```
Root first
```

Postorder tells:

```
Root last
```

---

# Preorder + Inorder

Algorithm:

1. First preorder element is root.
2. Find root in inorder.
3. Left side = left subtree.
4. Right side = right subtree.
5. Repeat.

---

# Optimization

Store inorder positions:

```
unordered_map
```

so searching root is:

```
O(1)
```

---

# Complexity

Time:

```
O(n)
```

Space:

```
O(n)
```

---

# Common Mistakes

## Wrong preorder index movement

Increment root index correctly.

---

## Missing base case

When:

```
start > end
```

return null.

---

# Related Problems

- Construct Binary Tree From Preorder and Inorder
- Construct Binary Tree From Postorder and Inorder

---

# 16. BST Pattern

## Pattern Explanation

Binary Search Tree problems are solved using the ordering property:

```
Left Subtree

< Root

< Right Subtree
```

This allows avoiding unnecessary traversal.

---

# How to Identify

Keywords:

- BST
- Sorted order
- Kth smallest/largest
- Search
- Range
- Floor
- Ceil
- Predecessor
- Successor

Think:

```
Use BST property
```

---

# Core Intuition

A normal Binary Tree requires:

```
Visit everything
```

A BST allows:

```
Discard half of the tree
```

similar to binary search.

---

# Common BST Patterns

---

## 1. Search in BST

### Idea

Compare target with current node.

```
target < root

↓

Go left
```

```
target > root

↓

Go right
```

---

Complexity:

Average:

```
O(log n)
```

Worst:

```
O(n)
```

---

## 2. Insert in BST

Find correct empty position.

Rule:

```
Smaller → Left

Greater → Right
```

---

## 3. Validate BST

### Recognition

Question:

"Is this a valid BST?"

Think:

```
Range Recursion
```

---

Wrong approach:

Only compare:

```
node.left < node

node.right > node
```

This fails.

Example:

```
       5
      / \
     1   7
        /
       4
```

4 is less than 5 but exists in right subtree.

Invalid.

---

Correct:

Maintain range:

```
(min,max)
```

---

## 4. Kth Smallest / Largest

### Key Observation

BST inorder gives:

```
Sorted order
```

Example:

```
2 3 4 5 6
```

Kth smallest:

Perform inorder and count nodes.

---

## 5. Floor and Ceil

### Floor

Largest value:

```
<= target
```

---

### Ceil

Smallest value:

```
>= target
```

---

## 6. Lowest Common Ancestor in BST

Use ordering.

For nodes:

```
p and q
```

Cases:

Both smaller:

```
Go left
```

Both larger:

```
Go right
```

Otherwise:

```
Current node is answer
```

---

# BST Complexity

Balanced BST:

Search:

```
O(log n)
```

Traversal:

```
O(n)
```

Skewed BST:

```
O(n)
```

---

# Common Mistakes

## Forgetting BST property

Do not blindly DFS.

---

## Assuming balanced tree

BST can become:

```
Linked List
```

---

## Using inorder unnecessarily

Many BST problems can be solved with direct traversal.

---

# Related Problems

- Validate BST
- Kth Smallest
- BST Iterator
- Recover BST
- Range Sum BST
- LCA BST


---

<br>

# 17. Prefix Sum in Trees Pattern

## Pattern Explanation

Prefix sum stores information about the path from root to current node.

Commonly used for:

```
Root-to-node paths
```

and

```
Path sum counting
```

---

# How to Identify

Keywords:

- Number of paths
- Sum equals target
- Root-to-node
- Path count
- Multiple paths

Think:

```
DFS + HashMap Prefix Sum
```

---

# Core Intuition

For arrays:

```
prefix[j] - prefix[i] = target
```

Same idea applies to trees.

Current path sum:

```
currentSum
```

Need previous sum:

```
currentSum - target
```

---

# Algorithm

Maintain:

```
unordered_map<int,int>
```

which stores:

```
prefixSum frequency
```

During DFS:

1. Add current node value.
2. Check required previous sum.
3. Explore children.
4. Remove current sum while backtracking.

---

# Template

```cpp
int dfs(TreeNode* root,
        int sum){

    if(!root)
        return 0;


    sum += root->val;


    int ans = mp[sum-target];


    mp[sum]++;


    ans += dfs(root->left,sum);

    ans += dfs(root->right,sum);


    mp[sum]--;


    return ans;
}
```

---

# Complexity

Time:

```
O(n)
```

Space:

```
O(h)
```

---

# Common Mistakes

## Forgetting backtracking

Remove prefix after returning.

---

## Confusing with root-to-leaf only

Prefix sum handles:

```
Any downward path
```

---

# Related Problems

- Path Sum III
- Sum Root to Leaf Numbers
- Maximum Path Problems


---

<br>

# 18. Level Order Variations Pattern

## Pattern Explanation

Many tree problems are small modifications of BFS.

Base:

```
Level Order Traversal
```

---

# How to Identify

Keywords:

- Each level
- Alternate direction
- Maximum per level
- Average level
- Last node
- First node

Think:

```
Queue + Level Processing
```

---

# Common Variations

---

## Zigzag Traversal

Alternate direction.

Example:

```
Level 1:

Left → Right


Level 2:

Right → Left
```

---

## Average of Levels

Store sum:

```
sum / level size
```

---

## Maximum Width

Track:

```
position index
```

of nodes.

---

## Right View

Take:

```
last node of level
```

---

## Left View

Take:

```
first node of level
```

---

# Generic Template

```cpp
queue<TreeNode*> q;

q.push(root);


while(!q.empty()){

    int size=q.size();


    while(size--){

        TreeNode* node=q.front();

        q.pop();


        if(node->left)
            q.push(node->left);


        if(node->right)
            q.push(node->right);
    }
}
```

---

# Complexity

Time:

```
O(n)
```

Space:

```
O(w)
```

where:

```
w = maximum width
```

---

# Common Mistakes

## Not storing level size

Without:

```cpp
int size=q.size();
```

levels get mixed.

---

## Forgetting empty tree case

Always handle:

```
root == nullptr
```

---

# Related Problems

- Level Order Traversal
- Zigzag Traversal
- Right View
- Maximum Width
- Average Levels

---
# 19. Parent Pointer Pattern

## Pattern Explanation

Normally in a binary tree:

```
Parent

↓

Child
```

movement is only downward.

But many problems require:

```
Child

↓

Parent
```

movement.

Examples:

- Nodes at distance K
- Burning Tree
- Minimum distance between nodes

For this, we store parent references.

---

# How to Identify

Keywords:

- Move upward
- Distance from node
- Nearest nodes
- Minimum time
- Spread
- Infection

Think:

```
Tree → Graph conversion
```

---

# Core Intuition

A tree is naturally directed:

```
Parent → Child
```

After adding parent pointers:

```
          Parent
        ↙   ↓   ↘
      Left Node Right
```

Now each node has three possible directions:

```
Left

Right

Parent
```

---

# Algorithm

Build parent map using DFS/BFS.

Example:

```cpp
parent[child] = node;
```

Then use BFS.

---

# Complexity

Building parent map:

```
O(n)
```

BFS:

```
O(n)
```

Total:

```
O(n)
```

Space:

```
O(n)
```

---

# Common Mistakes

## Forgetting visited array

After adding parent links:

Tree becomes a graph.

Without visited:

```
Child → Parent → Child
```

infinite loop.

---

## Using DFS for shortest distance

Minimum distance problems require:

```
BFS
```

---

# Related Problems

- All Nodes Distance K
- Burning Tree
- Minimum Time to Burn Tree


---

<br>

# 20. Burning Tree Pattern

## Pattern Explanation

Problem:

A fire starts from a target node.

Find the time required to burn the entire tree.

At every second:

Fire spreads to:

- Left child
- Right child
- Parent

---

# How to Identify

Keywords:

- Burn tree
- Infection
- Spread
- Time required
- Minimum time

Think:

```
Parent Map + BFS
```

---

# Core Idea

Convert tree into an undirected graph.

Possible movement:

```
Left

Right

Parent
```

Then BFS gives time.

---

# Algorithm

## Step 1

Create parent mapping.

---

## Step 2

Find target node.

---

## Step 3

Perform BFS from target.

For every level:

Increase time.

---

# Example

```
          1
        /   \
       2     3
      /
     4
```

Target:

```
4
```

Time:

```
0: 4

1: 2

2: 1

3: 3
```

Answer:

```
3
```

---

# Complexity

Time:

```
O(n)
```

Space:

```
O(n)
```

---

# Common Mistakes

## Forgetting parent direction

Only checking children gives wrong answer.

---

## Increasing time incorrectly

Increase time after completing one BFS level.

---

# Related Problems

- Burning Tree
- Infection Spread
- Distance K


---

<br>

# 21. Nodes At Distance K Pattern

## Pattern Explanation

Find all nodes exactly K distance away from a target node.

Distance can be:

```
Downward

or

Upward
```

---

# How to Identify

Keywords:

- K distance
- Target node
- Nearby nodes

Think:

```
Graph BFS
```

---

# Why Normal DFS Fails

DFS can move:

```
Parent → Child
```

but distance requires:

```
Child → Parent
```

---

# Algorithm

1. Build parent map.
2. Start BFS from target.
3. Track visited nodes.
4. Stop after K levels.

---

# Complexity

Time:

```
O(n)
```

Space:

```
O(n)
```

---

# Common Mistakes

## No visited array

Creates cycles.

---

## Confusing depth and distance

Distance:

number of edges.

---

# Related Problems

- All Nodes Distance K
- Burning Tree
- Minimum Distance Between Nodes


---

<br>

# 22. Flatten Tree Pattern

## Pattern Explanation

Flatten a binary tree into a linked list.

Required structure:

```
Right pointer only
```

Example:

Before:

```
       1
      / \
     2   5
    /     \
   3       6
```

After:

```
1
 \
  2
   \
    3
     \
      5
       \
        6
```

---

# How to Identify

Keywords:

- Flatten
- Convert to linked list
- In-place modification

Think:

```
Modified Preorder
```

---

# Core Idea

Flatten order follows:

```
Preorder

Root

Left

Right
```

---

# Approach 1

Store preorder traversal.

Then rebuild.

Complexity:

Space:

```
O(n)
```

---

# Optimal Approach

Use recursion.

At every node:

1. Flatten left subtree.
2. Flatten right subtree.
3. Attach left list between node and right list.

---

# Better Trick

Use reverse preorder:

```
Right

Left

Root
```

Maintain previous node.

---

# Template

```cpp
TreeNode* prev = nullptr;


void flatten(TreeNode* root){

    if(!root)
        return;


    flatten(root->right);

    flatten(root->left);


    root->right = prev;

    root->left = nullptr;


    prev = root;
}
```

---

# Complexity

Time:

```
O(n)
```

Space:

```
O(h)
```

---

# Common Mistakes

## Losing right subtree

Save it before changing pointers.

---

## Using inorder

Flatten follows preorder.

---

# Related Problems

- Flatten Binary Tree to Linked List
- Tree Traversal Modification

---
# 23. Tree To DLL Pattern

## Pattern Explanation

Convert a Binary Tree into a Doubly Linked List.

The linked list should usually follow:

```
Inorder Traversal
```

because inorder gives sorted order for BST.

The DLL uses:

```
left pointer  → previous node

right pointer → next node
```

---

# How to Identify

Keywords:

- Convert tree to linked list
- Doubly linked list
- Preserve order
- In-place conversion

Think:

```
Inorder + Pointer Manipulation
```

---

# Core Intuition

Inorder traversal already gives the required order:

```
Left

Root

Right
```

During traversal:

Maintain previous node.

Connect:

```
previous.right = current

current.left = previous
```

---

# Algorithm

Perform inorder traversal.

For every visited node:

1. Connect with previous node.
2. Update previous.
3. Continue traversal.

---

# Template

```cpp
TreeNode* prev = nullptr;


void convert(TreeNode* root){

    if(!root)
        return;


    convert(root->left);


    root->left = prev;


    if(prev)
        prev->right = root;


    prev = root;


    convert(root->right);
}
```

---

# Complexity

Time:

```
O(n)
```

Space:

```
O(h)
```

---

# Common Mistakes

## Using preorder

DLL conversion generally requires inorder.

---

## Forgetting previous pointer

The previous node is needed for linking.

---

## Not breaking tree links

Left/right pointers must be modified carefully.

---

# Related Problems

- Binary Tree to DLL
- BST to Sorted DLL
- Flatten Tree


---

<br>

# 24. Boundary Problems Pattern

## Pattern Explanation

Boundary traversal means printing the outer boundary of the tree.

Order:

```
Left Boundary

↓

Leaves

↓

Right Boundary (Reverse)
```

---

Example:

```
          1
        /   \
       2     3
      / \
     4   5
```

Boundary:

```
1 2 4 5 3
```

---

# How to Identify

Keywords:

- Boundary
- Exterior
- Perimeter
- Outer nodes

Think:

```
Multiple Traversals Combination
```

---

# Components

Boundary consists of:

## 1. Root

Always included.

---

## 2. Left Boundary

Exclude leaf nodes.

Move:

```
Left

otherwise Right
```

---

## 3. Leaf Nodes

Traverse entire tree.

Use:

```
DFS
```

---

## 4. Right Boundary

Exclude leaf nodes.

Store separately.

Reverse before adding.

---

# Algorithm

Steps:

```
Add root

↓

Add left boundary

↓

Add leaves

↓

Add reversed right boundary
```

---

# Complexity

Time:

```
O(n)
```

Space:

```
O(h)
```

---

# Common Mistakes

## Adding leaves twice

Boundary traversal handles leaves separately.

Do not include them in left/right boundary.

---

## Wrong right boundary order

Right boundary must be reversed.

---

# Related Problems

- Boundary Traversal
- Anti-clockwise Traversal
- Exterior of Binary Tree


---

# FINAL TREE PATTERN RECOGNITION SUMMARY

| Problem Statement | Pattern To Think |
|---|---|
| Visit every node | Traversal |
| Root to leaf | DFS |
| All paths | DFS + Backtracking |
| Level wise | BFS |
| Shortest distance | BFS |
| Need child information | Tree DP |
| Longest path | Diameter / Tree DP |
| Maximum contribution | Tree DP |
| Path maximum sum | Tree DP |
| Check height difference | Balanced Tree |
| Mirror comparison | Symmetry |
| Same structure | Subtree |
| Contains another tree | Subtree Matching |
| Common parent | LCA |
| Ancestor | DFS/LCA |
| Left/right visible nodes | View Problems |
| Top/bottom view | BFS + Horizontal Distance |
| K distance | Parent Map + BFS |
| Burning/infection | Graph BFS |
| Flatten tree | Reverse Preorder |
| Convert to DLL | Inorder Linking |
| Boundary/perimeter | Multiple Traversals |
| Sorted output from BST | Inorder |
| Search efficiently | BST Property |
| Kth smallest BST | Inorder Counting |
| Range query BST | Pruning |

---

# Final Pattern Identification Rule

Before coding any tree problem ask:

## Question 1

Do I need to visit every node?

```
Traversal
```

---

## Question 2

Do children give information to parent?

```
Tree DP
```

---

## Question 3

Do I need shortest distance?

```
BFS
```

---

## Question 4

Do I need paths?

```
DFS + Backtracking
```

---

## Question 5

Can I use ordering?

```
BST
```

---

## Question 6

Do I need upward movement?

```
Parent Map + BFS
```

---

## Question 7

Do I need to compare structures?

```
Recursive Matching
```

---

# Interview Approach

For any tree problem:

```
1. Identify the required information.

2. Choose traversal.

3. Decide what recursion returns.

4. Handle base case.

5. Check edge cases.

6. Analyze complexity.
```

---

# End of Tree Interview Patterns