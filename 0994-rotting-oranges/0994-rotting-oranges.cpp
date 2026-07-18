// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n= grid.size();
//         int m= grid[0].size();
//         queue<pair<int,int>>q;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(grid[i][j]== 2){
//                     q.push({i,j});
//                 }
//             }
//         }
//         int c1=0;
//         while(!q.empty()){
//             int r= q.front().first;
//             int c= q.front().second;
//             q.pop();

//             if(grid[r][c]==1){
//                 c1++;
//                 if(grid[r-1][c]==1 && r-1>=0){
//                     q.push({r-1, c});

//                 }
//                 if(grid[r+1][c]==1 && r+1<n){
//                     q.push({r+1,c});
//                 }
//                 if(grid[r][c-1]==1 && c-1>=0){
//                     q.push({r, c-1});
//                 }
//                 if(grid[r][c+1]==1 && c+1<m){
//                     q.push({r, c+1});
//                 }
//             }
//         }
//         return c1;

//     }
// };
// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();

//         queue<pair<int,int>> q;
//         int fresh = 0;

//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 if(grid[i][j] == 2) {
//                     q.push({i, j});
//                 }
//                 else if(grid[i][j] == 1) {
//                     fresh++;
//                 }
//             }
//         }
        

//         int minutes = 0;

//         while(!q.empty() && fresh > 0) {
//             int sz = q.size();

//             while(sz--) {
//                 auto [r, c] = q.front();
//                 q.pop();

//                 if(r - 1 >= 0 && grid[r - 1][c] == 1) {
//                     grid[r - 1][c] = 2;
//                     fresh--;
//                     q.push({r - 1, c});
//                 }

//                 if(r + 1 < n && grid[r + 1][c] == 1) {
//                     grid[r + 1][c] = 2;
//                     fresh--;
//                     q.push({r + 1, c});
//                 }

//                 if(c - 1 >= 0 && grid[r][c - 1] == 1) {
//                     grid[r][c - 1] = 2;
//                     fresh--;
//                     q.push({r, c - 1});
//                 }

//                 if(c + 1 < m && grid[r][c + 1] == 1) {
//                     grid[r][c + 1] = 2;
//                     fresh--;
//                     q.push({r, c + 1});
//                 }
//             }

//             minutes++;
//         }

//         return (fresh == 0) ? minutes : -1;
//     }
// };
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n, vector<int>(m,0));
        int c=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else if(grid[i][j]==1){
                    c++;
                }
            }
        }
        int time=0;
        while(!q.empty()){
            int r= q.front().first.first;
            int c= q.front().first.second;
            int t= q.front().second;
            q.pop();

            time = max( time, t);

            int dr[]= {-1,0,1,0};
            int dc[]= {0,1,0,-1};

            for(int i=0; i<4; i++){
                int newr= r+ dr[i];
                int newc= c+ dc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m &&
   grid[newr][newc]==1 && !vis[newr][newc]){
                    q.push({{newr, newc}, t+1});
                    vis[newr][newc]=1;
                }
            }

        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && vis[i][j]!=1) return -1;
            }
        }
        return time;
    }
};