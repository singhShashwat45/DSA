//Problem link - https://leetcode.com/problems/remove-nth-node-from-end-of-list/
struct ListNode {
    int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while(cur){
            ListNode* nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverse(head);
        ListNode* cur = head;
        ListNode* prev = nullptr;
        n=n-1;
        while(n--){
            prev = cur;
            cur = cur->next;
        }
        if(prev == nullptr) {
            head = cur->next;
        } else {
            prev->next = cur->next;
        }
        head = reverse(head);
        return head;

    }
};