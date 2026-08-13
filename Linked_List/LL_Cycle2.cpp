class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) break;
        }
        if(slow!=fast) return NULL;
        ListNode* temp = head;
        while(slow!=temp){
            slow = slow->next;
            temp = temp->next;
        }
        return slow;
    }
};
