#include<bits/stdc++.h>
using namespace std;

// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSymmetric(TreeNode* root){
    if(root==NULL) return false;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode* leftnode= q.front();
            q.pop();
            TreeNode* rightnode= q.front();
            q.pop();
            if(leftnode==NULL && rightnode==NULL) continue;
            if(leftnode==NULL && rightnode!=NULL)return false;
            if(leftnode!=NULL && rightnode==NULL)return false;
            if(leftnode->val!=rightnode->val)return false;

            q.push(leftnode->left);
            q.push(rightnode->right);
            q.push(leftnode->right);
            q.push(rightnode->left);
        }
    return true;
}
