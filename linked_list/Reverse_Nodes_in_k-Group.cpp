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

    ListNode* reverseList(ListNode* head) {
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

    ListNode* getKthNode(ListNode* head, int k){
        k-=1;
        while(head!= nullptr && k>0){
            head = head-> next;
            k--;
        }
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;
        while(temp){
            ListNode* kthNode = getKthNode(temp, k);
            if(kthNode == nullptr){
                if(prevLast) prevLast -> next =  temp;
                break;
            }

            ListNode* nextNode = kthNode -> next;
            kthNode->next = nullptr;
            
            ListNode* newHead = reverseList(temp); // capture reversed head
            if (temp == head) {
                head = newHead; // update global head
            } else {
                prevLast->next = newHead; // connect last group to current reversed
            }
            temp->next = nextNode; // connect end of reversed group to rest
            prevLast = temp;   
            temp = nextNode;

        }
        return head;
    }
};