#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> s;
    s.push(10); s.push(20); s.push(30);
    cout<<s.size()<<endl;
    s.pop();
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    s.push(50);
    cout<<s.top()<<endl;

}