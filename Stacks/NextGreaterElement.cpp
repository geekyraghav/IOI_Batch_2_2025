#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void print(vector<int>& v){
    for(int ele : v) 
        cout<<ele<<" ";
    cout<<endl;
}
int main(){
    vector<int> arr = {6,2,1,5,7,8,4};
    stack<int> st;
    int n = arr.size();
    vector<int> nge(n);
    nge[n-1] = -1;
    st.push(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        while(st.size() > 0 && st.top() <= arr[i]) 
            st.pop();
        if(st.size()==0) nge[i] = -1;
        else nge[i] = st.top();
        st.push(arr[i]);
    }
    print(arr);
    print(nge);
}