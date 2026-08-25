#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> s;
    s.push(10); s.push(20); s.push(30);
    s.push(40); s.push(50); s.push(60);
    // Print
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
}