class Solution {
public:
    void bfs(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        queue<pair<int,int>> q;
        // add boundary 1s to queue
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || j==0 || i==m-1 || j==n-1) && arr[i][j] == 1){
                    q.push({i,j});
                    arr[i][j] = -1; // marked visited
                }
            }
        }
        while(q.size() > 0){
            pair<int,int> front = q.front();
            q.pop();
            int r = front.first, c = front.second;
            // up
            if(r-1 >= 0 && arr[r-1][c] == 1){
                q.push({r-1,c});
                arr[r-1][c] = -1;
            } 
            // down
            if(r+1 < m && arr[r+1][c] == 1){
                q.push({r+1,c});
                arr[r+1][c] = -1;
            } 
            // left
            if(c-1 >= 0 && arr[r][c-1] == 1){
                q.push({r,c-1});
                arr[r][c-1] = -1;
            } 
            // right
            if(c+1 < n && arr[r][c+1] == 1){
                q.push({r,c+1});
                arr[r][c+1] = -1;
            } 
        }
    }
    int numEnclaves(vector<vector<int>>& arr) {
        bfs(arr);
        int count = 0;
        int m = arr.size(), n = arr[0].size();
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(arr[i][j] == 1) count++;
            }
        }
        return count;
    }
};
