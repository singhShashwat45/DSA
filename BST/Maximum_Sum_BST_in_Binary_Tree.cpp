#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
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
    int maxSum = 0;
    bool dfs(TreeNode* root, int &minVal, int &maxVal, int &sum){
        if(!root){
            minVal = INT_MAX;
            maxVal = INT_MIN;
            sum = 0;
            return true;
        }
        int lmin, lmax, lsum;
        int rmin, rmax, rsum;

        bool left = dfs(root->left, lmin, lmax, lsum);
        bool right = dfs(root->right, rmin, rmax, rsum);

        if(left && right && root->val > lmax && root->val <rmin){
            sum = root->val + lsum + rsum;
            minVal = min(root->val, lmin);
            maxVal = max(root->val, rmax);
            maxSum = max(maxSum, sum);
            return true;
        }

        // not a BST
        sum = 0;
        return false;

    }

    int maxSumBST(TreeNode* root) {
        int minVal, maxVal, sum;
        dfs(root, minVal, maxVal, sum);
        return maxSum;
    }
};