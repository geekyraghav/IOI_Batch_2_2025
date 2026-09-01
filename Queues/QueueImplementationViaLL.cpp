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
class MyQueue{
public:
    Node* head;
    Node* tail;
    int length;
    MyQueue(){
        head = tail = NULL;
        length = 0;
    }
    void push(int val){
        Node* n = new Node(val);
        if(length == 0) head = tail = n;
        else{
            tail->next = n;
            tail = n;
        }
        length++;
    }
    void pop(){
        head = head->next;
        length--;
    }
    int front(){
        return head->val;
    }
    int size(){
        return length;
    }
};
int main(){
    MyQueue q;
    q.push(10); q.push(20); q.push(30);
}