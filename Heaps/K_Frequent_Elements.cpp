class Solution {
public:
    typedef pair<int,int> pii;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int ele : nums){
            map[ele]++;
        }
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(auto x : map){
            pq.push({x.second,x.first});
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while(pq.size() > 0){
            ans.push_back((pq.top().second));
            pq.pop();
        }
        return ans;
    }
};
