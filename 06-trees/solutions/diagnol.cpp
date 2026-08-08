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


vector<int>diagnoltraversal(TreeNode*root){
    vector<int>ans;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode*node=q.front();
        q.pop();
        while(node){
            ans.push_back(node->val);
            if(node->left)q.push(node->left);
            node=node->right;
        }
    }
    return ans;
}