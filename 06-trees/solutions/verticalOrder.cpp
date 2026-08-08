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
// Example
// Tree
//             1
//           /   \
//          2     3
//         / \   / \
//        4   5 6   7
// Horizontal Distances
// -2 → 4  ,  -1 → 2   ,    0 → 1 5 6   ,  +1 → 3   ,  +2 → 7
// Output
// [ [4], [2],  [1,5,6],  [3],  [7] ]


// use level order traversal and map.. simliar to how we did in top and bottom order..
// but in map store the values of all the nodes having that horizontal distance and then iterate over the amp to get them..

vector<vector<int>>verticalOrder(TreeNode* root){
    if(root == nullptr) return {};
    queue<pair<TreeNode*,int>>q;  // node and hd
    map<int,vector<int>>map;  // hd and list of nodes of that hd
    q.push({root,0});
    while(!q.empty()){
        TreeNode* node=q.front().first;
        int dist=q.front().second;
        q.pop();

        map[dist].push_back(node->val);

        if(node->left)q.push({node->left,dist-1});
        if(node->right)q.push({node->right,dist+1});

    }
    vector<vector<int>>ans;
    for(auto &it:map){
        ans.push_back(it.second);
    }
    return ans;
}

// TREE GENERATOR
TreeNode* buildTree(vector<int> values) {

    if (values.empty() || values[0] == -1)
        return nullptr;

    TreeNode* root = new TreeNode(values[0]);

    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < values.size()) {

        TreeNode* node = q.front();
        q.pop();

        // Left child
        if (values[i] != -1) {
            node->left = new TreeNode(values[i]);
            q.push(node->left);
        }

        i++;

        if (i >= values.size())
            break;

        // Right child
        if (values[i] != -1) {
            node->right = new TreeNode(values[i]);
            q.push(node->right);
        }

        i++;
    }

    return root;
}

// PRINT RESULT
void printResult(vector<vector<int>> ans) {

    cout << "[ ";

    for (auto &column : ans) {

        cout << "[";

        for (int i = 0; i < column.size(); i++) {
            cout << column[i];

            if (i + 1 < column.size())
                cout << ", ";
        }

        cout << "] ";
    }

    cout << "]\n";
}

// MAIN
int main() {

    vector<int> values = {
        1,
        2, 3,
        4, 5, 6, 7
    };

    TreeNode* root = buildTree(values);

    vector<vector<int>> ans = verticalOrder(root);

    printResult(ans);

    return 0;
}