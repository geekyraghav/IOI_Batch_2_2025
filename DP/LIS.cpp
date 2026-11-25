class Solution {
public: 
    int lowerBound(vector<int>& arr, int ele){
        int ans = -1;
        int lo = 0, hi = arr.size()-1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(arr[mid] >= ele){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
    int lengthOfLIS(vector<int>& arr) {
        vector<int> ans;
        ans.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            if(arr[i] > ans[ans.size()-1]) 
                ans.push_back(arr[i]);
            else{ // replace incoming element with its lower bound in ans
                int lb = lowerBound(ans,arr[i]);
                ans[lb] = arr[i];
            }
        }
        return ans.size();
    }
};
