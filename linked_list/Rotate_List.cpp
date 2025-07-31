struct ListNode {
    int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    int getlen(ListNode* head){
        ListNode* cur = head;
        int l=0;
        while(cur){
            l++;
            cur = cur->next;
        }
        return l;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr|| head->next == nullptr || k == 0) return head;
        int len = getlen(head);
        k = k % len;
        if(k == 0) return head;

        int shift = len - k - 1;
        ListNode* temp = head;
        while(shift--){
            temp = temp->next;
        }
        ListNode* nextNode = temp->next;
        temp->next = nullptr;
        ListNode* cur = nextNode;
        while(nextNode->next != nullptr){
            nextNode = nextNode->next;
        }
        nextNode->next = head;
        return cur;
    }
};