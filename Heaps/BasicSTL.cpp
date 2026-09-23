#include<iostream>
#include<queue>
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> minHeap;
int main(){
    minHeap m;
    priority_queue<int> pq; // maxheap
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(0);
    pq.pop();
    cout<<pq.top()<<endl;
}