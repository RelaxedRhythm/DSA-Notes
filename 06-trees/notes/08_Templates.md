# 🌳 Tree Recursion Templates

> Reusable templates for solving Tree interview problems.

The most important skill in tree recursion:

```
Understand what the function returns.
```

Before coding, always decide:

1. What is my base case?
2. What does left child return?
3. What does right child return?
4. What should current node return?

---

# 1. Basic DFS Template

## Use When

- Visiting all nodes
- Searching
- Counting
- Simple traversal

---

```cpp
void dfs(TreeNode* root){

    if(root == nullptr)
        return;


    // Process current node


    dfs(root->left);


    dfs(root->right);
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

<br>

# 2. Preorder Template

## Order

```
Root

Left

Right
```

---

## Use Cases

- Copy tree
- Serialization
- Flatten tree
- Create tree representation

---

```cpp
void preorder(TreeNode* root){

    if(root == nullptr)
        return;


    cout << root->val;


    preorder(root->left);


    preorder(root->right);
}
```

---

# Iterative Preorder

Use stack.

```cpp
vector<int> preorder(TreeNode* root){

    vector<int> ans;


    if(root == nullptr)
        return ans;


    stack<TreeNode*> st;

    st.push(root);


    while(!st.empty()){

        TreeNode* node = st.top();

        st.pop();


        ans.push_back(node->val);


        if(node->right)
            st.push(node->right);


        if(node->left)
            st.push(node->left);
    }


    return ans;
}
```

---

<br>

# 3. Inorder Template

## Order

```
Left

Root

Right
```

---

## Use Cases

Most important for BST.

Examples:

- Sorted order
- Kth smallest
- BST validation

---

```cpp
void inorder(TreeNode* root){

    if(root == nullptr)
        return;


    inorder(root->left);


    cout << root->val;


    inorder(root->right);
}
```

---

# Iterative Inorder

```cpp
vector<int> inorder(TreeNode* root){

    vector<int> ans;

    stack<TreeNode*> st;


    TreeNode* curr = root;


    while(curr || !st.empty()){


        while(curr){

            st.push(curr);

            curr = curr->left;
        }


        curr = st.top();

        st.pop();


        ans.push_back(curr->val);


        curr = curr->right;
    }


    return ans;
}
```

---

<br>

# 4. Postorder Template

## Order

```
Left

Right

Root
```

---

## Use Cases

- Height
- Diameter
- Delete tree
- Tree DP

---

```cpp
void postorder(TreeNode* root){

    if(root == nullptr)
        return;


    postorder(root->left);


    postorder(root->right);


    cout << root->val;
}
```

---

# Iterative Postorder

Using two stacks:

```cpp
vector<int> postorder(TreeNode* root){

    vector<int> ans;


    if(!root)
        return ans;


    stack<TreeNode*> s1,s2;


    s1.push(root);


    while(!s1.empty()){

        TreeNode* node=s1.top();

        s1.pop();


        s2.push(node);


        if(node->left)
            s1.push(node->left);


        if(node->right)
            s1.push(node->right);
    }


    while(!s2.empty()){

        ans.push_back(s2.top()->val);

        s2.pop();
    }


    return ans;
}
```

---

<br>

# 5. Height Template

## Question

Find maximum depth of tree.

---

## Pattern

Postorder DFS.

---

```cpp
int height(TreeNode* root){

    if(root == nullptr)
        return 0;


    int left = height(root->left);


    int right = height(root->right);


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

<br>

# 6. Diameter Template

## Pattern

Tree DP.

Formula:

```
left height + right height
```

---

```cpp
int diameter = 0;


int height(TreeNode* root){

    if(root == nullptr)
        return 0;


    int left = height(root->left);


    int right = height(root->right);


    diameter = max(
        diameter,
        left + right
    );


    return 1 + max(left,right);
}
```

---

# Complexity

```
O(n)
```

---

# Important

Diameter can mean:

Edges:

```
left + right
```

Nodes:

```
left + right + 1
```

Check question.

---

<br>

# 7. Path Sum Template

## Root To Leaf Path

---

```cpp
bool hasPathSum(TreeNode* root,
                int target){

    if(root == nullptr)
        return false;


    if(!root->left &&
       !root->right){

        return target == root->val;
    }


    return hasPathSum(
                root->left,
                target-root->val)

        ||

        hasPathSum(
                root->right,
                target-root->val);
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

<br>

# 8. Maximum Path Sum Template

## Pattern

Tree DP + Global Answer.

---

```cpp
int ans = INT_MIN;


int solve(TreeNode* root){

    if(!root)
        return 0;


    int left =
    max(0,solve(root->left));


    int right =
    max(0,solve(root->right));


    ans=max(
        ans,
        left+right+root->val
    );


    return root->val +
           max(left,right);
}
```

---

# Complexity

```
O(n)
```

---

<br>

# 9. Lowest Common Ancestor Template

## Binary Tree LCA

---

```cpp
TreeNode* lca(TreeNode* root,
              TreeNode* p,
              TreeNode* q){

    if(root==nullptr ||
       root==p ||
       root==q)
        return root;


    TreeNode* left =
    lca(root->left,p,q);


    TreeNode* right =
    lca(root->right,p,q);


    if(left && right)
        return root;


    return left ? left : right;
}
```

---

# Complexity

```
O(n)
```

---

<br>

# 10. Subtree Template

## Check Same Tree

---

```cpp
bool same(TreeNode* a,
          TreeNode* b){

    if(!a || !b)
        return a==b;


    return a->val==b->val

        && same(a->left,b->left)

        && same(a->right,b->right);
}
```

---

## Subtree Check

```cpp
bool isSubtree(TreeNode* root,
               TreeNode* subRoot){

    if(!root)
        return false;


    if(same(root,subRoot))
        return true;


    return isSubtree(root->left,subRoot)

        ||

        isSubtree(root->right,subRoot);
}
```

---

# Complexity

Worst case:

```
O(n*m)
```

---

<br>

# 11. BST Recursion Template

## Search

```cpp
TreeNode* search(TreeNode* root,
                 int key){

    if(!root || root->val==key)
        return root;


    if(key < root->val)
        return search(root->left,key);


    return search(root->right,key);
}
```

---

## Insert

```cpp
TreeNode* insert(TreeNode* root,
                 int val){

    if(!root)
        return new TreeNode(val);


    if(val < root->val)

        root->left =
        insert(root->left,val);


    else

        root->right =
        insert(root->right,val);


    return root;
}
```

---

# 12. Recursion Cheat Rule

| Problem | Return |
|---|---|
| Height | Height |
| Diameter | Height + Global |
| Balance | Height / -1 |
| Path Sum | Boolean |
| Maximum Path | Contribution |
| LCA | Node |
| Subtree | Boolean |
| BST Search | Node |
| Tree DP | Required information |

---

# Final Recursion Checklist

Before writing recursive code:

```
1. Base case

2. Recursive calls

3. Combine answers

4. Return value
```

Most tree interview problems are solved by mastering these four steps.