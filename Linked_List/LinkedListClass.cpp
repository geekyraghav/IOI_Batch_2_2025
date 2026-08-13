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
class MyLinkedList{
private:
    Node* head;
    Node* tail;
    int size;
public:
    MyLinkedList(){
        head = tail = NULL;
        size = 0;
    }
    void addAtTail(int val){
        Node* n = new Node(val);
        if(size == 0) head = tail = n;
        else{
            tail->next = n;
            tail = n;
        }
        size++;
    }
    void addAtHead(int val){
        Node* n = new Node(val);
        if(size == 0) head = tail = n;
        else{
            n->next = head;
            head = n;
        }
        size++;
    }
    void print(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    void removeAtHead(){
        if(size==0){
            cout<<"List is Empty!"<<endl;
            return;
        }
        head = head->next;
        size--;
    }
    void remove(int idx){
        if(idx<0 || idx>=size){
            cout<<"Invalid Index"<<endl;
            return;
        }
        if(idx==0){
            removeAtHead();
            return;
        }
        Node* temp = head;
        for(int i=1;i<=idx-1;i++){
            temp = temp->next;
        }
        temp->next = temp->next->next; // magical line
        if(idx==size-1) tail = temp;
        
        size--;
    }
    int getSize(){
        return size;
    }
};
int main(){
    // 10->20->30->40
    MyLinkedList list;
    list.addAtTail(10);
    list.print();
    list.addAtTail(20);
    list.print();
    list.addAtTail(30);
    list.print();
    list.addAtTail(40);
    list.print();
    cout<<list.getSize()<<endl;
    // list.size = 0;
    // list.addAtTail(50);
    // list.print();
    list.addAtHead(50);
    list.print();
    list.addAtHead(60);
    list.print();
    list.removeAtHead();
    list.print();
}