
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
    void solve(TreeNode *root, vector<int>& v, int level){
        if(root == NULL){
            return;
        }
        if(v.size() == level){
            v.push_back(root->val);
        }
        solve(root->left, v, level+1); // PUT THIS LINE BELOW solve(root->right, v, level+1); FOR RIGHT VIEW
        solve(root->right, v, level+1);
    }
    vector<int> leftView(TreeNode *root) {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};