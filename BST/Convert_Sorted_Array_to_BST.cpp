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

    TreeNode* build(vector<int>& nums, int l, int r){
        if(l<=r){
            int mid = l + (r-l)/2;
            TreeNode* node = new TreeNode(nums[mid]);
            node->left = build(nums, l, mid-1);
            node->right = build(nums, mid+1, r);
            return node;
        }
        return NULL;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n= nums.size();
        return build(nums, 0, n-1);
    }
};