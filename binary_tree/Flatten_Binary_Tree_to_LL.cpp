#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> v;
    void solve(TreeNode* root){
        if(root == NULL) return;
        v.push_back(root->val);
        solve(root->left);
        solve(root->right);
    }

    void flatten(TreeNode* root) {
        if(root==NULL) return;
        solve(root);
        TreeNode* r = root;
        r->val = v[0];
        r->left = NULL;
        for(int i=1; i<v.size(); i++){
            r->right = new TreeNode(v[i]);
            r = r->right;
        }
    }
};