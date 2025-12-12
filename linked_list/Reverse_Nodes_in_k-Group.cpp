//Problem link - https://leetcode.com/problems/reverse-nodes-in-k-group
struct ListNode {
    int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 class Solution {
public:

    ListNode* reverseLinkedList(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
    
        while (k--) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;  // new head after reversing k nodes
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: check if list has at least k nodes
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp) return head;   // fewer than k nodes → no change
            temp = temp->next;
        }
    
        // Step 2: reverse first k nodes
        ListNode* newHead = reverseLinkedList(head, k);
    
        // Step 3: recursively process the remaining part
        head->next = reverseKGroup(temp, k);
    
        return newHead;
    }


};
