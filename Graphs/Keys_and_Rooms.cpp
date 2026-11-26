class Solution {
public:
    void bfs(int st, vector<vector<int>> &adj, vector<bool>& vis){
        queue<int> q;
        q.push(st);
        vis[st] = true;
        while(q.size() > 0){
            int top = q.front();
            q.pop();
            for(int node : adj[top]){
                if(!vis[node]){
                    q.push(node);
                    vis[node] = true;
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> vis(n,false);
        bfs(0,adj,vis);
        for(int i=0;i<n;i++){
            if(vis[i] == false) return false;
        }
        return true;
    }
};
