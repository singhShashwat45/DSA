//Problem link - https://leetcode.com/problems/linked-list-cycle/description/
struct ListNode {
    int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* cur=head;
        if(head==nullptr)
        {
            return false;
        }
        while(cur!=nullptr && cur->next != nullptr)
        {
            head=head->next;
            cur=cur->next->next;
            if(cur == head)
            {
                return true;
            }
        }
        return false;
    }
};