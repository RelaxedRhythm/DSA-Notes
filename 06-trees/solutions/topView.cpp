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


// return the nodes which are visible while looking from top..
// we find the horizontal height of each node and then store only the 1st available node of that height 
//use map to store the height;

vector<int>topView(TreeNode* root){
    vector<int>ans;
    if(root==NULL)return ans;
    queue<pair<TreeNode*,int>>q;
    map<int,int> map;

    q.push({root,0});
    while(!q.empty()){
        TreeNode* node=q.front().first;
        int dist = q.front().second;

        q.pop();

        if(map.find(dist)==map.end()) map[dist]=node->val;
        if(node->left)q.push({node->left,dist-1});
        if(node->right)q.push({node->right,dist+1});
    }
    for(auto &it:map){
        ans.push_back(it.second);
    }
    return ans;
}