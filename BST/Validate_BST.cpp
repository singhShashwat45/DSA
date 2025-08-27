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

    bool solve(TreeNode* root, long long minVal, long long maxVal){
        if(root==NULL) return true;
        int val = root->val;
        if(val <= minVal || val >= maxVal) return false;
        bool left = solve(root->left, minVal, val);
        bool right = solve(root->right, val, maxVal);
        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};