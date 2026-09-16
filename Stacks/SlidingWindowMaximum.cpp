class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        stack<int> st;
        vector<int> nge(n);
        for(int i=n-1;i>=0;i--){
            while(st.size() > 0 && arr[st.top()] <= arr[i])
                st.pop();
            if(st.size() != 0) nge[i] = st.top();
            else nge[i] = -1;
            st.push(i);
        }
        vector<int> ans(n-k+1);
        int j = 0;
        for(int i=0;i<n-k+1;i++){ // traversing all windows
            if(j < i) j = i;
            while(nge[j] != -1 && nge[j] < i+k) j = nge[j];
            ans[i] = arr[j];
        }
        return ans;
    }
};
