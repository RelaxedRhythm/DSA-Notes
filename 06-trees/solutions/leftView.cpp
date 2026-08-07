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

// find the nodes visible from the left side...
// in levelorder the 1st element in the q of that level..
// dfs left subtree 1st if not present then the right subtree;

void dfs(TreeNode* root,int level,vector<int>&ans){
    if(root==NULL)return;
    if(level==ans.size())ans.push_back(root->val);
    if(root->left) dfs(root->left,level+1,ans);
    if(root->right)dfs(root->right,level+1,ans);
}

vector<int> leftView(TreeNode* root){
    vector<int> ans;
    dfs(root,0,ans);
    return ans;
}