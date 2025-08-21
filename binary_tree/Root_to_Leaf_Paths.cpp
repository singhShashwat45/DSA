#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<map>
#include <set>
using namespace std;



struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
  
    
    void dfs(Node* root, vector<int> &path, vector<vector<int>> &ans){
        if(root == NULL) return;
        path.push_back(root->data);
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(path);
        } else {
            dfs(root->left, path, ans);
            dfs(root->right, path, ans);
        }
        path.pop_back();
    }
    
    vector<vector<int>> Paths(Node* root) {
        vector<int> path;
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        dfs(root, path, ans);
        return ans;
        
    }
};