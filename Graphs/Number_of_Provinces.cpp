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
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n,vector<int>(0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1) adj[i].push_back(j);
            }
        }
        vector<bool> vis(n,false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i,adj,vis);
                count++;
            } 
        }
        return count;
    }
};
