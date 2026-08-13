class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next->next!=NULL && fast->next->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next; // deletiom
        return head;
    }
};
