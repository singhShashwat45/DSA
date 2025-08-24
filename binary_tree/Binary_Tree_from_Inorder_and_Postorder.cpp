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

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int &postIndex, int inStart, int inEnd, unordered_map<int, int> &idx){
        if(inStart > inEnd) return NULL;

        int rootVal = postorder[postIndex--];
        TreeNode* node = new TreeNode(rootVal);

        int mid = idx[rootVal];

        node->right = build(inorder, postorder, postIndex, mid+1, inEnd, idx);
        node->left = build(inorder, postorder, postIndex, inStart, mid-1, idx);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> idx;
        for(int i=0; i<inorder.size(); i++){
            idx[inorder[i]] = i;
        }
        int postIndex = inorder.size()-1;
        return build(inorder, postorder, postIndex, 0, inorder.size() -1, idx);
    }
};