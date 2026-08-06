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

// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.

int height(TreeNode* root,int &ans){
    if(root==NULL)return 0;
    int leftHt=height(root->left,ans);
    int rightHt=height(root->right,ans);
    ans=max(ans,leftHt+rightHt+1);

    return max(leftHt,rightHt)+1;
}

int diam(TreeNode* root){
    int ans=0;
    height(root,ans);
    return ans;
}