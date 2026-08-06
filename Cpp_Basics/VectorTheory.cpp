#include<iostream>
using namespace std;
int main(){
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(-5);
    arr.push_back(11);
    arr.push_back(0);
    arr.push_back(18);
    arr.push_back(23);
    arr.push_back(8);
    arr.push_back(3);
    arr.push_back(13);
    cout<<arr.capacity();
    // vector<int> arr(5,-2);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}