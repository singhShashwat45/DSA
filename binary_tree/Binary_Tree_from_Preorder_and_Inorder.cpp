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

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &preIndex, int inStart, int inEnd, unordered_map<int,int> &idx){
        if(inStart > inEnd) return NULL;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = idx[rootVal];

        root->left = build(preorder, inorder, preIndex, inStart, mid-1, idx);
        root->right = build(preorder, inorder, preIndex, mid+1, inEnd, idx);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> idx;
        for(int i=0; i<inorder.size(); i++){
            idx[inorder[i]] = i;
        }
        int preIndex = 0;
        return build(preorder, inorder, preIndex, 0, inorder.size()-1, idx);
    }
};