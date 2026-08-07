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

void dfs(TreeNode*root,int level,int &ans){
    if(root==NULL)return;
    ans=min(ans,level);
    if(root->left)dfs(root->left,level+1,ans);
    if(root->right)dfs(root->right,level+1,ans);
}

int minDepth(TreeNode*root){
    int ans=0;
    dfs(root,0,ans);
    return ans;
}