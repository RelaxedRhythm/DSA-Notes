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

//we need too print or store the nodes visible from the right ...
// use level ordeer traversal and select the last element in each window..
// use dfs and traverse the right subtree first..if no right present then go the left subtree...


vector<int> rightView(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    vector<int>ans;
    while(!q.empty()){
        int size=q.size();
        
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            if(i==size-1) ans.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return ans;
}

