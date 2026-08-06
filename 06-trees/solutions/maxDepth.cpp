#include<bits/stdc++.h>
using namespace std;

// Given the root of a binary tree, return its maximum depth.
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs(TreeNode*root,int dist,int &ans){
    if(root==NULL)return;
    ans=max(dist,ans);
    dfs(root->left,dist+1,ans);
    dfs(root->right,dist+1,ans);
}

int maxDepth(TreeNode* root){
    int ans=0;
    dfs(root,1,ans);
    return ans; 
}