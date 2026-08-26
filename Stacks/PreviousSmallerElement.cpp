class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(st.size() > 0 && st.top() >= arr[i]) st.pop();
            if(st.size() == 0) pse[i] = -1;
            else pse[i] = st.top();
            st.push(arr[i]);
        }
        return pse;
    }
};
