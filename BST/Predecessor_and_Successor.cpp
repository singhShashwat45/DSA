#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;

class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;
        
        Node* curr = root;
        while(curr) {
            if(curr->data < key) {
                pre = curr;          // potential predecessor
                curr = curr->right;  // go right to find closer value
            }
            else if(curr->data > key) {
                suc = curr;          // potential successor
                curr = curr->left;   // go left to find closer value
            }
            else {
                // If key is found, check left subtree for predecessor
                if(curr->left) {
                    Node* temp = curr->left;
                    while(temp->right) temp = temp->right;
                    pre = temp;
                }
                // Check right subtree for successor
                if(curr->right) {
                    Node* temp = curr->right;
                    while(temp->left) temp = temp->left;
                    suc = temp;
                }
                break;
            }
        }
        
        return {pre, suc};
    }
};


// class Solution {
//   public:
//     vector<Node*> v;
//     void inorder(Node* root){
//         if(root==NULL) return;
//         inorder(root->left);
//         v.push_back(root);
//         inorder(root->right);
//     }
    
//     vector<Node*> findPreSuc(Node* root, int key) {
//         vector<Node*> ans(2, NULL);
//         if(root == NULL) return ans;
//         inorder(root);
//         for(int i=0; i<v.size(); i++){
//             if(v[i]->data < key) ans[0] = v[i];
//             if(v[i]->data > key && ans[1]==NULL){
//                 ans[1] = v[i];
//                 break;
//             }
//         }
//         return ans;
//     }
// };