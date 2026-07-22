// class Solution {
// public:
//     int n;
//      int m;
//     int dfs(int i, int j,  vector<vector<int>>&vis, vector<vector<int>>& grid, int c1){
//         queue<pair<int,int>>q;
//         vis[i][j]=1;
//         c1++;
//         q.push({i,j});

//         while(!q.empty()){
//             int r= q.front().first;
//             int c= q.front().second;
//             q.pop();

//             int dr[]= {-1,0, 1,0};
//             int dc[]= {0,1,0,-1};

//             for(int i=0; i<4; i++){
//                 int newr= r+dr[i];
//                 int newc= c+ dc[i];

//                 if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]== 1  && !vis[newr][newc]){
//                     q.push({newr, newc});
//                     vis[newr][newc]=1;
//                     c1++;
//                 }
//             }
//         }
//         return c1;
//     }
//     int largestIsland(vector<vector<int>>& grid) {
//         n= grid.size();
//         m= grid[0].size();
//         int mx=INT_MIN;
//         queue<pair<int,int>>qq;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(grid[i][j]==0){
//                     qq.push({i,j});
//                 }
//             }
//         }
//         if (qq.empty())
//          return n * m;
//         while(!qq.empty()){
//             int r= qq.front().first;
//             int c= qq.front().second;
//             grid[r][c]=1;
//             qq.pop();


//         vector<vector<int>>vis(n, vector<int>(m,0));
        
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(grid[i][j]== 1 && !vis[i][j]){
                  
//                     mx= max(mx,dfs(i,j, vis, grid,0));

//                 }
//             }
//         }
//         grid[r][c]=0;

//         }
//         return mx;
//     }
// };
class Solution {
public:
    int n, m;

    int bfs(int i, int j, vector<vector<int>>& grid, int id) {
        queue<pair<int,int>> q;
        q.push({i, j});
        grid[i][j] = id;

        int cnt = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == 1) {

                    grid[nr][nc] = id;
                    cnt++;
                    q.push({nr, nc});
                }
            }
        }

        return cnt;
    }

    int largestIsland(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        unordered_map<int,int> mp;

        int id = 2;

        // Step 1 : Har island ko unique id do
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    mp[id] = bfs(i, j, grid, id);
                    id++;
                }
            }
        }

        int ans = 0;

        // Agar saare 1 the
        for (auto &it : mp)
            ans = max(ans, it.second);

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Step 2 : Har zero ko 1 maan kar answer nikalo
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 0) {

                    unordered_set<int> st;

                    int cur = 1;

                    for (int k = 0; k < 4; k++) {

                        int nr = i + dr[k];
                        int nc = j + dc[k];

                        if (nr >= 0 && nr < n &&
                            nc >= 0 && nc < m &&
                            grid[nr][nc] > 1) {

                            st.insert(grid[nr][nc]);
                        }
                    }

                    for (auto x : st)
                        cur += mp[x];

                    ans = max(ans, cur);
                }
            }
        }

        return ans;
    }
};