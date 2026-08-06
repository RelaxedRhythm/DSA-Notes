#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
// A leaf is a node with no children.

void dfs(TreeNode* root, bool &hasPath,int targetSum){
    if(root==NULL)return ;
    if(!root->left && !root->right) {
        if(targetSum==root->val)hasPath=true;
        return;
    }
    targetSum-=root->val;

    if(root->left)dfs(root->left,hasPath,targetSum);
    if(root->right)dfs(root->right,hasPath,targetSum);
}

bool hasPathSum(TreeNode* root, int targetSum){
    bool hasPath=false;
    dfs(root,hasPath,targetSum);
    return hasPath;
}