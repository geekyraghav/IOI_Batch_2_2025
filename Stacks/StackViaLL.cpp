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
class MyStack{
private:
    Node* head;
    int length;
public:
    MyStack(){
        head = NULL;
        length = 0;
    }
    void push(int val){
        Node* n = new Node(val);
        n->next = head;
        head = n;
        length++;
    }
    void pop(){
        if(length == 0){
            cout<<"Stack is Empty!"<<endl;
            return;
        }
        head = head->next;
        length--;
    }
    int top(){
        if(length == 0){
            cout<<"Stack is Empty!"<<endl;
            return -1;
        }
        return head->val;
    }
    int size(){
        return length;
    }
    void print(){
        display(head);
        cout<<endl;
    }
    void display(Node* head){
        if(head == NULL) return;
        display(head->next);
        cout<<head->val<<" ";
    }
};
int main(){
    MyStack s;
    s.push(10); s.push(20); 
    s.push(30); s.push(40); 
    s.print();
    s.pop();
    s.print();
}
