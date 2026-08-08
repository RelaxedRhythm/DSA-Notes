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



// For boundary traversal
//  we have to add the root in the first step, 
// then add the left boundary by going through the left subtree, and if the left tree is not there, then move to the right step. 
// Then we would add the leaves, 
// then in step four, we add the right boundary. And before adding it, we reverse so that it is from bottom to top instead of top to bottom. Okay? 
// We have isLeaf function to check if the node is a leaf because leaves are to be added only in step three, not before that.

bool isLeaf(TreeNode* node){
    return node->val && !node->left && !node->right;
}

void leftBoundary(TreeNode* root,vector<int>&ans){
    TreeNode* curr=root->left;
    while(curr){
        if(!isLeaf(curr))ans.push_back(curr->val);
        if(curr->left) curr=curr->left;
        else curr=curr->right;
    }
}

void addLeaves(TreeNode*node,vector<int>&ans){
    if(node==NULL)return ;
    if(isLeaf(node))ans.push_back(node->val);
    addLeaves(node->left,ans);
    addLeaves(node->right,ans);
}

void rightBoundary(TreeNode* root,vector<int>&ans){
    TreeNode*curr=root->right;
    vector<int>temp;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->val); 
        if(curr->right)curr=curr->right;
        else curr=curr->left;
    }
    reverse(temp.begin(),temp.end());

    ans.insert(ans.end(),temp.begin(),temp.end());
}

vector<int>boundary(TreeNode*root){
    vector<int>ans;
    if(root==nullptr)
            return ans;

        if(!isLeaf(root))
            ans.push_back(root->val);

        leftBoundary(root,ans);

        addLeaves(root,ans);

        rightBoundary(root,ans);

        return ans;

}