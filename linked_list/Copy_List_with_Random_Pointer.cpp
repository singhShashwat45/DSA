class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
    if (head == nullptr) return nullptr;

    // First pass: Create new nodes and insert them directly after their corresponding original nodes.
    Node* cur = head;
    while (cur) {
        Node* newNode = new Node(cur->val);
        newNode->next = cur->next;
        cur->next = newNode;
        cur = newNode->next;
    }

    // Second pass: Assign random pointers for the copied nodes.
    cur = head;
    while (cur) {
        if (cur->random) {
            cur->next->random = cur->random->next;
        }
        cur = cur->next->next;
    }

    // Third pass: Separate the original list and the copied list.
    cur = head;
    Node* newHead = head->next;
    Node* copy = newHead;
    
    while (cur) {
        cur->next = cur->next->next;
        if (copy->next) {
            copy->next = copy->next->next;
        }
        cur = cur->next;
        copy = copy->next;
    }

    return newHead;
}

};