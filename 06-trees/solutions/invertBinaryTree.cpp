#include<bits/stdc++.h>
using namespace std;

// Given the root of a binary tree, invert the tree, and return its root.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
TreeNode* invertTree(TreeNode*root){
    if(root==NULL)return NULL;
        TreeNode* left=invertTree(root->left);
        TreeNode* right=invertTree(root->right);
        root->right=left;
        root->left=right;

        return root;
}