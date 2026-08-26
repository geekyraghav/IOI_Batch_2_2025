class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> pge(n);
        // pop, mark, push!
        for(int i=0; i<n; i++){
            while(st.size() > 0 && st.top() <= arr[i]){
                st.pop();
            }
            pge[i] = (st.size() > 0) ? st.top() : -1;
            st.push(arr[i]);
        }
        return pge;
    }
};
