#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    
    void solve(Node* root, int&k, int &ans){
        if(!root) return;
        solve(root->right, k, ans);
        k--;
        if(k==0){
            ans = root->data;
            return;
        }
        solve(root->left, k, ans);
    }
    
    int kthLargest(Node *root, int k) {
        int ans = -1;
        solve(root, k, ans);
        return ans;
    }
};