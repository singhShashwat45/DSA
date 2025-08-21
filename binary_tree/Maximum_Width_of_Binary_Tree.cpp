#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
    int widthOfBinaryTree(TreeNode* root) { //0 index-> 2*i+1 & 2*i +2
        if(root == NULL) return 0;
        long long ans = 0;
        queue<pair<TreeNode*, int>> q; //Node, index
        q.push({root, 0});
        long long first, last;
        while(!q.empty()){
            int sz = q.size();
            int mmin = q.front().second;
            for(int i=0; i<sz; i++){
                long long cur_ind = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = cur_ind;
                if(i == sz-1) last = cur_ind;
                if(node->left) q.push({node->left, cur_ind*2 + 1});
                if(node->right) q.push({node->right, cur_ind*2 + 2});
            }
            ans = max(ans, last - first +1);
        }

        return ans;

    }
};