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

    TreeNode* build(int &i, vector<int>& preorder, int maxVal, int minVal){
        if(i==preorder.size()) return NULL;
        int val = preorder[i];
        if(val<minVal || val>maxVal) return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left = build(i, preorder, val-1, minVal);
        root->right = build(i, preorder, maxVal, val+1);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(i, preorder, INT_MAX, INT_MIN);
    }
};