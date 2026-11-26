class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& arr, vector<vector<bool>>& vis) {
        int m = arr.size(), n = arr[0].size();
        vis[row][col] = true;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(q.size() > 0){
            pair<int,int> front = q.front();
            q.pop();
            int r = front.first, c = front.second;
            // up
            if(r-1 >= 0 && arr[r-1][c] == '1' && !vis[r-1][c]){
                q.push({r-1,c});
                vis[r-1][c] = true;
            } 
            // down
            if(r+1 < m && arr[r+1][c] == '1' && !vis[r+1][c]){
                q.push({r+1,c});
                vis[r+1][c] = true;
            } 
            // left
            if(c-1 >= 0 && arr[r][c-1] == '1' && !vis[r][c-1]){
                q.push({r,c-1});
                vis[r][c-1] = true;
            } 
            // right
            if(c+1 < n && arr[r][c+1] == '1' && !vis[r][c+1]){
                q.push({r,c+1});
                vis[r][c+1] = true;
            } 
        }
    }
    int numIslands(vector<vector<char>>& arr) {
        int m = arr.size(), n = arr[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j] == '1' && vis[i][j] == false){
                    bfs(i,j,arr,vis);
                    count++;
                }
            }
        }
        return count;
    }
};
