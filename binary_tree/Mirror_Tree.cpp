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
    void mirror(Node* node) {
       if (!node) return;

        swap(node->left, node->right);
        
        mirror(node->left);
        mirror(node->right); 
    }
};