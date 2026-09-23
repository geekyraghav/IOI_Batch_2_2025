class Solution {
  public:
    int kthSmallest(vector<int>& arr, int k) {
        priority_queue<int> pq;
        for(int ele : arr){
            pq.push(ele);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
