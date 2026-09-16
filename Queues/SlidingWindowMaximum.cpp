class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int> dq;
        vector<int> ans(n-k+1);
        for(int i=0;i<k;i++){
            while(dq.size() > 0 && arr[dq.back()] <= arr[i]) dq.pop_back();
            dq.push_back(i);
        }
        ans[0] = arr[dq.front()];
        for(int i=k;i<n;i++){
            while(dq.size() > 0 && arr[dq.back()] <= arr[i]) dq.pop_back();
            dq.push_back(i);
            int j = i - k + 1; // j is window start, i is window end
            while(dq.front() < j) dq.pop_front();
            ans[j] = arr[dq.front()];
        }
        return ans;
    }
};
