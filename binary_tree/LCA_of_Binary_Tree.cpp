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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*>qu;
        qu.push(root);
        while(!qu.empty()){
            TreeNode* node = qu.front();
            qu.pop();
            if(node->left){
                parent[node->left] = node;
                qu.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                qu.push(node->right);
            }
        }
        unordered_set<TreeNode*> ancestors;
        while (p) {
            ancestors.insert(p);
            p = parent[p];
        }
        while (q) {
            if (ancestors.count(q)) return q;
            q = parent[q];
        }
        return NULL;

    }
};