// class Solution {
// public:
//     int n, m,c;
//     void dfs(int r, int c, vector<vector<int>>&vis, vector<vector<int>>&grid){
//         queue<pair<int,int>>q;
//         q.push({r,c});
//         vis[r][c]=1;
//         c++;
//         while(!q.empty()){
//             int nr= q.front().first;
//             int nc= q.front().second;

//             q.pop();

//             for(int j=nc+1; j<m; j++){
//                 if(grid[nr][j]==1 && !vis[nr][j]){
//                     q.push({nr,j});
//                     vis[nr][j]=1;
//                     c++;
//                 }
//             }

//             for(int i=nr+1; i<n; i++){
//                 if(grid[i][nc]==1 && !vis[i][nc]){
//                     q.push({i, nc});
//                     vis[i][nc]=1;
//                     c++;
//                 }
//             }
//         }
//     }

//     int countServers(vector<vector<int>>& grid) {
//         n= grid.size();
//         m= grid[0].size();

//         vector<vector<int>>vis(n, vector<int>(m,0));
//         c=0;

//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(grid[i][j]== 1 && !vis[i][j]){
//                     dfs(i,j, vis, grid );
//                 }
//             }
//         }

//         return c;


//     }
// };


class Solution {
public:
    int n, m, c;

    void dfs(int r, int col, vector<vector<int>>& vis,
             vector<vector<int>>& grid) {

        queue<pair<int,int>> q;
        q.push({r, col});
        vis[r][col] = 1;

        while(!q.empty()) {
            int nr = q.front().first;
            int nc = q.front().second;
            q.pop();

            for(int j = 0; j < m; j++) {
                if(grid[nr][j] == 1 && !vis[nr][j]) {
                    q.push({nr, j});
                    vis[nr][j] = 1;
                }
            }

            for(int i = 0; i < n; i++) {
                if(grid[i][nc] == 1 && !vis[i][nc]) {
                    q.push({i, nc});
                    vis[i][nc] = 1;
                }
            }
        }
    }

    int countServers(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        c = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {

                    int cnt = 0;
                    queue<pair<int,int>> q;

                    q.push({i, j});
                    vis[i][j] = 1;
                    cnt++;

                    while(!q.empty()) {
                        int nr = q.front().first;
                        int nc = q.front().second;
                        q.pop();

                        for(int k = 0; k < m; k++) {
                            if(grid[nr][k] == 1 && !vis[nr][k]) {
                                q.push({nr, k});
                                vis[nr][k] = 1;
                                cnt++;
                            }
                        }

                        for(int k = 0; k < n; k++) {
                            if(grid[k][nc] == 1 && !vis[k][nc]) {
                                q.push({k, nc});
                                vis[k][nc] = 1;
                                cnt++;
                            }
                        }
                    }

                    if(cnt > 1) {
                        c += cnt;
                    }
                }
            }
        }

        return c;
    }
};
