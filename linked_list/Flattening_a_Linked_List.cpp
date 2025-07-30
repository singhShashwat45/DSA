struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = nullptr;
        bottom = nullptr;
    }

};


class Solution {
  public:
  
    Node* merge(Node* a, Node* b) {
        Node* dummy = new Node(0);
        Node* cur = dummy;

        while (a && b) {
            if (a->data < b->data) {
                cur->bottom = a;
                a = a->bottom;
            } else {
                cur->bottom = b;
                b = b->bottom;
            }
            cur = cur->bottom;
        }

        if (a) cur->bottom = a;
        else if (b) cur->bottom = b;

        return dummy->bottom;
    }

    Node *flatten(Node *root) {
        if (!root || !root->next)
            return root;
            
        root->next = flatten(root->next);
        root = merge(root, root->next);
        return root;
    }
};