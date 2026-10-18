class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();

        vector<vector<int>>vis(n, vector<int>(m,0));

        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=1;

        while(!q.empty()){
            int r= q.front().first;
            int c= q.front().second;

            q.pop();

            char ch= grid[r][c];

            if(ch== 'R'){
                int nr= r;
                int nc= c+1;
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
                else return {r,c};
            }
            else if( ch== 'D'){
                int nr= r+1;
                int nc= c;
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
                else return {r,c}; 
            }
            else if( ch== 'U'){
                int nr= r-1;
                int nc= c;
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
                else return {r,c};
            }
            else if(ch== 'L'){
                int nr= r;
                int nc= c-1;
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
                else return {r,c};
            }
        }

        return {0,0};
    }
};