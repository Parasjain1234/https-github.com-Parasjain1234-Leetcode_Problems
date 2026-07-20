class Solution {
public:
    int n;
     int m;
    bool dfs(int i, int j,  vector<vector<int>>&vis, vector<vector<int>>& grid){
        queue<pair<int,int>>q;
        vis[i][j]=1;
        q.push({i,j});
        bool ans=true;

        while(!q.empty()){
            int r= q.front().first;
            int c= q.front().second;
            q.pop();

            if(r==0 ||  c==0 || r== n-1 || c== m-1) {
                ans= false;
            }

            int dr[]= {-1,0, 1,0};
            int dc[]= {0,1,0,-1};

            for(int i=0; i<4; i++){
                int newr= r+dr[i];
                int newc= c+ dc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]== 0  && !vis[newr][newc]){
                    q.push({newr, newc});
                    vis[newr][newc]=1;
                }
            }
            
        }
        return ans;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n= grid.size();
        m= grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int c=0;
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(grid[i][j]== 0 && !vis[i][j]){
                    
                    if(dfs(i,j, vis, grid)) c++;

                }
            }
        }
        return c;
    }
};