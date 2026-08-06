#include<bits/stdc++.h>
using namespace std;

// Given a binary tree, determine if it is height-balanced.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int height(TreeNode* root){
    if(root==NULL)return 0;
    int leftHt=height(root->left);
    if(leftHt==-1)return -1;
    int rightHt=height(root->right);
    if(rightHt==-1)return -1;

    if(abs(leftHt-rightHt)>1)return -1;
    return max(leftHt,rightHt)+1;
}

bool balanced(TreeNode* root){
    return height(root)!=-1;
}