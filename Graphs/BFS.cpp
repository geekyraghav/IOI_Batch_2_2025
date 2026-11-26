class Solution {
  public:
    void bfs(int st, vector<vector<int>> &adj, vector<int>& ans, vector<bool>& vis){
        queue<int> q;
        q.push(st);
        vis[st] = true;
        while(q.size() > 0){
            int top = q.front();
            q.pop();
            ans.push_back(top);
            for(int node : adj[top]){
                if(!vis[node]){
                    q.push(node);
                    vis[node] = true;
                }
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size(); // 0 to n-1
        vector<bool> vis(n,false);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vis[i]) bfs(i,adj,ans,vis);
        }
        return ans;
    }
};
