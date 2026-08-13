class Solution {
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int lenA = 0;
        while(tempA!=NULL){
            tempA = tempA->next;
            lenA++;
        }
        int lenB = 0;
        while(tempB!=NULL){
            tempB = tempB->next;
            lenB++;
        }
        tempA = headA;
        tempB = headB;
        if(lenA>lenB){ // move tempA forward lenA-lenB times
            for(int i=1;i<=lenA-lenB;i++){
                tempA = tempA->next;
            }
        }
        else{ // move tempB forward lenB-lenA times
            for(int i=1;i<=lenB-lenA;i++){
                tempB = tempB->next;
            }
        }
        while(tempA!=tempB){
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
};
