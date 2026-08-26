class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();

        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && arr[st.top()] >= arr[i]) st.pop();
            if(st.size() > 0) nse[i] = st.top();
            else nse[i] = n; // -1
            st.push(i);
        }

        vector<int> pse(n);
        while(st.size() > 0) st.pop();
        for(int i=0;i<n;i++){
            while(st.size()>0 && arr[st.top()] >= arr[i]) st.pop();
            if(st.size() > 0) pse[i] = st.top();
            else pse[i] = -1; // -1
            st.push(i);
        }
        
        int maxArea = 0;
        for(int i=0;i<n;i++){
            int ht = arr[i];
            int width = nse[i] - pse[i] - 1;
            int area = ht*width;
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};
