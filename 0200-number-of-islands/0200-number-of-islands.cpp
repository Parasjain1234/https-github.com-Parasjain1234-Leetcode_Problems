class Solution {
public:
     int n;
     int m;
    void dfs(int i, int j,  vector<vector<int>>&vis, vector<vector<char>>& grid){
        queue<pair<int,int>>q;
        vis[i][j]=1;
        q.push({i,j});

        while(!q.empty()){
            int r= q.front().first;
            int c= q.front().second;
            q.pop();

            int dr[]= {-1,0, 1,0};
            int dc[]= {0,1,0,-1};

            for(int i=0; i<4; i++){
                int newr= r+dr[i];
                int newc= c+ dc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]== '1'  && !vis[newr][newc]){
                    q.push({newr, newc});
                    vis[newr][newc]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n= grid.size();
        m= grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int c=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]== '1' && !vis[i][j]){
                    c++;
                    dfs(i,j, vis, grid);

                }
            }
        }
        return c;
    }
};