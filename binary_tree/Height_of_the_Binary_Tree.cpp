#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
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

    int height(TreeNode* root){
        if(root==NULL) return 0;
        int ans = 0;
        ans = 1+ max(height( root->left), height(root->right));
        return ans;
    }

    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int ans = height(root);
        return ans;
    }
};