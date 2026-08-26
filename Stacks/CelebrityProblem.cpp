class Solution {
  public:
    int celebrity(vector<vector<int>>& arr) {
        stack<int> st;
        int n = arr.size();
        for(int i=0;i<n;i++) st.push(i);
        while(st.size() > 1){
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            if(arr[x][y]==0 && arr[y][x]==1) st.push(x);
            if(arr[y][x]==0 && arr[x][y]==1) st.push(y);
        }
        if(st.size()==0) return -1;
        int celeb = st.top();
        // check its row
        for(int j=0;j<n;j++){
            if(celeb==j) continue;
            if(arr[celeb][j]==1) return -1;
        }
        // check its col
        for(int i=0;i<n;i++){
            if(celeb==i) continue;
            if(arr[i][celeb]==0) return -1;
        }
        return celeb;
    }
};
