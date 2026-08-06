# 🌳 How To Identify Tree Problem Patterns

> The goal of this file is to identify the correct approach before coding.

Most tree problems become easy after answering:

```
"What kind of information does the problem need?"
```

---

# 1. Basic Recognition Flow

Before solving any tree problem:

## Step 1

Does the problem require visiting all nodes?

```
YES

↓

Traversal
```

---

## Step 2

Does a node need information from its children?

```
YES

↓

Postorder DFS / Tree DP
```

---

## Step 3

Does the problem ask for shortest distance?

```
YES

↓

BFS
```

---

## Step 4

Does the problem involve paths?

```
YES

↓

DFS + Backtracking
```

---

## Step 5

Does it involve parent movement?

```
YES

↓

Parent Map + BFS
```

---

## Step 6

Is it a BST?

```
YES

↓

Use Ordering Property
```

---

# 2. Pattern Recognition Table

| Question Says | Think | Algorithm | Data Structure | Complexity |
|---|---|---|---|---|
| Visit every node | Traversal | DFS/BFS | Stack/Queue | O(n) |
| Print tree | Traversal | DFS | Recursion | O(n) |
| Level wise output | BFS | Level Order | Queue | O(n) |
| Height of tree | Tree DP | Postorder DFS | Recursion | O(n) |
| Maximum depth | DFS | Height calculation | Recursion | O(n) |
| Minimum depth | BFS | Level search | Queue | O(n) |
| Root to leaf | DFS | Backtracking | Array | O(n) |
| All paths | DFS | Backtracking | Vector | O(n) |
| Path sum | DFS | Recursive sum | Recursion | O(n) |
| Maximum path | Tree DP | DFS | Global variable | O(n) |
| Longest path | Diameter | DFS | Recursion | O(n) |
| Balanced tree | Tree DP | Height check | Recursion | O(n) |
| Mirror tree | Symmetry | Recursive comparison | Recursion | O(n) |
| Same tree | Tree matching | DFS | Recursion | O(n) |
| Subtree check | Subtree | DFS matching | Recursion | O(n*m) |
| Common ancestor | LCA | DFS | Recursion | O(n) |
| BST ancestor | BST LCA | Binary search | Recursion | O(h) |
| Sorted BST output | Inorder | DFS | Stack | O(n) |
| Kth smallest BST | Inorder counting | DFS | Counter | O(n) |
| Validate BST | Range checking | DFS | Min/Max range | O(n) |
| Search BST | BST property | Binary search | Recursion | O(h) |
| Range in BST | Pruning | DFS | Recursion | O(h+k) |
| Nearest node | BFS | Level search | Queue | O(n) |
| Nodes distance K | Graph BFS | Parent map | HashMap + Queue | O(n) |
| Burning tree | Graph BFS | Parent map | Queue | O(n) |
| Infection spread | BFS | Graph traversal | Queue | O(n) |
| Left view | BFS/DFS | Level traversal | Queue | O(n) |
| Right view | BFS/DFS | Level traversal | Queue | O(n) |
| Top view | Vertical traversal | BFS | HashMap | O(n) |
| Bottom view | Vertical traversal | BFS | HashMap | O(n) |
| Vertical order | Column traversal | BFS | Map + Queue | O(n) |
| Zigzag traversal | Level variation | BFS | Queue | O(n) |
| Serialize tree | Traversal encoding | DFS | String | O(n) |
| Deserialize tree | Reconstruction | DFS | Queue | O(n) |
| Construct tree | Traversal relation | Recursion | HashMap | O(n) |
| Flatten tree | Modification | Reverse preorder | Recursion | O(n) |
| Convert tree to DLL | Ordering | Inorder | Pointer | O(n) |
| Boundary traversal | Outer nodes | DFS combination | Recursion | O(n) |

---

# 3. Keyword Based Identification

## "Root to Leaf"

Think:

```
DFS
```

Examples:

- Path Sum
- Binary Tree Paths

---

## "Any Node To Any Node"

Think:

```
Tree DP
```

Examples:

- Diameter
- Maximum Path Sum

---

## "Shortest"

Think:

```
BFS
```

Examples:

- Minimum depth
- Distance problems

---

## "K Distance"

Think:

```
Parent Map + BFS
```

Examples:

- Nodes at Distance K
- Burning Tree

---

## "Sorted"

Think:

```
BST Inorder
```

Examples:

- Kth smallest
- Validate ordering

---

## "Level"

Think:

```
Queue
```

Examples:

- Level order
- Views
- Zigzag

---

## "Ancestor"

Think:

```
LCA
```

Examples:

- Lowest Common Ancestor
- Distance between nodes

---

## "Maximum / Minimum"

Ask:

"Maximum what?"

If:

```
Subtree value

↓

Tree DP
```

If:

```
Distance

↓

Diameter
```

If:

```
Path sum

↓

Maximum Path Sum
```

---

# 4. DFS vs BFS Decision Table

| Requirement | Use |
|---|---|
| Explore all possibilities | DFS |
| Path problems | DFS |
| Height | DFS |
| Subtree | DFS |
| Ancestors | DFS |
| Minimum steps | BFS |
| Level information | BFS |
| Nearest node | BFS |
| Distance K | BFS |
| Burning tree | BFS |

---

# 5. Traversal Selection Table

| Need | Traversal |
|---|---|
| Copy tree | Preorder |
| Serialize | Preorder |
| BST sorted output | Inorder |
| Kth smallest | Inorder |
| Delete tree | Postorder |
| Height | Postorder |
| Diameter | Postorder |
| Level views | BFS |

---

# 6. Data Structure Selection

| Problem Type | Data Structure |
|---|---|
| DFS | Stack / Recursion |
| BFS | Queue |
| Parent tracking | HashMap |
| Vertical traversal | HashMap + Queue |
| Serialization | String |
| BST iterator | Stack |
| Prefix sum | HashMap |
| Construction | HashMap |

---

# 7. Interview Quick Decision Tree

```
Tree Problem

        |
        |

Need all nodes?

        |
   ------------
   |          |

 Yes          No


Traversal     BST?


               |
        -------------
        |           |

       Yes          No


   BST Logic     Need distance?


                    |
              -------------
              |           |

             Yes          No


       Parent Map       DFS


                         |
                   Need child info?


                         |
                  ---------------
                  |             |

                 Yes            No


             Tree DP       Simple DFS
```

---

# Final Rule

Before writing code:

Ask:

1. What is the output?
2. What information does a node need?
3. Which direction do I need to move?
4. Is ordering available?
5. What should recursion return?

These five questions identify almost every tree pattern.