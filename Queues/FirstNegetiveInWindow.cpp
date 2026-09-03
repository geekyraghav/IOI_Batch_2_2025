class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans(n-k+1,0);
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(arr[i] < 0) q.push({arr[i],i});
        }
        for(int i=0;i<n-k+1;i++){ // ith window start
            while(q.size() > 0 && q.front().second < i) q.pop();
            if(q.size() > 0 && q.front().second < i+k) ans[i] = q.front().first;
        }
        return ans;
    }
};
