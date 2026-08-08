class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));

        if(grid[0][0] ==1 || grid[n-1][m-1]==1) return -1;

    priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;

    pq.push({0,{0,0}});

    while(!pq.empty()){
        int wt= pq.top().first;

        int r= pq.top().second.first;
        int c= pq.top().second.second;

        pq.pop();

        if(r==n-1 && c== m-1) return wt+1;

        

        int row=r-1, col= c-1;
        if(row>=0 && row<n && col>=0 && col<n && !vis[row][col] && grid[row][col]==0){
            pq.push({wt+1, { row, col}});
            vis[row][col]=1;
        }
        
        row= r-1, col= c;
        if(row>=0 && row<n && col>=0 && col<n && !vis[row][col] && grid[row][col]==0){
            pq.push({wt+1, { row, col}});
            vis[row][col]=1;
        }
        row= r-1, col= c+1;
        if(row>=0 && row<n && col>=0 && col<n && !vis[row][col] && grid[row][col]==0){
             pq.push({wt+1, { row, col}});
            vis[row][col]=1;
        }
        row= r, col= c-1;
        if(row>=0 && row<n && col>=0 && col<n && !vis[row][col] && grid[row][col]==0){
             pq.push({wt+1, { row, col}});
            vis[row][col]=1;
        }
        row= r, col= c+1;
        if(row>=0 && row<n && col>=0 && col<n && !vis[row][col] && grid[row][col]==0){
             pq.push({wt+1, { row, col}});
            vis[row][col]=1;
        }
        
        row= r+1, col= c-1;
        if(row>=0 && row<n && col>=0 && col<n && !vis[row][col] && grid[row][col]==0){
            pq.push({wt+1, { row, col}});
            vis[row][col]=1;
        }
        
        row= r+1, col= c;
        if(row>=0 && row<n && col>=0 && col<n && !vis[row][col] && grid[row][col]==0){
             pq.push({wt+1, { row, col}});
            vis[row][col]=1;
        }
        
        row= r+1, col= c+1;
        if(row>=0 && row<n && col>=0 && col<n && !vis[row][col] && grid[row][col]==0){
             pq.push({wt+1, { row, col}});
            vis[row][col]=1;
        }


        

    }

    return -1;
    
    
    
   


    }
};