#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void printRec(Node* head){
    if(head==NULL) return;
    printRec(head->next);
    cout<<head->val<<" ";
}
int main(){
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);
    a.next = &b;
    b.next = &c;
    c.next = &d;

    // Print the LL with loop
    // print(&a);
    printRec(&a);

    
    // Node* ptr = &a;
    // cout<<a.val<<endl;
    // cout<<(*ptr).val<<endl;
    // cout<<ptr->val<<endl;
    // cout<<ptr->next->val<<endl;
    // cout<<ptr->next->next->val<<endl;

    
}