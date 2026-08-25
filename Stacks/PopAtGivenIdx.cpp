#include<iostream>
#include<stack>
using namespace std;
void print(stack<int> &s){
    stack<int> s2;
    while(s.size()>0){
        s2.push(s.top());
        s.pop();
    }
    while(s2.size()>0){
        cout<<s2.top()<<" ";
        s.push(s2.top());
        s2.pop();
    }
    cout<<endl;
}
void pop(stack<int> &s, int idx){
    if(idx<0 || idx>=s.size()){
        cout<<"Invalid Index"<<endl;
        return;
    }
    stack<int> s2;
    while(s.size() > idx+1){
        s2.push(s.top());
        s.pop();
    }
    s.pop(); // idx wala element gaya
    while(s2.size() > 0){
        s.push(s2.top());
        s2.pop();
    }
}
int main(){
    stack<int> s;
    s.push(10); s.push(20); s.push(30);
    s.push(40); s.push(50); s.push(60);
    print(s);
    pop(s,2);
    print(s);
}