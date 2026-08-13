class Solution {
  public:
    int getKthFromLast(Node* head, int n) {
        Node* slow = head;
        Node* fast = head;
        // Move slow 'n' steps ahead
        for(int i=1;i<=n;i++){
            if(slow==NULL) return -1;
            slow = slow->next;
        }
        // Move slow and fast together until slow is null
        while(slow!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        return fast->data;
    }
};
