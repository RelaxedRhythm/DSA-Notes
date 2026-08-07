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

// the consecutive levels are reversed...
// use level order traversal and reverse the consecutive levels with the help of flag index reversal...

vector<vector<int>>zigzag(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    bool isReversed=false;
    vector<vector<int>>ans;
    while(!q.empty()){
        int size=q.size();
        vector<int>level(size);
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            if(isReversed) level[size-i-1]=node->val;
            level[i]=node->val;
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        isReversed=!isReversed;
        ans.push_back(level);
    }
    return ans;
}