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
    
    int solve(Node *root, bool &flag) {
        
        if(root == NULL) return 0;
        if (!root->left && !root->right) return root->data;

        int left = solve(root->left, flag);
        int right = solve(root->right, flag);
        
        if (root->data != left + right) flag = false;
        return root->data;
    }
    
    int isSumProperty(Node *root) {
        if (!root) return 1;
        bool flag = true;
        solve(root, flag);
        return flag;
    }
};